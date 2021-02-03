    #ifndef LECTUREFILE_H
#define LECTUREFILE_H
#include <QFile>
#include <QDebug>
#include <QString>
#include <QTextStream>
#include <QStringList>
#include <QDomDocument>
#include <QFile>
#include <QtMath>

class lectureFile
{

public:

    lectureFile();
    virtual ~lectureFile();
    virtual QByteArrayList recupDonnees() = 0;


protected:

    QByteArray TexteCMD, profileCfg, frameCfg;
    QByteArrayList listCMD, listProfileCfg, listFrameCfg;
    QDomDocument *dom;
    int c = 3.0E8;
    double rangeIdxToMeters;
    double dopplerResolutionMps;
    double numAdcSamples;
    double numOfChirps;
};

#endif // LECTUREFILE_H
