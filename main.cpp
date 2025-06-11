#include "Hotel.h"
#include "Recepcionista.h"
#include "Limpieza.h"
#include "Cuarto.h"
#include "Huesped.h"
#include <iostream>
using namespace std;

void mostrarMenu() {
    cout << endl;
    cout << "------------------------" << endl;
    cout << "---- Menú Principal ----" << endl;
    cout << "1. Crear objeto" << endl;
    cout << "2. Usar objeto" << endl;
    cout << "3. Eliminar objeto" << endl;
    cout << "4. Asignar huésped a cuarto" << endl;
    cout << "5. Mostrar información del hotel" << endl;
    cout << "0. Salir" << endl;
    cout << "Seleccione una opción: " << endl;
}

int main() {

    Hotel *hotel = nullptr;
    int NUM_CUARTOS = 10;

    cout << "¿Desea usar el hotel por defecto? (s/n): ";
    char resp;
    cin >> resp;
    cin.ignore();

    // Si el usuario quiere usar el hotel por defecto
    if (resp == 's' || resp == 'S') {
        NUM_CUARTOS = 10;
        Cuarto *cuartos[NUM_CUARTOS];
        for (int i = 0; i < NUM_CUARTOS; i++) {
            if (i % 2 == 0)
                cuartos[i] = new Cuarto(i, "Sencillo", 200.0 + i);
            else
                cuartos[i] = new Cuarto(i, "Doble", 300.0 + i);
        }
        hotel = new Hotel("ITC Inn", "Constituyentes 4, Qro 76695", NUM_CUARTOS, 20, 20, cuartos);
    } else {
        string nombre, direccion;
        int numCuartos, numEmpleados, numHuespedes;
        cout << "Nombre del hotel: ";
        getline(cin, nombre);
        cout << "Dirección del hotel: ";
        getline(cin, direccion);
        cout << "Número de cuartos: ";
        cin >> numCuartos;
        cout << "Número máximo de empleados: ";
        cin >> numEmpleados;
        cout << "Número máximo de huéspedes: ";
        cin >> numHuespedes;
        
        // crear cuartos
        Cuarto *cuartos[numCuartos];
        int cuartosCreados = 0;
        while (cuartosCreados < numCuartos) {
            string tipo;
            double tarifa;
            int cantidad;
            cout << "Tipo de cuarto: ";
            cin.ignore();
            getline(cin, tipo);
            cout << "Tarifa para cuartos tipo " << tipo << ": ";
            cin >> tarifa;
            cout << "¿Cuántos cuartos de este tipo? (quedan " << (numCuartos - cuartosCreados) << "): " << endl;
            cin >> cantidad;
            cin.ignore();
            if (cantidad > (numCuartos - cuartosCreados))
                cantidad = numCuartos - cuartosCreados;
            for (int i = 0; i < cantidad; ++i) {
                cuartos[cuartosCreados] = new Cuarto(cuartosCreados, tipo, tarifa);
                cuartosCreados++;
            }
        }
        hotel = new Hotel(nombre, direccion, numCuartos, numEmpleados, numHuespedes, cuartos);
        NUM_CUARTOS = numCuartos;
    }
    cout << "------ Hotel creado con éxito-------" << endl;
    hotel->muestraHotel();

    // Loop de menu
    int opcion = -1;
    while (opcion != 0) {
        mostrarMenu();
        cin >> opcion;
        cin.ignore();
        switch (opcion) {
        case 1: {
            cout << "\n1. Empleado\n2. Huésped\nSeleccione tipo de objeto a crear: ";
            int tipo;
            cin >> tipo;
            cin.ignore();
            if (tipo == 1) {
                cout << "1. Recepcionista\n2. Limpieza\nSeleccione tipo de empleado: ";
                int tipoEmp;
                cin >> tipoEmp;
                cin.ignore();
                int id;
                string nombre;

                cout << "ID: ";
                cin >> id;
                cin.ignore();
                cout << "Nombre: ";
                getline(cin, nombre);
                Empleado *emp = nullptr;

                if (tipoEmp == 1){
                    emp = new Recepcionista(id, nombre);
                }
                else if (tipoEmp == 2){
                    emp = new Limpieza(id, nombre);
                }
                else {
                    cout << "Tipo de empleado inválido.\n";
                    break;
                }
                hotel->agregarEmpleado(emp);
                cout << "Empleado creado y agregado al hotel.\n";
            } else if (tipo == 2) {
                string nombre, correo, telefono;
                double dinero;
                cout << "Nombre: ";
                getline(cin, nombre);
                cout << "Correo: ";
                getline(cin, correo);
                cout << "Teléfono: ";
                getline(cin, telefono);
                cout << "Dinero: ";
                cin >> dinero;
                cin.ignore();
                Huesped *h = new Huesped(nombre, correo, telefono, dinero);
                hotel->registrarHuesped(h);
                cout << "Huésped creado y registrado.\n";
            } else {
                cout << "Tipo de objeto inválido.\n";
            }
            break;
        }
        case 2: { // Usar objeto

            int id;
            cout << "Ingrese el ID del empleado: ";
            cin >> id;
            cin.ignore();
            Empleado **empleados = hotel->getEmpleados();
            bool encontrado = false;
            for (int i = 0; i < hotel->getNumCuartos(); i++) {
                if (empleados[i] && empleados[i]->getID() == id) {
                    empleados[i]->mostrarInfo();
                    empleados[i]->trabajar();
                    encontrado = true;
                    break;
                }
            }
            if (!encontrado) {
                cout << "Empleado no encontrado.\n";
            }
            break;
        }
        case 3: { // Eliminar objeto
            cout << "\n1. Empleado\n2. Huésped\nSeleccione tipo de objeto a eliminar: ";
            int tipo;
            cin >> tipo;
            cin.ignore();
            if (tipo == 1) {
                int id;
                cout << "Ingrese el ID del empleado a eliminar: ";
                cin >> id;
                cin.ignore();
                hotel->eliminarEmpleado(id);
                cout << "Empleado eliminado.\n";
            } else if (tipo == 2) {
                string correo;
                cout << "Ingrese el correo del huésped a eliminar: ";
                getline(cin, correo);
                hotel->eliminarHuesped(correo);
                cout << "Huésped eliminado.\n";
            } else {
                cout << "Tipo de objeto inválido.\n";
            }
            break;
        }
        case 4: { // Asignar huésped a cuarto
            string correo;
            int numCuarto;
            cout << "Correo del huésped: "; getline(cin, correo);
            cout << "Número de cuarto: "; cin >> numCuarto; cin.ignore();
            Huesped** huespedes = hotel->getHuespedes();
            Huesped* h = nullptr;
            for (int i = 0; i < 20; i++) {
                if (huespedes[i] && huespedes[i]->getCorreo() == correo) {
                    h = huespedes[i];
                    break;
                }
            }
            if (h == nullptr) {
                cout << "Huésped no encontrado.\n";
                break;
            }
            hotel->alquilarCuarto(h, numCuarto);
            break;
        }
        case 5:{
            // Mostrar información del hotel
            hotel->muestraHotel();
            cout << "\n--- Empleados ---\n";
            Empleado** empleados = hotel->getEmpleados();
            for (int i = 0; i < 20; i++) {
                if (empleados[i] != nullptr) {
                    empleados[i]->mostrarInfo();
                } 
            }

            cout << "\n--- Huéspedes ---\n";
            Huesped** huespedes = hotel->getHuespedes();
            for (int i = 0; i < 20; i++) {
                if (huespedes[i] != nullptr) {
                    huespedes[i]->mostrarInfo();
                    
                }
            }

            cout << "\n--- Cuartos ---\n";
            Cuarto** cuartos = hotel->getCuartos();
            for (int i = 0; i < NUM_CUARTOS; i++) {
                if (cuartos[i]!=nullptr) {
                    cuartos[i]->mostrarInfo();
                }
            }
            break;
        }
        case 0:{
            cout << "Saliendo del programa..." << endl;
            break;
        }
        default:{
            cout << "Opción inválida." << endl;
            break;
        }
    }
}
    return 0;
}

// Empleados
/*
    Recepcionista* recep1 = new Recepcionista(1, "Ana");
    Recepcionista* recep2 = new Recepcionista(2, "Luis");
    Limpieza* limp1 = new Limpieza(3, "Maria");
    Limpieza* limp2 = new Limpieza(4, "Pedro");

    // Huespedes
    Huesped* guest1 = new Huesped("Carlos", "carlos@hotmail.com", "444-1111", 50000.0);
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

    // Info del hotel y empleados y polimorfismo
    hotel->muestraHotel();
    cout << "       ------------" << endl;
    cout << "       Empleados     " << endl;
    for (int i = 0; i < 10; i++) {
        if (hotel->getEmpleados()[i]) {

            hotel->getEmpleados()[i]->mostrarInfo();
            hotel->getEmpleados()[i]->trabajar(); // Simular trabajo
            cout << "Rol: " << hotel->getEmpleados()[i]->obtenerRol() << endl;
        }
    }

    // Cuartos
    cout << "------------" << endl;
    cout << "    Cuartos     " << endl;
    for (int i = 0; i < 10; i++) {
        if (hotel->getCuartos()[i]) hotel->getCuartos()[i]->mostrarInfo();
    }

    // Registrar huéspedes (todavía sin cuarto)
    //hotel->registrarHuesped(guest1);
    //hotel->registrarHuesped(guest2);

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
    guest2->setDinero(10000); // Le damos dinero
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

    cout << "Eliminando huésped con correo elena@hotmail.com:" << endl;
    hotel->eliminarHuesped("elena@hotmail.com");



    // Probar alquilar cuarto fuera de rango
    cout << "Intentando alquilar cuarto fuera de rango:" << endl;
    hotel->alquilarCuarto(guest1, 20);
 */