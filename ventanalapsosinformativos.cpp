#include "ventanalapsosinformativos.h"
#include "ui_ventanalapsosinformativos.h"

ventanalapsosinformativos::ventanalapsosinformativos(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ventanalapsosinformativos)
{
    ui->setupUi(this);
    this->setWindowTitle("Lapsos Informativos");
}

ventanalapsosinformativos::~ventanalapsosinformativos()
{
    delete ui;
}


void ventanalapsosinformativos::calculoLapsoInformativo(bool is_year){
    //Abriendo informe económico
        ifstream archivoEconomico;
        string lineEconomica;
        archivoEconomico.open(TextoInformeEconomico,ifstream::in);

        //variables locales para calcular los informes anuales o mensuales
        double cajuelas = 0;
        double gastos = 0;
        double ganancias = 0;
        int contador = 0;
        string yearRead = "";
        string monthRead = "";

        while(!archivoEconomico.eof()){
           getline(archivoEconomico,lineEconomica);
           if(lineEconomica.length() >= 9){
               string year = lineEconomica.substr(6,9);
               string month = lineEconomica.substr(3);
               yearRead = ui->fechaLapsoInformativo->text().toStdString();
               yearRead = yearRead.substr(6,9);
               monthRead = ui->fechaLapsoInformativo->text().toStdString();
               monthRead = monthRead.substr(3);


               if(is_year == 1){
                   if(year == yearRead){
                       while(lineEconomica !=  "--FinInformeEconomico--") {
                           getline(archivoEconomico,lineEconomica);
                           if(contador == 0){
                              cajuelas+= atof(lineEconomica.c_str());
                           }else{
                               if(contador == 1){
                                   gastos+= atof(lineEconomica.c_str());
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
               }else{
                   if(year == yearRead && month == monthRead){
                       while(lineEconomica !=  "--FinInformeEconomico--") {
                           getline(archivoEconomico,lineEconomica);
                           if(contador == 0){
                              cajuelas+= atof(lineEconomica.c_str());
                           }else{
                               if(contador == 1){
                                   gastos+= atof(lineEconomica.c_str());
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
           }
        }

    if(cajuelas!= 0){
        string informeAnual = "Año: " + yearRead + "\nMes: " + monthRead + "\nCajuelas: " + to_string(cajuelas) + "\nGastos: " + to_string(gastos) +
        "\nGanancias: " + to_string(ganancias) + "\nGananciaNeta: " + to_string(ganancias-gastos);
        QString informeAnualQt = QString::fromStdString(informeAnual);
        QMessageBox::information(this, "InformacionAnual",informeAnualQt);
    }else{
        QMessageBox::warning(this, "InformacionAnual","No existe registro");
    }
}




void ventanalapsosinformativos::on_anual_2_clicked()
{
    calculoLapsoInformativo(1);
}

void ventanalapsosinformativos::on_mensual_2_clicked()
{
    calculoLapsoInformativo(0);
}
