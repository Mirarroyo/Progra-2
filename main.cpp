#include <iostream>
#include <string>
#include <limits> 
#include "Biblioteca.h"
#include "Alumno.h" 
using namespace std;

// Declaración global del objeto principal
Biblioteca miBiblioteca;

// Declaración de funciones (Procedimientos)
void menu();
void registrarPrestamoFisico();
void registrarPrestamoEbook(); // Nueva función
void ejecutarMenu();



void menu() {
    cout << "\nSISTEMA DE BIBLIOTECA \n";
    cout << "1. Ver libros físicos disponibles. \n";
    cout << "2. Ver Ebooks disponibles. \n";
    cout << "3. Registrar préstamo de libro físico. \n";
    cout << "4. Registrar préstamo de Ebook. \n"; 
    cout << "5. Mostrar todos los préstamos físicos. \n";
    cout << "6. Mostrar todos los préstamos de Ebook. \n"; 
    cout << "7. Salir \n"; // Cambió a 7
}


void registrarPrestamoFisico() {
    string nombre, matricula;
    int indexLibro, dias;

    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    cout << "Nombre del alumno: ";
    getline(cin, nombre);

    cout << "Matrícula: ";
    getline(cin, matricula);

    Alumno a(nombre, matricula);

    miBiblioteca.mostrarLibrosFisicos();
    if (miBiblioteca.getNumLibFis() == 0) {
        return;
    }

    cout << "\nSelecciona el **número** del libro a prestar: ";
    cin >> indexLibro;

    int idx = indexLibro - 1; 
    
    if (idx >= 0 && idx < miBiblioteca.getNumLibFis()) {
        LibroFisico libroAPrestar = miBiblioteca.getLibroFisico(idx); 

        cout << "Días del préstamo: ";
        cin >> dias;
        
        miBiblioteca.agregarPrestamoFisico(libroAPrestar, a, dias);
        cout << "\n✔ Préstamo de libro físico registrado correctamente.\n";
    } else {
        cout << "\n⚠ Número de libro inválido.\n";
    }
}

void registrarPrestamoEbook() {
    string nombre, matricula;
    int indexLibro, dias;

    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    cout << "Nombre del alumno: ";
    getline(cin, nombre);

    cout << "Matrícula: ";
    getline(cin, matricula);

    Alumno a(nombre, matricula);

    miBiblioteca.mostrarEbooks();
    if (miBiblioteca.getNumEbooks() == 0) {
        return;
    }

    cout << "\nSelecciona el numero del Ebook a prestar: ";
    cin >> indexLibro;

    int idx = indexLibro - 1; 
    
    if (idx >= 0 & idx < miBiblioteca.getNumEbooks()) {
        Ebook ebookAPrestar = miBiblioteca.getEbook(idx); 

        cout << "Días del préstamo: ";
        cin >> dias;
        
        miBiblioteca.agregarPrestamoEbook(ebookAPrestar, a, dias);
        cout << "\nPréstamo de Ebook registrado correctamente.\n";
    } else {
        cout << "\n Número de Ebook inválido.\n";
    }
}

void ejecutarMenu() {
    int opcion = 0;
    const int SALIR = 7;

    while(opcion != SALIR) {

        menu();
        cout << "Opción: ";

        if (!(cin >> opcion)) {
            cout << "Entrada inválida. Intente de nuevo.\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue; 
        }

        switch(opcion) {
            case 1:
                miBiblioteca.mostrarLibrosFisicos();
                break;
            case 2:
                miBiblioteca.mostrarEbooks();
                break;
            case 3:
                registrarPrestamoFisico();
                break;
            case 4: // Nuevo caso
                registrarPrestamoEbook();
                break;
            case 5:
                miBiblioteca.mostrarPrestamosFisicos();
                break;
            case 6: // Nuevo caso
                miBiblioteca.mostrarPrestamosEbooks();
                break;
            case SALIR:
                cout << "Gracias por usar el sistema de biblioteca. ¡Hasta pronto!\n";
                break;
            default:
                cout << "Opción no válida. Por favor, seleccione un número del menú.\n";
                break;
        }
    }
}


// Función principal
int main() {
    
    // Inicialización y llamada al menú
    miBiblioteca.creaEjemplosLibros(); 
    ejecutarMenu();
    
    return 0;
}
