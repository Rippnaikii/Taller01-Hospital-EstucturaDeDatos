#include "Hospital.hpp"
#include <iostream>

Hospital::Hospital()
{
    this->cabecera = nullptr;
}

void Hospital::ingresarSeccion(string nombre)
{
    Seccion* nuevaSeccion = new Seccion(nombre);
    NodoSeccion* nuevoNodo = new NodoSeccion(nuevaSeccion);

    if (this->cabecera == nullptr)
    {
        this->cabecera = nuevoNodo;
        return;
    }

    NodoSeccion* nodoActual = this->cabecera;

    while (nodoActual->getSgte() != nullptr)
    {
        nodoActual = nodoActual->getSgte();
    }

    nodoActual->setSgte(nuevoNodo);
}

Seccion* Hospital::buscarSeccion(string nombre)
{
    NodoSeccion* nodoActual = this->cabecera;

    while (nodoActual != nullptr)
    {
        if (nodoActual->getSeccion()->getNombre() == nombre)
        {
            return nodoActual->getSeccion();
        }

        nodoActual = nodoActual->getSgte();
    }

    return nullptr;
}

void Hospital::mostrarSecciones()
{
    NodoSeccion* nodoActual = this->cabecera;

    while (nodoActual != nullptr)
    {
        cout << "- " << nodoActual->getSeccion()->getNombre() << endl;
        nodoActual = nodoActual->getSgte();
    }
}

Hospital::~Hospital()
{
    NodoSeccion* nodoActual = this->cabecera;

    while (nodoActual != nullptr)
    {
        NodoSeccion* siguiente = nodoActual->getSgte();

        delete nodoActual->getSeccion();
        delete nodoActual;

        nodoActual = siguiente;
    }

    this->cabecera = nullptr;
}