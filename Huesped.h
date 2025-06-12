/*
 *
 * Proyecto Hotel clase Huesped
 * Lucca Traslosheros Abascal
 * A01713944
 * 11/6/2025
 * version: 1
 * Esta clase define el objeto Huesped, que representa a un huésped del hotel.
 * Incluye atributos como nombre, correo, teléfono y dinero disponible.
 * Proporciona métodos para modificar y consultar estos atributos, así como para
 * realizar cobros y mostrar la información del huésped.
 */

#ifndef HUESPED_H
#define HUESPED_H

#include <iostream>
using namespace std;

// Declaración de la clase Huesped
class Huesped {
private:
    // Variables de instancia privadas
    string nombre, correo, telefono;
    double dinero;

public:
    // Constructores
    Huesped(): nombre(""), correo(""), telefono(""), dinero(0.0) {}

    Huesped(string nombre, string correo, string telefono, double dinero):
        nombre(nombre), correo(correo), telefono(telefono), dinero(dinero) {}

    // Métodos de acceso (getters)
    string getNombre() {
        return nombre;
    }

    string getCorreo() {
        return correo;
    }    

    string getTelefono() {
        return telefono;
    }    
    
    double getDinero() {
        return dinero;
    }  

    // Métodos modificadores (setters)
    void setNombre(string nombre) {
        this->nombre = nombre;
    }

    void setCorreo(string correo) {
        this->correo = correo;
    }

    void setTelefono(string telefono) {
        this->telefono = telefono;
    }

    void setDinero(double dinero) {
        this->dinero = dinero;
    }

    /**
     * cobrar descuenta la tarifa del dinero del huésped si tiene suficiente.
     * @ param tarifa Monto a cobrar.
     * @ return true si la transacción fue exitosa, false si no hay suficiente dinero.
     */
    bool cobrar(double tarifa) {
        if (dinero > tarifa) {
            this->dinero -= tarifa;
            return true;
        }
        else 
            return false;
    }

    /**
     * mostrarInfo imprime la información del huésped.
     */
    void mostrarInfo() {
        cout <<  "Mi nombre es "  << nombre << ", mi correo es " << correo <<
         ", mi telefono es: " << telefono << ", tengo: $" << dinero << endl;
    }
};

#endif

