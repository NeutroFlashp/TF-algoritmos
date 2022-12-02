#pragma once
#include <string>
#include <iostream>
using namespace std;

class Producto
{
private:
	long codigo, cantidad;
	int precio;

public:
	Producto() {}

	Producto(string codigo, string cantidad, string precio) {
		this->codigo = stol(codigo);
		this->cantidad = stol(cantidad);
		this->precio = stoi(precio);
	}

	long getCodigo() { return codigo; }
	long getCantidad() { return cantidad; }
	int  getPrecio() { return precio; }

	void setCantidad(long cantidad) { this->cantidad = cantidad; }

};