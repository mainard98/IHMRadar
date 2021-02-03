#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QChart>
#include <QChartView>
#include <QLineSeries>
#include <QValueAxis>
#include <QDateTimeAxis>
#include <QObject>
#include <QLabel>
#include <QSerialPortInfo>
#include <QSerialPort>
#include <QString>
#include "Serial.h"
#include "lecturefile.h"
#include "config.h"
#include "xml.h"
#include "inifile.h"
#include "lecture.h"
#include <QPushButton>
#include <qcustomplot.h>
#include <QFont>
#include <QPixmap>
#include <QLabel>
#include "sockettcp.h"
#include <Q3DScatter>
#include <QScatter3DSeries>
#include <QtDataVisualization>
#include "ihm6843.h"


QT_CHARTS_USE_NAMESPACE;


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    Serial  *portConfig;



private slots:

    void Start();
    void Stop();
    void getRangePlot(QVector<double>, QVector<double>);
    void getBreathing(double);
    void getHeartRate(double);
    void getChestDisplacement(double);
    void getDataXYZV(QVector<QVector<float>>,int);
    void getRangeP6843(QVector<double> xRange, QVector<double> yRange, double distance);

private:

    Ui::MainWindow *ui;
    IHM6843 *ihm6843;
    QFont titleFont;
    bool test = false;
    bool header = false;
    iniFile *file;
    QString port1;
    QString port2;
    int mode;
    quint16 numPort;
    QString ip;
    int vit1,vit2;
    lecture *lectureData;
    Config *configuration;
    lecture *tcpLecture;
    Config *tcpConfig;
    uint32_t compteurBreath = 0;
    uint32_t compteurHeart = 0;
    uint32_t compteurTorse = 0;
    bool title = false;
    bool openGL = false;
    double SpinBox_RCS;
    double maxRCS;
    int indexT;
    double maxBreathing;
    double minBreathing;
    double breathingWfm_display_max, breathingWfm_display_min;
    QVector3D point;

    QString fileName ="data.csv";


    int frame = 0;

    bool breathingWfm = false;
    bool rangePro = false;
    bool heart = false;
    bool chest = false;
    bool point3D = false;

    QVector<double> yBreathingWfm;
    QVector<double> xDistTimePlot, xDistTimePlot2, xDistTimePlotChest;
    QVector<double> yHeartRateWfm;
    QVector<double> yChest;

    int i = 0;
    double distanceMoyenne = 0;

};
#endif // MAINWINDOW_H
