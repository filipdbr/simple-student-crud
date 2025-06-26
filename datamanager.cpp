#include "datamanager.h"
#include <QFile>
#include <QTextStream>

DataManager::DataManager()
{
    wczytajDane();
}

// wczytywanie studentów
void DataManager::wczytajStudentow()
{
    // otwórz plik
    QFile plikStudentow("studenci.csv");

    // otwórz w trybie do odczytu
    if(plikStudentow.open(QIODevice::ReadOnly))
    {
        // otwórz strumień wejściowy z pliku
        QTextStream strumienWejsciowy(&plikStudentow);

        // dopóki są dane przechodź przez wiersze
        while(!strumienWejsciowy.atEnd())
        {
            // dziel wiersz na elementy - separator to ,
            QStringList elementyWiersza = strumienWejsciowy.readLine().split(",");

            // jeżeli liczba elementów >= 3 stwórz nowy objekt Student i dodaj do listy studentów
            if (elementyWiersza.size() >= 3)
            {
                studenci.append(Student(
                    elementyWiersza[0].toInt(),
                    elementyWiersza[1],
                    elementyWiersza[2]
                ));
            }
        }
        // zamknij plik z danymi
        plikStudentow.close();
    }
}

// wczytywanie przedmiotów
void DataManager::wczytajPrzedmioty()
{
    QFile plikPrzedmioty("przedmioty.csv");
    if(plikPrzedmioty.open(QIODevice::ReadOnly))
    {
        QTextStream strumienWejsciowy(&plikPrzedmioty);
        while(!strumienWejsciowy.atEnd())
        {
            QStringList elementyWiersza = strumienWejsciowy.readLine().split(",");
            if (elementyWiersza.size() >= 2)
            {
                przedmioty.append(Przedmiot(
                    elementyWiersza[0].toInt(),
                    elementyWiersza[1]
                ));
            }
        }
        plikPrzedmioty.close();
    }
}

// wczytywanie ocen
void DataManager::wczytajOceny()
{
    QFile plikOcen("oceny.csv");
    if(plikOcen.open(QIODevice::ReadOnly))
    {
        QTextStream strumienWejsciowy(&plikOcen);
        while(!strumienWejsciowy.atEnd())
        {
            QStringList elementyWiersza = strumienWejsciowy.readLine().split(",");
            if (elementyWiersza.size() >= 4)
            {
                oceny.append(Ocena(
                    elementyWiersza[0].toInt(),
                    elementyWiersza[1].toInt(),
                    elementyWiersza[2].toDouble(),
                    static_cast<bool>(elementyWiersza[3].toInt())
                    ));
            }
        }
        plikOcen.close();
    }
}

// wczutuje dane przy wykorzystaniu 3 powyższych funkcji. Podejście modularne
void DataManager::wczytajDane()
{
    wczytajStudentow();
    wczytajPrzedmioty();
    wczytajOceny();
}

// zapisywanie danych studentów
void DataManager::zapiszStudentow()
{
    // otwórz plik wyjścia
    QFile plikStudentow("studenci.csv");

    // korzystaj z trypu do zapisu i w trybie tekstowym
    if(plikStudentow.open(QIODevice::WriteOnly | QIODevice::Text))
    {
        // otwórz stumień wyjściowy
        QTextStream strumienWyjsciowy(&plikStudentow);

        // iteruj po liście studentów
        for(int i = 0; i < studenci.size(); i++)
        {
            // const i przekazanie przez parametr żeby unikąć nadpisania zmiennych.
            const Student& aktualnyStudent = studenci.at(i);

            // dodaj do strumienia
            strumienWyjsciowy << aktualnyStudent.getId() << "," << aktualnyStudent.getImie() << "," << aktualnyStudent.getNazwisko() << "\n";
        }
        // zamknij plik wyjściowy
        plikStudentow.close();
    }
}

// zapisywanie ocen
void DataManager::zapiszOceny()
{
    QFile plikOceny("oceny.csv");
    if(plikOceny.open(QIODevice::WriteOnly | QIODevice::Text))
    {
        QTextStream strumienWyjsciowy(&plikOceny);
        for(int i = 0; i < oceny.size(); i++)
        {
            const Ocena& aktualnaOcena = oceny.at(i);
            strumienWyjsciowy << aktualnaOcena.getStudentId() << "," << aktualnaOcena.getPrzedmiotId() << "," << aktualnaOcena.getOcena() << "," << static_cast<int>(aktualnaOcena.czyZal()) << "\n";
        }
        plikOceny.close();
    }
}

// zapisywanie przedmiotów
void DataManager::zapiszPrzedmioty()
{
    QFile plikPrzedmioty("przedmioty.csv");
    if(plikPrzedmioty.open(QIODevice::WriteOnly | QIODevice::Text))
    {
        QTextStream strumienWyjsciowy(&plikPrzedmioty);
        for(int i = 0; i < przedmioty.size(); i++)
        {
            const Przedmiot& aktualnyPrzedmiot = przedmioty.at(i);
            strumienWyjsciowy << aktualnyPrzedmiot.getId() << "," << aktualnyPrzedmiot.getNazwa() << "\n";
        }
        plikPrzedmioty.close();
    }
}

// zapisywanie danych przy wykorzystaniu 3 powyższych funkcji
void DataManager::zapiszDane()
{
    zapiszStudentow();
    zapiszOceny();
    zapiszPrzedmioty();
}
