#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "datamanager.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:

    // sloty dla panelu "Studenci"
    void on_pb_dodaj_student_clicked();
    void on_pb_edytuj_student_clicked();
    void on_pb_usun_student_clicked();

    // sloty dla panelu "Przedmioty"
    void on_pb_dodaj_przedmiot_clicked();
    void on_pb_edytuj_przedmiot_clicked();
    void on_pb_usun_przedmiot_clicked();

    // sloty dla panelu "Oceny"
    void on_pb_dodaj_ocene_clicked();
    void on_pb_edytuj_ocene_clicked();
    void on_pb_usun_ocene_clicked();

    // funkcje do odświeżania danych
    void refreshTabelaStudenci();
    void refreshTabelaPrzedmioty();
    void refreshListyRozwijane();
    void refreshTabelaOceny();

private:
    Ui::MainWindow *ui;
    // Instancja data managera
    DataManager dataManager;
};
#endif // MAINWINDOW_H
