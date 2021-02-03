#include "xml.h"

XML::XML()
{

}


QByteArrayList XML::recupDonnees()
{
    qDebug() << "fichier XML";

    dom = new QDomDocument("mon_xml");
    QFile xml_doc ("D:/Documents/Bureau/C++/QT/untitled/CMD.xml");

    if(!xml_doc.open(QIODevice::ReadOnly))
    {
        qDebug() << "Erreur a l'ouverture de CMD.xml";
    }

    if(!dom->setContent(&xml_doc))
    {
        xml_doc.close();
        qDebug() << "Erreur a l'ouverture du document XML";
    }

    QDomElement dom_element = dom->documentElement();
    QDomNode noeud = dom_element.firstChild();

    if(!dom_element.isNull())
        {
             tempString = dom_element.text();
             tempString.remove('\r');
             TexteCMD.append(tempString);
             listCMD = TexteCMD.split('\n');

        }

    return  listCMD;

}
