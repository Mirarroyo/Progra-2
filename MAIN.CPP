#include <iostream>
#include "Piloto.h"
#include "Auto.h"
#include "Escuedria.h"

int main() {
    // Crear objetos
    Piloto p1("Carlos Sainz", 55);
    Auto a1("Ferrari SF-24", 1050);
    Escuderia e1("Ferrari", 16);

    // Probar métodos
    std::cout << "\n--- Información del Piloto ---" << std::endl;
    p1.mostrarInfo();
    p1.saludar();

    std::cout << "\n--- Información del Auto ---" << std::endl;
    a1.mostrarInfo();
    a1.encender();

    std::cout << "\n--- Información de Escuderia ---" << std::endl;
    e1.mostrarInfo();
    e1.presentar();

    return 0;
}
