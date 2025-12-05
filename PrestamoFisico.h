/**
 * clase de agregación
 * registra préstamos de libros físicos a alumnos
 * relaciona instancias de LibroFisico y Alumno
 */
#ifndef PRESTAMOFISICO_H_
#define PRESTAMOFISICO_H_
#include "Alumno.h"
#include "LibroFisico.h"

class PrestamoFisico {
private:
// Atributos
    Libro libro; 
    Alumno alumno;     
    int dias;

public:
    // Constructor default 
    PrestamoFisico();
    /**
     * Constructor con parámetros
     * inicializa el estado de los atributos
     * @param l Libro prestado
     * @param a Alumno que realiza el préstamo
     * @param d Días del préstamo
     */
    PrestamoFisico(Libro l, Alumno a, int d);

    //Setter y Getter
    void setDias(int d);
    int getDias() const;

    // Método
    /**
     * genera reporte del préstamo en formato string
     * @return string con la info del préstamo
     * llama a toString() de Libro y Alumno
     */
    string toString() const;
};

// Implementación de las funnciones 

PrestamoFisico::PrestamoFisico() : libro(), alumno() {
    dias = 0;
}

PrestamoFisico::PrestamoFisico(Libro l, Alumno a, int d) {
    libro = l;
    alumno = a;
    dias = d;
}

void PrestamoFisico::setDias(int d) { 
    dias = d;
}
int PrestamoFisico::getDias() const {
     return dias; 
}
/**
 * Este método implementa la agregacion mediante la 
 * tecnica de delegación, llamando a los métodos toString()
 * de los objetos libro fisico y Alumno que forman parte del préstamo.
 */
string PrestamoFisico::toString() const {
    stringstream aux;
    aux << "Préstamo a: " << alumno.toString() 
    <<" de: "<< libro.toString() << "Por: " << dias << " días.";
    return aux.str();
}

#endif
