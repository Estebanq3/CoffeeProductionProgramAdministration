#ifndef REGISTRARCOLECTOR_H
#define REGISTRARCOLECTOR_H

#include <QDialog>
#include "mainwindow.h"

namespace Ui {
class registrarcolector;
}

class registrarcolector : public QDialog
{
    Q_OBJECT

public:
    explicit registrarcolector(QWidget *parent = nullptr);
    ~registrarcolector();

private slots:
    void on_calcularPago_clicked();


    void on_guardarInfo_clicked();

private:
    Ui::registrarcolector *ui;
};

#endif // REGISTRARCOLECTOR_H
