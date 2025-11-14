#ifndef ESCUDERIA_H
#define ESCUDERIA_H

#include <string>

class Escuderia {
private:
    std::string nombre;
    int campeonatos;

public:
    // Constructor
    Escuderia(std::string nombre, int campeonatos);

    // Métodos
    void mostrarInfo() const;
    void presentar() const;
};

#endif
