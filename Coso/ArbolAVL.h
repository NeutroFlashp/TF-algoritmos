#pragma once
#include "NodoAVL.h"

class ArbolAVL {
private:
    NodoAVL* raiz;

    void procesar(NodoAVL* e){
        cout << e->elemento.getCodigo() << "\n";
    }

    //Operaciones privadas
    int _altura(NodoAVL* nodo) {
        if (nodo == nullptr) return -1;
        return nodo->altura;
    }

    void _rotarDerecha(NodoAVL*& nodo) {
        int altura_root = nodo->altura;
        nodo->altura--;
        NodoAVL* p = nodo->izq;
        nodo->izq = p->der;
        p->der = nodo;
        //Actualizamos la altura
        p->altura = nodo->altura + 1;
        nodo = p;
    }

    void _rotarIzquierda(NodoAVL*& nodo) {
        int altura_root = nodo->altura;
        nodo->altura--;
        NodoAVL* p = nodo->der;
        nodo->der = p->izq;
        p->izq = nodo;
        //Actualizamos la altura
        p->altura = nodo->altura + 1;
        nodo = p;
    }
    void _balanceo(NodoAVL*& nodo) {
        int hizq = (nodo->izq == nullptr) ? -1 : _altura(nodo->izq);
        int hder = (nodo->der == nullptr) ? -1 : _altura(nodo->der);
        int fb = hder - hizq;

        if (fb > 1) { //rotar a la izq
            int hhizq = _altura(nodo->der->izq);
            int hhder = _altura(nodo->der->der);
            if (hhizq > hhder) { //verificar si aplica doble rotación
                _rotarDerecha(nodo->der);
            }
            _rotarIzquierda(nodo);
        }
        if (fb < -1) { //rotar a la der
            int hhizq = _altura(nodo->izq->izq);
            int hhder = _altura(nodo->izq->der);
            if (hhizq < hhder) {//verificar si aplica doble rotación 
                _rotarIzquierda(nodo->izq);
            }
            _rotarDerecha(nodo);
        }
        //Actualizar la altura del nodo raiz
        hizq = _altura(nodo->izq);
        hder = _altura(nodo->der);
        nodo->altura = 1 + ((hizq > hder) ? hizq : hder);
    }

    bool _insertar(NodoAVL*& nodo, Producto e) {

        if (nodo == nullptr) {
            //Nuevo elemento
            nodo = new NodoAVL();
            nodo->elemento = e;
            return true;
        }
        else if (e.getCodigo() == nodo->elemento.getCodigo()) {
            nodo->elemento.setCantidad(e.getCantidad() + nodo->elemento.getCantidad());
            return false;
        }
        else if (e.getCodigo() < nodo->elemento.getCodigo()) {
            _insertar(nodo->izq, e);
        }
        else if (e.getCodigo() > nodo->elemento.getCodigo()) {
            _insertar(nodo->der, e);
        }
        _balanceo(nodo);
        return true;
    }

    void _inOrden(NodoAVL* nodo) {
        if (nodo == nullptr) return;
        _inOrden(nodo->izq);
        procesar(nodo);
        _inOrden(nodo->der);
    }

public:
    ArbolAVL() {
        this->raiz = nullptr;
    }

    bool Insertar(Producto e) {
        return _insertar(raiz, e);
    }
    void inOrden() {
        _inOrden(raiz);
    }
};