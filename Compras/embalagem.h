#ifndef EMBALAGEM_H_INCLUDED
#define EMBALAGEM_H_INCLUDED
using namespace std;
#include <string>
#include "relogio.h"
#include "cinto.h"
#include "kit.h"

class Embalagem
{
public:
    Embalagem();
	Embalagem(string estampa, string tamanho);
    void PrintEstampa();
    string Estampa();
    string Tamanho();

private:
	string _estampa;
	string _tamanho;
};

#endif

