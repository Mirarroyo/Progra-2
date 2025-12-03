#ifndef LIBROFISICO_H_
#define LIBROFISICO_H_
#include "Libro.h" 
#include <sstream>


class LibroFisico: public Libro {
private:
    int paginas;

public:
    LibroFisico();
    LibroFisico(string t, string a, int n, int p);

    // Getters y Setters
    int getPaginas() const;
    void setPaginas(int p);


    string toStringFisico() const; 
};


LibroFisico::LibroFisico(): Libro() {
    paginas = 0;
}

LibroFisico::LibroFisico(string t, string a, int n, int p): Libro(t, a, n) {
    paginas = p;
}

// Getters y Setters
int LibroFisico::getPaginas() const { return paginas; }
void LibroFisico::setPaginas(int p) { paginas = p; }


string LibroFisico::toStringFisico() const {
    stringstream aux;
  
    aux << Libro::toString()
        << "\nTipo: Físico"
        << "\nPáginas: " << paginas;
    return aux.str();
}

#endif
