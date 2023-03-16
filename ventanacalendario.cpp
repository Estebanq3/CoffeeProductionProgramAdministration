#include "ventanacalendario.h"
#include "ui_ventanacalendario.h"

ventanacalendario::ventanacalendario(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ventanacalendario)
{
    ui->setupUi(this);
    this->setWindowTitle("Calendario Informes");
}

ventanacalendario::~ventanacalendario()
{
    delete ui;
}

void ventanacalendario::on_informeDelDia_clicked()
{
    //Abriendo Registro
        ifstream archivo;
        string line;
        string informeBuscado;
        archivo.open(TextoRegistro,ifstream::in);

    //Abriendo informe económico
        ifstream archivoEconomico;
        string lineEconomica;
        string informeEconomicoBuscado;
        archivoEconomico.open(TextoInformeEconomico,ifstream::in);

        //Se despliega si el usuario marca la opción informar sobre los trabajdores
        if(ui->opcionInforme->currentText().toStdString() == "InformeTrabajadores"){
            while(!archivo.eof()){
                getline(archivo,line);
                if(line == ui->calendario->selectedDate().toString("dd/MM/yyyy").toStdString()){
                     while(line !=  "--Fin Registro Trabajador--"){
                         getline(archivo,line);
                         informeBuscado += line + "\n";
                     }
                }
            }

            if(informeBuscado != ""){
                informeBuscado +=  "\nFecha: " + ui->calendario->selectedDate().toString("dd/MM/yyyy").toStdString();
                QString informeBuscadoQt = QString::fromStdString(informeBuscado);
                ui->cuadroInformativo->setText(informeBuscadoQt);
                //QMessageBox::information(this,"InformeRecordatorio",informeBuscadoQt);
            }else{
                QMessageBox::warning(this,"InformeRecordatorio","No existe registro");
            }
        }else{

                double cajuelas = 0;
                double gastos = 0;
                double ganancias = 0;
                while(!archivoEconomico.eof()){
                    getline(archivoEconomico,lineEconomica);
                    if(lineEconomica == ui->calendario->selectedDate().toString("dd/MM/yyyy").toStdString()){
                        int contador = 0;
                        while(lineEconomica !=  "--FinInformeEconomico--"){
                             getline(archivoEconomico,lineEconomica);
                             if(contador == 0){
                                cajuelas+= atof(lineEconomica.c_str());
                             }else{
                                if(contador == 1){
                                    gastos += atof(lineEconomica.c_str());
                                }else{
                                   if(contador == 2){
                                        ganancias += atof(lineEconomica.c_str());
                                   }
                                }
                             }
                             contador++;
                         }
                        contador = 0;
                    }
                }

            if(ui->opcionInforme->currentText().toStdString() == "InformeCajuelas"){
                if(cajuelas != 0){
                    string informeCajuelas = "Cajuelas Recolectadas el " + ui->calendario->selectedDate().toString("dd/MM/yyyy").toStdString()+ " " + to_string(cajuelas);
                    QString informeCajuelasQt = QString::fromStdString(informeCajuelas);
                    QMessageBox::information(this,"InformeCajuelas",informeCajuelasQt);
                }else{
                    QMessageBox::warning(this,"InformeCajuelas","No existe registro");
                }
            }else{
                if(ui->opcionInforme->currentText().toStdString() == "InformeGastos"){
                    if(gastos != 0){
                        string informeGastos = "Gastos del " + ui->calendario->selectedDate().toString("dd/MM/yyyy").toStdString()+ " ₡" + to_string(gastos);
                        QString informeGastosQt = QString::fromStdString(informeGastos);
                        QMessageBox::information(this,"InformeCajuelas",informeGastosQt);
                    }else{
                        QMessageBox::warning(this,"InformeGastos","No existe registro");
                    }
                }else{
                    if(ui->opcionInforme->currentText().toStdString() == "InformeGanancias"){
                         if(ganancias != 0){
                            string informeGanancias = "Ganancias del " + ui->calendario->selectedDate().toString("dd/MM/yyyy").toStdString()+ " ₡" + to_string(ganancias) + ". Dando una ganancia neta de: ₡" + to_string(ganancias-gastos);
                            QString informeGananciasQT = QString::fromStdString(informeGanancias);
                            QMessageBox::information(this,"InformeCajuelas",informeGananciasQT);
                         }else{
                             QMessageBox::warning(this,"InformeGanancias","No existe registro");
                         }
                    }
                }
            }
        }



}
