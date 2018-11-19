#include <string>
#include "embalagem.h"
#include <iostream>

Embalagem::Embalagem(string estampa, string tamanho)
{
    _estampa = estampa;
    _tamanho = tamanho;
}

Embalagem::Embalagem()
{
    _estampa = _tamanho = "";
}

void Embalagem::PrintEstampa()
{
    cout<<_estampa;
}

string Embalagem::Estampa()
{
    return _estampa;
}

string Embalagem::Tamanho()
{
    return _tamanho;
}
