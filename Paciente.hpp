#include <string>
#include "Persona.hpp"
using namespace std;
class Paciente: public Persona{
private:
    int id;
    string servicio;
public:
    Paciente(string nombre, int edad, int id, string servicio);
    string getServicio();
    void setServicio(string servicio);
    int getId();
    void setId(int id);
    ~Paciente();
};
