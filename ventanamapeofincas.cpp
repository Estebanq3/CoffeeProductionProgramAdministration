#include "ventanamapeofincas.h"
#include "ui_ventanamapeofincas.h"

ventanamapeoFincas::ventanamapeoFincas(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ventanamapeoFincas)
{
    ui->setupUi(this);
}

ventanamapeoFincas::~ventanamapeoFincas()
{
    delete ui;
}
