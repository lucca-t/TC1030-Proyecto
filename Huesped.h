#ifndef HUESPED_H
#define HUESPED_H

#include <iostream>
using namespace std;


class Huesped{
private:
    string nombre, correo, telefono;
    double dinero;

public:
//constructors
    Huesped(): nombre(""), correo(""), telefono(""){}

    Huesped(string nombre, string correo, string telefono, double dinero): nombre(nombre), correo(correo), telefono(telefono), dinero(dinero){}
//modificadores de acceso

    string getNombre(){
        return nombre;
    }

    string getCorreo(){
        return correo;
    }    

    string getTelefono(){
        return telefono;
    }    
    
    double getDinero(){
        return dinero;
    }  

    void setNombre(string nombre){
        this->nombre = nombre;
    }

    void setCorreo(string correo){
        this->correo = correo;
    }

    void setTelefono(string telefono){
        this->telefono = telefono;
    }

    void setDinero(double dinero){
        this->dinero = dinero;
    }

    bool cobrar(double tarifa){
        //checar si tienen suficiente dinero
        // regresar true si la transaccion fue exitosa
        if(dinero > tarifa){
            this -> dinero -= tarifa;
            return true;
        }
        else 
            return false;
        
    }

    void mostrarInfo(){
        cout <<  "Mi nombre es "  << nombre << ", mi correo es " << correo << " y mi telefono es: " << telefono << endl;
    }

};

#endif

