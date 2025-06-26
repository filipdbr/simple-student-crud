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

    // formatowanie dla zakładaki Studenci
    ui->tabWidget->setCurrentIndex(0); // ustaw domyślną zakładkę na pierwszą od lewej strony
    ui->tabela_studenci->verticalHeader()->setVisible(false); // usuń numerację wierszy
    ui->tabela_studenci->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch); // rozciągnij kolumny
    ui->tabela_studenci->horizontalHeader()->setSectionResizeMode(0, QHeaderView::ResizeToContents); // dopasuj pierwszą kolumnę do zawartości

    // formatowanie dla zakładaki Przedmioty
    ui -> tabela_przedmioty -> verticalHeader()->setVisible(false); // usuń numerację wierszy
    ui -> tabela_przedmioty -> horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch); // rozciągnij kolumny
    ui -> tabela_przedmioty -> horizontalHeader()->setSectionResizeMode(0, QHeaderView::ResizeToContents); // dopasuj pierwszą kolumnę do zawartości

    // odśwież tabele przy starcie
    refreshTabelaStudenci();
    refreshTabelaPrzedmioty();

    /*
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
    Student nowyStudent(dataManager.wygenerujIdStudenta(), imie, nazwisko);
    dataManager.dodajStudenta(nowyStudent);

    // poinformuj użytkownika o wyniku
    QMessageBox::information(this, "Sukces!", "Użytkownik " + nazwisko + " " + imie + " został pomyślnie dodany. ID: " + QString::number(nowyStudent.getId()));

    // odśwież tabele
    refreshTabelaStudenci();
    //refreshListyRozwijane();
}

void MainWindow::on_pb_edytuj_student_clicked()
{
    bool ok;
    int studentId = QInputDialog::getInt(this, "Tryb edycji", "Podaj ID studenta do edycji", 0, 0, 5000, 1, &ok);
    if(!ok)
    {
        return;
    }

    Student* studentDoEdycji = dataManager.znajdzStudenta(studentId);
    if (!studentDoEdycji)
    {
        QMessageBox::warning(this, "Brak wyników", "Student o podanym ID nie został znaleziony.");
        return;
    }

    QString noweImie = QInputDialog::getText(this, "Edycja studenta", "Podaj nowe imie: ", QLineEdit::Normal, studentDoEdycji->getImie(), &ok);
    if(!ok || noweImie.trimmed().isEmpty())
    {
        if(ok && noweImie.trimmed().isEmpty())
        {
            QMessageBox::warning(this, "Pozostawiono puste pole", "Imię nie może być puste");
        }
        return;
    }
    studentDoEdycji->setImie(noweImie);

    QString noweNazwisko = QInputDialog::getText(this, "Edycja studenta", "Podaj nowe nazwisko: ", QLineEdit::Normal, studentDoEdycji->getNazwisko(), &ok);
    if(!ok || noweNazwisko.trimmed().isEmpty())
    {
        if(ok && noweNazwisko.trimmed().isEmpty())
        {
            QMessageBox::warning(this, "Pozostawiono puste pole", "Nazwisko nie może być puste");
        }
        return;
    }
    studentDoEdycji->setNazwisko(noweNazwisko);

    QMessageBox::information(this, "Sukces!", "Dane studenta zostały pomyślnie zaktualizowane.");
    refreshTabelaStudenci();

}

void MainWindow::on_pb_usun_student_clicked()
{
    bool ok;
    int studentId = QInputDialog::getInt(this, "Usuwanie studenta", "Podaj ID studenta do usunięcia", 0, 0, 5000, 1, &ok);
    if(!ok)
    {
        return;
    }

    bool usunieto = dataManager.usunStudenta(studentId);
    if(!usunieto)
    {
        QMessageBox::warning(this, "Brak wyników", "Nie znaleziono studenta ID " + QString::number(studentId));
        return;
    }
    QMessageBox::information(this, "Sukces", "Student został usunięty");

    refreshTabelaStudenci();
    return;
}

// funkcja dodaje przedmiot do listy przedmiotów
void MainWindow::on_pb_dodaj_przedmiot_clicked()
{
    bool ok;
    QString nazwaPrzedmiotu = QInputDialog::getText(this, "Tworzenie nowego przemiotu", "Wprowadź nazwę przedmiotu", QLineEdit::Normal, "Nazwa Przedmiotu", &ok);
    if(!ok || nazwaPrzedmiotu.isEmpty())
    {
        if(ok && nazwaPrzedmiotu.isEmpty())
        {
            QMessageBox::warning(this, "Brak nazwy", "Nazwa przedmiotu nie może być pusta");
        }
        return;
    }

    // test czy taki przedmiot już istnieje
    bool czyIstnieje = dataManager.czyIstnieje(nazwaPrzedmiotu);
    if(czyIstnieje)
    {
        QMessageBox::warning(this, "Duplikat", "Taki przedmiot już istnieje, brak możliwości stworzenia duplikatu");
        return;
    }

    // Tworzenie przedmiotu i dodanie do listy
    Przedmiot nowyPrzedmiot(dataManager.wygenerujIdPrzedmiotu(), nazwaPrzedmiotu);
    dataManager.dodajPrzedmiot(nowyPrzedmiot);

    QMessageBox::information(this, "Sukces!", "Dodano nowy przedmiot: " + nowyPrzedmiot.getNazwa());

    refreshTabelaPrzedmioty();
}

/*
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
        ui -> tabela_studenci -> setItem(i, 0, idItem);

        // Ustaw Imię w drugiej kolumnie
        QTableWidgetItem *imieItem = new QTableWidgetItem(student.getImie());
        ui -> tabela_studenci -> setItem(i, 1, imieItem);

        // Ustaw Nazwisko w trzeciej kolumnie
        QTableWidgetItem *nazwiskoItem = new QTableWidgetItem(student.getNazwisko());
        ui -> tabela_studenci -> setItem(i, 2, nazwiskoItem);
    }
}

void MainWindow::refreshTabelaPrzedmioty()
{
    // wyszyść tabelę
    ui -> tabela_przedmioty -> setRowCount(0);

    // pobierz listę studentów
    QList listaPrzedmiotow = dataManager.getPrzedmioty();

    // ustaw nowy rozmiar tabeli na bazie długości listy studentów
    ui -> tabela_przedmioty -> setRowCount(listaPrzedmiotow.size());

    for(int i = 0; i < listaPrzedmiotow.size(); i++)
    {
        const Przedmiot& przedmiot = listaPrzedmiotow.at(i);

        // ustaw ID w pierwszej kolumnie
        QTableWidgetItem *idItem = new QTableWidgetItem(QString::number(przedmiot.getId()));
        ui -> tabela_przedmioty -> setItem(i, 0, idItem);

        // ustaw nazwę w drugiej kolumnie
        QTableWidgetItem *nazwaItem = new QTableWidgetItem(przedmiot.getNazwa());
        ui -> tabela_przedmioty -> setItem(i, 1, nazwaItem);
    }
}
