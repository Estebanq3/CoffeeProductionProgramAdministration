#include "ventanadeudas.h"
#include "ui_ventanadeudas.h"

ventanadeudas::ventanadeudas(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ventanadeudas)
{
    ui->setupUi(this);
    this->setWindowTitle("Deudas");
}

ventanadeudas::~ventanadeudas()
{
    delete ui;
}

void ventanadeudas::on_botonAccionDeuda_clicked()
{
    ifstream archivoDeudas;
    string lineDeudas;
    string informeDeudas = "";
    double deuda = 0;
    bool encontradoDeuda = false;
    archivoDeudas.open(TextoDeudasEconomicas,ifstream::in);


    if(ui->opcionDeuda->currentText().toStdString() == "BuscarDeuda"){
        while(!archivoDeudas.eof()){
            getline(archivoDeudas,lineDeudas);
            if(ui->lineDeuda->text().toStdString() == lineDeudas){
                encontradoDeuda = true;
                getline(archivoDeudas,lineDeudas);
                deuda += atof(lineDeudas.c_str());
            }
        }
        //Para que no reporte una deuda de 0 de algun nombre
        if(ui->lineDeuda->text().toStdString() == ""){
            encontradoDeuda = false;
        }
        if(encontradoDeuda == true){
            informeDeudas = "Se le debe un pago de: " + to_string(deuda) + " a la entidad " + ui->lineDeuda->text().toStdString();
            QString informeDeudasQt = QString::fromStdString(informeDeudas);
            QMessageBox::information(this,"Informacion Deudas", informeDeudasQt);
        }else{
            QMessageBox::warning(this,"Error", "No se ha encontrado deuda con esta entidad.\nVerifique que el nombre esté exactamente igual a como lo registró.");
        }


    }
}
