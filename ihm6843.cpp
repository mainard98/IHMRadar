#include "ihm6843.h"
#include "ui_ihm6843.h"
#include <QHBoxLayout>
#include <QPushButton>

IHM6843::IHM6843(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::IHM6843)
{
    ui->setupUi(this);

    ui->stop->setDisabled(stateStopButton);
    scatter = new Q3DScatter();

    series = new QScatter3DSeries;
    pointOrigine = new QScatter3DSeries;

    file = new iniFile;
    file->lireTCP(&ip,&numPort);

    QFile backupF(_filename);
    QTextStream flux(&backupF);

    if (!backupF.open(QIODevice::WriteOnly | QIODevice::Text | QIODevice::Append))
        qDebug() << "impossible d'ouvrir le fichier";

    QMenu *menuFichier = menuBar()->addMenu("Files");
    QAction *actionQuitter = new QAction("Quit", this);             //menu fichier
    QMenu *fichierCfg = menuFichier->addMenu("Change the cfg file");

    QDir directory("C:/cygwin64/home/alexis.mainard/2020-02-18/radarV2");
    QStringList listeCFG = directory.entryList(QStringList() << "*.cfg" << "*.CFG",QDir::Files);

    signalMapper = new QSignalMapper(this);
    foreach(QString filename, listeCFG) {

        ptAction = fichierCfg->addAction(filename);
        signalMapper->setMapping(ptAction,filename);
        connect(ptAction,SIGNAL(triggered()),signalMapper,SLOT(map()));

    }
    connect(signalMapper, SIGNAL(mapped(QString)),this, SLOT(change_cfg(QString)));

    menuFichier->addAction(actionQuitter);

    QMenu *menuParametre = menuBar()->addMenu("Settings");            //menu Parametre
    clutterR = new QAction("Clutter Removal");
    clutterR->setCheckable(true);
    clutterR->setChecked(true);
    rangeThreshold = new QAction("Range Threshold ");
    dopplerThreshold = new QAction("Doppler Threshold");
    observation = new QAction("Zone d'observation");
    backupFile = new QAction("Fichier de sauvegarde");

    menuParametre->addAction(clutterR);
    menuParametre->addAction(rangeThreshold);
    menuParametre->addAction(dopplerThreshold);
    menuParametre->addAction(observation);
    menuParametre->addAction(backupFile);

    tcpConfig = new Config(ip,numPort);

    scatter->addSeries(series);
    scatter->addSeries(pointOrigine);

    ui->horizontalLayout_2->addWidget(QWidget::createWindowContainer(scatter, this));
    scatter->setFlags(scatter->flags() ^ Qt::FramelessWindowHint);
    scatter->activeTheme()->setBackgroundEnabled(false);
    scatter->activeTheme()->setGridEnabled(true);
    scatter->activeTheme()->setLabelBackgroundEnabled(true);

    file->lireAxe(&minZ,&maxZ,&minX,&maxX,&minY,&maxY);

    scatter->axisZ()->setMax(maxZ);
    scatter->axisZ()->setMin(minZ);   //Azimuth

    scatter->axisX()->setMax(maxX);   //Normale
    scatter->axisX()->setMin(minX);

    scatter->axisY()->setMax(maxY);  //Elevation
    scatter->axisY()->setMin(minY);

    scatter->axisX()->setTitle("Normale (X)");
    scatter->axisX()->setTitleVisible(true);
    scatter->axisY()->setTitle("Elevation (Y)");
    scatter->axisY()->setTitleVisible(true);
    scatter->axisZ()->setTitle("Azimuth (Z)");
    scatter->axisZ()->setTitleVisible(true);

    series->setItemSize(0.1);
    pointOrigine->setItemSize(0.2);
    pointOrigine->setBaseColor(QColor(255,0,0));

    titleFont.setPointSize(12);
    titleFont.bold();
    QCPTextElement *myTitle2 = new QCPTextElement(ui->RangeP, "Range Profile");
    myTitle2->setFont(titleFont);
    ui->RangeP->plotLayout()->insertRow(0);
    ui->RangeP->plotLayout()->addElement(0, 0, myTitle2);
    ui->RangeP->addGraph();
    ui->RangeP->xAxis->setLabel("Distance");
    ui->RangeP->yAxis->setLabel("Magnitude");
    ui->RangeP->xAxis->setRange(0, 255*0.043602);

    connect(actionQuitter, SIGNAL(triggered()),this,SLOT(quitter()));
    connect(clutterR,SIGNAL(triggered()),this,SLOT(clutter_clicked()));
    connect(rangeThreshold,SIGNAL(triggered()),this,SLOT(cfar_range_clicked()));
    connect(dopplerThreshold,SIGNAL(triggered()),this,SLOT(cfar_doppler_clicked()));
    connect(observation,SIGNAL(triggered()),this,SLOT(changeAxisZ()));
    connect(backupFile,SIGNAL(triggered()),this,SLOT(change_backupFile()));
}

IHM6843::~IHM6843()
{
    delete ui;
}

void IHM6843::printVector3D(QVector<QVector3D> points, int nbObjet)
{
    data.clear();

    for(int i=0 ; i< nbObjet; i++){
                data.append(points[i]);
    }

    scatter->seriesList().at(0)->dataProxy()->resetArray(&data);
    scatter->seriesList().at(0)->dataProxy()->array();

    QScatterDataItem origine = QScatterDataItem(QVector3D(0,0,0));
    scatter->seriesList().at(1)->dataProxy()->addItem(origine);
}

void IHM6843::printRangeP(QVector<double> xRange, QVector<double> yRange)
{
//    qDebug() << "Range x" << xRange;
//    qDebug() << "Range y" << yRange;

    maxxRange = *std::max_element(xRange.constBegin(), xRange.constEnd());
    maxyRange = *std::max_element(yRange.constBegin(), yRange.constEnd());

//    if (maxyRange < 10.00)
//    {
//        ui->RangeP->yAxis->setRangeUpper(10.00);
//    }
//    else
//    {
//        ui->RangeP->yAxis->setRangeUpper(maxyRange);
//    }
    ui->RangeP->yAxis->setRangeUpper(3000);
    ui->RangeP->yAxis->setRangeLower(1400);

    ui->RangeP->graph(0)->setData(xRange,yRange);
    ui->RangeP->replot();

    xRange.clear();
    yRange.clear();
}

void IHM6843::printDistance(double distance)
{
    ui->distance->setText("Distance : " + QString::number(distance) + " m");
}

void IHM6843::on_stop_clicked()
{
   // qDebug() << "stop clicked";
    tcpConfig->writeStopSocket();
    alreadyStop = true;
    ui->stop->setDisabled(stateStopButton);
    ui->start->setDisabled(!stateStartButton);

}

void IHM6843::on_start_clicked()
{
   // qDebug() <<"start clicked";

    if(alreadyStop==false)
    {
        tcpConfig->writeStartSocket();
    }
    else
    {
        tcpConfig->writeStart0Socker();
        //alreadyStop==false;
    }
    ui->start->setDisabled(stateStartButton);
    ui->stop->setDisabled(!stateStopButton);
}

void IHM6843::quitter()
{
    tcpConfig->quitApp();
    qApp->closeAllWindows();

}

void IHM6843::clutter_clicked()
{
   // qDebug()<<"ALLO?";
    if(clutterR->isChecked())
    {
//      qDebug()<<"checked";
        tcpConfig->changeClusterON();
    }
    else
    {
//      qDebug()<<"not checked";
        tcpConfig->changeClusterOFF();
    }
}

void IHM6843::cfar_range_clicked()
{
    //qDebug() << "cfar range button";

    bool ok = false;
    QString threshold = QInputDialog::getText(this, "Change range threshold", "CFAR threshold :", QLineEdit::Normal, QString(), &ok);

    if (ok && !threshold.isEmpty())
    {
        tcpConfig->changeCFAR_Range(threshold);
    }
}

void IHM6843::cfar_doppler_clicked()
{
    bool ok = false;
    QString threshold = QInputDialog::getText(this, "Change doppler threshold", "CFAR threshold :", QLineEdit::Normal, QString(), &ok);

    if (ok && !threshold.isEmpty())
    {
        tcpConfig->changeCFAR_Doppler(threshold);
    }
}

void IHM6843::change_cfg(QString filename)
{
   //qDebug()<< filename;
   clutterR->setChecked(false);
   ui->stop->setDisabled(!stateStopButton);
   ui->start->setDisabled(stateStartButton);

   tcpConfig->writeProfile(filename);
}

void IHM6843::changeAxisZ()
{
    QList<int> axe;
    zone = new InputDialog;
    bool ok;

    axe = zone->getInt(this, &ok);

    maxZ = axe.at(0);
    minZ = axe.at(1);

    maxX = axe.at(2);
    minX = axe.at(3);

    maxY = axe.at(4);
    minY = axe.at(5);

    scatter->axisZ()->setMax(maxZ);   //Azimuth
    scatter->axisZ()->setMin(minZ);

    scatter->axisX()->setMax(maxX);   //Normale
    scatter->axisX()->setMin(minX);

    scatter->axisY()->setMax(maxY);   //Elevation
    scatter->axisY()->setMin(minY);

    file->ecrireAxe(minZ,maxZ,minX,maxX,minY,maxY);
}

void IHM6843::change_backupFile()
{

    qDebug() << _filename;
    bool ok = false;
    QString nouvFilename = QInputDialog::getText(this, "Nouveau nom", "Backup File", QLineEdit::Normal, QString(), &ok);

    _filename = nouvFilename;

    qDebug() << _filename;
}

double IHM6843::getP1()
{
    double P1 = tcpConfig->writeGetP1();
}

double IHM6843::getP2()
{




}

