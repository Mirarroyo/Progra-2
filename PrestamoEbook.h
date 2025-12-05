/**
 * clases de agregación
 * registra préstamos de ebooks a alumnos
 * relaciona instancias de Ebook y Alumno
 */
#ifndef PRESTAMOEBOOK_H_
#define PRESTAMOEBOOK_H_
#include "Alumno.h"
#include "Ebook.h"

class PrestamoEbook {
private:
    Ebook libro; 
    Alumno alumno;     
    int dias;

public:
/**
 * constructores con parámetros
 * inicializa el estado de los atributos
 * @param l Ebook prestado
 * @param a Alumno que realiza el préstamo
 * @param d Días del préstamo
 */
    // Constructor
    PrestamoEbook();
    PrestamoEbook(Ebook l, Alumno a, int d);

    //Setter y Getter
    void setDias(int d);
    int getDias() const;

    /**
     * genera reporte del préstamo en formato string
     * @return string con la info del préstamo
     * llama a toString() de Ebook y Alumno
     */
    // Método
    string toString() const;
};

// Implementación

PrestamoEbook::PrestamoEbook() : libro(), alumno() {
    dias = 0;
}

PrestamoEbook::PrestamoEbook(Ebook l, Alumno a, int d) {
    libro = l;
    alumno = a;
    dias = d;
}

void PrestamoEbook::setDias(int d) {
     dias = d; 
}
int PrestamoEbook::getDias() const {
     return dias;
}
/**
 * Este método implementa la agregacion mediante la 
 * tecnica de delegación, llamando a los métodos toString()
 * de los objetos Ebook y Alumno que forman parte del préstamo.
 */
string PrestamoEbook::toString() const {
    stringstream aux;
    aux << "Préstamo a: " << alumno.toString() 
    << " de: " << libro.toString() << "Por: " << dias << " días.";
    return aux.str();
}

#endif
