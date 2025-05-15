# TC1030-Proyecto

Este proyecto modela un sistema para la gestión de un hotel mediante una estructura de clases que representa sus elementos principales:
Hotel, Cuarto, Huesped y Empleado. 
La clase Hotel administra la información de las habitaciones, los huéspedes y el personal. El hotel contiene las habitaciones como composición, y los huespedes y personal como agregación.
Cada Cuarto contiene datos específicos y mantiene una referencia al huésped que lo ocupa. 
La clase Huesped almacena los datos personales de los clientes.
Empleado es una clase abstracta que sirve como base para las subclases Recepcionista y Limpieza, las cuales implementan comportamientos específicos, demostrando el uso de herencia y polimorfismo.
