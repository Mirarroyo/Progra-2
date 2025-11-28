#ifndef ALUMNO_H
#define ALUMNO_H
#include <iostream>
using namespace std;

class Alumno {
private:
    string nombre;
    string matricula;

public:
    // constructor
    Alumno(string n, string i){
        nombre = n;
        matricula = i;
    }

    // getters
    string getNombre() {
        return nombre;
    }
    string getMatricula() {
        return matricula;
    }

    //seteers
    void setNombre(string n) {
        nombre = n;
    }
    void setMatricula(string i) {
        matricula = i;
    }   

    //metodos
    void mostrarInfo() {
        cout << "Nombre: " << nombre << endl;
        cout << "Matricula: " << matricula << endl;
    }
};
#endif
