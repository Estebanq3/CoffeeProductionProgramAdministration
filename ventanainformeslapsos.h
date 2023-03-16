#ifndef VENTANAINFORMESLAPSOS_H
#define VENTANAINFORMESLAPSOS_H

#include <QDialog>
#include "mainwindow.h"

namespace Ui {
class ventanaInformesLapsos;
}

class ventanaInformesLapsos : public QDialog
{
    Q_OBJECT

public:
    explicit ventanaInformesLapsos(QWidget *parent = nullptr);
    ~ventanaInformesLapsos();

private:
    Ui::ventanaInformesLapsos *ui;
};

#endif // VENTANAINFORMESLAPSOS_H
