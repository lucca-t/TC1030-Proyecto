/*
 *
 * Proyecto Hotel clase Hotel
 * Lucca Traslosheros Abascal
 * A01713944
 * 11/6/2025
 * version: 1
 * Esta clase define el objeto Hotel, que administra la gestión de cuartos, empleados y huéspedes.
 * Incluye métodos para agregar, eliminar, buscar y mostrar información de empleados, huéspedes y cuartos,
 * así como para asignar cuartos y realizar cobros.
 */

#ifndef HOTEL_H
#define HOTEL_H

#include "Cuarto.h"
#include "Empleado.h"
#include "Huesped.h"
#include <iostream>
using namespace std;

// Declaración de la clase Hotel
class Hotel {
private:
    static const int MAX = 100;
    string nombre;
    string direccion;
    int numCuartos, numEmpleados, numHuespedes;
    int contCuartos, contEmpleados, contHuespedes;
    // Arreglos de apuntadores para cuartos, empleados y huéspedes
    Cuarto* cuartos[MAX];
    Empleado* empleados[MAX];
    Huesped* huespedes[MAX];

public:
    // Constructores con sobrecarga
    Hotel()
        : nombre(""), direccion(""), numCuartos(100), numEmpleados(100),
          numHuespedes(100), contCuartos(0), contEmpleados(0), contHuespedes(0)
    {
        for (int i = 0; i < MAX; i++) cuartos[i] = nullptr;
        for (int i = 0; i < MAX; i++) empleados[i] = nullptr;
        for (int i = 0; i < MAX; i++) huespedes[i] = nullptr;
    }

    Hotel(string nombre, string direccion, int numCuartos, int numEmpleados,
          int numHuespedes, Cuarto* cuartosSet[])
        : nombre(nombre), direccion(direccion), contCuartos(0),
          contEmpleados(0), contHuespedes(0),
          numCuartos(numCuartos), numEmpleados(numEmpleados),
          numHuespedes(numHuespedes)
    {
        for (int i = 0; i < numCuartos; i++) cuartos[i] = cuartosSet[i];
        for (int i = 0; i < numEmpleados; i++) empleados[i] = nullptr;
        for (int i = 0; i < numHuespedes; i++) huespedes[i] = nullptr;
    }

    // Métodos de acceso (getters)
    string getNombre()  { return nombre; }
    string getDireccion()  { return direccion; }
    Cuarto** getCuartos() { return cuartos; }
    Empleado** getEmpleados() { return empleados; }
    Huesped** getHuespedes() { return huespedes; }
    int getNumCuartos() { return numCuartos; }
    int getNumEmpleados() { return numEmpleados; }
    int getNumHuespedes() { return numHuespedes; }

    /**
     * alquilarCuarto asigna un huésped a un cuarto si está disponible y realiza el cobro.
     * @ param huesped Puntero al huésped.
     * @ param numeroCuarto Número de cuarto a asignar.
     * 
     */
    void alquilarCuarto(Huesped* huesped, int numeroCuarto){
        if (numeroCuarto < numCuartos) {
            // si se cobro con exito, agregamos huesped a sistema
            // checara si cuarto existe y esta disponible
            if (cobrar(huesped, numeroCuarto)) {
                cout << "Cuarto ocupado exitosamente" << endl;
                huespedes[numeroCuarto] = huesped;
                cuartos[numeroCuarto]->ocupar();
                for (int i = 0; i < numEmpleados; i++){
                    if (empleados[i] != nullptr && empleados[i]->obtenerRol() == "Recepcionista") {
                        // Si el empleado es recepcionista, lo asignamos al cuarto
                        cout << "Recepcionista asignado al cuarto." << endl;
                        empleados[i]->trabajar(); // Simula el trabajo del recepcionista
                        return;
                    }
                }
            }
            else {
                cout << "No se pudo cobrar al huesped" << endl;
                return; // si no se pudo cobrar no se ocupa el cuarto
            }
        }
        else {
            cout << "Operación fracasó" << endl;
        }
    }

    /**
     * cobrar descuenta la tarifa del cuarto al huésped si hay fondos y el cuarto está disponible.
     * @ param huesped Puntero al huésped.
     * @ param numeroCuarto Número de cuarto.
     * @ return true si el cobro fue exitoso, false en caso contrario.
     */
    bool cobrar(Huesped* huesped, int numeroCuarto){
        //  Checar si exista y esta disponible para cobrar
        if ((cuartos[numeroCuarto] != nullptr)
        && cuartos[numeroCuarto]->estaDisponible()) {
            // cobrar al huesped da bool si se cobro exitosamente
            if (huesped->cobrar(cuartos[numeroCuarto]->getTarifa())) {
                cout << "Cobro exitosamente" << endl;
                return true;
            }
            else {
                cout << "Transacción rechazada por falta de fondos" << endl;
                return false;
            }
        }
        else if (cuartos[numeroCuarto] == nullptr) {
            cout << "Cuarto no existe para cobrar" << endl;
            return false;
        }
        else {
            cout << "Cuarto esta ocupado" << endl;
            return false;
        }
    }


    void darSalidaHuesped(string correo){
        // Buscar al huésped por nombre
        for (int i = 0; i < numHuespedes; i++) {
            if (huespedes[i] != nullptr && huespedes[i]->getNombre() == correo) {
                // Liberar el cuarto asignado al huésped
                for (int j = 0; j < numCuartos; j++) {
                    if (cuartos[j] != nullptr && !cuartos[j]->estaDisponible()) {
                        cuartos[j]->liberar();
                        cout << "Huésped " << correo << " ha salido del hotel." << endl;
                        for(int i = 0 ; i < numEmpleados; i++) {
                            if(empleados[i] != nullptr && empleados[i]->obtenerRol() == "Limpieza") {
                                empleados[i]->trabajar(); // Simula el trabajo del empleado de limpieza
                                return;
                            }    
                        }    
                    return;
                    }
                }
            }
        }
        cout << "Huésped no encontrado." << endl;
    }
    //  Checar si hay espacio, y agregar en el primer espacio disponible
    //  Agrega un empleado si no hay duplicados por ID y hay espacio
    void agregarEmpleado(Empleado* empleado) {
        // Checar duplicados usando ID
        for (int i = 0; i < contEmpleados; i++) {
            if (empleados[i] != nullptr &&
                empleados[i]->getID() == empleado->getID()) {
                cout << "El empleado ya está registrado." << endl;
                return;
            }
        }
        if (contEmpleados < numEmpleados) {
            empleados[contEmpleados++] = empleado;
            cout << "Empleado creado y agregado al hotel.\n";
            return;
        } else {
            cout << "No hay espacio para más empleados." << endl;
            return;
        }
    }

    //  Usando ID encontramos y borramos el empleado
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

    /**
     * registrarHuesped agrega un huésped si no hay duplicados por correo y hay espacio.
     * @ param huesped Puntero al huésped a registrar.
     */
    void registrarHuesped(Huesped* huesped) {
        // Checar duplicados usando correo
        for (int i = 0; i < contHuespedes; i++) {
            if (huespedes[i] != nullptr &&
                huespedes[i]->getCorreo() == huesped->getCorreo()) {
                cout << "El huésped ya está registrado." << endl;
                return;
            }
        }
        if (contHuespedes < numHuespedes) {
            huespedes[contHuespedes++] = huesped;
            cout << "Huésped creado y registrado.\n";
        } else {
            cout << "No hay espacio para más huéspedes." << endl;
        }
    }

    /**
     * eliminarHuesped elimina un huésped por correo.
     * @ param correo Correo del huésped a eliminar.
     * @ return true si se eliminó, false si no se encontró.
     */
    bool eliminarHuesped(string correo){
        for (int i = 0; i < numHuespedes; i++) {
            if (huespedes[i] != nullptr && huespedes[i]->getCorreo() == correo) {
                delete huespedes[i];
                huespedes[i] = nullptr;
                cout << "Huesped eliminado exitosamente." << endl;

                return true;
            }
        }
        cout << "Huesped no encontrado." << endl;
        return false;
    }

    /**
     * huespedRegistrado verifica si un huésped ya está registrado por correo.
     * @ param huesped Puntero al huésped.
     * @ return true si ya está registrado, false si no.
     */
    bool huespedRegistrado(Huesped* huesped) {
        for (int i = 0; i < numHuespedes; i++) {
            if (huespedes[i] != nullptr &&
                huespedes[i]->getCorreo() == huesped->getCorreo()) {
                return true;
                
            }
        }
        return false;
    }

    /**
     * buscarEmpleado busca un empleado por ID.
     * @ param id ID del empleado.
     * @ return Puntero al empleado si se encuentra, nullptr si no.
     */
    Empleado* buscarEmpleado(int id) {
        for (int i = 0; i < numEmpleados; i++) {
            if (empleados[i] && empleados[i]->getID() == id) {
                return empleados[i];
            }
        }
        return nullptr;
    }

    /**
     * buscarHuesped busca un huésped por correo.
     * @ param correo Correo del huésped.
     * @ return Puntero al huésped si se encuentra, nullptr si no.
     */
    Huesped* buscarHuesped(string correo) {
        for (int i = 0; i < numHuespedes; i++) {
            if (huespedes[i] && huespedes[i]->getCorreo() == correo) {
                return huespedes[i];
            }
        }
        return nullptr;
    }

    /**
     * muestraHotel imprime la información general del hotel, 
     * incluyendo huéspedes, cuartos y empleados.
     */
    void muestraHotel() {
        cout << "Hotel: " << nombre << endl;
        cout << "Dirección: " << direccion << endl;

        cout << "Lista de huéspedes:" << endl;
        for (int i = 0; i < numHuespedes; i++) {
            if (huespedes[i] != nullptr) {
                huespedes[i]->mostrarInfo();
            }
        }
        cout << "Lista de cuartos:" << endl;
        for (int i = 0; i < numCuartos; i++) {
            if (cuartos[i] != nullptr) {
                cuartos[i]->mostrarInfo();
            }
        }
        cout << "Lista de empleados:" << endl;
        for (int i = 0; i < numEmpleados; i++) {
            if (empleados[i] != nullptr) {
                empleados[i]->mostrarInfo();
            }
        }
    }
};

#endif