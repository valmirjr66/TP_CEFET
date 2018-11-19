#include "relogio.h"
#include <string>
#include <iostream>
#include "acessorio.h"
#include "colecionavel.h"
using namespace std;

Relogio::Relogio(char tipo, string nome, string marca, char genero, string codigo, double preco, int ano, int edicao)
{
    _nome = nome;
    _marca = marca;
    _genero = genero;
    _codigo = codigo;
    _preco = preco;
    _tipo = tipo;
    _ano = ano;
    _edicao = edicao;
}

Relogio::Relogio()
{
    _nome = "NULL";
    _marca = "-";
    _genero = '-';
    _tipo = '-';
    _codigo = "-";
    _preco = 0;
    _ano = 0;
    _edicao = 0;
}

void Relogio::Gravar()
{
    _preco += 10;
}

void Relogio::Embalar()
{
    _preco += 5;
}
