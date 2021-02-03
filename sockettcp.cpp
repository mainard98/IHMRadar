#include "sockettcp.h"

SocketTCP::SocketTCP()
{

}

SocketTCP::SocketTCP(QString adIp, quint16 numPort)
{
    socket = new QTcpSocket;
    socket->abort();
    socket->connectToHost(adIp,numPort);
    qDebug() << "IP : " << adIp << " port :" << numPort;

    connect(socket,SIGNAL(readyRead()),this,SLOT(emitTrame()));
}

void SocketTCP::emitTrame()
{
//  qDebug() << "emitTrame";
    trameTcp = socket->readAll().toHex();
    emit dataTcp(trameTcp);
}

void SocketTCP::writeCMD()
{
    qDebug() << "write start";
    socket->write("start");
    socket->waitForBytesWritten(1000);
}

void SocketTCP::writeStart0()
{
//  qDebug() << "write start 0";
    socket->write("start0");
    socket->waitForBytesWritten(1000);

}

void SocketTCP::writeStop()
{
    socket->write("stop");
    socket->waitForBytesWritten(1000);
}

void SocketTCP::writeProfile(QString filename)
{
    QByteArray cmd ="setp ";
    cmd.append(filename);
    socket->write(cmd);
    socket->waitForBytesWritten(1000);
    writeCMD();
}

void SocketTCP::quitApp()
{
    writeStop();
    socket->waitForBytesWritten(1000);
    socket->write("quit");
}

void SocketTCP::clusterON()
{
    socket->write("cr on");
    socket->waitForBytesWritten(1000);

}

void SocketTCP::clusterOFF()
{
    socket->write("cr off");
    socket->waitForBytesWritten(1000);

}

void SocketTCP::cfar_range(QString threshold)
{
    QByteArray cmd("cfar_range ");
    cmd.append(threshold);
    socket->write(cmd);
    socket->waitForBytesWritten(1000);
}

void SocketTCP::cfar_doppler(QString threshold)
{
    QByteArray cmd("cfar_doppler ");
    cmd.append(threshold);
    socket->write(cmd);
    socket->waitForBytesWritten(1000);
}

double SocketTCP::writeGetP1()
{
    socket->write("get p1");
}
