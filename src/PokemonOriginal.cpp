#include "PokemonOriginal.h"
#include <iostream>

using namespace std;

int PokemonOriginal::totalPokemon = 0;

PokemonOriginal::PokemonOriginal() :
nombre(""),
tipo1("Normal"),
tipo2(""),
nivel(5),
hp(20),
ataque(10),
defensa(10),
especial(10),
velocidad(10)
{
    totalPokemon++;
}

PokemonOriginal::PokemonOriginal(const string nombre, const string tipo1, const string tipo2, int nivel, int hp, int ataque, int defensa, int especial, int velocidad):
nombre(nombre),
tipo1(tipo1),
tipo2(tipo2),
nivel(nivel),
hp(hp),
ataque(ataque),
defensa(defensa),
especial(especial),
velocidad(velocidad)
{
    totalPokemon++;
}

string PokemonOriginal::getNombre()
{
    return nombre;
}

void PokemonOriginal::setNombre(const string nombre)
{
    this->nombre = nombre;
}

string PokemonOriginal::getTipo1()
{
    return tipo1;
}

void PokemonOriginal::setTipo1(const string tipo1)
{
    this->tipo1 = tipo1;
}

string PokemonOriginal::getTipo2()
{
    return tipo2;
}

void PokemonOriginal::setTipo2(const string tipo2)
{
    this->tipo2 = tipo2;
}

int PokemonOriginal::getHP()
{
    return hp;
}

void PokemonOriginal::setHP(int hp)
{
    this->hp = hp;
}

int PokemonOriginal::getAtaque()
{
    return ataque;
}

void PokemonOriginal::setAtaque(int ataque)
{
    this->ataque = ataque;
}

int PokemonOriginal::getDefensa()
{
    return defensa;
}

void PokemonOriginal::setDefensa(int defensa)
{
    this->defensa = defensa;
}

int PokemonOriginal::getEspecial()
{
    return especial;
}

void PokemonOriginal::setEspecial(int especial)
{
    this->especial = especial;
}

int PokemonOriginal::getVelocidad()
{
    return velocidad;
}

void PokemonOriginal::setVelocidad(int velocidad)
{
    this->velocidad = velocidad;
}

int PokemonOriginal::getTotalPokemon()
{
    return totalPokemon;
}

PokemonOriginal PokemonOriginal::operator+(const PokemonOriginal& otro) const{
    return PokemonOriginal(nombre + "+" + otro.nombre, tipo1, tipo2,
        (nivel + otro.nivel)/2,
        (hp + otro.hp)/2,
        (ataque + otro.ataque)/2,
        (defensa + otro.defensa)/2,
        (especial + otro.especial)/2,
        (velocidad + otro.velocidad)/2);
}

PokemonOriginal PokemonOriginal::operator*(int multi) const {
    return PokemonOriginal(nombre, tipo1, tipo2,
    nivel * multi,
    hp * multi,
    ataque * multi,
    defensa * multi,
    especial * multi,
    velocidad * multi);
}

PokemonOriginal& PokemonOriginal::operator++()
{
    nivel = nivel + 1;
    hp += 2;
    ataque++;
    defensa++;
    especial++;
    velocidad++;
    return *this;
}

PokemonOriginal& PokemonOriginal::operator--()
{
    nivel = nivel - 1;
    return *this;
}

bool PokemonOriginal::operator==(const PokemonOriginal& otro) const
{
    return nombre == otro.nombre;
}

PokemonOriginal& PokemonOriginal::operator*=(int multi)
{
    hp *= multi;
    ataque*= multi;
    defensa *= multi;
    especial *= multi;
    velocidad *= multi;
    return *this;
}

ostream& operator<<(ostream& out, const PokemonOriginal& pokemon)
{
    out << pokemon.nombre << " Nv." << pokemon.nivel << "[" << pokemon.tipo1;
    if (!pokemon.tipo1.empty()) out << "/" << pokemon.tipo2;
    out << "] PS:" << pokemon.hp << "ATQ: " << pokemon.ataque
        << " DEF: " << pokemon.defensa << " ESP: " << pokemon.especial
        << " VEL: " << pokemon.velocidad;
    return out;
}

istream& operator>>(istream& in, PokemonOriginal& pokemon)
{
    cout << "Nombre: ";
    in >> pokemon.nombre;
    cout << "Tipo 1: ";
    in >> pokemon.tipo1;
    cout << "Tipo 2 (si no tiene, dejalo vacio): ";
    in >> pokemon.tipo2;
    cout << "Nivel: ";
    in >> pokemon.nivel;
    cout << "PS: ";
    in >> pokemon.hp;
    cout << "Ataque: ";
    in >> pokemon.ataque;
    cout << "Defensa: ";
    in >> pokemon.defensa;
    cout << "Especial: ";
    in >> pokemon.especial;
    cout << "Velocidad: ";
    in >> pokemon.velocidad;

    return in;
}

void PokemonOriginal::mostrarStats() const
{
    cout << "Estadisticas de " << nombre << endl;
    cout << "Nivel: " << nivel << endl;
    cout << "Tipo: " << tipo1;
    if (!tipo2.empty()) cout << "/" << tipo2;
    cout << endl;
    cout << "PS: " << hp << endl;
    cout << "Ataque: " << ataque << endl;
    cout << "Defensa: " << defensa << endl;
    cout << "Especial: " << especial << endl;
    cout << "Velocidad: " << velocidad << endl;
    cout << "Stat Total: " << calcularStatsTotales() << endl;
}

int PokemonOriginal::calcularStatsTotales() const
{
    return hp + ataque + defensa + especial + velocidad;
}

PokemonOriginal::~PokemonOriginal()
{
    //dtor
}
