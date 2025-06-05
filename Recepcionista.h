#ifndef RECEPCIONISTA_H
#define RECEPCIONISTA_H

#include "Empleado.h"
#include <iostream>
using namespace std;

class Recepcionista : public Empleado{
private:
    int llamadasAtendidas;
    int reservacionesHechas;

public:
    // constructor
    Recepcionista(int id, string nombre) : llamadasAtendidas(0), reservacionesHechas(0), Empleado(id, nombre) {}

    // modificadores de acceso
    int getLlamadas(){ 
        return llamadasAtendidas; 
    }

    int getReservaciones(){ 
        return reservacionesHechas;
    }

    void addLlamada(){
        llamadasAtendidas++;
    }

    void addReservacion(){
        reservacionesHechas++;
    }

    void mostrarInfo(){
        cout << "Soy un(a) " << this->obtenerRol() << ", me llamo " << this->nombre << " con " << llamadasAtendidas << " llamadas atendidas y " << reservacionesHechas << " reservaciones agendadas." << endl;
    }

    void trabajar()
    {
        cout << "Reservo una recamara" << endl;
        llamadasAtendidas++;
        reservacionesHechas++;
    }

    string obtenerRol(){
        return "Recepionista";
    }
};
#endif