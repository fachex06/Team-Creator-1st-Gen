#ifndef POKELEGEN_H
#define POKELEGEN_H

#include <PokemonOriginal.h>
#include <iostream>

using namespace std;

class PokeLegen : public PokemonOriginal
{
    public:
    PokeLegen();
    PokeLegen(const string nombre, const string tipo1, const string tipo2, int nivel, int hp, int ataque, int defensa, int especial, int velocidad,
                const string ubicacion);
    ~PokeLegen();

    string getUbicacion();
    void setUbicacion(const string ubicacion);

    void mostrarStats() const override;
    int calcularStatsTotales() const override;

    private:
    string ubicacion;
};

#endif // POKELEGEN_H
