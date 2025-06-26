#ifndef OCENA_H
#define OCENA_H

class Ocena
{
public:
    //konstuktor
    Ocena(int studentId, int przedmiotId, double ocena, bool zal);

    // getters
    int getStudentId() const;
    int getPrzedmiotId() const;
    double getOcena() const;
    bool czyZal() const;

    // setters
    void setOcena(double ocena);
    void setZal(bool czyZal);

private:

    // pola / atrybuty
    int studentId;
    int przedmiotId;
    double ocena;
    bool zaliczony;
};

#endif // OCENA_H
