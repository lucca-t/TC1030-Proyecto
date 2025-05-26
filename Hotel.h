#ifndef HOTEL_H
#define HOTEL_H

#include "Cuarto.h"
#include "Empleado.h"
#include "Huesped.h"
#include <iostream>
using namespace std;

class Hotel {
private:
    string nombre;
    string direccion;
    //tamaño de los arreglos, y los arreglos de apuntadores para todo
    int numCuartos;
    int numEmpleados;
    int numHuespedes;
    Cuarto** cuartos;      
    Empleado** empleados;  
    Huesped** huespedes;   

public:
    Hotel()
        : nombre(""), direccion(""), numCuartos(100), numEmpleados(100), numHuespedes(100)
    {
        cuartos = new Cuarto*[numCuartos];
        empleados = new Empleado*[numEmpleados];
        huespedes = new Huesped*[numHuespedes];
        for (int i = 0; i < numCuartos; i++) cuartos[i] = nullptr;
        for (int i = 0; i < numEmpleados; i++) empleados[i] = nullptr;
        for (int i = 0; i < numHuespedes; i++) huespedes[i] = nullptr;
    }


    Hotel(string nombre, string direccion, int numCuartos, int numEmpleados, int numHuespedes)
        : nombre(nombre), direccion(direccion), numCuartos(numCuartos), numEmpleados(numEmpleados), numHuespedes(numHuespedes)
    {
        cuartos = new Cuarto*[numCuartos];
        empleados = new Empleado*[numEmpleados];
        huespedes = new Huesped*[numHuespedes];
        for (int i = 0; i < numCuartos; ++i) cuartos[i] = nullptr;
        for (int i = 0; i < numEmpleados; ++i) empleados[i] = nullptr;
        for (int i = 0; i < numHuespedes; ++i) huespedes[i] = nullptr;
    }

    void alquilarCuarto(Huesped* huesped, int numeroCuarto){
        if(cobrar(huesped, numeroCuarto)){
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
        else if (cuartos[numeroCuarto]!= nullptr) {
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
        for (int i = 0; i < numEmpleados; i++) {
            if (empleados[i] == nullptr) {
                empleados[i] = empleado;
                return;
            }
        }
        cout << "No hay espacio para más empleados." << endl;
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
        for (int i = 0; i < numHuespedes; i++) {
            if (huespedes[i] == nullptr) {
                huespedes[i] = huesped;
                return;
            }
        }
        cout << "No hay espacio para más huéspedes." << endl;
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