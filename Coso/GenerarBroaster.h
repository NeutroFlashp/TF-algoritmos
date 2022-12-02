#pragma once
#include <functional>
#include "ListaBroaster.h"
#include "File.h"

Broaster* generateBroaster() {
	srand(time(NULL));
	Broaster* broaster = new Broaster();
	File<string>* file = new File<string>();
	broaster->addDepartamento(file->getDep1());
	broaster->addDepartamento(file->getDep2());
	broaster->addDepartamento(file->getDep3());
	broaster->addDepartamento(file->getDep4());
	broaster->addDepartamento(file->getDep5());
	broaster->addDepartamento(file->getDep6());
	broaster->addDepartamento(file->getDep7());

	function <float()> price = []() {return float(rand() % 501 + 4500) / 100; };
	broaster->addLocal(file->getDep1(), file->getLocal1(), price());
	broaster->addLocal(file->getDep1(), file->getLocal2(), price());
	broaster->addLocal(file->getDep1(), file->getLocal3(), price());
	broaster->addLocal(file->getDep1(), file->getLocal4(), price());
	broaster->addLocal(file->getDep1(), file->getLocal5(), price());
	broaster->addLocal(file->getDep1(), file->getLocal6(), price());
	broaster->addLocal(file->getDep1(), file->getLocal7(), price());
	broaster->addLocal(file->getDep1(), file->getLocal8(), price());
	broaster->addLocal(file->getDep1(), file->getLocal9(), price());
	broaster->addLocal(file->getDep1(), " ", 0);

	broaster->addLocal(file->getDep2(), file->getLocal1(), price());
	broaster->addLocal(file->getDep2(), file->getLocal2(), price());
	broaster->addLocal(file->getDep2(), file->getLocal3(), price());
	broaster->addLocal(file->getDep2(), file->getLocal4(), price());
	broaster->addLocal(file->getDep2(), file->getLocal5(), price());
	broaster->addLocal(file->getDep2(), file->getLocal6(), price());
	broaster->addLocal(file->getDep2(), file->getLocal7(), price());
	broaster->addLocal(file->getDep2(), file->getLocal8(), price());
	broaster->addLocal(file->getDep2(), file->getLocal9(), price());
	broaster->addLocal(file->getDep2(), " ", 0);

	broaster->addLocal(file->getDep3(), file->getLocal1(), price());
	broaster->addLocal(file->getDep3(), file->getLocal2(), price());
	broaster->addLocal(file->getDep3(), file->getLocal3(), price());
	broaster->addLocal(file->getDep3(), file->getLocal4(), price());
	broaster->addLocal(file->getDep3(), file->getLocal5(), price());
	broaster->addLocal(file->getDep3(), file->getLocal6(), price());
	broaster->addLocal(file->getDep3(), file->getLocal7(), price());
	broaster->addLocal(file->getDep3(), file->getLocal8(), price());
	broaster->addLocal(file->getDep3(), file->getLocal9(), price());
	broaster->addLocal(file->getDep3(), " ", 0);

	broaster->addLocal(file->getDep4(), file->getLocal1(), price());
	broaster->addLocal(file->getDep4(), file->getLocal2(), price());
	broaster->addLocal(file->getDep4(), file->getLocal3(), price());
	broaster->addLocal(file->getDep4(), file->getLocal4(), price());
	broaster->addLocal(file->getDep4(), file->getLocal5(), price());
	broaster->addLocal(file->getDep4(), file->getLocal6(), price());
	broaster->addLocal(file->getDep4(), file->getLocal7(), price());
	broaster->addLocal(file->getDep4(), file->getLocal8(), price());
	broaster->addLocal(file->getDep4(), file->getLocal9(), price());
	broaster->addLocal(file->getDep4(), " ", 0);

	broaster->addLocal(file->getDep5(), file->getLocal1(), price());
	broaster->addLocal(file->getDep5(), file->getLocal2(), price());
	broaster->addLocal(file->getDep5(), file->getLocal3(), price());
	broaster->addLocal(file->getDep5(), file->getLocal4(), price());
	broaster->addLocal(file->getDep5(), file->getLocal5(), price());
	broaster->addLocal(file->getDep5(), file->getLocal6(), price());
	broaster->addLocal(file->getDep5(), file->getLocal7(), price());
	broaster->addLocal(file->getDep5(), file->getLocal8(), price());
	broaster->addLocal(file->getDep5(), file->getLocal9(), price());
	broaster->addLocal(file->getDep5(), " ", 0);

	broaster->addLocal(file->getDep6(), file->getLocal1(), price());
	broaster->addLocal(file->getDep6(), file->getLocal2(), price());
	broaster->addLocal(file->getDep6(), file->getLocal3(), price());
	broaster->addLocal(file->getDep6(), file->getLocal4(), price());
	broaster->addLocal(file->getDep6(), file->getLocal5(), price());
	broaster->addLocal(file->getDep6(), file->getLocal6(), price());
	broaster->addLocal(file->getDep6(), file->getLocal7(), price());
	broaster->addLocal(file->getDep6(), file->getLocal8(), price());
	broaster->addLocal(file->getDep6(), file->getLocal9(), price());
	broaster->addLocal(file->getDep6(), " ", 0);

	broaster->addLocal(file->getDep7(), file->getLocal1(), price());
	broaster->addLocal(file->getDep7(), file->getLocal2(), price());
	broaster->addLocal(file->getDep7(), file->getLocal3(), price());
	broaster->addLocal(file->getDep7(), file->getLocal4(), price());
	broaster->addLocal(file->getDep7(), file->getLocal5(), price());
	broaster->addLocal(file->getDep7(), file->getLocal6(), price());
	broaster->addLocal(file->getDep7(), file->getLocal7(), price());
	broaster->addLocal(file->getDep7(), file->getLocal8(), price());
	broaster->addLocal(file->getDep7(), file->getLocal9(), price());
	broaster->addLocal(file->getDep7(), " ", 0);

	return broaster;
}