#include "student.h"

// implementacja konstruktora
Student::Student(int id, QString imie, QString nazwisko)
{
    studentId = id;
    this -> imie = imie;
    this -> nazwisko = nazwisko;
}

// implementacje metod
int Student::getId() const
{
    return studentId;
}

QString Student::getImie() const
{
    return imie;
}

QString Student::getNazwisko() const
{
    return nazwisko;
}

void Student::setImie(QString imie)
{
    this -> imie = imie;
}

void Student::setNazwisko(QString nazwisko)
{
    this -> nazwisko = nazwisko;
}
