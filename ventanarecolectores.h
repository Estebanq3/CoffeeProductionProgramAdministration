#ifndef VENTANARECOLECTORES_H
#define VENTANARECOLECTORES_H

#include <QDialog>
#include "mainwindow.h"

namespace Ui {
class ventanarecolectores;
}

class ventanarecolectores : public QDialog
{
    Q_OBJECT

public:
    explicit ventanarecolectores(QWidget *parent = nullptr);
    ~ventanarecolectores();

private slots:
    void on_desplegarListaRecolectores_clicked();

    void on_buscarRecolector_clicked();

private:
    Ui::ventanarecolectores *ui;
};

#endif // VENTANARECOLECTORES_H
