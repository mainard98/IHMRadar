 #include "mainwindow.h"
#include "ui_mainwindow.h"

using namespace QtDataVisualization;


MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setWindowTitle("XtreamWave - Demo");

    ihm6843 = new IHM6843();

    QPixmap pm("D:/Documents/Bureau/C++/QT/untitled/logo-Xtreamwave.jpg");
    ui->label1->setPixmap(pm);
    ui->label1->setScaledContents(true);

    centralWidget()->setLayout(ui->gridLayout_2);

    file = new iniFile();
    file->liremode(&mode);

    if(mode==1)
    {
        //PORTS
        file->lirevitesse(&vit1,&vit2);
        file->lireports(&port1,&port2);
        int typefichier = file->lireformat();

        configuration = new Config(typefichier, port2,vit2);
        lectureData = new lecture(port1,vit1,mode);
        qDebug() << "vitesse lecture :" << vit1 <<"vitesse config :" << vit2;

        connect(lectureData,SIGNAL(RangePlot(QVector<double>,QVector<double>)),this,SLOT(getRangePlot(QVector<double>,QVector<double>)));
        connect(lectureData,SIGNAL(breath(double)),this,SLOT(getBreathing(double)));
        connect(lectureData,SIGNAL(heart(double)),this,SLOT(getHeartRate(double)));
        connect(lectureData,SIGNAL(chest(double)),this,SLOT(getChestDisplacement(double)));
    }
    else if(mode==0)
    {
      //TCP
        MainWindow::setCentralWidget(ihm6843);
        file->lireTCP(&ip,&numPort);

      //qDebug() << "TCP LECTURE";
        tcpLecture = new lecture(ip,numPort,mode);

        connect(tcpLecture,SIGNAL(dataXYZV(QVector<QVector<float>>,int)),this,SLOT(getDataXYZV(QVector<QVector<float>>,int)));
        connect(tcpLecture,SIGNAL(RangePlot6843(QVector<double>,QVector<double>,double)),this,SLOT(getRangeP6843(QVector<double>, QVector<double>,double)));
    }

    qRegisterMetaType<QVector<double>>("QVector<double>");

    connect(ui->mStart, SIGNAL(clicked()),this,SLOT(Start()));
    connect(ui->mStop, SIGNAL(clicked()),this,SLOT(Stop()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::Start()
{

    configuration->writeS();
}

void MainWindow::Stop()
{
    configuration->writeSto();
}

void MainWindow::getRangePlot(QVector<double> xRange, QVector<double> yRange)
{
        SpinBox_RCS = 2000.000;
        maxRCS = *std::max_element(yRange.constBegin(), yRange.constEnd());

        if(rangePro==false)
        {
            titleFont.setPointSize(12);
            titleFont.bold();
            QCPTextElement *myTitle2 = new QCPTextElement(ui->RangeProfile, "Range Profile");
            myTitle2->setFont(titleFont);
            ui->RangeProfile->plotLayout()->insertRow(0);
            ui->RangeProfile->plotLayout()->addElement(0, 0, myTitle2);
            ui->RangeProfile->addGraph();
            ui->RangeProfile->xAxis->setLabel("Distance (m)");
            ui->RangeProfile->yAxis->setLabel("Magnitude");
            rangePro = true;
        }

        ui->RangeProfile->graph(0)->setData(xRange, yRange);
        ui->RangeProfile->xAxis->setRange(0.3, 0.912);

        if (maxRCS < SpinBox_RCS)
        {
            ui->RangeProfile->yAxis->setRangeUpper(SpinBox_RCS);
        }
        else
        {
            ui->RangeProfile->yAxis->setRangeUpper(maxRCS);
        }

        ui->RangeProfile->replot();
}

void MainWindow::getBreathing(double yBreath)
{
    compteurBreath = compteurBreath + 1;
    int indexT = compteurBreath % 256;

    double maxBreathing = *std::max_element(yBreathingWfm.constBegin(), yBreathingWfm.constEnd());
    double minBreathing = *std::min_element(yBreathingWfm.constBegin(), yBreathingWfm.constEnd());
    double breathingWfm_display_max, breathingWfm_display_min;

    if (maxBreathing < 1)
        breathingWfm_display_max = 1;
    else
        breathingWfm_display_max = maxBreathing;

    if (minBreathing > -1)
        breathingWfm_display_min = -1;
    else
        breathingWfm_display_min = minBreathing;

    yBreathingWfm.append(yBreath);
    xDistTimePlot.append(indexT);

        if(breathingWfm==false)
          {
            titleFont.setPointSize(12);
            titleFont.bold();
            QCPTextElement *myTitle = new QCPTextElement(ui->BreathingWaveform, "Breathing Waveform");
            myTitle->setFont(titleFont);
            ui->BreathingWaveform->plotLayout()->insertRow(0);
            ui->BreathingWaveform->plotLayout()->addElement(0, 0, myTitle);
            ui->BreathingWaveform->addGraph();
            ui->BreathingWaveform->xAxis->setRange(0, 256);
            ui->BreathingWaveform->yAxis->setLabel("Phase (radian)");
            ui->BreathingWaveform->yAxis->setRange(-1,1);
            ui->BreathingWaveform->setNoAntialiasingOnDrag(true);
            breathingWfm = true;
          }

//  qDebug() << indexT;
    ui->BreathingWaveform->yAxis->setRangeLower(breathingWfm_display_min);
    ui->BreathingWaveform->yAxis->setRangeUpper(breathingWfm_display_max);
    ui->BreathingWaveform->graph(0)->addData(xDistTimePlot, yBreathingWfm);

    if(indexT==255)
    {
         ui->BreathingWaveform->graph(0)->data()->removeAfter(indexT==255);
         yBreathingWfm.clear();
         xDistTimePlot.clear();
    }

    ui->BreathingWaveform->replot();

//  qDebug() << yBreathingWfm << xDistTimePlot;
}

void MainWindow::getHeartRate(double yHeart)
{
    compteurHeart = compteurHeart + 1;
    int indexT = compteurHeart % 256;

    double maxHeart = *std::max_element(yHeartRateWfm.constBegin(), yHeartRateWfm.constEnd());
    double minHeart = *std::min_element(yHeartRateWfm.constBegin(), yHeartRateWfm.constEnd());
    double HeartWfm_display_max, HeartWfm_display_min;

    if (maxHeart < 0.5)
        HeartWfm_display_max = 0.5;
    else
        HeartWfm_display_max = maxHeart;

    if (minHeart > -1)
        HeartWfm_display_min = -1;
    else
        HeartWfm_display_min = minHeart;

    if(heart==false)
    {
        titleFont.setPointSize(12);
        titleFont.bold();
        QCPTextElement *myTitle = new QCPTextElement(ui->HeartRate, "Heart Rate");
        myTitle->setFont(titleFont);
        ui->HeartRate->plotLayout()->insertRow(0);
        ui->HeartRate->plotLayout()->addElement(0, 0, myTitle);
        ui->HeartRate->addGraph();
        ui->HeartRate->xAxis->setRange(0, 256);
        ui->HeartRate->yAxis->setLabel("Phase (radian)");
        ui->HeartRate->yAxis->setRange(-1,1);
        ui->HeartRate->setNoAntialiasingOnDrag(true);
        heart = true;
    }

    yHeartRateWfm.append(yHeart);
    xDistTimePlot2.append(indexT);

//  qDebug() << yHeartRateWfm << xDistTimePlot2;

    ui->HeartRate->yAxis->setRangeLower(HeartWfm_display_min);
    ui->HeartRate->yAxis->setRangeUpper(HeartWfm_display_max);
    ui->HeartRate->graph(0)->addData(xDistTimePlot2,yHeartRateWfm);

    if(indexT==255)
    {
         ui->HeartRate->graph(0)->data()->removeAfter(indexT==255);
         yHeartRateWfm.clear();
         xDistTimePlot2.clear();
    }

//    qDebug() << indexT;

    ui->HeartRate->replot();

}

void MainWindow::getChestDisplacement(double yChestDisplacement)
{
    compteurTorse = compteurTorse + 1;
    int indexT = compteurTorse % 256;

    if(chest==false)
    {
        titleFont.setPointSize(12);
        titleFont.bold();
        QCPTextElement *myTitle = new QCPTextElement(ui->ChestDisplacement, "Chest Displacement");
        myTitle->setFont(titleFont);
        ui->ChestDisplacement->plotLayout()->insertRow(0);
        ui->ChestDisplacement->plotLayout()->addElement(0, 0, myTitle);
        ui->ChestDisplacement->addGraph();
        ui->ChestDisplacement->xAxis->setRange(0, 256);
        ui->ChestDisplacement->yAxis->setLabel("Displacement");
        ui->ChestDisplacement->xAxis->setLabel("Frame (index)");
        ui->ChestDisplacement->yAxis->setRange(-10,10);
        ui->ChestDisplacement->setNoAntialiasingOnDrag(true);
        chest = true;
    }

    xDistTimePlotChest.append(indexT);
    yChest.append(yChestDisplacement);

    if(indexT==255)
    {
         ui->ChestDisplacement->graph(0)->data()->removeAfter(indexT==255);
         yChest.clear();
         xDistTimePlotChest.clear();
    }

    ui->ChestDisplacement->graph()->addData(xDistTimePlotChest,yChest);
    ui->ChestDisplacement->yAxis->rescale();
    ui->ChestDisplacement->replot();
}

void MainWindow::getDataXYZV(QVector<QVector<float>> data, int nbObjet)
{
//  qDebug() << "data" << data;           //Liste de tableau de float X Y Z V
    QVector<QVector3D> tabDataXYZ;

    qDebug() << "FRAME" << frame++;
    QFile file(fileName);
    QTextStream flux(&file);

    if (!file.open(QIODevice::WriteOnly | QIODevice::Text | QIODevice::Append))
          qDebug() << "impossible d'ouvrir le fichier";

    for(int i=0;i<nbObjet;i++)
    {
        QVector3D pointTemp(data[i][1],-data[i][2],data[i][0]);   //Y  Z  X du radar = X  Y  Z de mon graph

        if(header == false)
        {
            flux << "frame;y;z;x;v\n";
            header = true;
        }
        flux << frame << ";" << data[i][1] << ";" <<-data[i][2]<< ";" << data[i][0] << "\n";
        qDebug() << "Vitesse" << data[i][3];

//      qDebug() << "QVector3D" << pointTemp;
        tabDataXYZ.append(pointTemp);
//      qDebug() << "tab" << tabDataXYZ;
    }

    ihm6843->printVector3D(tabDataXYZ,nbObjet);
    tabDataXYZ.clear();
}

void MainWindow::getRangeP6843(QVector<double> xRange, QVector<double> yRange, double distance)
{
//  qDebug() << "getRange" ;
    i++;
    ihm6843->printRangeP(xRange,yRange);

    distanceMoyenne += distance;

    if(i == 5)
    {
        distanceMoyenne = distanceMoyenne / i;
        ihm6843->printDistance(distanceMoyenne);
        i = 0;
        distanceMoyenne = 0 ;
       }
}
