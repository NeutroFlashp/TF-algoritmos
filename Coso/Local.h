#pragma once
#include <iostream>
using namespace std;
template <class T1, class T2>
class Local
{
private:

	/*string nombre;
	float precio;*/

	T1 nombre;
	T2 precio;
	Local* siguiente;
	Local* anterior;

	friend class Hamburguesa;
	friend class Broaster;

public:

	Local(T1 nombre, T2 precio) {
		this->nombre = nombre;
		this->precio = precio;
		siguiente = nullptr;
		anterior = nullptr;

	}
	~Local() {}

};