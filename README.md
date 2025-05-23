# TC1030-Proyecto

Este proyecto modela un sistema para la gestión de un hotel mediante una estructura de clases que representa sus elementos principales:
Hotel, Cuarto, Huesped y Empleado. 
La clase Hotel administra la información de las habitaciones, los huéspedes y el personal. El hotel contiene las habitaciones como composición, y los huespedes y personal como agregación.

Cada Cuarto contiene datos específicos y mantiene una referencia al huésped que lo ocupa. 
La clase Huesped almacena los datos personales de los clientes.
Empleado es una clase abstracta que sirve como base para las subclases Recepcionista y Limpieza, las cuales implementan comportamientos específicos, demostrando el uso de herencia y polimorfismo.

El proyecto podría fallar al acceder a posiciones inválidas en los arreglos, como buscar una habitación o un huésped que no existe. También puede ocurrir un fallo si no se inicializan correctamente los atributos en los constructores, causando comportamientos inesperados. Además, la falta de validación en operaciones como eliminar empleados o registrar huéspedes puede hacer que el programa se detenga.

compilar con: "g++ Empleado.h Limpieza.h Recepcionista.h main.cpp"

correr en windows: "a.exe"
