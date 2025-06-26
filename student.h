#ifndef STUDENT_H
#define STUDENT_H

#include <QString>

class Student
{
public:
    // konstruktor
    Student(int id, QString imie, QString nazwisko);

    // getters
    int getId() const;
    QString getImie() const;
    QString getNazwisko() const;

    // setters
    void setImie(QString imie);
    void setNazwisko(QString nazwisko);

private:
    int studentId;
    QString imie;
    QString nazwisko;
};

#endif // STUDENT_H
