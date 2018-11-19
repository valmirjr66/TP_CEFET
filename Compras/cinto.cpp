#include "cinto.h"
#include <string>
using namespace std;

Cinto::Cinto(string tamanho, string nome, string marca, char genero, string codigo, double preco)
{
    _tamanho = tamanho;
    _nome = nome;
    _marca = marca;
    _genero = genero;
    _codigo = codigo;
    _preco = preco;
}

Cinto::Cinto()
{
    _tamanho = "-";
    _nome = "-";
    _marca = "-";
    _genero = '-';
    _codigo = "-";
    _preco = 0;
}

void Cinto::Embalar()
{
    _preco += 3;
}
