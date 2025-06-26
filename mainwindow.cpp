#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QMessageBox>
#include <QInputDialog>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // wczytaj dane z plików csv przy starcie
    dataManager.wczytajDane();

    // odśwież tabele przy starcie
    refreshTabelaStudenci();

    /*
    refreshTabelaPrzedmioty();
    refreshTabelaOceny();
    refreshListyRozwijane();
    refreshPosumowanie();
    */
}

MainWindow::~MainWindow()
{
    // zapisz dane przy zamykaniu aplikacji
    dataManager.zapiszDane();
    delete ui;
}

// funkcja pomocnicza do znajowania największego id studenta
void MainWindow::on_pb_dodaj_student_clicked()
{
    bool ok;
    QString imie = QInputDialog::getText(this, "Dodaj Studenta", "Podaj imię studenta:", QLineEdit::Normal, QString(), &ok);
    if(!ok || imie.trimmed().isEmpty())
    {
        if(ok && imie.trimmed().isEmpty())
        {
            QMessageBox::warning(this, "Pozostawiono puste pole", "Imię nie może być puste");
        }
        return;
    }

    QString nazwisko = QInputDialog::getText(this, "Dodaj Studenta", "Podaj nazwisko studenta:", QLineEdit::Normal, QString(), &ok);
    if(!ok || imie.trimmed().isEmpty())
    {
        if(ok && nazwisko.trimmed().isEmpty())
        {
            QMessageBox::warning(this, "Pozostawiono puste pole", "Nazwisko nie może być puste");
        }
        return;
    }

    // sformatowanie zmiennych
    imie = imie.trimmed();
    nazwisko = nazwisko.trimmed();

    // utwórz nowego studenta
    Student nowyStudent(dataManager.wygenerujId(), imie, nazwisko);
    dataManager.dodajStudenta(nowyStudent);

    // poinformuj użytkownika o wyniku
    QMessageBox::information(this, "Sukces!", "Użytkownik " + nazwisko + " " + imie + " został pomyślnie dodany. ID: " + QString::number(nowyStudent.getId()));

    // odśwież tabele
    refreshTabelaStudenci();
    //refreshListyRozwijane();
}

/*
void MainWindow::on_pb_edytuj_student_clicked()
{

}


void MainWindow::on_pb_usun_student_clicked()
{

}


void MainWindow::on_pb_dodaj_przedmiot_clicked()
{

}


void MainWindow::on_pb_edytuj_przedmiot_clicked()
{

}


void MainWindow::on_pb_usun_przedmiot_clicked()
{

}


void MainWindow::on_pb_dodaj_ocene_clicked()
{

}


void MainWindow::on_pb_edytuj_ocene_clicked()
{

}


void MainWindow::on_pb_usun_ocene_clicked()
{

}


void MainWindow::on_pb_eksport_clicked()
{

}

*/

void MainWindow::refreshTabelaStudenci()
{
    // wyszyść tabelę
    ui -> tabela_studenci -> setRowCount(0);

    // pobierz listę studentów
    QList listaStudentow = dataManager.getStudenci();

    // ustaw nowy rozmiar tabeli na bazie długości listy studentów
    ui -> tabela_studenci -> setRowCount(listaStudentow.size());

    for(int i = 0; i < listaStudentow.size(); i++)
    {
        const Student& student = listaStudentow.at(i);

        // Ustaw ID w pierwszej kolumnie
        QTableWidgetItem *idItem = new QTableWidgetItem(QString::number(student.getId()));
        ui->tabela_studenci->setItem(i, 0, idItem);

        // Ustaw Imię w drugiej kolumnie
        QTableWidgetItem *imieItem = new QTableWidgetItem(student.getImie());
        ui->tabela_studenci->setItem(i, 1, imieItem);

        // Ustaw Nazwisko w trzeciej kolumnie
        QTableWidgetItem *nazwiskoItem = new QTableWidgetItem(student.getNazwisko());
        ui->tabela_studenci->setItem(i, 2, nazwiskoItem);
    }
}

