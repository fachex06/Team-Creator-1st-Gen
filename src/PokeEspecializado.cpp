#include "PokeEspecializado.h"

PokeStarter::PokeStarter():
PokemonOriginal(),
evolucion(""),
puedeEvolucionar(false)
{}

PokeStarter::PokeStarter(const string nombre, const string tipo1, const string tipo2, int nivel, int hp, int ataque, int defensa, int especial, int velocidad,
const string evolucion, bool puedeEvolucionar) :

PokemonOriginal(nombre, tipo1, tipo2, nivel, hp, ataque, defensa, especial, velocidad),
evolucion(evolucion),
puedeEvolucionar(puedeEvolucionar)
{}

string PokeStarter::getEvolucion()
{
    return evolucion;
}

void PokeStarter::setEvolucion(const string evolucion)
{
    this->evolucion=evolucion;
}

bool PokeStarter::getPuedeEvolucionar()
{
    return puedeEvolucionar;
}

void PokeStarter::setPuedeEvolucionar(bool puedeEvolucionar)
{
    this->puedeEvolucionar=puedeEvolucionar;
}

void PokeStarter::mostrarStats() const
{
    cout << "Puede evolucionar: " << (puedeEvolucionar ? "Si" : "No") << endl;
}

PokeStarter::~PokeStarter()
{
    //dtor
}
