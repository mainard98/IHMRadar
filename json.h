#ifndef JSON_H
#define JSON_H
#include "lecturefile.h"
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonValue>
#include <QJsonArray>



class JSON : public lectureFile
{

public:
    JSON();

    QByteArrayList recupDonnees() override;






};

#endif // JSON_H
