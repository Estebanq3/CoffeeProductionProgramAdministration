#ifndef VENTANAMAPEOFINCAS_H
#define VENTANAMAPEOFINCAS_H

#include <QDialog>
#include "mainwindow.h"

namespace Ui {
class ventanamapeoFincas;
}

class ventanamapeoFincas : public QDialog
{
    Q_OBJECT

public:
    explicit ventanamapeoFincas(QWidget *parent = nullptr);
    ~ventanamapeoFincas();

private:
    Ui::ventanamapeoFincas *ui;
};

#endif // VENTANAMAPEOFINCAS_H
