#ifndef LIBRO_H_
#define LIBRO_H_

#include <string>
#include <sstream>

using namespace std;

class Libro {
private:
    string titulo;
    string autor;
    int anio;

public:
    // Constructores y métodos
    Libro();
    Libro(string t, string a, int n);

    // Getters
    string getTitulo() const;
    string getAutor() const;
    int getAnio() const;

    // Métodos
    string toString() const; 
};

// Implementación

Libro::Libro() {
    titulo = "";
    autor = "";
    anio = 0;
}


Libro::Libro(string t, string a, int n) {
    titulo = t;
    autor = a;
    anio = n;
}

// Getters

string Libro::getTitulo() const { return titulo; }
string Libro::getAutor() const { return autor; }
int Libro::getAnio() const { return anio; }


string Libro::toString() const {
    stringstream aux;
    aux << "Título: " << titulo << "\n"
        << "Autor: " << autor << "\n"
        << "Año: " << anio;
    return aux.str();
}

#endif 
