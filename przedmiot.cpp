#include "przedmiot.h"

// implementacja konstruktora
Przedmiot::Przedmiot(QString id, QString nazwa)
{
    this -> id = id;
    this -> nazwa = nazwa;
}

// implementacja metod
QString Przedmiot::toStringCSV()
{
    Qstring nazwaSformatowana = nazwa;
    nazwaSformatowana.replace(",", "_");    // zastąp "," w celu uniknięcia uszkodzenia struktury pliku csv
    return id + ", " + nazwaSformatowana;
}

// optional w celu umożliwienia zwrócenia pustej wartości
std::optional<Przemiot> Przedmiot::fromStringCSV(QString wiersz)
{
    QStringList skladowa = wiersz.split(",", Qt::SkipEmptyParts);
    if(skladowe.size() < 2){
        return NULL;
    }
    return Przedmiot(skladowa[0].trimmed(), skladowa[1].trimmed);
}
