#include "txt.h"

TXT::TXT()
{





}

QByteArrayList TXT::recupDonnees()
{
    qDebug() << "fichier TXT";

         QFile CMD("D:/Documents/Bureau/C++/QT/untitled/CMD.txt");

         if(CMD.open(QIODevice::ReadOnly | QIODevice::Text))
         {
             while(!CMD.atEnd())
             {
                 TexteCMD = CMD.readAll();
             }
              CMD.close();
         }
         else
         {
               qDebug() << "Erreur lors de l'ouverture du fichier" ;
         }

         listCMD = TexteCMD.split('\n');
//         qDebug() << listCMD <<"LISTE";
//         calculParam();
         return listCMD;
}
