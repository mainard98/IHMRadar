#ifndef TXT_H
#define TXT_H
#include "lecturefile.h"

class TXT : public lectureFile
{
public:

    TXT();
    QByteArrayList recupDonnees() override;

};

#endif // TXT_H
