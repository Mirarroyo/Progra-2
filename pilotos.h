#ifndef PILOTO_H
#define PILOTO_H

#include <string>

class Piloto {
private:
    std::string nombre;
    int numero;

public:
    // Constructor
    Piloto(std::string nombre, int numero);

    // Métodos
    void mostrarInfo() const;
    void saludar() const;
};

#endif
