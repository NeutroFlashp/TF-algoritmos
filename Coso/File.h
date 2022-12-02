#pragma once
#include <fstream>
#include <iostream>
#include <stdlib.h>
#include <string>

//using namespace System;
using namespace std;
template <typename T>
class File {
private:
	ofstream fileWrite;
	ifstream fileRead;

	/*string dep1, dep2, dep3, dep4, dep5, dep6, dep7;
	string local1, local2, local3, local4, local5, local6, local7, local8, local9;*/
	T dep1, dep2, dep3, dep4, dep5, dep6, dep7;
	T local1, local2, local3, local4, local5, local6, local7, local8, local9;

public:
	File() {
		readData();
	}
	~File() {}

	void readData() {
		fileRead.open("archivo.txt", ios::in);
		if (fileRead.fail()) {
			fileRead.close();

			fileWrite.open("archivo.txt", ios::out);
			fileWrite << "Lima" << endl;
			fileWrite << "Lambayeque" << endl;
			fileWrite << "Piura" << endl;
			fileWrite << "Ancash" << endl;
			fileWrite << "Junin" << endl;
			fileWrite << "Amazonas" << endl;
			fileWrite << "Loreto" << endl;

			fileWrite << "Mc Donalds" << endl;
			fileWrite << "KFC" << endl;
			fileWrite << "Excelencia" << endl;
			fileWrite << "Bembos" << endl;
			fileWrite << "Rokys" << endl;
			fileWrite << "Popeyes" << endl;
			fileWrite << "Broaster Kong" << endl;
			fileWrite << "Naoki Chicken" << endl;
			fileWrite << "Rustica" << endl;

			fileWrite.close();
			fileRead.open("archivo.txt", ios::in);
		}

		getline(fileRead, dep1);
		getline(fileRead, dep2);
		getline(fileRead, dep3);
		getline(fileRead, dep4);
		getline(fileRead, dep5);
		getline(fileRead, dep6);
		getline(fileRead, dep7);

		getline(fileRead, local1);
		getline(fileRead, local2);
		getline(fileRead, local3);
		getline(fileRead, local4);
		getline(fileRead, local5);
		getline(fileRead, local6);
		getline(fileRead, local7);
		getline(fileRead, local8);
		getline(fileRead, local9);

		fileRead.close();
	}

	T getDep1() { return dep1; }
	T getDep2() { return dep2; }
	T getDep3() { return dep3; }
	T getDep4() { return dep4; }
	T getDep5() { return dep5; }
	T getDep6() { return dep6; }
	T getDep7() { return dep7; }

	T getLocal1() { return local1; }
	T getLocal2() { return local2; }
	T getLocal3() { return local3; }
	T getLocal4() { return local4; }
	T getLocal5() { return local5; }
	T getLocal6() { return local6; }
	T getLocal7() { return local7; }
	T getLocal8() { return local8; }
	T getLocal9() { return local9; }

};