#ifndef LECTURE_H
#define LECTURE_H
#include <Serial.h>
#include <QString>
#include <QByteArray>
#include <QtEndian>
#include <math.h>
#include <QVector>
#include "sockettcp.h"
#include <QVector3D>
#include <QGenericMatrix>

class lecture : public QObject
{
    Q_OBJECT

public:

    lecture();
    lecture(QString nomPort, int vitesse, int mode);
    lecture(QString adIp, quint16 numPort, int modeLect);

    void processData();
    void processData6843();
    qint16 parseRangeProfile(QByteArray data, int valuePos, int valueSize);
    double parseValueFloat(QByteArray data,  int valuePos, int valueSize);
    int parseLengthFrame(QByteArray data, int valuePos, int valueSize);
    int parseValueNumDetectedObj(QByteArray data, int valuePos, int valueSize);
    void parsePoint(QByteArray data, int valuePos, int valueSize, int nombreObj);
    double findMaximum(QVector<double> RangeProfile, double seuil);

    QVector<float> matriceRotation(float x, float y, float z);

private:

    Serial *portLecture;
    SocketTCP *socketLecure;

    QByteArray dataBuffer, data;
    int magicOk;
    uint32_t Compteur = 0;

    int modeLecture;
    int frame=0;
    int test=0;

    int theta1 = -7;
    int theta2 = 25;

    float cosa = cos(theta1*(M_PI/180));
    float cosb = cos(theta2*(M_PI/180));
    float sina = sin(theta1*(M_PI/180));
    float sinb = sin(theta2*(M_PI/180));

    QVector<float> origine;
    QVector<QVector<float>> listData;

    QString fileName ="C:/Users/alexis.mainard/OneDrive - yncréa/Bureau/XtreamWave/ProjetRadar_Socket/Centre.csv";

    double seuil = 0;
    double distPeek;
    double moyenneDistance = 0;
    int dataStartIndex;

public slots:
    void reception(QByteArray trame);

signals:
    void RangePlot(QVector<double>,QVector<double>);
    void RangePlot6843(QVector<double>,QVector<double>,double);
    void breath(double);
    void heart(double);
    void chest(double);
    void dataXYZV(QVector<QVector<float>>,int);

};

#endif // LECTURE_H
