#include "ventanafincas.h"
#include "ui_ventanafincas.h"

ventanafincas::ventanafincas(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ventanafincas)
{
    ui->setupUi(this);
    this->setWindowTitle("Fincas");
}

ventanafincas::~ventanafincas()
{
    delete ui;
}

void ventanafincas::mostrarDatosFincas(string nombreFinca){
    bool fincaEncontrada = false;
    string informacionFinca = "";
    string lineFinca = "";
    fstream ListadoFincas;
    ListadoFincas.open (TextoInformacionFincas,fstream::in);

    while(!ListadoFincas.eof()){
        getline(ListadoFincas,lineFinca);
        if(lineFinca == nombreFinca){
            fincaEncontrada = true;
            informacionFinca += "Nombre: "+ lineFinca + "\n";

            getline(ListadoFincas,lineFinca);
            informacionFinca += "Cajuelas Cosechadas: " + lineFinca + "\n";

            getline(ListadoFincas,lineFinca);
            informacionFinca += "Ganancias Recibidas: " + lineFinca + "\n";
        }
    }

    if(fincaEncontrada == true){
        QString informacionFincaQt = QString::fromStdString(informacionFinca);
        QMessageBox::information(this,"Información Finca", informacionFincaQt);
    }else{
        QMessageBox::warning(this,"Información Finca", "No hay registro de esta finca");
    }

}

void ventanafincas::on_verFincaAchiote_clicked()
{
    mostrarDatosFincas("FincaAchiote");
}

void ventanafincas::on_verFincaChuruca_clicked()
{
    mostrarDatosFincas("FincaChuruca");
}

void ventanafincas::on_verFincaArena_clicked()
{
    mostrarDatosFincas("FincaArena");
}
