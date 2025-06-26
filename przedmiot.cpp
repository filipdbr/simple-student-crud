#include "przedmiot.h"

// implementacja konstruktora
Przedmiot::Przedmiot(int id, QString nazwa)
{
    przedmiotId = id;
    this -> nazwa = nazwa;
}

// implementacja metod
int Przedmiot::getId() const
{
    return przedmiotId;
}

QString Przedmiot::getNazwa() const
{
    return nazwa;
}

void Przedmiot::setNazwa(QString nazwa)
{
    this -> nazwa = nazwa;
}
