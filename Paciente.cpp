#include "Paciente.hpp"

Paciente::Paciente(string nombre, int edad, int id, string servicio): Persona(nombre, edad)
{
    this->id = id;
    this->servicio = servicio;
}

Paciente::~Paciente()
{}

string Paciente::getServicio()
{
    return this->servicio;
}
void Paciente::setServicio(string servicio)
{
    this->servicio = servicio;
}
int Paciente::getId()
{
    return this->id;
}
void Paciente::setId(int id)
{
    this->id = id;
}