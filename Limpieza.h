/*
 *
 * Proyecto Hotel clase Limpieza
 * Lucca Traslosheros Abascal
 * A01713944
 * 11/6/2025
 * version: 1
 * Esta clase define el objeto Limpieza, que hereda de Empleado.
 * Representa a un empleado encargado de la limpieza en el hotel, 
 * con atributos adicionales como cuartos limpiados y suministros.
 * Incluye métodos para trabajar, reponer suministros y mostrar información.
 */

#ifndef LIMPIEZA_H
#define LIMPIEZA_H

#include "Empleado.h"
#include <iostream>
using namespace std;

// Declaración de la clase Limpieza que hereda de Empleado
class Limpieza: public Empleado {
private:
    // Variables de instancia privadas
    int cuartosLimpiados;
    int suministros;
public:
    // Constructor que inicializa los atributos y llama al constructor base
    Limpieza(int id, string nombre): Empleado(id, nombre) {
        this->cuartosLimpiados = 0;
        this->suministros = 10;
    }

    // Métodos de acceso (getters)
    int getNumLimpiados() {
        return cuartosLimpiados;
    }

    int getSuministros() {
        return suministros;
    }

    // Método para reponer suministros
    void reponerSuministros() {
        cout << "Suministros repuestos" << endl;
        suministros = 10;
    }

    // Sobreescritura de la clase base Empleado
    // Implementación del método abstracto trabajar
    void trabajar() {
        if (suministros == 0) {
            cout << "Suministros agotados, repoblar suministros por favor." << endl;
        } else {
            suministros -= 1;
            cuartosLimpiados++;
            cout << "Cuarto limpiado" << endl;
        }
    }

    // Implementación del método abstracto obtenerRol
    string obtenerRol() {
        return "Limpieza";
    }

    // Implementación del método abstracto mostrarInfo
    void mostrarInfo() {
        cout << "Soy " << this->obtenerRol() << ", me llamo " 
             << nombre << " con " << suministros 
             << " suministros y " << cuartosLimpiados 
             << " cuartos limpiados." << endl;
    }
};

#endif