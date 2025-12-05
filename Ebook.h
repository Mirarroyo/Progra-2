/**
 * Classe Ebook que hereda de Libro
 * Atribuos: formato - digital (KINDLE, PDF, EPUB)
 */
#ifndef EBOOK_H_
#define EBOOK_H_
#include "Libro.h" 
#include <sstream>

// Clase Ebook hereda de Libro
class Ebook: public Libro {

private:
// Atributo específico de Ebook
    string formato;

public:
/**
 * cosntructores con parametros
 * llamada a constructor de la clase base Libro
 * inicializa el estado de los atributos heredados y propios
 * @param f Formato del ebook (KINDLE, PDF, EPUB)
 */
    // Constructores
    Ebook();
    Ebook(string t, string a, int n, string f);

    // Getter y Setter
    string getFormato() const;
    void setFormato(string f);
/**
 * (estado del objeto )
 * @return string con la info del Ebook
 * combina la info de la clase base y el formato
 */
    // Método
    string toStringEbook() const; 
};

// Implementación de funciones

Ebook::Ebook(): Libro() {
    formato = "";
}

Ebook::Ebook(string t, string a, int n, string f): Libro(t, a, n) {
    formato = f;
}

// Getter y Setter
string Ebook::getFormato() const { 
    return formato; 
}
void Ebook::setFormato(string f) {
     formato = f; 
}

string Ebook::toStringEbook() const {
    stringstream aux;

    aux << Libro::toString()
        << "Tipo: Ebook "<< "Formato: " << formato;
    return aux.str();
}

#endif
