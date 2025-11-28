#ifdef LIBRO_H
#define LIBRO_H
#include <iostream>
using namespace std;

class Libro {
private:
    string titulo;
    string autor;
    bool disponible;

public:
    // constructor
    Libro(string t, string a) {
        titulo = t;
         autor = a;
          disponible = true;
    }

    // geters
    string getTitulo() {
        return titulo;
    }
    string getAutor() {
        return autor;
    }
    bool getDisponible() {
        return disponible;
    }

    // seters
    void setTitulo(string t) {
        titulo = t;
    }
    void setAutor(string a) {
        autor = a;
    }
    void setDisponible(bool d) {
        disponible = d;
    }

    //metodos
    void mostrarInfo() {
        cout << "Título: " << titulo << endl;
        cout << "Autor: " << autor << endl;
        cout << "Disponible: " << (disponible? "Sí" : "No") 
        << endl;
    }
};
#endif
