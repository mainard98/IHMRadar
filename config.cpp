#include "config.h"

Config::Config()
{



}

Config::Config(int type, QString portC, int vitesse)
{
    if(type==0)
        profile = new TXT();
    else
        if(type==1)
            profile = new XML();
    else
            if(type==2)
                profile = new JSON();

    portConfig = new Serial(portC,1);
    portConfig->settingsConfig(vitesse);
    portConfig->openSerial(QIODevice::ReadWrite);
    recupProfil();
    portConfig->startRadar(vitalsigns);
}

Config::Config(QString adIp, quint16 numPort)
{
    socketConfig = new SocketTCP(adIp, numPort);
}

void Config::writeCMD()
{
//    qDebug() << "config write cmd";
    socketConfig->writeCMD();
}

Config::~Config()
{
    qDebug() << "destruction port config";
//  delete portLecture;
    delete portConfig;
}

void Config::recupProfil()
{   
    vitalsigns =  profile->recupDonnees();
//    qDebug() << "vitlasigns" << vitalsigns;
}

void Config::writeS()
{
    portConfig->writeStart();
}

void Config::writeSto()
{
    portConfig->writeStop();
}

void Config::writeStopSocket()
{
    //qDebug()<< "config stop";
    socketConfig->writeStop();
}

void Config::writeStartSocket()
{
   // qDebug()<<"config start";
    socketConfig->writeCMD();
}

void Config::writeStart0Socker()
{
    //qDebug()<<"config start 0";
    socketConfig->writeStart0();
}

void Config::writeProfile(QString filename)
{
    socketConfig->writeProfile(filename);
}

void Config::quitApp()
{
    socketConfig->quitApp();
}

void Config::changeClusterON()
{
    socketConfig->clusterON();
}

void Config::changeClusterOFF()
{
    socketConfig->clusterOFF();
}

void Config::changeCFAR_Range(QString threshold)
{
    socketConfig->cfar_range(threshold);
}

void Config::changeCFAR_Doppler(QString threshold)
{
    socketConfig->cfar_doppler(threshold);

}

double Config::writeGetP1()
{
  qDebug() << "GET P1";
  socketConfig->writeGetP1();

}
