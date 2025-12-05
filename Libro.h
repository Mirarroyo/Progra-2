/**
 * Clase Padre: Libro
 * contiene atributos y métodos comunes para los tipos de libros.
 */
#ifndef LIBRO_H_
#define LIBRO_H_
#include <string>
#include <sstream>
using namespace std;

class Libro {
protected:
// Artibutos en protected para que las clases hijas puedan acceder
    string titulo;
    string autor;
    int anio;

public:
    // Constructores
    Libro();
    /**
     * Constructor con parámetros
     * inicializar el estado del objeto 
     * @param t Título del libro
     * @param a Autor del libro
     * @param n Año de publicación
     *  */ 

    Libro(string t, string a, int n);

    // Getters para acceder a los atributos
    string getTitulo() const;
    string getAutor() const;
    int getAnio() const;
    /**
     * Devuelve la info base del libro en formato string
     * (estado del objeto )
     * @return string con la info del libro
     */

    // Métodos
    string toString() const; 
};

/**
 * Implementación de las funciones ya definicas
 *  */


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

string Libro::getTitulo() const { 
    return titulo; 
}
string Libro::getAutor() const { 
    return autor; 
}
int Libro::getAnio() const {
     return anio; 
}

// Métodos

string Libro::toString() const {
    stringstream aux;
    aux << "Título: " << titulo<< "Autor: " << autor << "Año: " << anio;
    return aux.str();
}

#endif 
