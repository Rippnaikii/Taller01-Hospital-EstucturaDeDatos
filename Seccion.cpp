#include "Seccion.hpp"

Seccion::Seccion(string nombre){ // al parecer no es necesario incluir el <string>, ya que importamos Seccion.hpp
    this->nombre = nombre;
    this->cabecera = nullptr;
}

string Seccion::getNombre(){return this->nombre;}

void Seccion::ingresarPaciente(Paciente* p){
    //FALTA ESTO...
}
void Seccion::mostrarEstado(){
    cout << "=== ESTADO " << this->nombre << " ===" << endl;
    
    if (this->cabecera == nullptr) {
        cout << "No hay pacientes en este departamento." << endl;
        return;
    }
    NodoPaciente* nodoActual = this->cabecera; // o solo cabecera??
    int contador = 0;
    while (nodoActual != nullptr)
    {
        contador++;
        nodoActual = nodoActual->getSgte();
    }
    cout << "Pacientes en el departamento de " << this->nombre << ": " << contador << endl;

    nodoActual = this->cabecera; // Reiniciamos el cursor al inicio
    while (nodoActual != nullptr) {
        Paciente* p = nodoActual->getPaciente();
        cout << "- " << p->getNombre() << " (" << p->getEdad() << ")" << endl;
        nodoActual = nodoActual->getSgte();
    }
    

}

Seccion::~Seccion(){

}