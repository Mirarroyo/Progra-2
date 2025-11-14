#ifndef AUTO_H
#define AUTO_H

#include <string>

class Auto {
private:
    std::string modelo;
    int potencia;

public:
    // Constructor
    Auto(std::string modelo, int potencia);

    // Métodos
    void mostrarInfo() const;
    void encender() const;
};

#endif
