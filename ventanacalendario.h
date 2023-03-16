#ifndef VENTANACALENDARIO_H
#define VENTANACALENDARIO_H

#include <QDialog>
#include "mainwindow.h"

namespace Ui {
class ventanacalendario;
}

class ventanacalendario : public QDialog
{
    Q_OBJECT

public:
    explicit ventanacalendario(QWidget *parent = nullptr);
    ~ventanacalendario();

private slots:
    void on_informeDelDia_clicked();

private:
    Ui::ventanacalendario *ui;
};

#endif // VENTANACALENDARIO_H
