#ifndef RELOGIO_H
#define RELOGIO_H
#include <string>
#include "acessorio.h"
#include "colecionavel.h"
using namespace std;

class Relogio : public Acessorio, public Colecionavel
{
public:
    inline Relogio();
    inline Relogio(char tipo, string nome, string marca, char genero, string codigo, double preco, int ano, int edicao);
    inline void Gravar();
    inline void Embalar();

private:
	char _tipo;
};

#endif
