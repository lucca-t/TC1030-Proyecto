/*
 * Proyecto Hotel main
 * Lucca Traslosheros Abascal
 * A01713944
 * 11/6/2025
 *
 * Este es un proyecto para la clase TC1030 Programación Orientada a
 * Objetos. Es un programa que modela la gestión de un hotel, permitiendo
 * crear, eliminar y manipular empleados, huéspedes y cuartos, así como
 * asignar huéspedes a cuartos y mostrar información relevante del hotel.
 */

#include "Hotel.h"
#include "Recepcionista.h"
#include "Limpieza.h"
#include "Cuarto.h"
#include "Huesped.h"

#include <limits>  // para manejar errores de entrada con ints y strings
#include <iostream> // para imprimir y interactuar con menú.
using namespace std;

// Muestra el menú principal de opciones al usuario
void mostrarMenu() {
    cout << endl;
    cout << "------------------------" << endl;
    cout << "---- Menú Principal ----" << endl;
    cout << "1. Crear objeto" << endl;
    cout << "2. Trabaja empleado" << endl;
    cout << "3. Eliminar objeto" << endl;
    cout << "4. Asignar huésped a cuarto" << endl;
    cout << "5. Eliminar huésped de cuarto" << endl;
    cout << "6. Mostrar información del hotel" << endl;
    cout << "7. Mostrar información de persona" << endl;
    cout << "0. Salir" << endl;
    cout << "Seleccione una opción: " << endl;
}
/*
 * Si la entrada es inválida, muestra mensaje de error 
 * y limpia el buffer de entrada. Si no se hace esto, el programa
 * intenta checar el cin infininamente 
 */
void entryError(){  
    if (cin.fail()) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Entrada inválida. Intente de nuevo." << endl;
        return;
    }
}
int main() {
    // Puntero al objeto principal Hotel
    Hotel *hotel = nullptr;
    int num_cuartos = 10;

    // Pregunta al usuario si desea usar el hotel por defecto
    cout << "¿Desea usar el hotel por defecto? (s/n): ";
    char resp;
    cin >> resp;
    cin.ignore();

    // Si el usuario quiere usar el hotel por defecto, se inicializa con valores predefinidos
    if (resp == 's' || resp == 'S') {
        num_cuartos = 10;
        Cuarto *cuartos[num_cuartos];
        for (int i = 0; i < num_cuartos; i++) {
            if (i % 2 == 0)
                cuartos[i] = new Cuarto(i, "Sencillo", 200.0 + i);
            else
                cuartos[i] = new Cuarto(i, "Doble", 300.0 + i);
        }
        hotel = new Hotel("ITC Inn", "Constituyentes 4, Qro 76695", num_cuartos, 20, 20, cuartos);
    } else {
        // Si el usuario quiere crear un hotel personalizado
        string nombre, direccion;
        int numCuartos, numEmpleados, numHuespedes;
        cout << "Nombre del hotel: ";
        getline(cin, nombre);
        cout << "Dirección del hotel: ";
        getline(cin, direccion);
        cout << "Número de cuartos: ";
        cin >> numCuartos;
        entryError();
        cout << "Número máximo de empleados: ";
        cin >> numEmpleados;
        entryError();
        cout << "Número máximo de huéspedes: ";
        cin >> numHuespedes;
        entryError();

        // Creación de los cuartos personalizados
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
            cout << "¿Cuántos cuartos de este tipo? (quedan " << (numCuartos - cuartosCreados) << "): ";
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
            // Crear empleado o huésped
            cout << "\n1. Empleado\n2. Huésped\nSeleccione tipo de objeto a crear: ";
            int tipo;
            cin >> tipo;
            entryError();
            if (cin.fail()) break;
            cin.ignore();
            if (tipo == 1) {
                // Crear empleado (Recepcionista o Limpieza)
                cout << "1. Recepcionista\n2. Limpieza\nSeleccione tipo de empleado: ";
                int tipoEmp;
                cin >> tipoEmp;
                entryError();
                if (cin.fail()) break;
                cin.ignore();
                int id;
                string nombre;

                cout << "ID: ";
                cin >> id;
                entryError();
                if (cin.fail()) break;
                cin.ignore();
                cout << "Nombre: ";
                getline(cin, nombre);
                Empleado *emp = nullptr;

                if (tipoEmp == 1) {
                    emp = new Recepcionista(id, nombre);
                    hotel->agregarEmpleado(emp);
                    break;
                } else if (tipoEmp == 2) {
                    emp = new Limpieza(id, nombre);
                    hotel->agregarEmpleado(emp);
                    break;
                } else {
                    cout << "Tipo de empleado inválido.\n";
                    break;
                }

            } else if (tipo == 2) {
                // Crear huésped
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
                entryError();
                if (cin.fail()) break;
                cin.ignore();
                Huesped *h = new Huesped(nombre, correo, telefono, dinero);
                hotel->registrarHuesped(h);

            } else {
                cout << "Tipo de objeto inválido.\n";
            }
            break;
        }
        case 2: { // Usar objeto (solo empleados)
            int id;
            cout << "Ingrese el ID del empleado: ";
            cin >> id;
            entryError();
            if (cin.fail()) break;
            cin.ignore();
            Empleado *empleado = hotel->buscarEmpleado(id);
            if (empleado) {
                empleado->mostrarInfo();
                empleado->trabajar();
            } else {
                cout << "Empleado no encontrado.\n";
                break;
            }

            if (empleado->obtenerRol() == "Limpieza"){
                int resupply;
                cout << "¿Desea reponer suministros? (1. Sí, 2. No): ";
                cin >> resupply;
                entryError();
                if (cin.fail()) break;
                cin.ignore();
                if (resupply == 1) {
                    Limpieza *limpieza = dynamic_cast<Limpieza*>(empleado);
                    if (limpieza) {
                        limpieza->reponerSuministros();
                        limpieza->mostrarInfo();
                    } else {
                        cout << "El empleado no es de limpieza.\n";
                    }
                }
            }
            break;
        }
        case 3: { // Eliminar empleado o huésped
            cout << "\n1. Empleado\n2. Huésped\nSeleccione tipo de objeto a eliminar: ";
            int tipo;
            cin >> tipo;
            entryError();
            if (cin.fail()) break;
            cin.ignore();
            if (tipo == 1) {
                int id;
                cout << "Ingrese el ID del empleado a eliminar: ";
                cin >> id;
                entryError();
                if (cin.fail()) break;
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
            cout << "Correo del huésped: ";
            getline(cin, correo);
            cout << "Número de cuarto: ";
            cin >> numCuarto;
            entryError();
            if (cin.fail()) break;
            cin.ignore();
            Huesped *huesped = hotel->buscarHuesped(correo);
            if (huesped) {
                hotel->alquilarCuarto(huesped, numCuarto);
                break;
            } else {
                cout << "Huésped no encontrado.\n";
                break;
            }
        }
        case 5: { // Eliminar huésped de cuarto
            string correo;
            cout << "Ingrese el correo del huésped a eliminar del cuarto: ";
            getline(cin, correo);
            hotel->eliminarHuesped(correo);
            hotel->darSalidaHuesped(correo);
            break;
        }
        case 6: { // Mostrar información general del hotel
            hotel->muestraHotel();
            cout << "\n--- Huéspedes ---" << endl;
            break;
        }
        case 7: { // Mostrar información de persona específica
            cout << "\n Ingrese 1 para mostrar información de un empleado, o 2 para un huésped: ";
            int tipo;
            cin >> tipo;
            entryError();
            if (cin.fail()) break;
            cin.ignore();
            if (tipo == 1) {
                int id;
                cout << "Ingrese el ID del empleado: ";
                cin >> id;
                entryError();
                if (cin.fail()) break;
                cin.ignore();
                Empleado *empleado = hotel->buscarEmpleado(id);
                if (empleado) {
                    empleado->mostrarInfo();
                    break;
                } else {
                    cout << "Empleado no encontrado.\n";
                    break;
                }
            } else if (tipo == 2) {
                string correo;
                cout << "Ingrese el correo del huésped: ";
                getline(cin, correo);
                Huesped *huesped = hotel->buscarHuesped(correo);

                if (huesped) {
                    huesped->mostrarInfo();
                    break;
                } else {
                    cout << "Huésped no encontrado.\n";
                }
            } else {
                cout << "Tipo inválido.\n";
                break;
            }
        }
        case 0: {
            // Salir del programa
            cout << "Saliendo del programa..." << endl;
            break;
        }
        default: {
            cout << "Opción inválida." << endl;
            break;
        }
        }
    }
    return 0;
}
