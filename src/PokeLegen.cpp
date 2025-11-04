#include "PokeLegen.h"


PokeLegen::PokeLegen():
PokemonOriginal(),
ubicacion()
{}

PokeLegen::PokeLegen(const string nombre, const string tipo1, const string tipo2, int nivel, int hp, int ataque, int defensa, int especial, int velocidad,
                const string ubicacion):

PokemonOriginal(nombre, tipo1, tipo2, nivel, hp, ataque, defensa, especial, velocidad),
ubicacion(ubicacion)
{}

string PokeLegen::getUbicacion()
{
    return ubicacion;
}

void PokeLegen::setUbicacion(const string ubicacion)
{
    this->ubicacion=ubicacion;
}

void PokeLegen::mostrarStats() const 
{
    PokemonOriginal::mostrarStats();

    cout << "Ubicacion: " << ubicacion << endl;
}

int PokeLegen::calcularStatsTotales() const
{
    return PokemonOriginal::calcularStatsTotales() * 1.2;
}

PokeLegen::~PokeLegen()
{
    //dtor
}
