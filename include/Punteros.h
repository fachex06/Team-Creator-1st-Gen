#ifndef PUNTEROS_H
#define PUNTEROS_H

#include <PokeLegen.h>
#include <PokeEspecializado.h>
#include <vector>
#include <memory>

using namespace std;

class Punteros
{
    public:
        Punteros();
        virtual ~Punteros();

        void mostrarMenu();
        void agregarPoke();
        void buscarPoke();
        void eliminarPoke();
        void mostrarRegistro();
        void mostrarInfo();
        void limpiarBuffer();


    private:
    vector<unique_ptr<PokemonOriginal>> pokedex;
    PokemonOriginal*** punteros;
    int capacidad;

    void crearPunteros();
    void limpiarMemoria();
    int buscarNombre(string& nombre);
    void iniciarPokemonBase();
};

#endif // PUNTEROS_H
