#pragma once
#include <string>
using namespace std;

class NodeStack 
{

public:

	string data;
	NodeStack* next;

	NodeStack(string data, NodeStack* next = nullptr) {
		this->data = data;
		this->next = next;
	}
};
class Stack
{
private:

	NodeStack* top;

public:
	Stack() { top = nullptr; }
	~Stack() {}

	bool isEmpty() { return top == nullptr; }

	void push(string v) {
		if (isEmpty()) {
			top = new NodeStack(v);
		}
		else
		{
			NodeStack* n = new NodeStack(v, top);
			top = n;

		}
	}

	string pop() {
		if (isEmpty()) {
			return "NULL";
		}
		else
		{
			NodeStack* aux = top;
			string data = (string)(top->data);
			top = (NodeStack*)top->next;

			aux->next = nullptr;
			delete aux;

			return data;
		}
	}

	void printStack() {

		cout << "Historial de acciones\n";
		NodeStack* aux = top;
			
			do{
				cout << "\n" << aux->data ;
				aux = aux->next;
			} while (aux != nullptr);
		
	}
};