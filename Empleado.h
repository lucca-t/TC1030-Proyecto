#ifndef EMPLEADO_H
#define EMPLEADO_H

#include <iostream>
using namespace std;

class Empleado{
protected:
    int id;
    string nombre;
    double salario;
    string turno;

public:
    Empleado(int id, string nombre, double salario, string turno): id(id), 
    nombre(nombre), salario(salario), turno(turno){}

    Empleado(int id, string nombre): id(id), nombre(nombre){} 

    Empleado(): id(0), nombre(""){}


    //modificadores de acceso
    int getID(){    //no se cambia porque solo es su id y no se cambia
        return id;
    }

    string getNombre(){
        return nombre;
    }

    void setNombre(string nombre){  // tal vez se cambian el nombre
        this -> nombre = nombre;
    }

    void setTurno(string turno){
        this -> turno = turno;
    }
    
    string getTurno(){
        return turno;
    }

    virtual void trabajar() = 0;

    virtual string mostrarInfo() = 0;

    virtual string obtenerRol() = 0;

};

#endif
