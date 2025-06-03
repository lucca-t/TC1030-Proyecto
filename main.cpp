#include "Hotel.h"
#include "Recepcionista.h"
#include "Limpieza.h"
#include "Cuarto.h" 
#include "Huesped.h"
#include <iostream>
using namespace std;

int main() {
    // Empleados
    Recepcionista* recep1 = new Recepcionista(1, "Ana");
    Recepcionista* recep2 = new Recepcionista(2, "Luis");
    Limpieza* limp1 = new Limpieza(3, "Maria");
    Limpieza* limp2 = new Limpieza(4, "Pedro");

    // Huespedes
    Huesped* guest1 = new Huesped("Carlos", "carlos@hotmail.com", "444-1111", 1000.0);
    Huesped* guest2 = new Huesped("Elena", "elena@hotmail.com", "442-2222", 50.0); // poco dinero para probar

    // Cuartos
    Cuarto* cuartos[10];
    for (int i = 0; i < 10; i++) {
        if (i % 2 == 0) {
            cuartos[i] = new Cuarto(i, "Sencillo", 200.0 + i);
        } else {
            cuartos[i] = new Cuarto(i, "Doble", 300.0 + i );
        }
    }

    // Hotel
    Hotel* hotel = new Hotel("Fiesta Inn", "Consituyentes 4, Qro 76695", 10, 10, 10, cuartos);



    // Agregar empleados
    hotel->agregarEmpleado(recep1);
    hotel->agregarEmpleado(recep2);
    hotel->agregarEmpleado(limp1);
    hotel->agregarEmpleado(limp2);

    // Info del hotel y empleados
    hotel->muestraHotel();
    cout << "------------" << endl;
    cout << "    Empleados     " << endl;
    for (int i = 0; i < 10; i++) {
        if (hotel->getEmpleados()[i]) hotel->getEmpleados()[i]->mostrarInfo();
    }

    // Cuartos
    cout << "------------" << endl;
    cout << "    Cuartos     " << endl;
    for (int i = 0; i < 10; i++) {
        if (hotel->getCuartos()[i]) hotel->getCuartos()[i]->mostrarInfo();
    }

    // Registrar huéspedes (todavía sin cuarto)
    hotel->registrarHuesped(guest1);
    hotel->registrarHuesped(guest2);

    // Carlos renta el cuarto 2 (debe funcionar)
    cout << "Carlos intenta rentar el cuarto 2:" << endl;
    hotel->alquilarCuarto(guest1, 2);

    // Elena intenta rentar el cuarto 2 (ya ocupado)
    cout << "Elena intenta rentar el cuarto 2 (ya ocupado):" << endl;
    hotel->alquilarCuarto(guest2, 2);

    // Elena intenta rentar el cuarto 3 (no le alcanza)
    cout << "Elena intenta rentar el cuarto 3 (no tiene dinero suficiente):" << endl;
    hotel->alquilarCuarto(guest2, 3);

    // Ahora sí le alcanza a Elena
    guest2->cobrar(-200); // Le damos dinero
    cout << "Elena intenta rentar el cuarto 1 (ahora sí tiene dinero):" << endl;
    hotel->alquilarCuarto(guest2, 1);

    // Mostrar huéspedes (por cuarto)
    cout << "--- Huéspedes en el hotel (por cuarto) ---" << endl;
    for (int i = 0; i < 10; i++) {
        if (hotel->getHuespedes()[i]) hotel->getHuespedes()[i]->mostrarInfo();
    }

    // Eliminar empleado y huésped
    cout << "Eliminando empleado con ID 2 (Luis):" << endl;
    hotel->eliminarEmpleado(2);

    cout << "Eliminando huésped con correo elena@mail.com:" << endl;
    hotel->eliminarHuesped("elena@mail.com");

    // Probar métodos de empleados (herencia/polimorfismo)
    cout << "--- Prueba de métodos de empleados (polimorfismo) ---" << endl;
    Empleado* empleadosPrueba[2] = {recep1, limp1};
    for (int i = 0; i < 2; i++) {
        empleadosPrueba[i]->trabajar();
        empleadosPrueba[i]->mostrarInfo();
        cout << "Rol: " << empleadosPrueba[i]->obtenerRol() << endl;
    }

    // Probar alquilar cuarto fuera de rango
    cout << "Intentando alquilar cuarto fuera de rango:" << endl;
    hotel->alquilarCuarto(guest1, 20);

    
    return 0;
}