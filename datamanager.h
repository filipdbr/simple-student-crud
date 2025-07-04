#ifndef DATAMANAGER_H
#define DATAMANAGER_H

#include "student.h"
#include "przedmiot.h"
#include "ocena.h"

#include <QList>
#include <QString>

class DataManager
{
public:
    // konstruktor
    DataManager();

    // metody
    void wczytajDane();
    void zapiszDane();

    // studenci
    QList<Student> getStudenci() const;
    void dodajStudenta(const Student& student);
    bool usunStudenta(int studentId);
    Student* znajdzStudenta(int studentId);
    int wygenerujIdStudenta() const;
    int liczPrzedmioty(int studentId) const;

    // przedmioty
    QList<Przedmiot> getPrzedmioty() const;
    void dodajPrzedmiot(const Przedmiot& przedmiot);
    bool usunPrzedmiot(int przedmiotId);
    Przedmiot* znajdzPrzedmiot(int przedmiotId);
    int wygenerujIdPrzedmiotu() const;
    bool czyIstnieje(QString nazwaPrzedmiotu) const;
    int liczStudentow(int przedmiotId) const;

    // oceny
    QList<Ocena> getOceny() const;
    void dodajOcena(const Ocena& ocena);
    bool usunOcena(int studentId, int przedmiotId);
    Ocena* znajdzOcene(int studentId, int przedmiotId);

private:
    QList<Student> studenci;
    QList<Przedmiot> przedmioty;
    QList<Ocena> oceny;

    void wczytajStudentow();
    void wczytajOceny();
    void wczytajPrzedmioty();

    void zapiszStudentow();
    void zapiszOceny();
    void zapiszPrzedmioty();
};

#endif // DATAMANAGER_H
