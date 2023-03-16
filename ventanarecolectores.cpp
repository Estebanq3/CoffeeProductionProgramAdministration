#include "ventanarecolectores.h"
#include "ui_ventanarecolectores.h"

ventanarecolectores::ventanarecolectores(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ventanarecolectores)
{
    ui->setupUi(this);
    this->setWindowTitle("Recolectores");
}

ventanarecolectores::~ventanarecolectores()
{
    delete ui;
}

void ventanarecolectores::on_desplegarListaRecolectores_clicked()
{
    string nombres = "";
    string cadenaNombres = "";
    fstream ListadoNombres;
    ListadoNombres.open(TextoListadoRecolectores, fstream::in);
    while(!ListadoNombres.eof()){
        getline(ListadoNombres,nombres);
        cadenaNombres += nombres + "\n";
    }

    QString cadenaNombresQt = QString::fromStdString(cadenaNombres);
    ui->mostradorDatosRecolectores->setText(cadenaNombresQt);

}

void ventanarecolectores::on_buscarRecolector_clicked()
{
    string datos = "";
    string scanData = "";
    bool registroEncontrado = false;

    fstream RecolectorData;
    RecolectorData.open(TextoDeudasEconomicas, fstream::in);
    while(!RecolectorData.eof()){
        getline(RecolectorData,scanData);
        if(scanData == ui->lineRecolectorABuscar->text().toStdString()){
            registroEncontrado = true;
            datos += "Nombre: " + scanData;
            getline(RecolectorData,scanData);
            datos += "\nDeuda con la entidad: " + scanData;
            getline(RecolectorData,scanData);
            datos += "\nCajuelas totales que ha recolectado: " + scanData;
            getline(RecolectorData,scanData);
            datos += "\nHoras totales trabajadas: " + scanData;
        }
    }

    if(registroEncontrado == true){
        QString datosQt = QString::fromStdString(datos);
        //QMessageBox::information(this,"Registro de recolector",datosQt);
        ui->mostradorDatosRecolectores->setText(datosQt);
    }else{
        QMessageBox::warning(this,"Registro de recolector", "Datos no encontrados");
    }


}
