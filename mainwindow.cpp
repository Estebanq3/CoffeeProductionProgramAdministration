#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setWindowTitle("Coffe App");
    setWindowIcon(QIcon(":/new/prefix1/coffeCup.jpg"));
}

MainWindow::~MainWindow()
{
    delete ui;
}

//Funciones para cálculos de Coffe App




//-----------------------------------------------------------------------------------------------
//Función para eliminar datos registrados que se digitaron equivocadamente
//Pestaña configuraciones
//**Cambie idioma o fuente y tamaño de letra
//Función que limpie archivos
//Lista de trabajadores, como perfiles en ventanas flotantes


//Funciones desplegar ventanas secundarias
void MainWindow::on_desplegar2Ventana_clicked()
{
    registrarcolector = new class registrarcolector(this);
    registrarcolector->show();

}

//-----------------------------------------------------------------------------------------------

void MainWindow::on_desplegarVentanaCalendario_clicked()
{
    ventanacalendario = new class ventanacalendario(this);
    ventanacalendario->show();
}




void MainWindow::on_desplegarLapsosInformativos_clicked()
{
    ventanalapsosinformativos = new class ventanalapsosinformativos(this);
    ventanalapsosinformativos->show();
}

void MainWindow::on_desplegarVentanaInformes_2_clicked()
{
    ventanadeudas = new class ventanadeudas(this);
    ventanadeudas->show();
}

void MainWindow::on_borrarRegistros_clicked()
{
    QMessageBox::information(this,"Información","Se han borrado todos los registros");
    fstream Registro;
    Registro.open(TextoRegistro, std::ofstream::out | std::ofstream::trunc);
    Registro.close();
    Registro.open(TextoInformeEconomico, std::ofstream::out | std::ofstream::trunc);
    Registro.close();
    Registro.open(TextoDeudasEconomicas, std::ofstream::out | std::ofstream::trunc);
    Registro.close();
    Registro.open(TextoDeudasEconomicasRespaldo, std::ofstream::out | std::ofstream::trunc);
    Registro.close();
    Registro.open(TextoListadoRecolectores, std::ofstream::out | std::ofstream::trunc);
    Registro.close();
    Registro.open(TextoInformacionFincas, std::ofstream::out | std::ofstream::trunc);
    Registro.close();


}

void MainWindow::on_mostrarRecolectores_clicked()
{
    ventanarecolectores = new class ventanarecolectores(this);
    ventanarecolectores->show();
}

void MainWindow::on_mostrarFincas_clicked()
{
    ventanafincas = new class ventanafincas(this);
    ventanafincas->show();
}
