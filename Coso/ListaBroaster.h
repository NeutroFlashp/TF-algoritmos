#pragma once
#include "Departamento.h"
#include <iostream>
typedef unsigned int uint;

class Broaster
{
private:
	Departamento<string>* primero;
	uint tamano;

public:
	class Iterador {
		Local<string, float>* aux;

	public:
		Iterador(Local<string, float>* aux = nullptr) : aux(aux) {}
		void operator ++ () { aux = aux->siguiente; }
		bool operator != (Iterador it) { return aux != it.aux; }
		Local<string, float>* operator* () { return aux->siguiente; }
		Local<string, float>* getIt() { return aux; }
	};
	Broaster() {
		tamano = 0;
		primero = nullptr;
	}
	~Broaster() {}

	bool isEmpty() { return tamano == 0; }
	uint getTamano() { return tamano; }

	Departamento<string>* getDepartamento(string nombre) {
		Departamento<string>* aux = primero;

		while (aux != nullptr)
		{
			if (aux->nombre == nombre)
				return aux;

			aux = aux->siguiente;
		}
		return nullptr;
	}

	void addDepartamento(string nombre) {
		Departamento<string>* nuevo = new Departamento<string>(nombre);

		if (isEmpty()) primero = nuevo;

		else
		{
			Departamento<string>* aux = primero;

			while (aux->siguiente != nullptr)
				aux = aux->siguiente;

			aux->siguiente = nuevo;
		}
		tamano++;
	}

	void addLocal(string departamento, string nombre, float precio) {
		Departamento<string>* auxDep = getDepartamento(departamento);
		Local<string, float>* nuevo = new Local<string, float>(nombre, precio);

		if (auxDep->local == nullptr)
		{
			auxDep->local = nuevo;
			auxDep->ultimo = nuevo;
		}
		else
		{
			auxDep->ultimo->siguiente = nuevo;
			nuevo->anterior = auxDep->ultimo;
			auxDep->ultimo = nuevo;
		}

	}

	void printList(string departamento) {
		Departamento<string>* auxDep = primero;

		while (auxDep->nombre != departamento)
			auxDep = auxDep->siguiente;

		Local<string, float>* auxLoc = auxDep->local;

		cout << "\nEn " << auxDep->nombre << " estan estos locales:\n";

		while (auxLoc != auxDep->ultimo)
		{
			cout << "\n<" << auxLoc->nombre << ">   " << "\t" << auxLoc->precio;
			auxLoc = auxLoc->siguiente;
		}

	}

	void sort(string nombre) {
		Departamento<string>* auxDep = primero;
		while (auxDep->nombre != nombre)
			auxDep = auxDep->siguiente;
		for (Iterador i = auxDep->local; *i != nullptr; i++)
		{
			for (Iterador j = auxDep->local; *j != nullptr; j++)
			{
				if (i.getIt()->precio < j.getIt()->precio)
				{
					float temp = i.getIt()->precio;
					string temp2 = i.getIt()->nombre;

					i.getIt()->precio = j.getIt()->precio;
					i.getIt()->nombre = j.getIt()->nombre;

					j.getIt()->precio = temp;
					j.getIt()->nombre = temp2;
				}
			}
		}
	}
};