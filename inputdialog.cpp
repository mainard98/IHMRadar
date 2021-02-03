#include "inputdialog.h"

#include <QLabel>
#include <QLineEdit>
#include <QDialogButtonBox>
#include <QFormLayout>

InputDialog::InputDialog(QWidget *parent) : QDialog(parent)
{
    QFormLayout *lytMain = new QFormLayout(this);
    bool flag = 0;
    int title = 1;
    setWindowTitle("Zone d'observation");

    file = new iniFile;
    file->lireAxe(&_minAz,&_maxAz,&_minNo,&_maxNo,&_minEl,&_maxEl);


    for(int j = 0; j < 3 ; j++)
    {
        QLabel *tLabel = new QLabel(this);

        switch(title)
        {
            case 1: tLabel->setText("Azimuth");
                    lytMain->addRow(tLabel);
                    for (int i = 0; i < 2; ++i)
                    {
                        tSpin = new QSpinBox(this);

                        QLabel *tMax = new QLabel("Max");
                        QLabel *tMin = new QLabel("Min");
                        tSpin->setRange(-10,10);

                        if(flag==0)
                        {
                            lytMain->addRow(tMax,tSpin);
                            tSpin->setValue(_maxAz);
                            flag = 1;
                        }
                        else
                        {
                            lytMain->addRow(tMin,tSpin);
                            tSpin->setValue(_minAz);
                            flag = 0;
                        }

                        fields << tSpin;
                    }
                    title = 2;
                    break;

            case 2: tLabel->setText("Normale");
                    lytMain->addRow(tLabel);
                    for (int i = 0; i < 2; ++i)
                    {
                        tSpin = new QSpinBox(this);

                        QLabel *tMax = new QLabel("Max");
                        QLabel *tMin = new QLabel("Min");
                        tSpin->setRange(-10,10);

                        if(flag==0)
                        {
                            lytMain->addRow(tMax,tSpin);
                            tSpin->setValue(_maxNo);

                            flag = 1;
                        }
                        else
                        {
                            lytMain->addRow(tMin,tSpin);
                            tSpin->setValue(_minNo);

                            flag = 0;
                        }

                        fields << tSpin;
                    }
                    title = 3;
                    break;

            case 3: tLabel->setText("Elevation");
                    lytMain->addRow(tLabel);
                    for (int i = 0; i < 2; ++i)
                    {
                        tSpin = new QSpinBox(this);

                        QLabel *tMax = new QLabel("Max");
                        QLabel *tMin = new QLabel("Min");
                        tSpin->setRange(-10,10);

                        if(flag==0)
                        {
                            lytMain->addRow(tMax,tSpin);
                            tSpin->setValue(_maxEl);

                            flag = 1;
                        }
                        else
                        {
                            lytMain->addRow(tMin,tSpin);
                            tSpin->setValue(_minEl);

                            flag = 0;
                        }

                        fields << tSpin;
                    }
                    break;
        }

    }

    QDialogButtonBox *buttonBox = new QDialogButtonBox
            ( QDialogButtonBox::Ok,
              Qt::Horizontal, this );
    lytMain->addWidget(buttonBox);

    bool conn = connect(buttonBox, &QDialogButtonBox::accepted,
                   this, &InputDialog::accept);
    Q_ASSERT(conn);

    setLayout(lytMain);
}

QList<int> InputDialog::getInt(QWidget *parent, bool *ok)
{
    InputDialog *dialog = new InputDialog(parent);

    QList<int> list;

    const int ret = dialog->exec();
    if (ok)
        *ok = !!ret;

    if (ret) {
        foreach (auto field, dialog->fields) {
            list << field->value();
        }
    }

    dialog->deleteLater();
    return list;
}

void InputDialog::getAxis(int maxAz, int minAz, int maxNo, int minNo, int maxEl, int minEl)
{
    _maxAz = maxAz;
    _minAz = minAz;
    _maxNo = maxNo;
    _minNo = minNo;
    _maxEl = maxEl;
    _minEl = minEl;

    qDebug() << _maxAz << _minAz << _maxNo << _minNo << _maxEl << _minEl;
}
