#ifndef LIMPIEZA_H
#define LIMPIEZA_H

#include "Empleado.h"
#include <iostream>
using namespace std;

class Limpieza: public Empleado{
private:
    int cuartosLimpiados;
    int suministros;
public:
    Limpieza(int id, string nombre): Empleado(id, nombre){
        this -> cuartosLimpiados = 0;
        this -> suministros = 10;
    }

    int getNumLimpiados(){return cuartosLimpiados;}

    int getSuministros(){
        return suministros;
    }

    void reponerSuministros(){
        cout << "Suministros repuestos" << endl;
        suministros = 10;
    }

    void trabajar() {
        if(suministros == 0){
            cout << "Suministros agotados, repoblar suministros por favor." << endl;
        }else{
        suministros-=1;
        cuartosLimpiados++;
        cout << "Cuarto limpiado" << endl;
        }
    }

    string obtenerRol() {
        return "Limpieza";
    }

    void mostrarInfo() {
        cout << "Soy "<< this->obtenerRol() << ", me llamo " << this->nombre <<   " con " << suministros 
        << " suministros y " << cuartosLimpiados << " cuartos limpiados." << endl;
    }


};

#endif