#include "ColaPacientes.hpp"
#include <iostream>
using namespace std;

ColaPacientes::ColaPacientes()
{
    this->cabecera = nullptr;
    this->final = nullptr;
}

void ColaPacientes::ingresar(Paciente* paciente)
{
    NodoCola* nuevo = new NodoCola(paciente);

    if (cabecera == nullptr)
    {
        cabecera = nuevo;
        final = nuevo;
    }
    else
    {
        final->setSgte(nuevo);
        final = nuevo;
    }
}

bool ColaPacientes::estaVacia()
{
    return cabecera == nullptr;
}

Paciente* ColaPacientes::sacarPaciente()
{
    if (estaVacia())
    {
        return nullptr;
    }

    NodoCola* nodoAux = cabecera;
    Paciente* paciente = nodoAux->getPaciente();

    cabecera = cabecera->getSgte();

    if (cabecera == nullptr)
    {
        final = nullptr;
    }

    delete nodoAux;

    return paciente;
}

ColaPacientes::~ColaPacientes()
{
    while (!estaVacia())
    {
        Paciente* pacienteActual = sacarPaciente();
        delete pacienteActual;  //vamos eliminando mientras vamos sacando de la cola.. 
    }
}

void ColaPacientes::mostrarCola(){ 
    NodoCola* nodoActual = cabecera;

    while(nodoActual != nullptr){
        Paciente* pacienteActual = nodoActual->getPaciente(); //BUSCAMOS AL PACIENTE, PORQUE ESTABAMOS EN EL NODO SOLAMENTE..
        cout << "Nombre: " << pacienteActual->getNombre() << ", Edad: " << pacienteActual->getEdad() << ", ID: " << pacienteActual->getId() << ", Servicio: " << pacienteActual->getServicio() << endl;
        nodoActual = nodoActual->getSgte();
    
    }
}

