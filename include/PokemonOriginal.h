#ifndef POKEMONORIGINAL_H
#define POKEMONORIGINAL_H
#include <string>
#include <iostream>
#include <vector>

using namespace std;

class PokemonOriginal
{
    public:
    PokemonOriginal();
    PokemonOriginal(const string nombre, const string tipo1, const string tipo2, int nivel, int hp, int ataque, int defensa, int especial, int velocidad);

    virtual ~PokemonOriginal();

    string getNombre();
    void setNombre(const string nombre);

    string getTipo1();
    void setTipo1(const string tipo1);

    string getTipo2();
    void setTipo2(const string tipo2);

    int getHP();
    void setHP(int hp);

    int getAtaque();
    void setAtaque(int ataque);

    int getDefensa();
    void setDefensa(int defensa);

    int getEspecial();
    void setEspecial(int especial);

    int getVelocidad();
    void setVelocidad(int velocidad);

    static int getTotalPokemon();

    PokemonOriginal operator+(const PokemonOriginal& otro) const;
    PokemonOriginal operator*(int multi) const;
    PokemonOriginal& operator++();
    PokemonOriginal& operator--();
    bool operator==(const PokemonOriginal& otro) const;
    PokemonOriginal& operator*=(int multi);
    friend ostream& operator<<(ostream& out, const PokemonOriginal& pokemon);
    friend istream& operator>>(istream& in, PokemonOriginal& pokemon);

    virtual void mostrarStats() const;
    virtual int calcularStatsTotales() const;


    protected:
    string nombre;
    string tipo1;
    string tipo2;
    int nivel;
    int hp;
    int ataque;
    int defensa;
    int especial;
    int velocidad;
    static int totalPokemon;
};

#endif // POKEMONORIGINAL_H
