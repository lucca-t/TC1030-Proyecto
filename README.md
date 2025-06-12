# TC1030-Proyecto: Sistema de Gestión de Hotel

## Autor
Lucca Traslosheros Abascal  
A01713944  
11/6/2025

---

## Descripción

Este proyecto es una aplicación de consola en C++ que modela la gestión de un hotel. Permite crear, eliminar y manipular empleados, huéspedes y cuartos, así como asignar huéspedes a cuartos y mostrar información relevante del hotel. El sistema implementa conceptos fundamentales de la programación orientada a objetos como herencia, polimorfismo, clases abstractas, sobrecarga y sobreescritura de métodos, y modificadores de acceso.

---

## Estructura del Proyecto

- **Hotel:** Clase principal que administra cuartos, empleados y huéspedes.
- **Cuarto:** Representa un cuarto del hotel, con atributos como número, tipo, tarifa y disponibilidad.
- **Empleado (abstracta):** Clase base para empleados, con métodos virtuales puros. 
                            No se puede crear objeto de empleado y los metodos virtuales tienen un =0
  - **Recepcionista:** Hereda de Empleado, maneja llamadas y reservaciones.
  - **Limpieza:** Hereda de Empleado, maneja cuartos limpiados y suministros.
- **Huesped:** Representa a un huésped, con atributos como nombre, correo, teléfono y dinero disponible.

---

## Instalación y Ejecución

Compilar con: "g++ Empleado.h Limpieza.h Recepcionista.h Cuarto.h Hotel.h Huesped.h main.cpp"

Correr en Windows: ".\a.exe"

## Uso

Al iniciar el programa, puedes elegir entre usar un hotel por defecto o crear uno personalizado.  
El menú principal te permite:
- Crear empleados o huéspedes
- Hacer trabajar a un empleado
- Eliminar empleados o huéspedes
- Asignar huéspedes a cuartos
- Eliminar huéspedes de cuartos
- Mostrar información general del hotel
- Mostrar información de una persona específica

---

## Casos que pueden hacer que el proyecto deje de funcionar

- **Entradas inválidas:** Si el usuario ingresa letras donde se espera un número, el sistema limpia el buffer y pide la entrada de nuevo, evitando loops infinitos. Puede causar comportamiento inesperado.
- **Índices fuera de rango:** El sistema valida que los números de cuarto y de empleado estén dentro de los límites permitidos.
- **Memoria:** Si se eliminan empleados o huéspedes, los punteros se ponen en `nullptr` para evitar accesos inválidos.
- **Duplicados:** No se permite registrar empleados con el mismo ID ni huéspedes con el mismo correo.
- **Espacios llenos:** Si se alcanza el máximo de empleados, huéspedes o cuartos, el sistema lo notifica y no permite agregar más.

---

## Conceptos de POO implementados

- **Herencia:** `Recepcionista` y `Limpieza` heredan de `Empleado`.
- **Clases abstractas:** `Empleado` es abstracta, no se puede crear objeto de Empleado, y define métodos virtuales puros.
- **Polimorfismo:** Se usan punteros a `Empleado` para manejar diferentes tipos de empleados.
- **Modificadores de acceso:** Uso de `private`, `protected` y `public` en atributos y métodos.
- **Sobrecarga y sobreescritura:** Constructores sobrecargados y métodos virtuales sobreescritos en las clases hijas.

---

## Control de versiones

Este proyecto utiliza Git para el control de versiones.  
Puedes ver el historial de cambios en la pestaña "Commits" de GitHub.

---