#ifndef VENTANAINSERTARDATOS_H
#define VENTANAINSERTARDATOS_H

#include <QDialog>
#include "mainwindow.h"
#include "ui_ventanainsertardatos.h"

namespace Ui {
class VentanaInsertarDatos;
}

class VentanaInsertarDatos : public QDialog
{
    Q_OBJECT

public:
    explicit VentanaInsertarDatos(QWidget *parent = nullptr);
    ~VentanaInsertarDatos();

private slots:
    void on_pushButton_clicked();

private:
    Ui::VentanaInsertarDatos *ui;

    void on_calcularPagoVentana2_clicked();
    void on_pushBotton_clicked();
};

#endif // VENTANAINSERTARDATOS_H
