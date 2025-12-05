/**
 * Clase LibroFisico que hereda de Libro
 * Atributos: num de paginas
 */
#ifndef LIBROFISICO_H_
#define LIBROFISICO_H_
#include "Libro.h" 
#include <sstream>

// Clase LibroFisico hereda de Libro
class LibroFisico: public Libro {
private:
// Atributo específico de LibroFisico
    int paginas;

public:
    // Constructor default
    LibroFisico();
    /**
     * Constructor con parámetros
     * llamada a constructor de la clase base Libro
     * inicializa el estado de los atributos heredados y propios
     * @param p Número de páginas del libro físico
     */
    LibroFisico(string t, string a, int n, int p);

    // Getter y Setter
    int getPaginas() const;
    void setPaginas(int p);

    // Método
    /**
     * (estado del objeto )
     * @return string con la info del Libro Físico
     * combina la info de la clase base y el número de páginas
     */
    string toStringFisico() const; 
};

 // Implementación de funciones
LibroFisico::LibroFisico(): Libro() {
    paginas = 0;
}

LibroFisico::LibroFisico(string t, string a, int n, int p): Libro(t, a, n) {
    paginas = p;
}

// Getter y Setter
int LibroFisico::getPaginas() const { 
    return paginas;
}
void LibroFisico::setPaginas(int p) { 
    paginas = p; 
}


string LibroFisico::toStringFisico() const {
    stringstream aux;
  
    aux << Libro::toString()
        << "Tipo: Físico" << "Páginas: " << paginas;
    return aux.str();
}

#endif
