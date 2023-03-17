#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include "centre.h"
#include <QIntValidator>
#include <QSqlQueryModel>
#include <iostream>
#include <QModelIndex>
using namespace  std ;
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->lineEditIdC->setValidator( new QIntValidator(0, 999, this));
    QStringList allowedValues = {"ferme", "ouvert"};
    QRegExpValidator *validator = new QRegExpValidator(QRegExp(allowedValues.join("|")));
    ui->lineEditEtat->setValidator(validator);
    QRegExpValidator *validatorr = new QRegExpValidator(QRegExp("[a-zA-Z]+"));
    ui->lineEditnomCentre->setValidator(validatorr);

   ui->tableCentre->setModel(c.afficherC());
   ui->tableCentre->setModel(c.afficherC()) ;

}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_ajoutC_clicked()
{ int idC=ui->lineEditIdC->text().toInt();
    QString nomC=ui->lineEditnomCentre->text();
    QString adresse=ui->lineEdit_localC->text();
    QString etat=ui->lineEditEtat->text();


  centre c(idC,nomC,adresse,etat);
bool test=c.ajouterC();
if (test)
{
    ui->tableCentre->setModel(c.afficherC());
    QMessageBox::information(nullptr, QObject::tr("ok"),
                QObject::tr("ajout effectué.\n"
                            "Click Cancel to exit."), QMessageBox::Cancel);
}
else
    QMessageBox::critical(nullptr, QObject::tr("la si aala "),
                QObject::tr("non effectué .\n"
                            "Click Cancel to exit."), QMessageBox::Cancel);

ui->lineEditIdC->clear();
ui->lineEditEtat->clear();
ui->lineEdit_localC->clear();
ui->lineEditnomCentre->clear();
}

void MainWindow::on_pushButton_SC_clicked()
{

    int id=ui->lineEditIdC->text().toInt();
    bool test=c.supprimerC(id);
   if (test)
   {
       ui->tableCentre->setModel(c.afficherC());// actualiser le tableau
       QMessageBox::information(nullptr, QObject::tr("ok"),
                   QObject::tr("supprimée\n"
                               "Click Cancel to exit."), QMessageBox::Cancel);

   }
   else
       QMessageBox::critical(nullptr, QObject::tr("la si aala "),
                   QObject::tr("non.\n"
                               "Click Cancel to exit."), QMessageBox::Cancel);
   ui->lineEditIdC->clear();
   ui->lineEditEtat->clear();
   ui->lineEdit_localC->clear();
   ui->lineEditnomCentre->clear();
}



void MainWindow::on_pushButton_modC_clicked()
{

      int id=ui->lineEditIdC->text().toInt();
        QString nomC=ui->lineEditnomCentre->text();
        QString adresse=ui->lineEdit_localC->text();
        QString etat=ui->lineEditEtat->text();
centre c(id,nomC,adresse,etat);
    bool test=c.modifierC(id);
    if (test)
    {
        ui->tableCentre->setModel(c.afficherC());
        QMessageBox::information(nullptr, QObject::tr("ok"),
                    QObject::tr("c bon \n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
    }
    else
        QMessageBox::critical(nullptr, QObject::tr("la si aala "),
                    QObject::tr("erreur.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

    ui->lineEditIdC->clear();
    ui->lineEditEtat->clear();
    ui->lineEdit_localC->clear();
    ui->lineEditnomCentre->clear();

 }


void MainWindow::on_tableCentre_clicked(const QModelIndex &index)
{

     int id=index.sibling(index.row(),0).data().toInt();
     QString adresse=index.sibling(index.row(),1).data().toString();
     QString etat=index.sibling(index.row(),2).data().toString();
     QString nom=index.sibling(index.row(),3).data().toString();

     ui->lineEditIdC->setText(QString::number(id));
     ui->lineEditEtat->setText(etat);
     ui->lineEdit_localC->setText(adresse);
     ui->lineEditnomCentre->setText(nom);



}

void MainWindow::on_pushButton_pdfC_clicked()
{
    centre c ;
        bool test=false;
            test=c.genererPDF();
            if(test)

                {
               // ui->tableCentre->setModel(c.afficherC());
                QMessageBox::information(nullptr, QObject::tr("créé"),

                                    QObject::tr(" PDF créé.\n"

                                                "Click Cancel to exit."), QMessageBox::Cancel);}
            else

                {

                    QMessageBox::critical(nullptr, QObject::tr("non créé"),

                                QObject::tr("PDF non créé !.\n"

                                            "Click Cancel to exit."), QMessageBox::Cancel);



        }
}

void MainWindow::on_pushButton_rechercheC_clicked()
{
    /*QString adresse=ui->lineEdit_localC->text();

   bool test=c.rechercheparadresse(adresse);
   if(test)
   {

       QMessageBox::information(nullptr, QObject::tr("reference existe"),
                   QObject::tr("reference existe.\n"
                               "Click Cancel to exit."), QMessageBox::Cancel);
       ui->tableCentre->setModel( c.afficherparadresse(adresse));//refresh

       //ui->tableView->clear();

   }
   else
       QMessageBox::critical(nullptr, QObject::tr("reference n'existe pas"),
                   QObject::tr("reference n'existe pas !.\n"
                               "Click Cancel to exit."), QMessageBox::Cancel);
      // ui->tableView->clear();*/


}

void MainWindow::on_pushButton_trierCid_clicked()
{
   ui->tableCentre->setModel(c.trierparid());
}
