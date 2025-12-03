#ifndef ALUMNO_H_
#define ALUMNO_H_

#include <iostream>
#include <string>
#include <sstream>

using namespace std;

class Alumno {
private:
    string nombre;
    string matricula;

public:
    // Constructores y métodos
    Alumno();
    Alumno(string n, string m);

    // Getters y Setters
    string getNombre() const;
    string getMatricula() const;
    void setNombre(string n);
    void setMatricula(string m);

    string toString() const;
};

// Implementación

Alumno::Alumno() {
    nombre = "";
    matricula = "";
}

Alumno::Alumno(string n, string m) {
    nombre = n;
    matricula = m;
}

// Getters
string Alumno::getNombre() const { return nombre; }
string Alumno::getMatricula() const { return matricula; }

// Setters
void Alumno::setNombre(string n) { nombre = n; }
void Alumno::setMatricula(string m) { matricula = m; }

string Alumno::toString() const {
    stringstream aux;
    aux << "Alumno: " << nombre << " (" << matricula << ")";
    return aux.str();
}

#endif 
