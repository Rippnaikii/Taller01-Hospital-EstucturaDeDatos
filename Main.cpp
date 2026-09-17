#include <iostream>
#include <fstream>
#include <string>
#include "ColaPacientes.hpp"
#include "Seccion.hpp"
#include "Hospital.hpp"
using namespace std;


int main(int argc, char const *argv[])
{
    ColaPacientes filaPacientes;
    ifstream archivo("pacientes.txt");
    if (!archivo.is_open()){
        cout << "No se pudo abrir el archivo.." << endl;
        return 1;
    }
    char linea[500]; //array de caracteres para la linea..
    while(archivo.getline(linea,500)){
        char* puntero = linea; //puntero que recorre la linea..
        char* inicioPalabra = linea; //se queda al principio sin avanzar..

        string nombre;
        string servicio;
        string id;
        int edad = 0;
        int partes = 0;

        while (*puntero != '\0') //mientas no sea el final de la linea.. importante las '' es un caracter
        {
            if (*puntero == ';')
            {
                *puntero = '\0'; //asi se corta la palabra

                switch (partes) //switch porque soy un pro..
                {
                case 0:
                    id = inicioPalabra;
                    break;
                case 1:
                    nombre = inicioPalabra;
                    break;
                case 2:
                    edad = stoi(inicioPalabra);
                    break;
                default:
                    cout<<"Algo salió mal.."<<endl;
                    break;
                }

                inicioPalabra = puntero + 1;
                partes++;
            }
            puntero++; //este va letra por letra..
        
            
        }
        servicio = inicioPalabra; //donde quedo el puntero al final.. ya que no tiene ;

        Paciente* nuevoPaciente = new Paciente(nombre,edad,id,servicio);
        filaPacientes.ingresar(nuevoPaciente);
    }
    archivo.close();

    filaPacientes.mostrarCola();

    Hospital hospital;

    hospital.ingresarSeccion("Urgencias");
    hospital.ingresarSeccion("Medicina General");
    hospital.ingresarSeccion("Cardiologia");
    hospital.ingresarSeccion("Neurologia");
    hospital.ingresarSeccion("Traumatologia");
    hospital.ingresarSeccion("Cirugia");
    hospital.ingresarSeccion("Pediatria");
    hospital.ingresarSeccion("Hospitalizacion");

    cout << endl;
    cout << "=== SECCIONES DEL HOSPITAL ===" << endl;
    hospital.mostrarSecciones();

    Paciente* pacienteAtendido = filaPacientes.sacarPaciente();

    if (pacienteAtendido != nullptr)
    {
        Seccion* seccionPaciente = hospital.buscarSeccion(
            pacienteAtendido->getServicio()
        );

        if (seccionPaciente != nullptr)
        {
            seccionPaciente->ingresarPaciente(pacienteAtendido);
        }
    }

    cout << endl;

    Seccion* cardiologia = hospital.buscarSeccion("Cardiologia");

    if (cardiologia != nullptr)
    {
        cardiologia->mostrarEstado();
    }

    return 0;
}
