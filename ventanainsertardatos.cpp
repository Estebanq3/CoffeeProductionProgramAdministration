#include "VentanaInsertarDatos.h"


VentanaInsertarDatos::VentanaInsertarDatos(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::VentanaInsertarDatos)
{
    ui->setupUi(this);
    this->setWindowTitle("Insertar Registro Laboral");
}

VentanaInsertarDatos::~VentanaInsertarDatos()
{
    delete ui;
}

void VentanaInsertarDatos::on_calcularPagoVentana2_clicked()
{
    double pago = ui->lineCajuela->text().toDouble() * ui->linePrecioCajuela->text().toDouble();
    string informe = "El pago del recolector de nombre "+ui->lineName->text().toStdString()+
    " es de ₡" + to_string(pago) + ".Café recolectado en la finca: " + ui->lineFinca->currentText().toStdString();
    QString informeQt = QString::fromStdString(informe);
    cout << "Hola probando" << endl;
    QMessageBox::information(this,"Pago del recolector",informeQt);

}

void VentanaInsertarDatos::on_pushBotton_clicked()
{

}
