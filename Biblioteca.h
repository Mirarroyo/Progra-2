#ifndef BIBLIOTECA_H_
#define BIBLIOTECA_H_

#include <iostream>
#include <string>
#include <sstream>
#include <limits>

#include "LibroFisico.h" 
#include "Ebook.h"    
#include "PrestamoFisico.h" 
#include "PrestamoEbook.h" 
#include "Alumno.h" 

using namespace std;


const int MAX_LIBROS = 50;
const int MAX_PRESTAMOS = 50;

class Biblioteca {
private:
    LibroFisico librosFisicos[MAX_LIBROS];
    Ebook ebooks[MAX_LIBROS]; 
    PrestamoFisico prestamosFisicos[MAX_PRESTAMOS];
    PrestamoEbook prestamosEbooks[MAX_PRESTAMOS]; 

    int numLibFis;
    int numEbooks; 
    int numPresFis;
    int numPresEbooks; 

public:
    Biblioteca();
    void creaEjemplosLibros(); 
    
    // Getters
    int getNumLibFis() const;
    int getNumEbooks() const; 
    
    // Métodos
    LibroFisico getLibroFisico(int index) const; 
    Ebook getEbook(int index) const; 
    void mostrarLibrosFisicos() const;
    void mostrarEbooks() const; 

    // Métodos de gestión de préstamos
    void agregarPrestamoFisico(LibroFisico l, Alumno a, int d);
    void agregarPrestamoEbook(Ebook e, Alumno a, int d); 
    void mostrarPrestamosFisicos() const;
    void mostrarPrestamosEbooks() const; 
};


Biblioteca::Biblioteca() {
    numLibFis = 0;
    numEbooks = 0; 
    numPresFis = 0;
    numPresEbooks = 0; 
}

void Biblioteca::creaEjemplosLibros() {
    // Libros Físicos
    librosFisicos[0] = LibroFisico("Alas de Sangre", "Rebecca Yarros", 2022, 561);
    numLibFis += 1;
    librosFisicos[1] = LibroFisico("Alas de Hierro", "Rebecca Yarros",2024, 892);
    numLibFis += 1;

    // Ebooks
    ebooks[0] = Ebook("Alas de Onix", "Rebecca Yarros", 2025, "KINDLE");
    numEbooks += 1;
    ebooks[1] = Ebook("It end with us", "Colleen Hovers", 1605, "PDF");
    numEbooks += 1;
}

// Implementación de Getters

int Biblioteca::getNumLibFis() const { return numLibFis; }

int Biblioteca::getNumEbooks() const { return numEbooks; }

// Implementación de Métodos de Libros

LibroFisico Biblioteca::getLibroFisico(int index) const {
    if (index >= 0 & index < numLibFis) {
        return librosFisicos[index];
    }
    return LibroFisico(); 
}

Ebook Biblioteca::getEbook(int index) const {
    if (index >= 0 & index < numEbooks) {
        return ebooks[index];
    }
    return Ebook(); 
}

void Biblioteca::mostrarLibrosFisicos() const {
    cout << "\nLibros Físicos Disponibles" << numLibFis << "\n";
    if (numLibFis == 0) {
        cout << "No hay libros físicos registrados.\n";
        return;
    }
    for (int i = 0; i < numLibFis; i++) {
        // *** CAMBIO CLAVE: Se llama a toStringFisico() ***
        cout << "Libro" << (i + 1) << "\n" 
             << librosFisicos[i].toStringFisico() << "\n-\n";
    }
}

void Biblioteca::mostrarEbooks() const {
    cout << "\n Ebooks Disponibles (" << numEbooks;;
    if (numEbooks == 0) {
        cout << "No hay ebooks registrados.\n";
        return;
    }
    for (int i = 0; i < numEbooks; i++) {
        cout << "Ebook " << (i + 1) << "\n"
             << ebooks[i].toStringEbook() << "\n-\n";
    }
}

// Implementación de Métodos de Préstamos

void Biblioteca::agregarPrestamoFisico(LibroFisico l, Alumno a, int d) {
    // Al crear el objeto PrestamoFisico, éste llamará a l.toStringFisico()
    if (numPresFis < MAX_PRESTAMOS) {
        prestamosFisicos[numPresFis] = PrestamoFisico(l, a, d);
        numPresFis += 1;
    } else {
        cout << "Error: No se pueden registrar más préstamos físicos.\n";
    }
}

void Biblioteca::agregarPrestamoEbook(Ebook e, Alumno a, int d) {
    // Al crear el objeto PrestamoEbook, éste llamará a e.toStringEbook()
    if (numPresEbooks < MAX_PRESTAMOS) {
        prestamosEbooks[numPresEbooks] = PrestamoEbook(e, a, d);
        numPresEbooks += 1;
    } else {
        cout << "Error: No se pueden registrar más préstamos de Ebook.\n";
    }
}

void Biblioteca::mostrarPrestamosFisicos() const {
    cout << "\nLista de Préstamos Físicos Registrados " << numPresFis;
    if (numPresFis == 0) {
        cout << "No hay préstamos físicos registrados.\n";
        return;
    }
    for (int i = 0; i < numPresFis; i++) {
        cout << "\nPréstamo" << (i + 1) << "\n";
        cout << prestamosFisicos[i].toString() << "\n-\n";
    }
}

void Biblioteca::mostrarPrestamosEbooks() const {
    cout << "\nLista de Préstamos de Ebook Registrados" << numPresEbooks;
    if (numPresEbooks == 0) {
        cout << "No hay préstamos de Ebook registrados.\n";
        return;
    }
    for (int i = 0; i < numPresEbooks; i++) {
        cout << "\nPréstamo" << (i + 1) << "\n";
        cout << prestamosEbooks[i].toString() << "\n-\n";
    }
}


#endif 
