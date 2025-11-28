ifndef BIBLIO_H
#define BIBLIO_H
#include <iostream>
#include "Libro.h"
#include "Alumno.h"
using namespace std;

class Biblio {
private:
    string nombre;
    Libro libro;
    Alumno alumno;

public:
    // constructor
    Biblio(string n, Libro l, Alumno a) : libro(l), alumno(a) {
        nombre = n;
    }

    // getters
    string getNombre() {
        return nombre;
    }
   
    void mostrarInfo() {
        cout << "Biblioteca: " << nombre << endl;
        cout << "Información del Libro:" << endl;
        libro.mostrarInfo();
        cout << "Información del Alumno:" << endl;
        alumno.mostrarInfo();
    }
};
#endif
