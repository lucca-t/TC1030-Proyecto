# TC1030-Project: Hotel Management System

## Author  
Lucca Traslosheros Abascal  
A01713944  
11/6/2025

---

## Description

This project is a C++ console application that models the management of a hotel. It allows creating, deleting, and manipulating employees, guests, and rooms, as well as assigning guests to rooms and displaying relevant hotel information. The system implements fundamental object-oriented programming concepts such as inheritance, polymorphism, abstract classes, method overloading and overriding, and access modifiers.

---

## Project Structure

- **Hotel:** Main class that manages rooms, employees, and guests.  
- **Room:** Represents a hotel room, with attributes such as number, type, rate, and availability.  
- **Employee (abstract):** Base class for employees, with pure virtual methods.  
                             Employee objects cannot be created and virtual methods have =0.  
  - **Receptionist:** Inherits from Employee, handles calls and reservations.  
  - **Cleaning:** Inherits from Employee, handles cleaned rooms and supplies.  
- **Guest:** Represents a guest, with attributes such as name, email, phone, and available money.

---

## Installation and Execution

Compile with: `g++ Empleado.h Limpieza.h Recepcionista.h Cuarto.h Hotel.h Huesped.h main.cpp`

Run on Windows: `.\a.exe`

## Usage

When starting the program, you can choose to use a default hotel or create a customized one.  
The main menu allows you to:  
- Create employees or guests  
- Make an employee work  
- Delete employees or guests  
- Assign guests to rooms  
- Remove guests from rooms  
- Show general hotel information  
- Show specific person information

---

## Cases That May Cause the Project to Stop Working

- **Invalid inputs:** If the user enters letters where numbers are expected, the system clears the buffer and requests input again, avoiding infinite loops. This may cause unexpected behavior.  
- **Out-of-range indices:** The system validates that room and employee numbers are within allowed limits.  
- **Memory:** If employees or guests are deleted, pointers are set to `nullptr` to avoid invalid access.  
- **Duplicates:** Registering employees with the same ID or guests with the same email is not allowed.  
- **Full capacity:** If the maximum number of employees, guests, or rooms is reached, the system notifies and does not allow adding more.

---

## OOP Concepts Implemented

- **Inheritance:** `Receptionist` and `Cleaning` inherit from `Employee`.  
- **Abstract classes:** `Employee` is abstract; objects of Employee cannot be created and it defines pure virtual methods.  
- **Polymorphism:** Pointers to `Employee` are used to handle different types of employees.  
- **Access modifiers:** Use of `private`, `protected`, and `public` on attributes and methods.  
- **Overloading and overriding:** Overloaded constructors and virtual methods overridden in child classes.

---

## Version Control

This project uses Git for version control.  
You can see the change history in the "Commits" tab on GitHub.

---

## UML Visible in Files

[Link to UML inside the folder](TC1030-UML.pdf)
