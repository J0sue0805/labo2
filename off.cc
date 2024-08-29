#include <iostream>

#include <string>

struct PersonajeRPG
{
    std::string nombre;
    int salud;
    int nivel;
    int poder;
    std::string tipo;
};

// Poder Promedio

// Subir de Nivel
void SubirNivel(PersonajeRPG personajes[], int tamano);
// Mostrar datos
void MostrarDatos(PersonajeRPG personajes[], int tamano);

// Pedir datos

void LlenarInfoPj(PersonajeRPG personajes[], int tamano);

int main(int argc, char *argv[])
{
    int numero_de_personajes = 0;

    std::cout << "Ingrese el numero de personajes a crear: ";
    std::cin >> numero_de_personajes;

    PersonajeRPG personajes[numero_de_personajes];
    LlenarInfoPj(personajes, numero_de_personajes);
    SubirNivel(personajes, numero_de_personajes);

    MostrarDatos(personajes, numero_de_personajes);

    return 0;
}

void LlenarInfoPj(PersonajeRPG personajes[], int tamano)
{

    for (int i = 0; i < tamano; ++i)
    {
        std::cout << "---------------------------------------------------------" << std::endl;
        std::cout << "Ingrese el nombre del personaje:  ";
        std::cin.ignore();
        std::getline(std::cin, personajes[i].nombre);
        std::cout << "Ingrese el valor de salud del personaje:  ";
        std::cin >> personajes[i].salud;
        std::cout << "Ingrese el nivel del personaje:  ";
        std::cin >> personajes[i].nivel;
        std::cout << "Ingrese el valor del poder del personaje:  ";
        std::cin >> personajes[i].poder;
        std::cin.ignore();
        std::cout << "Ingrese el tipo de personaje: (Mago - Guerrero - etc...) ";
        std::cin >> personajes[i].tipo;
    }
}

void MostrarDatos(PersonajeRPG personajes[], int tamano)
{

    for (int i = 0; i < tamano; ++i)
    {
        std::cout << "---------------------------------------------------------" << std::endl;
        std::cout << "Datos del Personaje" << std::endl;
        std::cout << "Nombre: " << personajes[i].nombre << std::endl;
        std::cout << "Salud: " << personajes[i].salud << std::endl;
        std::cout << "Nivel: " << personajes[i].nivel << std::endl;
        std::cout << "Poder: " << personajes[i].poder << std::endl;
        std::cout << "Tipo: " << personajes[i].tipo << std::endl;
        std::cout << "---------------------------------------------------------" << std::endl;
    }
}

void SubirNivel(PersonajeRPG personajes[], int tamano)
{

    for (int i = 0; i < tamano; ++i)
    {
        personajes[i].nivel++;

        if (personajes[i].tipo == "Mago")
        {
            personajes[i].poder += 5;
        }
        else if (personajes[i].tipo == "Guerrero")
        {
            personajes[i].poder += 3;
        }
        else
        {
            personajes[i].poder += 2;
        }
    }
}