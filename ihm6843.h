#ifndef IHM6843_H
#define IHM6843_H

#include <QMainWindow>
#include <Q3DScatter>
#include <QScatter3DSeries>
#include <QtDataVisualization>
#include <QHBoxLayout>
#include <QPushButton>
#include "inifile.h"
#include "sockettcp.h"
#include "config.h"
#include "lecture.h"
#include "inputdialog.h"

using namespace QtDataVisualization;


namespace Ui {
class IHM6843;
}

class IHM6843 : public QMainWindow
{

    Q_OBJECT

public:

    explicit IHM6843(QWidget *parent = nullptr);
    void printVector3D(QVector<QVector3D> points, int nbObjet);
    void printRangeP(QVector<double> xRange, QVector<double> yRange);
    void printDistance(double distance);
    double getP1();
    double getP2();

    ~IHM6843();

private slots:

    void on_stop_clicked();
    void on_start_clicked();
    void clutter_clicked();
    void cfar_range_clicked();
    void cfar_doppler_clicked();
    void quitter();
    void change_cfg(QString filename);
    void changeAxisZ();
    void change_backupFile();

private:

    Ui::IHM6843 *ui;
    int compteur = 0;
    QScatterDataArray data;
    QScatterDataArray Origine;
    Q3DScatter *scatter;
    Q3DScatter *origine;

    QVector3D origineVector;

    QString _filename = "data.csv";

    QScatter3DSeries *pointOrigine;
    QScatter3DSeries *series;
    QScatter3DSeries *prevseries;
    double maxxRange,maxyRange;
    bool graph = false;
    QFont titleFont;
    QHBoxLayout horizontalLayout;
    iniFile *file;
    quint16 numPort;
    QString ip;
    int mode;
    Config *tcpConfig;
    lecture *tcpLecture;
    bool alreadyStop = false;
    bool cluster =false;

    QAction *profile6842;
    QAction *profileFP34;
    QAction *profileFP50;
    QAction *profileFP100;
    QAction *clutterR;
    QAction *rangeThreshold;
    QAction *ptAction;
    QAction *dopplerThreshold;
    QAction *observation;
    QAction *backupFile;

    QSignalMapper *signalMapper;
    bool stateStartButton = true;
    bool stateStopButton = true;

    int maxZ;
    int minZ;

    int maxX;
    int minX;

    int maxY;
    int minY;

    QList<int> listAxes;
    InputDialog *zone;


};

#endif // IHM6843_H
