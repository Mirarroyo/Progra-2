/**
 * actua con la principal clase que gestiona la biblioteca
 * responsable de almacenar libros y préstamos
 */
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

// establece máximo de libros y préstamos
const int MAX_LIBROS = 40;
const int MAX_PRESTAMOS = 40;

class Biblioteca {
private:
// almqacenamiento gestionado con las constantes
    LibroFisico librosFisicos[MAX_LIBROS];
    Ebook ebooks[MAX_LIBROS]; 
    PrestamoFisico prestamosFisicos[MAX_PRESTAMOS];
    PrestamoEbook prestamosEbooks[MAX_PRESTAMOS]; 

    // contadores de libros y préstamos
    int numLibFis;
    int numEbooks; 
    int numPresFis;
    int numPresEbooks; 

public:
// Constructor inicializa contadores a 0
    Biblioteca();
    /**
     * crea ejemplos de libros físicos y ebooks
     * incrementa los contadores correspondientes
     */
    void creaEjemplosLibros(); 
    
    // Getters para obtener el numero actual 
    int getNumLibFis() const;
    int getNumEbooks() const; 
    
    // Métodos
    /**
     *  itera sobre la colección librosFisicos y muestra la información
     * de cada elemento utilizando el método toStringFisico() de la clase LibroFisico
     * iItera sobre la colección ebooks y muestra la información
     * de cada elemento utilizando el método toStringEbook() de la clase Ebook
     */
    LibroFisico getLibroFisico(int index) const; 
    Ebook getEbook(int index) const; 
    void mostrarLibrosFisicos() const;
    void mostrarEbooks() const; 

    // Métodos de gestión de préstamos
    /**
     * crea y registra PrestamoFisico en la colección
     * verifica la capacidad máxima antes de insertar
     * @param l LibroFisico que forma parte de la agregación
     * @param a Alumno que forma parte de la agregación
     * @param d Duración del préstamo
     */
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
    librosFisicos[0] = LibroFisico("Alas de Sangre ", "Rebecca Yarros", 2022, 561);
    numLibFis += 1;
    librosFisicos[1] = LibroFisico("Alas de Hierro ", "Rebecca Yarros ",2024, 892);
    numLibFis += 1;
    librosFisicos[2] = LibroFisico("Alas de Onix ", "Rebecca Yarros ",2025, 892);
    numLibFis += 1;
    librosFisicos[3] = LibroFisico("Secret Santa ", "Sophie Jomain",2025, 388);
    numLibFis += 1;
    librosFisicos[4] = LibroFisico("9 de noviembre ", "Colleen Hoover ",2024, 384);
    numLibFis += 1;
    librosFisicos[5] = LibroFisico("Amor entre paginas ", "Emily Wibberley ",2023, 424);
    numLibFis += 1;
    librosFisicos[6] = LibroFisico("Carry on ", "Rainbow Rowell ",2017, 528);
    numLibFis += 1;
    librosFisicos[7] = LibroFisico("Esta vez sera diferente ", "Carley Fortune ",2025, 361);
    numLibFis += 1;

    // Ebooks
    ebooks[0] = Ebook("Esta vez sera mejor ", "Christine Riccio ", 2021, "KINDLE");
    numEbooks += 1;
    ebooks[1] = Ebook("It end with us ", "Colleen Hoover ", 2018, "PDF");
    numEbooks += 1;
    ebooks[2] = Ebook("It starts with us ", "Colleen Hoover ", 2022, "PDF");
    numEbooks += 1;
    ebooks[3] = Ebook("Hasta que la bOda nos separe ", "CMia Sosa ", 2023, "KINDLE");
    numEbooks += 1;
    ebooks[4] = Ebook("Nosotros en la luna ", "Alice Kellen ", 2020, "PDF");
    numEbooks += 1;
    ebooks[5] = Ebook("Persona normal ", "Benito Taibo  ", 1900, "KINDLE");
    numEbooks += 1;
    ebooks[6] = Ebook("Corazonadas ", "Benito Taibo ", 1910, "KINDLE");
    numEbooks += 1;
    ebooks[7] = Ebook("Las tres hermanas ", "Heather Morris ", 2021, "PDF");
    numEbooks += 1;

}


// Implementación de Getters

int Biblioteca::getNumLibFis() const { 
    return numLibFis;
}

int Biblioteca::getNumEbooks() const { 
    return numEbooks; 
}

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
        cout << "No hay.\n";
        return;
    }
    for (int i = 0; i < numLibFis; i++) {
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
    // al crear el objeto PrestamoFisico, éste llamará a l.toStringFisico()
    if (numPresFis < MAX_PRESTAMOS) {
        prestamosFisicos[numPresFis] = PrestamoFisico(l, a, d);
        numPresFis += 1;
    } else {
        cout << "Error.\n";
    }
}

void Biblioteca::agregarPrestamoEbook(Ebook e, Alumno a, int d) {
    // al crear el objeto PrestamoEbook, éste llamará a e.toStringEbook()
    if (numPresEbooks < MAX_PRESTAMOS) {
        prestamosEbooks[numPresEbooks] = PrestamoEbook(e, a, d);
        numPresEbooks += 1;
    } else {
        cout << "Error.\n";
    }
}

void Biblioteca::mostrarPrestamosFisicos() const {
    cout << "\nLista de Préstamos Físicos Registrados " << numPresFis;
    if (numPresFis == 0) {
        cout << "No hay.\n";
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
        cout << "No hay.\n";
        return;
    }
    for (int i = 0; i < numPresEbooks; i++) {
        cout << "\nPréstamo" << (i + 1) << "\n";
        cout << prestamosEbooks[i].toString() << "\n-\n";
    }
}


#endif 
