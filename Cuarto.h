/*
 *
 * Proyecto Hotel clase Cuarto
 * Lucca Traslosheros Abascal
 * A01713944
 * 11/6/2025
 * version: 1
 * Esta clase define el objeto Cuarto, que representa un cuarto de hotel con sus atributos
 * principales como número, tipo, tarifa y disponibilidad. Incluye métodos para modificar y
 * consultar el estado del cuarto.
 */

#ifndef CUARTO_H
#define CUARTO_H

#include "Huesped.h"
#include <iostream>
using namespace std;

// Declaración de la clase Cuarto
class Cuarto {
private:
    // Variables de instancia privadas
    int numero;
    string tipo;
    double tarifa;
    bool disponible;

public:
    // Constructores
    Cuarto(): numero(0), tipo(""), tarifa(0.0), disponible(true) {}
    Cuarto(int numero, string tipo, double tarifa): numero(numero), 
    tipo(tipo), tarifa(tarifa), disponible(true) {}

    // Métodos de acceso (getters)
    bool estaDisponible() {
        return disponible;
    }

    int getNumero() {
        return numero;
    }

    string getTipo() {
        return tipo;
    }

    double getTarifa() {
        return tarifa;
    }

    // Métodos modificadores (setters)
    void setTarifa(double tarifa) {
        this->tarifa = tarifa;
    }

    void setTipo(string tip) {
        this->tipo = tip;
    }

    void setNumero(int num) {
        this->numero = num;
    }

    // Ocupar cuarto
    bool ocupar() {
        if (disponible) {
            disponible = false;
            return true;
        } else
            return false;
    }

    // liberar cuarto
    void liberar() {
        disponible = true;
    }

    // Método para mostrar información del cuarto
    void mostrarInfo() {
        cout << "Cuarto # : " << numero;
        cout << "  Tipo de cuarto: " << tipo;
        cout << "  Tarifa: $" << tarifa;
        // Mostrar si está disponible o no
        cout << "  Disponible: " << (disponible ? "Sí" : "No") << endl;
    }
};

#endif