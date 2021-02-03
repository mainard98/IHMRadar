#ifndef SOCKETTCP_H
#define SOCKETTCP_H
#include <QString>
#include <QTcpSocket>
#include <QtEndian>

class SocketTCP : public QObject
{
    Q_OBJECT

public:
    SocketTCP();
    SocketTCP(QString adIp, quint16 numPort);
    void writeCMD();

    void writeStop();
    void writeStart0();
    void writeProfile(QString filename);
    void quitApp();
    void clusterON();
    void clusterOFF();
    void cfar_range(QString threshold);
    void cfar_doppler(QString threshold);
    double writeGetP1();


private:
    int test = 0;
    QTcpSocket *socket;
    QByteArray trameTcp;
    bool flag = false;
    double P1 = 0.0;

signals:
    void dataTcp(QByteArray);

public slots:
    void emitTrame();



};

#endif // SOCKETTCP_H
