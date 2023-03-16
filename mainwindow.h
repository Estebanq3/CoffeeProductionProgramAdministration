#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMessageBox>
#include <QDate>

//incluyendo ventanas adicionales
#include "registrarcolector.h"
#include "ventanacalendario.h"
#include "ventanalapsosinformativos.h"
#include "ventanadeudas.h"
#include "ventanarecolectores.h"
#include "ventanafincas.h"


//Librerías de c++
#include "string.h"
#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <vector>
#include <math.h>
#include <iomanip>

using namespace std;

#define TextoDeudasEconomicas  "C:/Users/Esteban Quesada/Desktop/C++/CoffeAppInterfazOrdenada/DeudasEconomicas.txt"
#define TextoDeudasEconomicasRespaldo  "C:/Users/Esteban Quesada/Desktop/C++/CoffeAppInterfazOrdenada/DeudasEconomicasRespaldo.txt"
#define TextoInformacionFincas  "C:/Users/Esteban Quesada/Desktop/C++/CoffeAppInterfazOrdenada/InformacionFincas.txt"
#define TextoInformacionFincasRespaldo  "C:/Users/Esteban Quesada/Desktop/C++/CoffeAppInterfazOrdenada/InformacionFincasRespaldo.txt"
#define TextoInformeEconomico  "C:/Users/Esteban Quesada/Desktop/C++/CoffeAppInterfazOrdenada/InformeEconomico.txt"
#define TextoListadoRecolectores  "C:/Users/Esteban Quesada/Desktop/C++/CoffeAppInterfazOrdenada/ListadoRecolectores.txt"
#define TextoRegistro  "C:/Users/Esteban Quesada/Desktop/C++/CoffeAppInterfazOrdenada/Registro.txt"




QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();



private slots:

    void on_desplegar2Ventana_clicked();

    void on_desplegarVentanaCalendario_clicked();

    void on_desplegarLapsosInformativos_clicked();

    void on_desplegarVentanaInformes_2_clicked();

    void on_borrarRegistros_clicked();

    void on_mostrarRecolectores_clicked();

    void on_mostrarFincas_clicked();

private:
    Ui::MainWindow *ui;
    class registrarcolector* registrarcolector;
    class ventanacalendario* ventanacalendario;
    class ventanalapsosinformativos* ventanalapsosinformativos;
    class ventanadeudas* ventanadeudas;
    class ventanarecolectores * ventanarecolectores;
    class ventanafincas* ventanafincas;
};
#endif // MAINWINDOW_H
