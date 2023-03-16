#ifndef VENTANADEUDAS_H
#define VENTANADEUDAS_H

#include <QDialog>
#include "mainwindow.h"

namespace Ui {
class ventanadeudas;
}

class ventanadeudas : public QDialog
{
    Q_OBJECT

public:
    explicit ventanadeudas(QWidget *parent = nullptr);
    ~ventanadeudas();

private slots:
    void on_botonAccionDeuda_clicked();

private:
    Ui::ventanadeudas *ui;
};

#endif // VENTANADEUDAS_H
