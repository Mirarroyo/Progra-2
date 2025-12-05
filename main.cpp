/**
 * implementacion de enu principal 
 * flujo de control del programa
 * manejo de entradas y salidas e interacción con el usuario

 */
#include <iostream>
#include <string>
#include <limits> 

#include "Biblioteca.h"
#include "Alumno.h" 

using namespace std;
/**
 * Muestra el menú de opciones al usuario
 */

void menu() {
    cout << "BIBLIOTECA" << endl;
    cout << "1) Ver libros físicos disponibles." << endl;
    cout << "2) Ver Ebooks disponibles." << endl;
    cout << "3) Registrar préstamo de libro físico." << endl;
    cout << "4) Registrar préstamo de Ebook." << endl; 
    cout << "5) Mostrar todos los préstamos físicos." << endl;
    cout << "6) Mostrar todos los préstamos de Ebook." << endl; 
    cout << "7) Salir" << endl; 
}

/**
 * Maneja la lógica para registrar un préstamo físico
 * @param Biblioteca1 Referencia a la instancia de Biblioteca
 * maneja entradas del usuario y valida selección 
 */
void registrarPrestamoFisico(Biblioteca & Biblioteca1) {
    string nombre, matricula;
    int indexLibro, dias;

    // registro de alumno

    cout << "Nombre del alumno: ";
    cin.ignore();
    getline(cin, nombre);

    cout << "Matrícula: ";
    cin.ignore();
    getline(cin, matricula);

    Alumno a(nombre, matricula);

    Biblioteca1.mostrarLibrosFisicos();
    if (Biblioteca1.getNumLibFis() == 0) {
        return;
    }

    cout << "\nSelecciona el número del libro por prestar: ";
    
    // Validación de entrada
    while (!(cin >> indexLibro) || indexLibro < 1 || indexLibro > Biblioteca1.getNumLibFis()) {
        cout << "Rspuesta no valida. " << Biblioteca1.getNumLibFis() << endl;
        cin.clear();
        cout << "\nSelecciona el número del libro por prestar: ";
    }

    int idx = indexLibro - 1; // Convertir número de menú a índice de arreglo
    
    LibroFisico libroAPrestar = Biblioteca1.getLibroFisico(idx); 

    cout << "Días del préstamo: ";
    // Validación de entrada
    while (!(cin >> dias) || dias <= 0) {
        cout << "Días no válidos. Vuelve a intentarlo: ";
        cin.clear();
    }
    
    Biblioteca1.agregarPrestamoFisico(libroAPrestar, a, dias);
    cout << "\n Préstamo registrado correctamente.\n";
}

/**
 * Maneja la lógica para registrar un préstamo de Ebook
 * @param Biblioteca1 Referencia a la instancia de Biblioteca
 * maneja entradas del usuario y valida selección
 */
void registrarPrestamoEbook(Biblioteca& Biblioteca1) {
    string nombre, matricula;
    int indexLibro, dias;

    cout << "Nombre del alumno: ";
    cin.ignore();
    getline(cin, nombre);

    cout << "Matrícula: ";
    cin.ignore();
    getline(cin, matricula);

    Alumno a(nombre, matricula);

    Biblioteca1.mostrarEbooks();
    if (Biblioteca1.getNumEbooks() == 0) {
        return;
    }

    cout << "\nSelecciona el número del Ebook por prestar: ";
    
    // Validación de entrada 
    while (!(cin >> indexLibro) || indexLibro < 1 || indexLibro > Biblioteca1.getNumEbooks()) {
        cout << "Rspuesta no valida. " << Biblioteca1.getNumEbooks() << endl;
        cin.clear();
        cout << "\nSelecciona el número del Ebook a prestar: ";
    }

    int idx = indexLibro - 1; 
    
    Ebook ebookAPrestar = Biblioteca1.getEbook(idx); 

    cout << "Días del préstamo: ";
    // Validación de entrada 
    while (!(cin >> dias) || dias <= 0) {
        cout << "Vuelve a intentarlo: ";
        cin.clear();
    }
    
    Biblioteca1.agregarPrestamoEbook(ebookAPrestar, a, dias);
    cout << "\nPréstamo registrado correctamente.\n";
}


/**
 * Ejecuta el ciclo principal del menú
 * continúa hasta que el usuario decide salir
 * @param Biblioteca1 Referencia a la instancia de Biblioteca
 */
void ejecutarMenu(Biblioteca& Biblioteca1) {
    int opcion = 0;
    const int SALIR = 7;

    while(opcion != SALIR) {

        menu();
        cout << "Opción: ";

        // Validación de entrada 
        if (!(cin >> opcion) || opcion < 1 || opcion > 7) {
            cout << "Opcion invalida." << endl;
            cin.clear(); 
        }

        switch(opcion) {
            case 1:
                Biblioteca1.mostrarLibrosFisicos();
                break;
            case 2:
                Biblioteca1.mostrarEbooks();
                break;
            case 3:
                registrarPrestamoFisico(Biblioteca1);
                break;
            case 4: 
                registrarPrestamoEbook(Biblioteca1);
                break;
            case 5:
                Biblioteca1.mostrarPrestamosFisicos();
                break;
            case 6: 
                Biblioteca1.mostrarPrestamosEbooks();
                break;
            case SALIR:
                cout << "¡Hasta pronto!\n";
                break;
        }
    }
}


// Función principal
int main() {
    
    // La instancia del objeto Biblioteca
    Biblioteca Biblioteca1; 
    
    // Inicialización de datos
    Biblioteca1.creaEjemplosLibros(); 
    
    // Ejecución del menú
    ejecutarMenu(Biblioteca1);
    
    return 0;
}
