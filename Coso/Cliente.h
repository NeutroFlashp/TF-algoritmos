#pragma once
#include <string>
#include <iostream>
using namespace std;

class Cliente
{
private:
	string nombre;
	string apellido;
	long DNI, telefono, edad;

public:
	Cliente(){}

	Cliente(string nombre, string apellido, string DNI, string telefono, string edad) {
		this->nombre = nombre;
		this->apellido = apellido;
		this->DNI = stol(DNI);
		this->telefono = stol(telefono);
		this->edad = stoi(edad);
	}

	string getName() { return nombre; }
	string getApellido() { return apellido; }
	long getDNI() { return DNI; }
	long getTelefono() { return telefono; }
	long getEdad() { return edad; }

};