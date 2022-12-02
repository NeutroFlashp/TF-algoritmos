#pragma once
#include "Producto.h"

class NodoAVL {
public:
	Producto elemento;
	NodoAVL* izq;
	NodoAVL* der;
	int altura;

	NodoAVL() {
		izq = nullptr;
		der = nullptr;
		altura = 0;
	}
};

