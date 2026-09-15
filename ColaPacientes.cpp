#include "ColaPacientes.hpp"

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
{}

//Falta implementar sacarPaciente, estaVacia y mostrarCola
//logica fifo
