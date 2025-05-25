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
    int N;
    Cuarto* cuartos;
    Empleado* empleados[100];
    int numEmpleados;
    Huesped* huespedes;
    int numHuespedes;

public:
    Hotel(string nombre, string direccion, int N)
        : nombre(nombre), direccion(direccion), N(N), numEmpleados(10), numHuespedes(0)
    {
        cuartos = new Cuarto[N];
        huespedes = new Huesped[N];
    }


    void muestraHotel() {
        cout << "Hotel: " << nombre << endl;
        cout << "Dirección: " << direccion << endl;
        cout << "Número de cuartos: " << N << endl;
        cout << "Número de empleados: " << numEmpleados << endl;
        cout << "Número de huéspedes: " << numHuespedes << endl;
    }

    // Puedes agregar otros métodos según el UML si los necesitas
};

#endif