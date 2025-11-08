#ifndef POKEESPECIALIZADO_H
#define POKEESPECIALIZADO_H
#include <PokemonOriginal.h>
#include <iostream>

using namespace std;


class PokeStarter : public PokemonOriginal
{
    public:
        PokeStarter();
        PokeStarter(const string nombre, const string tipo1, const string tipo2, int nivel, int hp, int ataque, int defensa, int especial, int velocidad
        , const string evolucion, bool puedeEvolucionar);
        ~PokeStarter();

        string getEvolucion();
        void setEvolucion(const string evolucion);

        bool getPuedeEvolucionar();
        void setPuedeEvolucionar(bool puedeEvolucionar);

        void mostrarStats() const override;
        

    private:
    string evolucion;
    bool puedeEvolucionar;
};

#endif // POKEESPECIALIZADO_H
