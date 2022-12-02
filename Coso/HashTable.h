#pragma once
#include <iostream>
#include <vector>
#include <list>
#include <string>
#include "Cliente.h"

using namespace std;

class HashEntidad {
private:
	int key;
	Cliente value;

public:
	HashEntidad() {}
	HashEntidad(int key, Cliente value) {
		this->key = key;
		this->value = value;
	}
	int getKey() {
		return key;
	}
	Cliente getValue() {
		return value;
	}
};


class HashTabla
{
private:
	vector<list<HashEntidad>> theLists;
	size_t currentSize;
	size_t myhash(const int key) const {
		size_t hashVal = key;
		hashVal %= theLists.size();
		return hashVal;
	}

public:
	HashTabla(int size = 100) : currentSize{ 0 } {
		theLists.resize(size);
	}

	void makeEmpty() {
		for (auto& thisList : theLists)
			thisList.clear();
	}

	bool insert(HashEntidad&& x) {
		auto& whichList = theLists[myhash(x.getKey())];
		whichList.push_back(x);
		return true;
	}
	void DispAll() {
		size_t pos = 0;
		for (auto& thisList : theLists) {
			cout << "Key: " + to_string(pos) << "\t | ";
			for (auto& it : theLists[pos]) {
				cout << it.getValue().getName() << ", ";
			}
			cout << endl;
			pos++;
		}
	}

};