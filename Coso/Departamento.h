#pragma once
#include <iostream>
#include "Local.h"
template <class T>
class Departamento
{
private:
	//string nombre;

	T nombre;
	Departamento* siguiente;
	Local<string, float>* local;
	Local<string, float>* ultimo;

	friend class Hamburguesa;
	friend class Broaster;

public:


	Departamento(T nombre) {
		this->nombre = nombre;
		siguiente = nullptr;
		local = nullptr;
	}

	~Departamento() {}

	T getNombre() { return nombre; }
	void setNombre(T nombre) { this->nombre = nombre; }

	Departamento* getSiguiente() { return siguiente; }
	void setSiguiente(Departamento* siguiente) { this->siguiente = siguiente; }

};