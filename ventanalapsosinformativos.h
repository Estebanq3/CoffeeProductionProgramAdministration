#ifndef VENTANALAPSOSINFORMATIVOS_H
#define VENTANALAPSOSINFORMATIVOS_H

#include <QDialog>
#include "mainwindow.h"

namespace Ui {
class ventanalapsosinformativos;
}

class ventanalapsosinformativos : public QDialog
{
    Q_OBJECT

public:
    explicit ventanalapsosinformativos(QWidget *parent = nullptr);
    ~ventanalapsosinformativos();

private slots:
    void on_anual_2_clicked();

    void on_mensual_2_clicked();

private:
    Ui::ventanalapsosinformativos *ui;
    void calculoLapsoInformativo(bool is_year);

};

#endif // VENTANALAPSOSINFORMATIVOS_H
