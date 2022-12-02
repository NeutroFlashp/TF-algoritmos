#pragma once
#include "Compra.h"
#include <iostream>
using namespace std;

class Cola
{
private:
	Compra<string>* primero;
	Compra<string>* ultimo;
public:
	Cola() {
		primero = nullptr;
		ultimo = nullptr;
	}
	~Cola() {}

	bool isEmpty() { return (primero == nullptr); }

	void enqueue(string nombre, uint departamento, uint local, uint objeto, uint num, string codpostal, string tarjeta) {
		Compra<string>* nuevo = new Compra<string>(nombre, departamento, local, objeto, num, codpostal, tarjeta);
		if (isEmpty())
		{
			primero = nuevo;
			ultimo = nuevo;
		}
		else
		{
			ultimo->siguiente = nuevo;
			ultimo = nuevo;
		}
	}

	void dequeue() {
		if (!isEmpty())
		{
			Compra<string>* aux = primero;
			if (primero == ultimo)
			{
				primero = nullptr;
				ultimo = nullptr;
			}
			else
			{
				primero = primero->siguiente;
			}
			cout << "\nSe ha completado la siguiente compra:";
			aux->printAll();
		}
		else
		{
			cout << "\nLa cola esta vacia";
		}
	}

	void printCola() {
		Compra<string>* aux = primero;
		if (!isEmpty())
		{
			while (aux != ultimo->siguiente)
			{
				aux->printAll();
				aux = aux->siguiente;
			}
		}
		else cout << "\nLa cola esta vacia";
	}

};