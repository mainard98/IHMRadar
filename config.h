#ifndef CONFIG_H
#define CONFIG_H
#include "lecturefile.h"
#include "txt.h"
#include "xml.h"
#include "json.h"
#include "Serial.h"
#include <QList>
#include "sockettcp.h"



class Config : public QObject
{

    Q_OBJECT

public:

    Config();
    Config(int type, QString portC, int vitesse);
    Config(QString adIp, quint16 numPort);
    ~Config();
    void recupProfil();
    void writeS();
    void writeSto();
    void writeCMD();
    void writeStopSocket();
    void writeStartSocket();
    void writeStart0Socker();
    void writeProfile(QString filename);
    void quitApp();
    void changeClusterON();
    void changeClusterOFF();
    void changeCFAR_Range(QString threshold);
    void changeCFAR_Doppler(QString threshold);
    double writeGetP1();

private:

    lectureFile *profile;
    QByteArrayList vitalsigns;
    QString reponse;
    int ligne = 0;
    Serial *portConfig;
    SocketTCP *socketConfig;
    bool cluster = false;

};

#endif // CONFIG_H
