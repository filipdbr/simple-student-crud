#ifndef STUDENT_H
#define STUDENT_H

#include <QString>
#include <QStringList>
#include <QList>

// tworzę klasę wewnątrz klasy student - ocena jest ściśle powiązana ze studentem i nie ma prawa istnieć bez studenta
// enum dla ocen, możliwe jedynie od 2 do 5.
enum class Ocena : double {
    BrakOceny = 0.0,
    Dwa = 2.0,
    Trzy = 3.0,
    TrzyPol = 3.5,
    Cztery = 4.0,
    CzteryPol = 4.5,
    Piec = 5.0
};

// struktura reprezentująca zaliczenie przedmiotu
struct ZaliczeniePrzedmiotu {

    // pola / atrybuty
    QString przedmiotId;
    Ocena ocena;
    bool zaliczony;

    //konsturktor
    ZaliczeniePrzedmiotu() = delete;
    ZaliczeniePrzedmiotu(QString przedmiot, Ocena ocenaStudenta = Ocena::BrakOceny, bool zal = false);
    QString toStringCSV();
    static std::optional<ZaliczeniePrzedmiotu> fromStringCSV(QString wiersz);
};

class Student
{
public:
    // attrybuty
    QString studentId;
    QString imie;
    QString nazwisko;
    QList<ZaliczeniePrzedmiotu> listaZaliczen;

    // konstruktory
    Student() = delete;
    Student(QString id, QString imieStudenta, QString NazwiskoStudenta);

    // metody
    // dodaje nowe zaliczenie lub aktualizuje istniejące
    void dodajZaliczenie(const ZaliczeniePrzedmiotu& zaliczenie);

    // usuwa zaliczenie dla danego ID przedmiotu
    void usunZaliczenie(const QString& przedmiotID);

    // znajduje zaliczenie dla danego ID przedmiotu (zwraca wskaźnik lub nullptr)
    ZaliczeniePrzedmiotu* znajdzZaliczenie(const QString& przedmiotID);

    // ustawia całą listę zaliczeń (może być używane do wczytywania)
    void ustawListeZaliczen(const QList<ZaliczeniePrzedmiotu>& nowaLista);

    // konwersuje na CSV
    QString toStringCSV();

    // konwertuje z CSV
    static std::optional<Student> fromStringCSV(const QString& wiersz);
};

#endif // STUDENT_H
