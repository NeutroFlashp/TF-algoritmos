#pragma once
#include <functional>
#include "ListaHamburguesa.h"
#include "File.h"

Hamburguesa* generateHamburguesa() {
	srand(time(NULL));
	Hamburguesa* hamburguesa = new Hamburguesa();
	File<string>* file = new File<string>();
	hamburguesa->addDepartamento(file->getDep1());
	hamburguesa->addDepartamento(file->getDep2());
	hamburguesa->addDepartamento(file->getDep3());
	hamburguesa->addDepartamento(file->getDep4());
	hamburguesa->addDepartamento(file->getDep5());
	hamburguesa->addDepartamento(file->getDep6());
	hamburguesa->addDepartamento(file->getDep7());

	function <float()> price = []() {return float(rand() % 501 + 1000) / 100; };
	hamburguesa->addLocal(file->getDep1(), file->getLocal1(), price());
	hamburguesa->addLocal(file->getDep1(), file->getLocal2(), price());
	hamburguesa->addLocal(file->getDep1(), file->getLocal3(), price());
	hamburguesa->addLocal(file->getDep1(), file->getLocal4(), price());
	hamburguesa->addLocal(file->getDep1(), file->getLocal5(), price());
	hamburguesa->addLocal(file->getDep1(), file->getLocal6(), price());
	hamburguesa->addLocal(file->getDep1(), file->getLocal7(), price());
	hamburguesa->addLocal(file->getDep1(), file->getLocal8(), price());
	hamburguesa->addLocal(file->getDep1(), file->getLocal9(), price());
	hamburguesa->addLocal(file->getDep1(), " ", 0);

	hamburguesa->addLocal(file->getDep2(), file->getLocal1(), price());
	hamburguesa->addLocal(file->getDep2(), file->getLocal2(), price());
	hamburguesa->addLocal(file->getDep2(), file->getLocal3(), price());
	hamburguesa->addLocal(file->getDep2(), file->getLocal4(), price());
	hamburguesa->addLocal(file->getDep2(), file->getLocal5(), price());
	hamburguesa->addLocal(file->getDep2(), file->getLocal6(), price());
	hamburguesa->addLocal(file->getDep2(), file->getLocal7(), price());
	hamburguesa->addLocal(file->getDep2(), file->getLocal8(), price());
	hamburguesa->addLocal(file->getDep2(), file->getLocal9(), price());
	hamburguesa->addLocal(file->getDep2(), " ", 0);

	hamburguesa->addLocal(file->getDep3(), file->getLocal1(), price());
	hamburguesa->addLocal(file->getDep3(), file->getLocal2(), price());
	hamburguesa->addLocal(file->getDep3(), file->getLocal3(), price());
	hamburguesa->addLocal(file->getDep3(), file->getLocal4(), price());
	hamburguesa->addLocal(file->getDep3(), file->getLocal5(), price());
	hamburguesa->addLocal(file->getDep3(), file->getLocal6(), price());
	hamburguesa->addLocal(file->getDep3(), file->getLocal7(), price());
	hamburguesa->addLocal(file->getDep3(), file->getLocal8(), price());
	hamburguesa->addLocal(file->getDep3(), " ", 0);

	hamburguesa->addLocal(file->getDep4(), file->getLocal1(), price());
	hamburguesa->addLocal(file->getDep4(), file->getLocal2(), price());
	hamburguesa->addLocal(file->getDep4(), file->getLocal3(), price());
	hamburguesa->addLocal(file->getDep4(), file->getLocal4(), price());
	hamburguesa->addLocal(file->getDep4(), file->getLocal5(), price());
	hamburguesa->addLocal(file->getDep4(), file->getLocal6(), price());
	hamburguesa->addLocal(file->getDep4(), file->getLocal7(), price());
	hamburguesa->addLocal(file->getDep4(), file->getLocal8(), price());
	hamburguesa->addLocal(file->getDep4(), file->getLocal9(), price());
	hamburguesa->addLocal(file->getDep4(), " ", 0);

	hamburguesa->addLocal(file->getDep5(), file->getLocal1(), price());
	hamburguesa->addLocal(file->getDep5(), file->getLocal2(), price());
	hamburguesa->addLocal(file->getDep5(), file->getLocal3(), price());
	hamburguesa->addLocal(file->getDep5(), file->getLocal4(), price());
	hamburguesa->addLocal(file->getDep5(), file->getLocal5(), price());
	hamburguesa->addLocal(file->getDep5(), file->getLocal6(), price());
	hamburguesa->addLocal(file->getDep5(), file->getLocal7(), price());
	hamburguesa->addLocal(file->getDep5(), file->getLocal8(), price());
	hamburguesa->addLocal(file->getDep5(), file->getLocal9(), price());
	hamburguesa->addLocal(file->getDep5(), " ", 0);

	hamburguesa->addLocal(file->getDep6(), file->getLocal1(), price());
	hamburguesa->addLocal(file->getDep6(), file->getLocal2(), price());
	hamburguesa->addLocal(file->getDep6(), file->getLocal3(), price());
	hamburguesa->addLocal(file->getDep6(), file->getLocal4(), price());
	hamburguesa->addLocal(file->getDep6(), file->getLocal5(), price());
	hamburguesa->addLocal(file->getDep6(), file->getLocal6(), price());
	hamburguesa->addLocal(file->getDep6(), file->getLocal7(), price());
	hamburguesa->addLocal(file->getDep6(), file->getLocal8(), price());
	hamburguesa->addLocal(file->getDep6(), file->getLocal9(), price());
	hamburguesa->addLocal(file->getDep6(), " ", 0);

	hamburguesa->addLocal(file->getDep7(), file->getLocal1(), price());
	hamburguesa->addLocal(file->getDep7(), file->getLocal2(), price());
	hamburguesa->addLocal(file->getDep7(), file->getLocal3(), price());
	hamburguesa->addLocal(file->getDep7(), file->getLocal4(), price());
	hamburguesa->addLocal(file->getDep7(), file->getLocal5(), price());
	hamburguesa->addLocal(file->getDep7(), file->getLocal6(), price());
	hamburguesa->addLocal(file->getDep7(), file->getLocal7(), price());
	hamburguesa->addLocal(file->getDep7(), file->getLocal8(), price());
	hamburguesa->addLocal(file->getDep7(), file->getLocal9(), price());
	hamburguesa->addLocal(file->getDep7(), " ", 0);

	return hamburguesa;
}