#ifndef HOTEL_H
#define HOTEL_H

#include "Cuarto.h"
#include "Empleado.h"
#include "Huesped.h"
#include <iostream>
using namespace std;

class Hotel {
private:
    static const int MAX = 100;
    string nombre;
    string direccion;
    int numCuartos,numEmpleados,numHuespedes;
    int contCuartos,contEmpleados,contHuespedes;
    //tamaño de los arreglos, y los arreglos de apuntadores para todo
    Cuarto* cuartos[MAX];      
    Empleado* empleados[MAX];  
    Huesped* huespedes[MAX];   

public:
    Hotel()
        : nombre(""), direccion(""), numCuartos(100), numEmpleados(100), numHuespedes(100), contCuartos(0), contEmpleados(0), contHuespedes(0)
    {
        for (int i = 0; i < MAX; i++) cuartos[i] = nullptr;
        for (int i = 0; i < MAX; i++) empleados[i] = nullptr;
        for (int i = 0; i < MAX; i++) huespedes[i] = nullptr;

    }


    Hotel(string nombre, string direccion, int numCuartos, int numEmpleados, int numHuespedes, Cuarto* cuartosSet[])
        : nombre(nombre), direccion(direccion), contCuartos(0), contEmpleados(0), contHuespedes(0), 
        numCuartos(numCuartos), numEmpleados(numEmpleados), numHuespedes(numHuespedes)
    {
        for (int i = 0; i < numCuartos; i++) cuartos[i] = cuartosSet[i];
        for (int i = 0; i < numEmpleados; i++) empleados[i] = nullptr;
        for (int i = 0; i < numHuespedes; i++) huespedes[i] = nullptr;
    }

    // Getters
    string getNombre() const {
        return nombre;
    }

    string getDireccion() const {
        return direccion;
    }

    Cuarto** getCuartos() {
        return cuartos;
    }

    Empleado** getEmpleados() {
        return empleados;
    }

    Huesped** getHuespedes() {
        return huespedes;
    }

    void alquilarCuarto(Huesped* huesped, int numeroCuarto){

        if((numeroCuarto < numCuartos) && (huesped, numeroCuarto)){
            // si se cobro con exito, agregamos huesped a sistema
            // y cuarto ya no esta disponible
            huespedes[numeroCuarto] = huesped;
            cuartos[numeroCuarto]->ocupar();
        }
        else{
            cout << "Operación fracasó" << endl;
        }
    }   


    // asumiendo que esta disponible, cobrar al huesped, true si exitoso falso si no
    bool cobrar(Huesped* huesped, int numeroCuarto){
        // checar si exista y esta disponible para cobrar
        if( (cuartos[numeroCuarto]!= nullptr) && cuartos[numeroCuarto]->estaDisponible()){
            // cobrar al huesped da bool si se cobro exitosamente
            if( huesped->cobrar(cuartos[numeroCuarto]->getTarifa()) ) {
                cout << "Cobro exitosamente" << endl;
                return true;
            }
            else{
                cout << "Transacción rechazada por falta de fondos" << endl;
                return false;
            }
        }
        else if (cuartos[numeroCuarto]== nullptr) {
            cout << "Cuarto no existe para cobrar" << endl;
            return false;
        }
        else {
            cout << "Cuarto esta ocupado" << endl;
            return false;
        }
    }



    //checar si hay espacio, y agregar en el primer espacio disponible
    // si esta lleno imprimir error
    void agregarEmpleado(Empleado* empleado) {
        if(contEmpleados < numHuespedes){
            empleados[contEmpleados++] = empleado;
        }else{
        cout << "No hay espacio para más empleados." << endl;
        }
    }

    //usando ID encontramos y borramos el empleado
    void eliminarEmpleado(int id) {
        for (int i = 0; i < numEmpleados; i++) {
            if (empleados[i] != nullptr && empleados[i]->getID() == id) {
                delete empleados[i];
                empleados[i] = nullptr;
                return;
            }
        }
        cout << "Empleado no encontrado." << endl;
    }

    void registrarHuesped(Huesped* huesped) {
        if(contHuespedes < numHuespedes){
            huespedes[contHuespedes++] = huesped;
        }else{
        cout << "No hay espacio para más huéspedes." << endl;
        }
    }
    
    void eliminarHuesped(string correo){
        for (int i = 0; i < numHuespedes; i++) {
            if (huespedes[i] != nullptr && huespedes[i]->getCorreo() == correo) {
                delete huespedes[i];
                huespedes[i] = nullptr;
                return;
            }
        }
        cout << "Huesped no encontrado." << endl;
    }


    void muestraHotel() { 
        cout << "Hotel: " << nombre << endl;
        cout << "Dirección: " << direccion << endl;
        cout << "Número de cuartos: " << numCuartos << endl;
        cout << "Número de empleados: " << numEmpleados << endl;
        cout << "Número de huéspedes: " << numHuespedes << endl;
    }
};

#endif