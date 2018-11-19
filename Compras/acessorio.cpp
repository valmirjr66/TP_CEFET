#include "acessorio.h"
#include <string>
#include <iostream>
using namespace std;

double Acessorio::Preco() const
{
    return _preco;
}
string Acessorio::Nome() const
{
    return _nome;
}

void Acessorio::PrintPreco()
{
    cout << _preco;
}

void Acessorio::PrintNome()
{
    cout << _nome;
}

void Acessorio::Listar()
{
    cout<< "Nome: " << _nome << "\n"
        << "Marca: " << _marca << "\n"
        << "Genero: " << _genero << "\n"
        << "Codigo: " << _codigo << "\n"
        << "Preco: " << _preco << "\n";
}
