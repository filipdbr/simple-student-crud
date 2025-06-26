#include "przedmiot.h"

// implementacja konstruktora
Przedmiot::Przedmiot(int id, QString nazwa)
{
    przedmiotId = id;
    this -> nazwa = nazwa;
}

// implementacja metod
int getId() const
{
    return przedmiotId;
}

QString getNazwa() const
{
    return nazwa;
}

void setNazwa(QString nazwa);
{
    this -> nazwa = nazwa;
}
