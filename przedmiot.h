#ifndef PRZEDMIOT_H
#define PRZEDMIOT_H

#include <QString>
#include <QStringList>
#include <optional>

class Przedmiot
{
public:

    // konstruktor
    Przedmiot(int id, QString nazwa);

    // getters
    int getId() const;
    QString getNazwa() const;

    // setters
    void setNazwa(QString nazwa);

private:
    int przedmiotId;
    QString nazwa;
};

#endif // PRZEDMIOT_H
