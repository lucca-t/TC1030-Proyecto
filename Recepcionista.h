/*
 *
 * Proyecto Hotel clase Recepcionista
 * Lucca Traslosheros Abascal
 * A01713944
 * 11/6/2025
 * version: 1
 * Esta clase define el objeto Recepcionista, que hereda de Empleado.
 * Representa a un empleado encargado de la recepción en el hotel,
 * con atributos adicionales como llamadas atendidas y reservaciones hechas.
 * Incluye métodos para trabajar, agregar llamadas, agregar reservaciones y mostrar información.
 */

#ifndef RECEPCIONISTA_H
#define RECEPCIONISTA_H

#include "Empleado.h"
#include <iostream>
using namespace std;

// Declaración de la clase Recepcionista que hereda de Empleado
class Recepcionista : public Empleado {
private:
    // Variables de instancia privadas
    int llamadasAtendidas;
    int reservacionesHechas;

public:
    // Constructor que inicializa los atributos y llama al constructor base
    Recepcionista(int id, string nombre): 
        llamadasAtendidas(0), reservacionesHechas(0), Empleado(id, nombre) {}

    // Métodos de acceso (getters)
    int getLlamadas(){ 
        return llamadasAtendidas; 
    }

    int getReservaciones(){ 
        return reservacionesHechas;
    }

    // Métodos modificadores
    void addLlamada(){
        llamadasAtendidas++;
    }

    void addReservacion(){
        reservacionesHechas++;
    }

    // Sobreescritura de la clase base Empleado
    // Implementación del método abstracto mostrarInfo
    void mostrarInfo(){
        cout << "Soy un(a) " << obtenerRol() << ", me llamo " << nombre 
        << " con " << llamadasAtendidas << " llamadas atendidas y " 
        << reservacionesHechas << " reservaciones agendadas." << endl;
    }

    // Implementación del método abstracto trabajar
    void trabajar() {
        cout << "Reservo una recamara" << endl;
        llamadasAtendidas++;
        reservacionesHechas++;
    }

    // Implementación del método abstracto obtenerRol
    string obtenerRol(){
        return "Recepcionista";
    }
};

#endif