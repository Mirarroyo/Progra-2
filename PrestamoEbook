#ifndef PRESTAMOEBOOK_H_
#define PRESTAMOEBOOK_H_

#include "Alumno.h"
#include "Ebook.h"

class PrestamoEbook {
private:
    Ebook libro; 
    Alumno alumno;     
    int dias;

public:
    // Constructores y métodos
    PrestamoEbook();
    PrestamoEbook(Ebook l, Alumno a, int d);

    void setDias(int d);
    int getDias() const;
    string toString() const;
};

// Implementación

PrestamoEbook::PrestamoEbook() : libro(), alumno() {
    dias = 0;
}

PrestamoEbook::PrestamoEbook(Ebook l, Alumno a, int d) {
    libro = l;
    alumno = a;
    dias = d;
}

void PrestamoEbook::setDias(int d) { dias = d; }
int PrestamoEbook::getDias() const { return dias; }

string PrestamoEbook::toString() const {
    stringstream aux;
    aux << "Préstamo de Ebook\n"
        << alumno.toString() << "\n"
        << libro.toString() << "\n"
        << "Días de préstamo: " << dias;
    return aux.str();
}

#endif
