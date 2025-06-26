#ifndef PRZEDMIOT_H
#define PRZEDMIOT_H

#include <QString>

class Przedmiot
{
public:

    // atrybuty
    QString id;
    QString nazwa;

    // konstruktor
    Przedmiot(QString id, QString nazwa);
    Przedmiot() = delete;

    // metody
    Qstring toStringCSV();                      // zwraca string do zapisu w CSV
    Przedmiot fromStringCSV(QString wiersz);    // tworzy obiekt na bazie danych z wiersza
};

#endif // PRZEDMIOT_H
