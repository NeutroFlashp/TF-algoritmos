#pragma once
#include <iostream>
#include "File.h"
#include "ListaHamburguesa.h"
#include "ListaBroaster.h"
typedef unsigned int uint;
using namespace std;

template<class T>
class Compra
{
public:
	Compra* siguiente;
	T nombre, departamento, local, objeto, codpostal, tarjeta;
	uint num;

	File<string>* file = new File<string>();
	string dep1 = file->getDep1();
	string dep2 = file->getDep2();
	string dep3 = file->getDep3();
	string dep4 = file->getDep4();
	string dep5 = file->getDep5();
	string dep6 = file->getDep6();
	string dep7 = file->getDep7();
	string local1 = file->getLocal1();
	string local2 = file->getLocal2();
	string local3 = file->getLocal3();
	string local4 = file->getLocal4();
	string local5 = file->getLocal5();
	string local6 = file->getLocal6();
	string local7 = file->getLocal7();
	string local8 = file->getLocal8();
	string local9 = file->getLocal9();

	friend class Cola;
public:
	Compra(T nombre, uint departamento, uint local, uint objeto, uint num, T codpostal, T tarjeta) {
		this->nombre = nombre;
		this->num = num;
		this->tarjeta = tarjeta;
		this->codpostal = codpostal;
		switch (departamento)
		{
		case 1: this->departamento = dep1; break;
		case 2: this->departamento = dep2; break;
		case 3: this->departamento = dep3; break;
		case 4: this->departamento = dep4; break;
		case 5: this->departamento = dep5; break;
		case 6: this->departamento = dep6; break;
		case 7: this->departamento = dep7; break;
		}

		switch (local)
		{
		case 1: this->local = local1; break;
		case 2: this->local = local2; break;
		case 3: this->local = local3; break;
		case 4: this->local = local4; break;
		case 5: this->local = local5; break;
		case 6: this->local = local6; break;
		case 7: this->local = local7; break;
		case 8: this->local = local8; break;
		case 9: this->local = local9; break;
		}

		switch (objeto)
		{
		case 1:this->objeto = "Paracetamol"; break;
		case 2:this->objeto = "Aspirina"; break;
		}

	}
	~Compra() {}

	void setNombre(T v) { nombre = v; }
	void setDepto(T v) { departamento = v; }
	void setLocal(T v) { local = v; }
	void setObjeto(T v) { objeto = v; }

	T getNombre() { return nombre; }
	T getDepto() { return departamento; }
	T getLocal() { return local; }
	T getObjeto() { return objeto; }

	void printAll() {
		cout << "\n\n Nombre:		" << nombre;
		cout << "\n Numero de tarjeta:	" << tarjeta;
		cout << "\n Departamento:		" << departamento;
		cout << "\n Codigo postal:		" << codpostal;
		cout << "\n Local:			" << local;
		cout << "\nCompra registrada de " << num << " caja(s) de " << objeto;
	}
};