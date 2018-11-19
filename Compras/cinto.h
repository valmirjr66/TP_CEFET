#ifndef CINTO_H_INCLUDED
#define CINTO_H_INCLUDED
#include <string>
using namespace std;
#include "acessorio.h"

class Cinto : public Acessorio
{
public:
    inline Cinto();
	inline Cinto(string tamanho, string nome, string marca, char genero, string codigo, double preco);
    inline void Embalar();

private:
	string _tamanho;
};

#endif
