#include "ventanainformeslapsos.h"
#include "ui_ventanainformeslapsos.h"

ventanaInformesLapsos::ventanaInformesLapsos(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ventanaInformesLapsos)
{
    ui->setupUi(this);
}

ventanaInformesLapsos::~ventanaInformesLapsos()
{
    delete ui;
}
