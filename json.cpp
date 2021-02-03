#include "json.h"

JSON::JSON()
{

}


QByteArrayList JSON::recupDonnees()
{
    qDebug() << "fichier JSON";

     QString val;
     QFile file("D:/Documents/Bureau/C++/QT/untitled/CMD.json");

     if(file.open(QIODevice::ReadOnly | QIODevice::Text))
     {

        val = file.readAll();
              file.close();

              QJsonDocument d = QJsonDocument::fromJson(val.toUtf8());
              QJsonObject sett2 = d.object();
              QJsonValue value = sett2.value(QString("vitalsigns"));
              QJsonObject item = value.toObject();

              QJsonArray test = item["commandes"].toArray();

              for(int i =0; i<test.size(); i++)
              {
                  TexteCMD.append(test[i].toString()+'\n');

              }

              listCMD = TexteCMD.split('\n');
              return listCMD;
     }
     else
     {
           qDebug() << "Erreur lors de l'ouverture du fichier" ;
     }
              return listCMD;
}

