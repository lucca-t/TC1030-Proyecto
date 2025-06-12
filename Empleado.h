/*
 * Proyecto Hotel clase Empleado
 * Lucca Traslosheros Abascal
 * A01713944
 * 11/6/2025
 * version: 1
 * Esta clase define el objeto abstracto Empleado, que sirve como base para otros tipos de empleados
 * Incluye atributos como id, nombre, salario y turno, así como métodos para acceder y modificar
 * estos atributos. Define métodos virtuales puros para trabajar, mostrar información y obtener el rol,
 * que deben ser implementados por las clases hijas.
 */

#ifndef EMPLEADO_H
#define EMPLEADO_H

#include <iostream>
using namespace std;

// Declaración de la clase abstracta Empleado
class Empleado {
protected:
    // Declaro variables de instancia protegidos
    int id;
    string nombre;
    double salario;
    string turno;

public:
    // Constructores incluyendo sobrecarga 
    Empleado(int id, string nombre, double salario, string turno): id(id), 
        nombre(nombre), salario(salario), turno(turno) {}

    Empleado(int id, string nombre): id(id), nombre(nombre) {}

    Empleado(): id(0), nombre("") {}

    // Métodos de acceso (getters)
    int getID() { // El ID no cambia después de asignarse
        return id;
    }

    string getNombre() {
        return nombre;
    }

    string getTurno() {
        return turno;
    }
    
    double getSalario() {
        return salario;
    }

    // Métodos modificadores (setters)
    void setNombre(string nombre) {  
        this->nombre = nombre;
    }

    void setTurno(string turno) {
        this->turno = turno;
    }
    
    void setSalario(double salario) {
        this->salario = salario;
    }

    // Métodos virtuales puros (abstractos)

    /** 
     * Método virtual puro que debe ser implementado por las clases hijas.
     * Es en la manera que el empleado realiza su trabajo específico.  
     * @ param
     * @ return void imprime el trabajo realizado.
     */
    virtual void trabajar() = 0;


    /** 
     * Método virtual puro que debe ser implementado por las clases hijas.
     * Muestra información específica del empleado, como su rol y estadísticas.
     * @ param
     * @ return void imprime la información del empleado.
     */
    virtual void mostrarInfo() = 0;

    /** 
     * Método virtual puro que debe ser implementado por las clases hijas.
     * Devuelve el rol del empleado, como "Recepcionista" o "Limpieza".
     * @ param
     * @ return string que representa el rol del empleado.
     */
    virtual string obtenerRol() = 0;

};

#endif
