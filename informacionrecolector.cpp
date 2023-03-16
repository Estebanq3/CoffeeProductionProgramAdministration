#include "informacionrecolector.h"
#include "ui_informacionrecolector.h"

InformacionRecolector::InformacionRecolector(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::InformacionRecolector)
{
    ui->setupUi(this);
}

InformacionRecolector::~InformacionRecolector()
{
    delete ui;
}
