#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "centre.h"

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_ajoutC_clicked();

    void on_pushButton_SC_clicked();

    void on_pushButton_modC_clicked();

    void on_tableCentre_clicked(const QModelIndex &index);

    void on_pushButton_pdfC_clicked();

    void on_pushButton_8_clicked();

    void on_pushButton_recherche_clicked();

    void on_pushButton_rechercheC_clicked();

    void on_pushButton_trierCid_clicked();

private:
    Ui::MainWindow *ui;
    centre c ;
};
#endif // MAINWINDOW_H
