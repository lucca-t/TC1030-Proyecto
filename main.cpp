#include "Empleado.h"
#include "Recepcionista.h"
#include "Limpieza.h"

#include <iostream>
using namespace std;

int main(){
    Recepcionista Lucca = Recepcionista(100, "Lucca");
    cout << "Testing herencia" << endl;
    Lucca.mostrarInfo();
    
    cout << "-------------" << endl;
    for(int i = 0; i < 5; i++){Lucca.trabajar();}
    Lucca.addLlamada();
    Lucca.addLlamada();

    Lucca.mostrarInfo();
    
    cout << "-------------" << endl;
    Limpieza Oscar = Limpieza(123, "Oscar");
    Oscar.mostrarInfo();
    cout << "-------------" << endl;

    for(int i = 0; i < 11; i++){
        Oscar.trabajar();
    }

    cout << "-------------" << endl;
    Oscar.mostrarInfo();
    Oscar.reponerSuministros();
    Oscar.trabajar();

    cout << "-------------" << endl;
    Oscar.mostrarInfo();
    return 0;
}