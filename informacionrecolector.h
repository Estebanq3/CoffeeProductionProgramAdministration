#ifndef INFORMACIONRECOLECTOR_H
#define INFORMACIONRECOLECTOR_H

#include <QDialog>

namespace Ui {
class InformacionRecolector;
}

class InformacionRecolector : public QDialog
{
    Q_OBJECT

public:
    explicit InformacionRecolector(QWidget *parent = nullptr);
    ~InformacionRecolector();

private:
    Ui::InformacionRecolector *ui;
};

#endif // INFORMACIONRECOLECTOR_H
