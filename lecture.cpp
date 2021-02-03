#include "lecture.h"

lecture::lecture()
{


}

lecture::lecture(QString nomPort, int vitesse, int mode)
{

    portLecture = new Serial(nomPort,0);
    portLecture->settingsLecture(vitesse);
    portLecture->openSerial(QIODevice::ReadWrite);
    modeLecture=mode;
    qDebug() << "mode" << modeLecture;

    connect(portLecture,SIGNAL(dataTrame(QByteArray)),this,SLOT(reception(QByteArray)));

}

lecture::lecture(QString adIp, quint16 numPort, int mode)
{
    socketLecure = new SocketTCP(adIp, numPort);
    modeLecture = mode;
//  qDebug() << "mode:" << modeLecture;

    connect(socketLecure,SIGNAL(dataTcp(QByteArray)),this,SLOT(reception(QByteArray)));
}

void lecture::reception(QByteArray trame)
{
    dataBuffer = trame;
//  qDebug() << "TRAME" << trame;
//  qDebug() << "mode:" << modeLecture;
//  qDebug() << dataBuffer;

    if(modeLecture==1)
    {
      processData();
    }
    else if(modeLecture==0)
        {
         processData6843();
        }

    dataBuffer.clear();
}

void lecture::processData()
{
//      qDebug() << "PROCESS" ;
        QByteArray searchStr("0201040306050807");
        int dataStartIndex = dataBuffer.indexOf(searchStr);

         if(dataStartIndex == -1)
             {
                magicOk = 0;
                qDebug() << "Pas de mot magique";
             }
         else
             {
                data = dataBuffer.mid(dataStartIndex,512);
//              qDebug() << "data : " << data;

                if(data.size() >= 512)
                {
//                  qDebug() << "Magic OK";
                    magicOk = 1;
                }
                else
                {
                    magicOk = 0;
                }

             }
            if(magicOk ==1)
            {
//////////////////////////RANGE PROFILE//////////////////////////////////

               QVector<double> RangeProfile (34);
               QVector<double> yRange (17);
               QVector<double> xRange (17);

              int indexRange = 368;
              for(unsigned int index = 0; index < 34; index++)
              {
                qint16 tempRange = parseRangeProfile(data,indexRange,4);
                RangeProfile[index] = tempRange;
//              qDebug() << RangeProfile[index];
                indexRange = indexRange + 4;
              }
              for(unsigned int index = 0; index < 17; index++ )
              {
                 yRange[index] = sqrt(RangeProfile[2*index]*RangeProfile[2*index]+ RangeProfile[2*index + 1]*RangeProfile[2*index + 1]);
                 xRange[index] = 0.3 + 0.0360*index;
//               qDebug() << "yRange" << yRange[index] << " xRange" << xRange[index];
              }
              emit RangePlot(xRange,yRange);
            }

//////////////////////////BREATHING WAVEFORM/////////////////////////////

            double breathWfm_Out = parseValueFloat(data,136, 8);
//            qDebug() << breathWfm_Out;
            emit breath(breathWfm_Out);


///////////////////////////HEART RATE WAVEFORM/////////////////////////////
            double heartRateWfm_Out = parseValueFloat(data,144,8);
//             qDebug() << heartRateWfm_Out;
            emit heart(heartRateWfm_Out);

//////////////////////////CHEST DISPLACEMENT//////////////////////////////
            double chestDisplacement = parseValueFloat(data,128,8);
//            qDebug() << chestDisplacement;
            emit chest(chestDisplacement);

}

void lecture::processData6843()
{
    dataStartIndex = 0;
//  qDebug() << dataBuffer;

    QByteArray searchStr("78563412");
    dataStartIndex = dataBuffer.indexOf(searchStr);
//  qDebug() << dataBuffer;

    if(dataStartIndex == -1)
        {
           magicOk = 0;
//         qDebug() << "Pas de mot magique";
        }
    else
        {
//        int lengthFrame = parseLengthFrame(dataBuffer,8,8);
//        qDebug() << "Length frame" << lengthFrame;
//        int pointsLeng = parseLengthFrame(dataBuffer,16,8);
//        qDebug() << "Points len : " << pointsLeng;
          int numObj = parseValueNumDetectedObj(dataBuffer,24,4);
//        qDebug() << "Nombre d'objet :" << numObj;

      parsePoint(dataBuffer,32,32*numObj,numObj);
      int indexLenghtRangeP = 32*(numObj+1);
//    int lenghtRangeP = parseLengthFrame(dataBuffer,indexLenghtRangeP,8);

//    qDebug() <<"Taille Range Profile" << lenghtRangeP;
      int indexRangeP = indexLenghtRangeP + 8;
      QVector<double> RangeProfile (256);
      QVector<double> yRange(256), xRange(256);
//    qDebug() << "Index range p" << indexRangeP;

        for(int index = 0; index < 256; index++)
        {
          double tempRange = parseRangeProfile(dataBuffer,indexRangeP,4);
          RangeProfile[index] = tempRange;
//        qDebug() << RangeProfile[index];
          indexRangeP = indexRangeP + 4;
        }

        distPeek = findMaximum(RangeProfile,2100);
//        qDebug() << "Distance " << distPeek;

        for(int index = 0; index < 256; index++ )
        {
           yRange[index] = RangeProfile[index];
           xRange[index] = index*0.043602;
//         qDebug() << "yRange" << yRange[index] << " xRange" << xRange[index];
        }

           emit RangePlot6843(xRange,yRange,distPeek);
           xRange.clear();
           yRange.clear();
           RangeProfile.clear();
    }
}

qint16 lecture::parseRangeProfile(QByteArray data, int valuePos, int valueSize)
{
    bool ok;
    QByteArray parseData;
    parseData = data.mid(valuePos, valueSize);
    QString strParseData = parseData;
//  qDebug() << strParseData << "Pars Data";
    qint16 parseValueOut = strParseData.toInt(&ok,16);
    parseValueOut =  qToBigEndian(parseValueOut);
//  qDebug() << parseValueOut << "ParseValueOut";

    return parseValueOut;
}

double lecture::parseValueFloat(QByteArray data, int valuePos, int valueSize)
{
    bool ok;
    QByteArray parseData;
    parseData = data.mid(valuePos,valueSize);
    QString strParseData = parseData;
    quint32 temp_int = strParseData.toUInt(&ok,16);
    temp_int =  qToBigEndian(temp_int);        // Convert to Big-Endian
    float parseValueOut;
    parseValueOut = *reinterpret_cast<float*>(&temp_int); // cast to Float
    return parseValueOut;
}

int lecture::parseLengthFrame(QByteArray data, int valuePos, int valueSize)
{
    bool ok;
    QByteArray parseData;
    parseData = data.mid(valuePos,valueSize);
    QString strParseData = parseData;
//    qDebug() << strParseData << "Pars Data";
    qint32 parseValueOut = strParseData.toInt(&ok,16);
    parseValueOut =  qToBigEndian(parseValueOut);
    return parseValueOut;
//    qDebug() << parseValueOut << "ParseValueOut";
}

int lecture::parseValueNumDetectedObj(QByteArray data, int valuePos, int valueSize)
{
    bool ok;
    QByteArray parseData;
    parseData = data.mid(valuePos,valueSize);
    QString strParseData = parseData;
//    qDebug() << strParseData << "Pars Data";
    qint16 parseValueOut = strParseData.toInt(&ok,16);
    parseValueOut =  qToBigEndian(parseValueOut);

    if(parseValueOut >1000)
    {
        parseValueOut = 0;
    }
    return parseValueOut;
//  qDebug() << parseValueOut << "ParseValueOut";
}

void lecture::parsePoint(QByteArray data, int valuePos, int valueSize, int nombreObj)
{
    bool ok;
    QByteArray parseData, parseX,parseY,parseZ,parseV;
    parseData = data.mid(valuePos,valueSize);

    for(int i=0; i<nombreObj;i++)
    {
//      qDebug() << "Point " << i+1;
        parseX = parseData.mid(0+(32*i),8);
//      qDebug() << parseX;
        QString strX = parseX;
        quint32 temp_intX = strX.toUInt(&ok,16);
        temp_intX =  qToBigEndian(temp_intX);
        float ValueX;
        ValueX = *reinterpret_cast<float*>(&temp_intX);
//      qDebug() << "x :" << ValueX;

        parseY = parseData.mid(8+(32*i),8);
//      qDebug() << parseY;
        QString strY = parseY;
        quint32 temp_intY = strY.toUInt(&ok,16);
        temp_intY =  qToBigEndian(temp_intY);
        float ValueY;
        ValueY = *reinterpret_cast<float*>(&temp_intY);
//      qDebug() << "y :" << ValueY;

        parseZ = parseData.mid(16+(32*i),8);
//      qDebug() << parseZ;
        QString strZ = parseZ;
        quint32 temp_intZ = strZ.toUInt(&ok,16);
        temp_intZ =  qToBigEndian(temp_intZ);
        float ValueZ;
        ValueZ = *reinterpret_cast<float*>(&temp_intZ);
//      qDebug() << "z :" << ValueZ;

        parseV = parseData.mid(24+(32*i),8);
//      qDebug() << parseV;
        QString strV = parseV;
        quint32 temp_intV = strV.toUInt(&ok,16);
        temp_intV =  qToBigEndian(temp_intV);
        float ValueV;
        ValueV = *reinterpret_cast<float*>(&temp_intV);
//      qDebug() << "v : " << ValueV;

        QVector<float> data3D;
        data3D = matriceRotation(ValueX,ValueY,ValueZ);
        data3D.append(ValueV);

//      data3D.append(ValueX);
//      data3D.append(ValueY);
//      data3D.append(ValueZ);
//      data3D.append(ValueV);

        qDebug() << "data3D : " << data3D;

    listData.append(data3D);
    data3D.clear();
  }

    emit dataXYZV(listData,nombreObj);
    listData.clear();
}

QVector<float> lecture::matriceRotation(float x, float y, float z)
{
    QVector<float> newPoint;
    float newX, newY, newZ;

    newX = (cosa*(pow(cosa,2)+(1-pow(cosa,2))*cosb)+(cosa*pow(sina,2)*(1-cosb)))*x + (-sina*(pow(cosa,2)+((1-pow(cosa,2))*cosb))+(pow(cosa,2)*sina*(1-cosb)))*y + (sina*sinb)*z;
    newY = ((pow(cosa,2)*sina*(1-cosb)+(sina*(pow(sina,2)+(1-pow(sina,2))*cosb)))*x + (-cosa*pow(sina,2)*(1-cosa)+(cosa*(pow(sina,2)+(1-pow(sina,2)*cosb))))*y + (-cosa*sinb)*z);
    newZ = ((pow(sina,2)*sinb)+(pow(cosa,2)*sinb))*y + cosb*z;

    newPoint.append(newX);
    newPoint.append(newY);
    newPoint.append(newZ);

    return newPoint;
}

double lecture::findMaximum(QVector<double> RangeProfile, double seuil)
{
    double maxRPActuel = *std::max_element(RangeProfile.begin(),RangeProfile.end());
    int maxRPActuelIndex = std::max_element(RangeProfile.begin(),RangeProfile.end()) - RangeProfile.begin();
//  qDebug() << "Max Range Profile actuel"  << maxRPActuel << "Index " << maxRPActuelIndex;
//  qDebug() << "Range profile :" << RangeProfile;

    if(maxRPActuel > seuil)
    {
//      qDebug() << "Distance de l'objet :" << maxRPActuelIndex*0.043602;
        return maxRPActuelIndex*0.043602;
    }else
    {
        return 0;
    }
}


