#pragma once
#include "Cliente.h"
#include <functional>
#include <list>

using namespace std;

class Nodo
{
public:
	Cliente elemento;
	Nodo* izq;
	Nodo* der;
};
class Arbol
{
	typedef function<int(Cliente, Cliente)> Comp;

	void(*procesar)(Cliente);
	Nodo* raiz;
	Comp comparar;
	size_t size = 0;

private:
	bool _buscar(Nodo* nodo, Cliente e) {
		if (nodo == nullptr) return false;
		else
		{
			int r = comparar(nodo->elemento, e);
			if (r == 0) return true;
			else if (r < 0)
			{
				return _buscar(nodo->der, e);
			}
			else
			{
				return _buscar(nodo->izq, e);
			}
		}
	}

	bool _insertar(Nodo*& nodo, Cliente e) {
		if (nodo == nullptr) {
			nodo = new Nodo();
			nodo->elemento = e;
			size++;
			return true;
		}
		else
		{
			int r = comparar(nodo->elemento, e);
			//if (r == 0)return false;
			//else 
			if (r < 0)
			{
				return _insertar(nodo->der, e);
			}
			else
			{
				return _insertar(nodo->izq, e);
			}
		}
	}

	void _enOrden(Nodo* nodo) {
		if (nodo == nullptr) return;
		_enOrden(nodo->der);
		procesar(nodo->elemento);
		_enOrden(nodo->izq);
	}

	void _preOrden(Nodo* nodo) {
		if (nodo == nullptr) return;
		procesar(nodo->elemento);
		_preOrden(nodo->izq);
		_preOrden(nodo->der);
	}

	void _postOrden(Nodo* nodo) {
		if (nodo == nullptr) return;
		_preOrden(nodo->izq);
		_preOrden(nodo->der);
		procesar(nodo->elemento);
	}

	string _maxCases(Nodo* nodo) {
		while (nodo->der != nullptr) {
			nodo = nodo->der;
		}
		return nodo->elemento.getName();
	}

	string _minCases(Nodo* nodo) {
		while (nodo->izq != nullptr) {
			nodo = nodo->izq;
		}
		return nodo->elemento.getName();
	}
public:
	Arbol(void(*nuevoProcesar)(Cliente)) {
		procesar = nuevoProcesar;
		comparar = [](Cliente a, Cliente b)->int {
			if (a.getEdad() < b.getEdad()) { return -1; }
			else
			{
				return 1;
			}
		};
		raiz = nullptr;
	}

	bool Buscar(Cliente e) {
		return _buscar(raiz, e);
	}
	bool Insertar(Cliente e) {
		return _insertar(raiz, e);
	}
	void EnOrden() {
		_enOrden(raiz);
	}
	void PreOrden() {
		_preOrden(raiz);
	}
	void PostOrden() {
		_postOrden(raiz);
	}

	size_t getSize() {
		return size;
	}

	string maxCases() {
		return _maxCases(raiz);
	}
	string minCases() {
		return _minCases(raiz);
	}
};