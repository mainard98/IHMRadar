#ifndef XML_H
#define XML_H
#include "lecturefile.h"
#include <QtXml>


class XML : public lectureFile
{
public:

    XML();
    QByteArrayList recupDonnees() override;
private:

    QString tempString;




};

#endif // XML_H
