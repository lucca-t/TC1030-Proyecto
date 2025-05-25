#ifndef CUARTO_H
#define CUARTO_H

#include "Huesped.h"
#include <iostream>
using namespace std;

class Cuarto{
private:
    int numero;
    string tipo;
    double tarifa;
    bool disponible;
public:
    Cuarto(): numero(0), tipo(""), tarifa(0.0), disponible(true){}

    Cuarto(int numero, string tipo, double tarifa): numero(numero), tipo(tipo), tarifa(tarifa), disponible(true){}

    bool estaDisponible(){
        return disponible;
    }

    int getNumero(){
        return numero;
    }

    string getTipo(){
        return tipo;
    }
    
    double getTarifa(){
        return tarifa;
    }

    bool ocupar(){
        //returns true si fue ocupado exitosamente y falso si no
        if(disponible){
            disponible = false;
            return true;
        }
        else
            return false;
    }

    void liberar(){
        this -> disponible = true;
    }

    void setTarifa(double tarifa){
        this -> tarifa = tarifa;
    }   

    void mostrarInfo(){
        cout << "Número de cuarto: " << numero;
        cout << "  Tipo de cuarto: " << tipo;
        cout << "  Tarifa: $" << tarifa;
        cout << "  Disponible: " << disponible << endl;
    }
    
};

#endif