#include "ocena.h"

// implementacja konstruktora
Ocena::Ocena(int studentId, int przedmiotId, double ocena = 2.0, bool zal = false)
{
    this -> studentId = studentId;
    this -> przedmiotId = przedmiotId;
    this -> ocena = ocena;
    zaliczony = zal;
}

// impementacja metod
int Ocena::getStudentId() const
{
    return studentId;
}

int Ocena::getPrzedmiotId() const
{
    return przedmiotId;
}

double Ocena::getOcena() const
{
    return ocena;
}

bool Ocena::czyZal() const
{
    return zaliczony;
}

void Ocena::setOcena(double ocena)
{
    this -> ocena = ocena;
}

void Ocena::setZal(bool czyZal)
{
    zaliczony = czyZal;
}
