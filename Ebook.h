#ifndef EBOOK_H_
#define EBOOK_H_

#include "Libro.h" 
#include <sstream>

// Clase Ebook hereda de Libro
class Ebook: public Libro {

private:
    string formato;

public:
    // Constructores y métodos
    Ebook();
    Ebook(string t, string a, int n, string f);

    // Getters y Setters
    string getFormato() const;
    void setFormato(string f);

    string toStringEbook() const; 
};

// Implementación

Ebook::Ebook(): Libro() {
    formato = "";
}

Ebook::Ebook(string t, string a, int n, string f): Libro(t, a, n) {
    formato = f;
}

// Getter y Setter

string Ebook::getFormato() const { return formato; }
void Ebook::setFormato(string f) { formato = f; }

string Ebook::toStringEbook() const {
    stringstream aux;

    aux << Libro::toString()
        << "\nTipo: Ebook"
        << "\nFormato: " << formato;
    return aux.str();
}

#endif
