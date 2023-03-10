#ifndef EQUIPEMENT_H
#define EQUIPEMENT_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class equipement; }
QT_END_NAMESPACE

class equipement : public QMainWindow
{
    Q_OBJECT

public:
    equipement(QWidget *parent = nullptr);
    ~equipement();

private slots:
    void on_pushButton_clicked();

private:
    Ui::equipement *ui;
};
#endif // EQUIPEMENT_H
