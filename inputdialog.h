#ifndef INPUTDIALOG_H
#define INPUTDIALOG_H

#include <QDialog>
#include <QDebug>
#include <QDoubleSpinBox>
#include "inifile.h"

class QLineEdit;
class QLabel;
class QSpinBox;

class InputDialog : public QDialog
{
    Q_OBJECT
public:
    explicit InputDialog(QWidget *parent = nullptr);

    static QList<int> getInt(QWidget *parent, bool *ok = nullptr);
    void getAxis(int minAz, int maxAz, int minNo, int maxNo, int minEl, int maxEl);

private:
    QList<QSpinBox*> fields;
    QSpinBox *tSpin;
    iniFile *file;

    int _maxAz;
    int _minAz;
    int _maxNo;
    int _minNo;
    int _maxEl;
    int _minEl;


};

#endif // INPUTDIALOG_H
