#ifndef VENTANAFINCAS_H
#define VENTANAFINCAS_H

#include <QDialog>
#include "mainwindow.h"
#include <string>

namespace Ui {
class ventanafincas;
}

class ventanafincas : public QDialog
{
    Q_OBJECT

public:
    explicit ventanafincas(QWidget *parent = nullptr);
    ~ventanafincas();

private slots:
    void on_verFincaAchiote_clicked();

    void on_verFincaChuruca_clicked();

    void mostrarDatosFincas(std::string nombreFinca);

    void on_verFincaArena_clicked();

private:
    Ui::ventanafincas *ui;

};

#endif // VENTANAFINCAS_H
