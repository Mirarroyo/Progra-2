#ifndef PRESTAMOFISICO_H_
#define PRESTAMOFISICO_H_

#include "Alumno.h"
#include "LibroFisico.h"

class PrestamoFisico {
private:
    Libro libro; 
    Alumno alumno;     
    int dias;

public:
    // Constructores y métodos
    PrestamoFisico();
    PrestamoFisico(Libro l, Alumno a, int d);

    void setDias(int d);
    int getDias() const;
    string toString() const;
};

// Implementación

PrestamoFisico::PrestamoFisico() : libro(), alumno() {
    dias = 0;
}

PrestamoFisico::PrestamoFisico(Libro l, Alumno a, int d) {
    libro = l;
    alumno = a;
    dias = d;
}

void PrestamoFisico::setDias(int d) { dias = d; }
int PrestamoFisico::getDias() const { return dias; }

string PrestamoFisico::toString() const {
    stringstream aux;
    aux << "Préstamo de Fisico\n"
        << alumno.toString() << "\n"
        << libro.toString() << "\n"
        << "Días de préstamo: " << dias;
    return aux.str();
}

#endif
