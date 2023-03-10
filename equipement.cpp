#include "equipement.h"
#include "ui_equipement.h"

equipement::equipement(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::equipement)
{
    ui->setupUi(this);
}

equipement::~equipement()
{
    delete ui;
}


void equipement::on_pushButton_clicked()
{

}
