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

ColaPacientes::~ColaPacientes()
{}

//Falta implementar sacarPaciente, estaVacia y mostrarCola
//logica fifo
