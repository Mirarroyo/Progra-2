/**
 * Representa al usuario en este programa 
 * sus instancias son agregadas por las clases de préstamo 
 */
#ifndef ALUMNO_H_
#define ALUMNO_H_
#include <iostream>
#include <string>
#include <sstream>

using namespace std;

class Alumno {
private:
    // Atributos
    string nombre;
    string matricula;

public:
    // Constructor default
    Alumno();
    /**
     * Constructor con parámetros
     * @param n Nombre del alumno
     * @param m Matrícula del alumno
     */

    Alumno(string n, string m);

    // Getters para obteneter un atributo priado
    string getNombre() const;
    string getMatricula() const;
    // Setters para modificar un atributo privado
    void setNombre(string n);
    void setMatricula(string m);

    /**
     * @return cadena string con info del alumno
     * Una representación en cadena del objeto alumno
     */
    string toString() const;
};

// Implementación de funciones 

Alumno::Alumno() {
    nombre = "";
    matricula = "";
}

Alumno::Alumno(string n, string m) {
    nombre = n;
    matricula = m;
}

// Getters
string Alumno::getNombre() const { 
    return nombre; 
}
string Alumno::getMatricula() const {
     return matricula; 
    }

// Setters
void Alumno::setNombre(string n) {
     nombre = n; 
    }
void Alumno::setMatricula(string m) {
     matricula = m;
     }
// Método
string Alumno::toString() const {
    stringstream aux;
    aux << "Alumno: " << nombre << " , " << matricula;
    return aux.str();
}

#endif 
