#include <iostream>
#include <conio.h>
#include <fstream>
#include <string>
#include <sstream>
#include "ListaHamburguesa.h"
#include "ListaBroaster.h"
#include "File.h"
#include "GenerarHamburguesa.h"
#include "GenerarBroaster.h"
#include "ColaCompras.h"
#include "HistoryStack.h"
#include "HashTable.h"
#include "Arbol.h"
#include "ArbolAVL.h"

using std::cout;
using std::cin;

void quicksort(int A[50], int primero, int ultimo)
{
	int central, i, j;
	int pivote;
	central = (primero + ultimo) / 2;
	pivote = A[central];
	i = primero;
	j = ultimo;
	do
	{
		while (A[i] < pivote) i++;
		while (A[j] > pivote) j--;
		if (i <= j)
		{
			int temp;
			temp = A[i];
			A[i] = A[j];
			A[j] = temp;
			i++;
			j--;
		}
	}

	while (i <= j);
	if (primero < j)
		quicksort(A, primero, j);
	if (i < ultimo)
		quicksort(A, i, ultimo);
}
void escribir(int A[50], int n)
{
	int i;
	cout << endl << "Arreglo de horas de ingreso de los trabajadores ordenadas\n\n";
	for (i = 0; i < n; i++)
	{
		cout << "0" << int(A[i] / 100) << ":";
		if (int(A[i] % 100) < 10) cout << "0";
		cout << int(A[i] % 100) << "\n";
	}
}


uint ordenarLista() {
	uint ord = 9;
	while (ord < 0 || ord > 1) {
		cout << "\n\nDesea ordenar la lista? (1 = SI || 0 = NO)   "; cin >> ord;
	}

	return ord;
}
void imprimir(Cliente e) {
	cout << e.getName() << " " << e.getApellido() << ", " << e.getEdad() << "\n";
}

int main() {
	srand(time(NULL));
	ifstream readFileClientesFrecuentes;

	ifstream readFileProductosLima;
	ofstream writeFileProductosLima;

	ifstream readFileProductosLambayeque;
	ofstream writeFileProductosLambayeque;

	ifstream readFileProductosPiura;
	ofstream writeFileProductosPiura;

	ifstream readFileProductosAncash;
	ofstream writeFileProductosAncash;

	ifstream readFileProductosJunin;
	ofstream writeFileProductosJunin;

	ifstream readFileProductosAmazonas;
	ofstream writeFileProductosAmazonas;

	ifstream readFileProductosLoreto;
	ofstream writeFileProductosLoreto;

	long codrand, cantrand;
	float prerand;

	string linea = "";
	string dato = "";
	HashTabla ht;

	int hora_ingreso[50]; 
	for (size_t i = 0; i < 50; i++) {
		hora_ingreso[i] = (800 + rand() % 60);
	}

	Arbol* arbol = new Arbol(imprimir);
	ArbolAVL* productosLima = new ArbolAVL();
	ArbolAVL* productosLambayeque = new ArbolAVL();
	ArbolAVL* productosPiura = new ArbolAVL();
	ArbolAVL* productosAncash = new ArbolAVL();
	ArbolAVL* productosJunin = new ArbolAVL();
	ArbolAVL* productosAmazonas = new ArbolAVL();
	ArbolAVL* productosLoreto = new ArbolAVL();

	readFileClientesFrecuentes.open("clientes_frecuentes.csv", ios::in);

	if (readFileClientesFrecuentes.fail()) {
		std::cout << "No se pudo abrir el archivo\n";
		_getch();
		exit(1);
	}
	getline(readFileClientesFrecuentes, linea);
	while (getline(readFileClientesFrecuentes, linea)) {
		stringstream stream(linea);

		string nombre;
		string apellido;
		string DNI;
		string telefono;
		string edad;

		getline(stream, nombre, ';');
		getline(stream, apellido, ';');
		getline(stream, DNI, ';');
		getline(stream, telefono, ';');
		getline(stream, edad, ';');

		Cliente c = Cliente(nombre, apellido, DNI, telefono, edad);

		arbol->Insertar(c);
		ht.insert(HashEntidad(c.getDNI() + c.getTelefono() * 37, c));

	}
	readFileClientesFrecuentes.close();

	
	
	// Productos comprados en todo el anio en el dep. de LIMA
	linea = "";
	dato = "";
	readFileProductosLima.open("productos_lima.csv", ios::in);
	if (readFileProductosLima.fail()) {
		readFileProductosLima.close();

		writeFileProductosLima.open("productos_lima.csv", ios::out);
		writeFileProductosLima << "Codigo;Cantidad;Precio" << endl;
		for (size_t i = 0; i < 150000; i++)
		{
			codrand = (100000 + (rand() % (999999 - 100000)));
			cantrand = (10000 + rand() % 40000);
			prerand = (1000 + rand() % 3001);

			writeFileProductosLima << codrand << ";" << cantrand << ";" << prerand << endl;
		}
		writeFileProductosLima.close();
		readFileProductosLima.open("productos_lima.csv", ios::in);

	}
	getline(readFileProductosLima, linea);
	while (getline(readFileProductosLima, linea)) {
		
		
		stringstream stream(linea);

		string codigo;
		string cantidad;
		string precio;

		getline(stream, codigo, ';');
		getline(stream, cantidad, ';');
		getline(stream, precio, ';');

		Producto c = Producto(codigo, cantidad, precio);
		productosLima->Insertar(c);

	}
	readFileProductosLima.close();



	// Productos comprados en todo el anio en el dep. de Lambayeque
	linea = "";
	dato = "";

	readFileProductosLambayeque.open("productos_lambayeque.csv", ios::in);
	if (readFileProductosLambayeque.fail()) {
		readFileProductosLambayeque.close();

		writeFileProductosLambayeque.open("productos_lambayeque.csv", ios::out);
		writeFileProductosLambayeque << "Codigo;Cantidad;Precio" << endl;
		for (size_t i = 0; i < 150000; i++)
		{
			codrand = (100000 + (rand() % (999999 - 100000)));
			cantrand = (10000 + rand() % 40000);
			prerand = (1000 + rand() % 3001);

			writeFileProductosLambayeque << codrand << ";" << cantrand << ";" << prerand << endl;
		}

		writeFileProductosLambayeque.close();
		readFileProductosLambayeque.open("productos_lambayeque.csv", ios::in);

	}

	getline(readFileProductosLambayeque, linea);
	while (getline(readFileProductosLambayeque, linea)) {
		stringstream stream(linea);

		string codigo;
		string cantidad;
		string precio;

		getline(stream, codigo, ';');
		getline(stream, cantidad, ';');
		getline(stream, precio, ';');

		Producto c = Producto(codigo, cantidad, precio);
		productosLambayeque->Insertar(c);
	}
	readFileProductosLambayeque.close();



	// Productos comprados en todo el anio en el dep. de Piura
	linea = "";
	dato = "";

	readFileProductosPiura.open("productos_piura.csv", ios::in);
	if (readFileProductosPiura.fail()) {
		readFileProductosPiura.close();

		writeFileProductosPiura.open("productos_piura.csv", ios::out);
		writeFileProductosPiura << "Codigo;Cantidad;Precio" << endl;
		for (size_t i = 0; i < 150000; i++)
		{
			codrand = (100000 + (rand() % (999999 - 100000)));
			cantrand = (10000 + rand() % 40000);
			prerand = (1000 + rand() % 3001);

			writeFileProductosPiura << codrand << ";" << cantrand << ";" << prerand << endl;
		}

		writeFileProductosPiura.close();
		readFileProductosPiura.open("productos_piura.csv", ios::in);

	}

	getline(readFileProductosPiura, linea);
	while (getline(readFileProductosPiura, linea)) {
		stringstream stream(linea);

		string codigo;
		string cantidad;
		string precio;

		getline(stream, codigo, ';');
		getline(stream, cantidad, ';');
		getline(stream, precio, ';');

		Producto c = Producto(codigo, cantidad, precio);
		productosPiura->Insertar(c);
	}
	readFileProductosPiura.close();
	


	// Productos comprados en todo el anio en el dep. de Ancash
	linea = "";
	dato = "";

	readFileProductosAncash.open("productos_ancash.csv", ios::in);
	if (readFileProductosAncash.fail()) {
		readFileProductosAncash.close();

		writeFileProductosAncash.open("productos_ancash.csv", ios::out);
		writeFileProductosAncash << "Codigo;Cantidad;Precio" << endl;
		for (size_t i = 0; i < 150000; i++)
		{
			codrand = (100000 + (rand() % (999999 - 100000)));
			cantrand = (10000 + rand() % 40000);
			prerand = (1000 + rand() % 3001);

			writeFileProductosAncash << codrand << ";" << cantrand << ";" << prerand << endl;
		}

		writeFileProductosAncash.close();
		readFileProductosAncash.open("productos_ancash.csv", ios::in);

	}

	getline(readFileProductosAncash, linea);
	while (getline(readFileProductosAncash, linea)) {
		stringstream stream(linea);

		string codigo;
		string cantidad;
		string precio;

		getline(stream, codigo, ';');
		getline(stream, cantidad, ';');
		getline(stream, precio, ';');

		Producto c = Producto(codigo, cantidad, precio);
		productosAncash->Insertar(c);
	}
	readFileProductosAncash.close();



	// Productos comprados en todo el anio en el dep. de Junin
	linea = "";
	dato = "";

	readFileProductosJunin.open("productos_junin.csv", ios::in);
	if (readFileProductosJunin.fail()) {
		readFileProductosJunin.close();

		writeFileProductosJunin.open("productos_junin.csv", ios::out);
		writeFileProductosJunin << "Codigo;Cantidad;Precio" << endl;
		for (size_t i = 0; i < 150000; i++)
		{
			codrand = (100000 + (rand() % (999999 - 100000)));
			cantrand = (10000 + rand() % 40000);
			prerand = (1000 + rand() % 3001);

			writeFileProductosJunin << codrand << ";" << cantrand << ";" << prerand << endl;
		}

		writeFileProductosJunin.close();
		readFileProductosJunin.open("productos_junin.csv", ios::in);

	}

	getline(readFileProductosJunin, linea);
	while (getline(readFileProductosJunin, linea)) {
		stringstream stream(linea);

		string codigo;
		string cantidad;
		string precio;

		getline(stream, codigo, ';');
		getline(stream, cantidad, ';');
		getline(stream, precio, ';');

		Producto c = Producto(codigo, cantidad, precio);
		productosJunin->Insertar(c);
	}
	readFileProductosJunin.close();


	// Productos comprados en todo el anio en el dep. de Amazonas
	linea = "";
	dato = "";

	readFileProductosAmazonas.open("productos_amazonas.csv", ios::in);
	if (readFileProductosAmazonas.fail()) {
		readFileProductosAmazonas.close();

		writeFileProductosAmazonas.open("productos_amazonas.csv", ios::out);
		writeFileProductosAmazonas << "Codigo;Cantidad;Precio" << endl;
		for (size_t i = 0; i < 150000; i++)
		{
			codrand = (100000 + (rand() % (999999 - 100000)));
			cantrand = (10000 + rand() % 40000);
			prerand = (1000 + rand() % 3001);

			writeFileProductosAmazonas << codrand << ";" << cantrand << ";" << prerand << endl;
		}

		writeFileProductosAmazonas.close();
		readFileProductosAmazonas.open("productos_amazonas.csv", ios::in);

	}

	getline(readFileProductosAmazonas, linea);
	while (getline(readFileProductosAmazonas, linea)) {
		stringstream stream(linea);

		string codigo;
		string cantidad;
		string precio;

		getline(stream, codigo, ';');
		getline(stream, cantidad, ';');
		getline(stream, precio, ';');

		Producto c = Producto(codigo, cantidad, precio);
		productosAmazonas->Insertar(c);
	}
	readFileProductosAmazonas.close();



	// Productos comprados en todo el anio en el dep. de Loreto
	linea = "";
	dato = "";

	readFileProductosLoreto.open("productos_loreto.csv", ios::in);
	if (readFileProductosLoreto.fail()) {
		readFileProductosLoreto.close();

		writeFileProductosLoreto.open("productos_loreto.csv", ios::out);
		writeFileProductosLoreto << "Codigo;Cantidad;Precio" << endl;
		for (size_t i = 0; i < 150000; i++)
		{
			codrand = (100000 + (rand() % (999999 - 100000)));
			cantrand = (10000 + rand() % 40000);
			prerand = (1000 + rand() % 3001);

			writeFileProductosLoreto << codrand << ";" << cantrand << ";" << prerand << endl;
		}

		writeFileProductosLoreto.close();
		readFileProductosLoreto.open("productos_loreto.csv", ios::in);

	}

	getline(readFileProductosLoreto, linea);
	while (getline(readFileProductosLoreto, linea)) {
		stringstream stream(linea);

		string codigo;
		string cantidad;
		string precio;

		getline(stream, codigo, ';');
		getline(stream, cantidad, ';');
		getline(stream, precio, ';');

		Producto c = Producto(codigo, cantidad, precio);
		productosLoreto->Insertar(c);
	}
	readFileProductosLoreto.close();


	// Lectura de datos de los departamentos y locales dentro de ellos de un archivo 
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

	string nombre, codpostal, tarjeta;
	uint objop = 0;
	uint localop = 0;
	int opcion = 0;
	uint depto = 0;
	uint num = 0;
	uint oplocal = 0;
	long admin_code = 0;
	Hamburguesa* hamburguesa = generateHamburguesa();
	Broaster* broaster = generateBroaster();
	Cola* cola = new Cola();
	Stack* historyStack = new Stack();

	system("cls");
	cout << "Ingrese su codigo de acceso: "; cin >> admin_code;

	historyStack->push("Inicio de sesion del trabajador: " + to_string(admin_code));

	function <void()> MostrarMenuPrincipal = []() {
		system("cls");
		cout << "===============MENU==============="
			"\n1. Ver precios del Hamburguesa"
			"\n2. Ver precios de la Broaster"
			"\n3. Agregar pedido a la cola"
			"\n4. Ver toda la cola"
			"\n5. Marcar pedido como entregado"
			"\n6. Ver historial de acciones"
			"\n7. Ver clientes mas habituales"
			"\n8. Ver clientes ordenados por la edad"
			"\n9. Ver mapa de locales en Lima"
			"\n10. Ver los productos comprados en el anio"
			"\n11. Ver horario de llegada de los trabajadores"
			"\n12. Salir"
			"\n\n Ingrese su opcion... ";
	};

	function <void()> PrimeraOpcion = [&]() {
		while (depto < 1 || depto > 7)
		{
			system("cls");
			cout << "Departamentos: " <<
				"\n 1. " << dep1 <<
				"\n 2. " << dep2 <<
				"\n 3. " << dep3 <<
				"\n 4. " << dep4 <<
				"\n 5. " << dep5 <<
				"\n 6. " << dep6 <<
				"\n 7. " << dep7 <<
				"\n\n Ingrese su opcion: ";
			cin >> depto;
			system("cls");
		}
		switch (depto) {
		case 1:
			hamburguesa->printList(dep1);
			historyStack->push("Ver precios de la Hamburgesa en " + dep1);
			if (ordenarLista()) {
				hamburguesa->sort(dep1);
				system("cls");
				cout << "\nLista ordenada: \n";
				hamburguesa->printList(dep1);
				historyStack->push("Ordenar lista");
				_getch();
			}
			depto = 0;
			break;

		case 2:
			hamburguesa->printList(dep2);
			historyStack->push("Ver precios de la Hamburgesa en " + dep2);
			if (ordenarLista()) {
				hamburguesa->sort(dep2);
				system("cls");
				cout << "\n\nLista ordenada: \n";
				hamburguesa->printList(dep2);
				historyStack->push("Ordenar lista");
				_getch();
			}
			depto = 0;
			break;

		case 3:
			hamburguesa->printList(dep3);
			historyStack->push("Ver precios de la Hamburgesa en " + dep3);
			if (ordenarLista()) {
				hamburguesa->sort(dep3);
				system("cls");
				cout << "\n\nLista ordenada: \n";
				hamburguesa->printList(dep3);
				historyStack->push("Ordenar lista");
				_getch();
			}
			depto = 0;
			break;

		case 4:
			hamburguesa->printList(dep4);
			historyStack->push("Ver precios de la Hamburgesa en " + dep4);
			if (ordenarLista()) {
				hamburguesa->sort(dep4);
				system("cls");
				cout << "\n\nLista ordenada: \n";
				hamburguesa->printList(dep4);
				historyStack->push("Ordenar lista");
				_getch();
			}
			depto = 0;
			break;

		case 5:
			hamburguesa->printList(dep5);
			historyStack->push("Ver precios de la Hamburgesa en " + dep5);
			if (ordenarLista()) {
				hamburguesa->sort(dep5);
				system("cls");
				cout << "\n\nLista ordenada: \n";
				hamburguesa->printList(dep5);
				historyStack->push("Ordenar lista");
				_getch();
			}
			depto = 0;
			break;

		case 6:
			hamburguesa->printList(dep6);
			historyStack->push("Precios de la Hamburgesa en " + dep6);
			if (ordenarLista()) {
				hamburguesa->sort(dep6);
				system("cls");
				cout << "\n\nLista ordenada: \n";
				hamburguesa->printList(dep6);
				historyStack->push("Ordenar lista");
				_getch();
			}
			depto = 0;
			break;

		case 7:
			hamburguesa->printList(dep7);
			historyStack->push("Precios de la Hamburgesa en " + dep7);
			if (ordenarLista()) {
				hamburguesa->sort(dep7);
				system("cls");
				cout << "\n\nLista ordenada: \n";
				hamburguesa->printList(dep7);
				historyStack->push("Ordenar lista");
				_getch();
			}
			depto = 0;
			break;
		}
	};
	function <void()> SegundaOpcion = [&]() {
		while (depto < 1 || depto > 7)
		{
			system("cls");
			cout << "Departamentos: " <<
				"\n 1. " << dep1 <<
				"\n 2. " << dep2 <<
				"\n 3. " << dep3 <<
				"\n 4. " << dep4 <<
				"\n 5. " << dep5 <<
				"\n 6. " << dep6 <<
				"\n 7. " << dep7 <<
				"\n\n Ingrese su opcion: ";
			cin >> depto;
			system("cls");
		}
		switch (depto) {
		case 1:
			broaster->printList(dep1);
			historyStack->push("Precios del Broaster en " + dep1);
			if (ordenarLista()) {
				broaster->sort(dep1);
				system("cls");
				cout << "\n\nLista ordenada: \n";
				broaster->printList(dep1);
				historyStack->push("Ordenar lista");
				_getch();
			}
			depto = 0;
			break;

		case 2:
			broaster->printList(dep2);
			historyStack->push("Precios del Broaster en " + dep2);
			if (ordenarLista()) {
				broaster->sort(dep2);
				system("cls");
				cout << "\n\nLista ordenada: \n";
				broaster->printList(dep2);
				historyStack->push("Ordenar lista");
				_getch();
			}
			depto = 0;
			break;

		case 3:
			broaster->printList(dep3);
			historyStack->push("Precios del Broaster en " + dep3);
			if (ordenarLista()) {
				broaster->sort(dep3);
				system("cls");
				cout << "\n\nLista ordenada: \n";
				broaster->printList(dep3);
				historyStack->push("Ordenar lista");
				_getch();
			}
			depto = 0;
			break;

		case 4:
			broaster->printList(dep4);
			historyStack->push("Precios del Broaster en " + dep4);
			if (ordenarLista()) {
				broaster->sort(dep4);
				system("cls");
				cout << "\n\nLista ordenada: \n";
				broaster->printList(dep4);
				historyStack->push("Ordenar lista");
				_getch();
			}
			depto = 0;
			break;

		case 5:
			broaster->printList(dep5);
			historyStack->push("Precios del Broaster en " + dep5);
			if (ordenarLista()) {
				broaster->sort(dep5);
				system("cls");
				cout << "\n\nLista ordenada: \n";
				broaster->printList(dep5);
				historyStack->push("Ordenar lista");
				_getch();
			}
			depto = 0;
			break;

		case 6:
			broaster->printList(dep6);
			historyStack->push("Precios del Broaster en " + dep6);
			if (ordenarLista()) {
				broaster->sort(dep6);
				system("cls");
				cout << "\n\nLista ordenada: \n";
				broaster->printList(dep6);
				historyStack->push("Ordenar lista");
				_getch();
			}
			depto = 0;
			break;

		case 7:
			broaster->printList(dep7);
			historyStack->push("Precios del Broaster en " + dep7);
			if (ordenarLista()) {
				broaster->sort(dep7);
				system("cls");
				cout << "\n\nLista ordenada: \n";
				broaster->printList(dep7);
				historyStack->push("Ordenar lista");
				_getch();
			}
			depto = 0;
			break;
		}
	};
	function <void()> TerceraOpcion = [&]() {
		system("cls");

		historyStack->push("Agregar pedido en la cola");
		cout << "Nombre del comprador: "; cin >> nombre;
		while (depto < 1 || depto > 7)
		{
			system("cls");
			cout << "Departamentos: " <<
				"\n 1. " << dep1 <<
				"\n 2. " << dep2 <<
				"\n 3. " << dep3 <<
				"\n 4. " << dep4 <<
				"\n 5. " << dep5 <<
				"\n 6. " << dep6 <<
				"\n 7. " << dep7 <<
				"\n\n Ingrese su opcion... ";
			cin >> depto;
			system("cls");
		}
		while (objop < 1 || objop > 2)
		{
			system("cls");
			cout << "Producto: " <<
				"\n 1. Hamburguesa" <<
				"\n 2. Broaster" <<
				"\n\n Ingrese su opcion: ";
			cin >> objop;
			system("cls");
		}
		while (localop < 1 || localop > 9)
		{
			system("cls");
			cout << "Locales: " <<
				"\n 1. " << local1 <<
				"\n 2. " << local2 <<
				"\n 3. " << local3 <<
				"\n 4. " << local4 <<
				"\n 5. " << local5 <<
				"\n 6. " << local6 <<
				"\n 7. " << local7 <<
				"\n 8. " << local8 <<
				"\n 9. " << local9 <<
				"\n\n Ingrese su opcion: ";
			cin >> localop;
			system("cls");
		}
		while (num < 1)
		{
			system("cls");
			cout << "Ingrese la cantidad: "; cin >> num;
			system("cls");
		}
		cout << "Ingrese su codigo postal: "; cin >> codpostal;
		system("cls");
		cout << "Ingrese su tarjeta de credito/debito: "; cin >> tarjeta;
		system("cls");
		cola->enqueue(nombre, depto, localop, objop, num, codpostal, tarjeta);
		//opcion = 
		objop = depto = localop = num = 0;
	};
	function <void()> CuartaOpcion = [&]() {
		system("cls");
		historyStack->push("Cola de pedidos");
		cola->printCola();
		//opcion = 0;
		_getch();
	};
	function <void()> QuintaOpcion = [&]() {
		system("cls");
		historyStack->push("Marcar pedido como entregado");
		cola->dequeue();
		//opcion = 0;
		_getch();
	};
	function <void()> SextaOpcion = [&]() {
		system("cls");
		historyStack->push("Historial de acciones");
		historyStack->printStack();
		_getch();
	};
	function <void()> SeptimaOpcion = [&]() {
		system("cls"); 
		historyStack->push("Clientes habituales");
		cout << "Hash Table:\n";
		ht.DispAll();
		_getch();
	};
	function <void()> OctavaOpcion = [&]() {
		system("cls");
		historyStack->push("Clientes frecuentes ordenados por la edad");
		cout << "Arbol ordenado de menor a mayor edad:\n\n";
		arbol->EnOrden();
		_getch();
	};
	function <void()> NovenaOpcion = [&]() {
		historyStack->push("Ver mapa de los locales en Lima");

		while (oplocal < 1 || oplocal > 9) {
			system("cls");
			cout << "\nEn que local se encuentra? ";
			cout << "\n1. " << local1;
			cout << "\n2. " << local2;
			cout << "\n3. " << local3;
			cout << "\n4. " << local4;
			cout << "\n5. " << local5;
			cout << "\n6. " << local6;
			cout << "\n7. " << local7;
			cout << "\n8. " << local8;
			cout << "\n9. " << local9 << "\n";
			cin >> oplocal;
		}
		system("cls");
		switch (oplocal)
		{
		case 1: historyStack->push("Ver distancia entre locales desde " + local1); break;
		case 2: historyStack->push("Ver distancia entre locales desde " + local2); break;
		case 3: historyStack->push("Ver distancia entre locales desde " + local3); break;
		case 4: historyStack->push("Ver distancia entre locales desde " + local4); break;
		case 5: historyStack->push("Ver distancia entre locales desde " + local5); break;
		case 6: historyStack->push("Ver distancia entre locales desde " + local6); break;
		case 7: historyStack->push("Ver distancia entre locales desde " + local7); break;
		case 8: historyStack->push("Ver distancia entre locales desde " + local8); break;
		case 9: historyStack->push("Ver distancia entre locales desde " + local9); break;
		}
		_getch();

	};
	function <void()> DecimaOpcion = [&]() {
		while (depto < 1 || depto > 7)
		{
			system("cls");
			cout << "Departamentos: " <<
				"\n 1. " << dep1 <<
				"\n 2. " << dep2 <<
				"\n 3. " << dep3 <<
				"\n 4. " << dep4 <<
				"\n 5. " << dep5 <<
				"\n 6. " << dep6 <<
				"\n 7. " << dep7 <<
				"\n\n Ingrese su opcion... ";
			cin >> depto;
		}
			system("cls");
			switch (depto) {
			case 1:
				historyStack->push("Productos comprados en el departamento de " + dep1);
				cout << "Lista de productos ordenados por codigo: \n";
				productosLima->inOrden();
				depto = 0;
				_getch();
				break;

			case 2:
				historyStack->push("Productos comprados en el departamento de " + dep2);
				cout << "Lista de productos ordenados por codigo: \n";
				productosLambayeque->inOrden();
				depto = 0;
				_getch();
				break;

			case 3:
				historyStack->push("Productos comprados en el departamento de " + dep3);
				cout << "Lista de productos ordenados por codigo: \n";
				productosPiura->inOrden();
				depto = 0;
				_getch();
				break;

			case 4:
				historyStack->push("Productos comprados en el departamento de " + dep4);
				cout << "Lista de productos ordenados por codigo: \n";
				productosAncash->inOrden();
				depto = 0;
				_getch();
				break;

			case 5:
				historyStack->push("Productos comprados en el departamento de " + dep5);
				cout << "Lista de productos ordenados por codigo: \n";
				productosJunin->inOrden();
				depto = 0;
				_getch();
				break;

			case 6:
				historyStack->push("Productos comprados en el departamento de " + dep6);
				cout << "Lista de productos ordenados por codigo: \n";
				productosAmazonas->inOrden();
				depto = 0;
				_getch();
				break;

			case 7:
				historyStack->push("Productos comprados en el departamento de " + dep7);
				cout << "Lista de productos ordenados por codigo: \n";
				productosLoreto->inOrden();
				depto = 0;
				_getch();
				break;
			}
	};
	function <void()> OnceavaOpcion = [&]() {
		system("cls");
		historyStack->push("Hora de ingreso de los empleados");
		quicksort(hora_ingreso, 0, 49);
		escribir(hora_ingreso, 50);
		_getch();
	};


	function <void()> Menu = [&]() {
		MostrarMenuPrincipal();
		cin >> opcion;
		if (opcion >= 1 && opcion <= 11) {
			switch (opcion)
			{
			case 1: PrimeraOpcion(); break;
			case 2: SegundaOpcion(); break;
			case 3: TerceraOpcion(); break;
			case 4: CuartaOpcion(); break;
			case 5: QuintaOpcion(); break;
			case 6: SextaOpcion(); break;
			case 7: SeptimaOpcion(); break;
			case 8: OctavaOpcion(); break;
			case 9: NovenaOpcion(); break;
			case 10: DecimaOpcion(); break;
			case 11: OnceavaOpcion(); break;
			case 12: exit(1);
			}
			Menu();
		}
		else { 
			opcion = 0;
			Menu();
		}
	};
	Menu();
}