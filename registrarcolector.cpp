#include "registrarcolector.h"
#include "ui_registrarcolector.h"

registrarcolector::registrarcolector(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::registrarcolector)
{
    ui->setupUi(this);
    this->setWindowTitle("Registro");
}

registrarcolector::~registrarcolector()
{
    delete ui;
}

void registrarcolector::on_calcularPago_clicked()
{
        if(ui->lineCajuela->text() != "" && ui->linePrecioCajuela->text() != "" && ui->lineName->text()!= "" && ui->lineFinca->currentText() != "" && ui->linePagoRecibidor->text() != ""){
            double pago = ui->lineCajuela->text().toDouble() * ui->linePrecioCajuela->text().toDouble();
            string informe = "El pago del recolector de nombre " +ui->lineName->text().toStdString()+ " es de ₡" + to_string(pago)
            + ".Café recolectado en la finca: " + ui->lineFinca->currentText().toStdString();
            QString informeQt = QString::fromStdString(informe);
            QMessageBox::information(this,"Registrar/Calcular Datos Recolector",informeQt);
        }else{
            QMessageBox::warning(this,"Error", "Espacio sin rellenar");
        }
}

/*

*/


void registrarcolector::on_guardarInfo_clicked()
{
    if(ui->lineCajuela->text() != "" && ui->linePrecioCajuela->text() != "" && ui->lineName->text()!= "" && ui->lineFinca->currentText() != "" && ui->lineHoras->text() != "" && ui->linePagoRecibidor->text() != ""){
        QMessageBox::information(this, "Informe Guardado", "Informacion del recolector se ha guardado");
        fstream Registro;
        Registro.open (TextoRegistro, fstream::in | fstream::out | fstream::app);
        Registro << endl << ui->fechaInforme->text().toStdString()
        << "\nNombre: " << ui->lineName->text().toStdString()
        << "\nCajuelas Recolectadas: " << ui->lineCajuela->text().toDouble()
        << "\nHorasTrabajadas: " << ui->lineHoras->text().toStdString()
        << "\nPago: ₡" << ui->lineCajuela->text().toDouble() * ui->linePrecioCajuela->text().toDouble()
        << "\nFinca: " << ui->lineFinca->currentText().toStdString()
        << "\n--Fin Registro Trabajador--" << endl;
        Registro.close();

        //Archivo que lleva los registros económicos del pago que se le debe realizar a los recolectores cada día, y el pago
        //que se recibirá del recibidor de café
        fstream InformeEconomico;
        InformeEconomico.open (TextoInformeEconomico, fstream::in | fstream::out | fstream::app);
        InformeEconomico << endl << ui->fechaInforme->text().toStdString()
        << "\n" << ui->lineCajuela->text().toDouble()
        << "\n" << ui->lineCajuela->text().toDouble() * ui->linePrecioCajuela->text().toDouble()
        << "\n" << ui->lineCajuela->text().toDouble() * ui->linePagoRecibidor->text().toDouble()
        << "\n--FinInformeEconomico--" << endl;

       //----------------------------------------------------------------------------------------------------------------------------------------------------
       //Listado de nombres
        bool nombreListado = false;
        string lineListado = "";
        fstream ListadoRecolectores;
        fstream ListadoRecolectoresWrite;
        ListadoRecolectores.open (TextoListadoRecolectores,fstream::in);

        while(!ListadoRecolectores.eof()){
            getline(ListadoRecolectores,lineListado);
            if(lineListado == ui->lineName->text().toStdString()){
                nombreListado = true;
                ListadoRecolectores.close();
            }
        }
        if(nombreListado == false){
            ListadoRecolectoresWrite.open (TextoListadoRecolectores,fstream::in | fstream::out | fstream::app);
            ListadoRecolectoresWrite << ui->lineName->text().toStdString() << endl;
            ListadoRecolectoresWrite.close();
        }
        //----------------------------------------------------------------------------------------------------------------------------------------------------
        //Fincas Info
        bool nombreFinca = false;
        double newCajuelasFinca = 0;
        double newGanancias = 0;

        string lineFinca = "";
        fstream ListadoFincas;
        fstream ListadoFincasRespaldo;
        ListadoFincas.open (TextoInformacionFincas,fstream::in);
        //Limpiando fincas respaldo
        ListadoFincasRespaldo.open(TextoInformacionFincasRespaldo, std::ofstream::out | std::ofstream::trunc);
        ListadoFincasRespaldo.close();

        ListadoFincasRespaldo.open(TextoInformacionFincasRespaldo);
        while(!ListadoFincas.eof()){
            getline(ListadoFincas,lineFinca);
            if(lineFinca == ui->lineFinca->currentText().toStdString()){
                nombreFinca = true;
                getline(ListadoFincas,lineFinca);
                newCajuelasFinca = atof(lineFinca.c_str());
                newCajuelasFinca += ui->lineCajuela->text().toDouble();

                getline(ListadoFincas,lineFinca);
                newGanancias = atof(lineFinca.c_str());
                newGanancias += ui->lineCajuela->text().toDouble()* ui->linePagoRecibidor->text().toDouble();
                getline(ListadoFincas,lineFinca);
                getline(ListadoFincas,lineFinca);
            }
            ListadoFincasRespaldo << lineFinca << endl;


        }

        //Copiando el archivo copia a la original para que queden actualizados los datos y borrar los viejos
        if(nombreFinca == true){
            //Actualizando el único dato que había que cambiar
            ListadoFincasRespaldo<< ui->lineFinca->currentText().toStdString() << "\n" << to_string(newCajuelasFinca)
            << "\n" << to_string(newGanancias)
            << "\n--FinFinca--" << endl;
            ListadoFincasRespaldo.close();

            FILE *file1 , *file2;
            int data1 =0;
            file1 = fopen (TextoInformacionFincasRespaldo, "r" );
            file2 = fopen (TextoInformacionFincas, "w" );

            while ( (data1 = fgetc ( file1 )) != EOF ) {
               fputc ( data1, file2 );
            }

            fclose ( file1 );
            fclose ( file2 );
        }else{
            fstream InformacionFincas2;
            InformacionFincas2.open(TextoInformacionFincas,fstream::in | fstream::out | fstream::app);
            InformacionFincas2 << ui->lineFinca->currentText().toStdString() << "\n" << ui->lineCajuela->text().toStdString()
            << "\n" << ui->lineCajuela->text().toDouble()* ui->linePagoRecibidor->text().toDouble()
            << "\n--FinFinca--" << endl;
        }


        //----------------------------------------------------------------------------------------------------------------------------------------------------
        //DEUDAS
        //Guardar en txt las deudas que se tienen con los recolectores de café
        fstream DeudasEconomicas;
        bool nombreEncontrado = false;
        double newDeuda = 0;
        double newCajuelas = 0;
        double newHorasTrabajadas = 0;
        string lineDeuda = "";
        DeudasEconomicas.open(TextoDeudasEconomicas,fstream::in);
        //------------------------------------
        fstream DeudasEconomicasRespaldo;
        //Limpiando archivo de respaldo para no migrar basura
        DeudasEconomicasRespaldo.open(TextoDeudasEconomicasRespaldo, std::ofstream::out | std::ofstream::trunc);
        DeudasEconomicasRespaldo.close();

        //Abriendo archivo de respaldo ya limpio para comenzar a hacer la copia de Deudas Económicas
        DeudasEconomicasRespaldo.open(TextoDeudasEconomicasRespaldo);

        //Buscando si existe ya el recolector de café para actualizar sus datos luego de los nuevos datos ingresados
        while(!DeudasEconomicas.eof()){
            getline(DeudasEconomicas,lineDeuda);
            if(lineDeuda == ui->lineName->text().toStdString()){
                //Pago
                getline(DeudasEconomicas,lineDeuda);
                newDeuda = atof(lineDeuda.c_str());
                newDeuda += ui->lineCajuela->text().toDouble() * ui->linePrecioCajuela->text().toDouble();
                //Cajuelas
                getline(DeudasEconomicas,lineDeuda);
                newCajuelas = atof(lineDeuda.c_str());
                newCajuelas += ui->lineCajuela->text().toDouble();
                //HorasTrabajadas
                getline(DeudasEconomicas,lineDeuda);
                newHorasTrabajadas = atof(lineDeuda.c_str());
                newHorasTrabajadas += ui->lineHoras->text().toDouble();


                nombreEncontrado = true;
                getline(DeudasEconomicas,lineDeuda);
                getline(DeudasEconomicas,lineDeuda);
            }
            DeudasEconomicasRespaldo << lineDeuda << endl;


        }
        //Copiando el archivo copia a la original para que queden actualizados los datos y borrar los viejos
        if(nombreEncontrado == true){
            //Actualizando el único dato que había que cambiar
            DeudasEconomicasRespaldo << "\n" << ui->lineName->text().toStdString() << "\n" << to_string(newDeuda)
            << "\n" << to_string(newCajuelas) << "\n" << to_string(newHorasTrabajadas)
            << "\n--FinDeuda--" << endl;
            DeudasEconomicasRespaldo.close();

            FILE *file1 , *file2;
            int data1 =0;
            file1 = fopen (TextoDeudasEconomicasRespaldo, "r" );
            file2 = fopen (TextoDeudasEconomicas, "w" );

            while ( (data1 = fgetc ( file1 )) != EOF ) {
               fputc ( data1, file2 );
            }

            fclose ( file1 );
            fclose ( file2 );
        }

        //Si no existe un recolector de café con los datos nuevos introducidos entonces se crea un nuevo individuo.
        if(nombreEncontrado == false){
            fstream DeudasEconomicas2;
            DeudasEconomicas2.open(TextoDeudasEconomicas,fstream::in | fstream::out | fstream::app);
            DeudasEconomicas2 << "\n" << ui->lineName->text().toStdString() << "\n" << ui->lineCajuela->text().toDouble() * ui->linePrecioCajuela->text().toDouble()
            << "\n" << ui->lineCajuela->text().toStdString() << "\n" << ui->lineHoras->text().toStdString()
            << "\n--FinDeuda--" << endl;
        }
    }else{
        QMessageBox::warning(this, "Error", "Espacios sin rellenar");
    }
}
