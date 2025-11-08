#include "Punteros.h"
#include "PokeEspecializado.h"
#include <iostream>

using namespace std;

void Punteros::limpiarBuffer() {
    cin.clear();
    cin.ignore(1000, '\n');
}

Punteros::Punteros()
{
    punteros = nullptr;
    capacidad = 0;
    crearPunteros();
    iniciarPokemonBase();
}

Punteros::~Punteros()
{
    limpiarMemoria();
}

void Punteros::crearPunteros()
{
    capacidad = 12;
    punteros = new PokemonOriginal**[capacidad];
    for (int i = 0; i < capacidad; i++) {
        punteros[i] = new PokemonOriginal*[6];
        for(int j=0; j < 6; j++) {
            punteros[i][j] = nullptr;
        }
    }
}

void Punteros::limpiarMemoria()
{
    if(punteros){
        for(int i = 0; i < capacidad; i++) {
            delete[] punteros[i];
        }
        delete[] punteros;
    }
}

void Punteros::iniciarPokemonBase(){
    pokedex.push_back(make_unique<PokeStarter>("Bulbasaur", "Planta", "Veneno", 15, 20, 15, 15, 22, 26, "Ivysaur", true));
        
    pokedex.push_back(make_unique<PokeLegen>("Zapdos", "Electrico","Volador", 65, 230, 140, 135, 430, 125, "Central de Energia"));
}

void Punteros::mostrarMenu()
{
    int opc;

    do {
        system("cls");
        cout << "==== Agenda de Pokemones =====" << endl;
        cout << "1. Agregar Pokemon. " << endl;
        cout << "2. Buscar Pokemon" << endl;
        cout << "3. Eliminar Pokemon." << endl;
        cout << "4. Mostrar Lista Completa. " << endl;
        cout << "5. Enlistar stats" << endl;
        cout << "6. Salir" << endl;
        cout << "Total Registrados: " << pokedex.size() << endl;
        cout << "Escoga una opcion: ";
        cin >> opc;
        limpiarBuffer();

        switch(opc){
            case 1: 
                agregarPoke(); 
                break;
            case 2: 
                buscarPoke(); 
                break;
            case 3: 
                eliminarPoke(); 
                break;
            case 4: 
                mostrarRegistro(); 
                break;
            case 5: 
                mostrarInfo(); 
                break;
            case 6:
                cout << "Adios!" << endl;
                break;
            default:
                cout << "Opcion no valida" << endl;
        }

        if (opc != 6)
        {
            cout << "\nPresiona ENTER para continuar...";
            cin.get();
        }
    } while(opc != 6);
}

void Punteros::agregarPoke()
{
    system("cls");
    int tipo;

    cout << "Selecciona el tipo:" << endl;
    cout << "1. Comun." << endl;
    cout << "2. Starter" << endl;
    cout << "3. Legendario" << endl;
    cout << "Escoge: ";
    cin >> tipo;
    limpiarBuffer();

    string nombre, tipo1, tipo2;
    int nivel, hp, ataque, defensa, especial, velocidad;

    cout << "Nombre: ";
    getline(cin, nombre);
    cout << "Tipo 1: ";
    getline(cin, tipo1);
    cout << "Tipo 2 (si no tiene dejalo vacio): ";
    getline(cin, tipo2);

    cout << "Nivel: ";
    cin >> nivel;
    cout << "HP: ";
    cin >> hp;
    cout << "Ataque: ";
    cin >> ataque;
    cout << "Defensa: ";
    cin >> defensa;
    cout << "Especial: ";
    cin >> especial;
    cout << "Velocidad: ";
    cin >> velocidad;
    limpiarBuffer();

    switch (tipo) {
        case 1: {
            auto pokemon = make_unique<PokemonOriginal>(nombre, tipo1, tipo2, nivel, hp, ataque, defensa, especial, velocidad);
            pokedex.push_back(move(pokemon));
            break;
        }
        case 2: {
            string evolucion;
            bool puedeEvolucionar;
            
            cout << "Evolucion: ";
            getline(cin, evolucion);
            cout << "Puede evolucionar? (1=Si, 0=No): ";
            cin >> puedeEvolucionar;
            limpiarBuffer();
            
            auto pokemon = make_unique<PokeStarter>(
                nombre, tipo1, tipo2, nivel, hp, ataque, defensa, especial, velocidad, 
                evolucion, puedeEvolucionar);
            pokedex.push_back(move(pokemon));
            break;
        }
        case 3: {
            string ubicacion;
            cout << "Ubicacion: ";
            getline(cin, ubicacion);
            
            auto pokemon = make_unique<PokeLegen>(
                nombre, tipo1, tipo2, nivel, hp, ataque, defensa, especial, velocidad, ubicacion);
            pokedex.push_back(move(pokemon));
            break;
        }
        default:
            cout << "Tipo no valido." << endl;
            return;
    }

    cout << "Agregado exitosamente!" << endl; 
}

void Punteros::buscarPoke()
{
    system("cls");
    cout << "=== Buscar Pokemon ===" << endl;
    
    if (pokedex.empty())
    {
        cout << "La Pokedex esta vacia. " << endl;
        return;
    }

    string nombre;
    cout << "Ingrese el nombre del Pokemon a buscar: ";
    getline(cin, nombre);

    int ind = buscarNombre(nombre);
    if (ind != -1)
    {
        cout << "\nPokemon encontrado: " << endl;
        pokedex[ind]->mostrarStats();
    } else{
        cout << "Pokemon no encontrado. " << endl;
    }
}

void Punteros::eliminarPoke(){
    system("cls");
    cout << "=== Borrar Pokemon ===" << endl;

    if (pokedex.empty())
    {
        cout << "La Pokedex esta vacia. " << endl;
        return;
    }

    string nombre;
    cout << "Ingrese el nombre del Pokemon a eliminar: ";
    getline(cin, nombre);

    int ind = buscarNombre(nombre);
    if (ind != -1) {
        cout << "\nPokemon a borrar:" << endl;
        pokedex[ind]->mostrarStats();

        char conf;
        cout << "Quiere eliminar este pokemon? (s/n): ";
        cin >> conf;
        limpiarBuffer();

        if(conf == 's'|| conf =='S'){
            pokedex.erase(pokedex.begin() + ind);
            cout << "Pokemon eliminado exitosamente!" << endl;
        }
        else{
            cout << "Eliminacion cancelada" << endl;
        }
    }
    else{
       cout << "Pokemon no encontrado..." << endl;
    }
}

void Punteros::mostrarRegistro()
{
    system("cls");
    cout << "=== Pokedex Completa ==="  << endl;

    if (pokedex.empty()) {
        cout << "La Pokedex esta vacia." << endl;
        return;
    }

    for(size_t i = 0; i < pokedex.size(); i++){
        cout << i + 1 << ". ";
        pokedex[i]->mostrarStats();
        cout << "----------------------"<< endl;
    }
}

void Punteros::mostrarInfo(){
    system("cls");
    cout << "=== Estadisticas ===" << endl;
    cout << "Total de Pokemon: " << pokedex.size() << endl;
    
    if (pokedex.empty()) {
        cout << "No hay pokemon registrados." << endl;
        return;
    }

    int statTotalMax = 0;
    string pokemonMasFuerte;

    for(const auto& pokemon : pokedex) {
        int stats = pokemon->calcularStatsTotales();
        if (stats > statTotalMax) {
            statTotalMax = stats;
            pokemonMasFuerte = pokemon->getNombre();
        }
    }

    cout << "Pokemon mas fuerte: " << pokemonMasFuerte << endl;
    cout << "Stat total mas alto: " << statTotalMax << endl;
}

int Punteros::buscarNombre(string& nombre) {
    for(size_t i = 0; i < pokedex.size(); i++){
        if(pokedex[i]->getNombre() == nombre){
            return i;
        }
    }
    return -1;
}