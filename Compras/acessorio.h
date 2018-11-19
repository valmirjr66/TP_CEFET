#ifndef ACESSORIO_H_INCLUDED
#define ACESSORIO_H_INCLUDED
#include <string>
using namespace std;

class Acessorio
{
public:
	void PrintPreco();
	void PrintNome();
	void Listar();
    double Preco() const;
    string Nome() const;
protected:
	string _nome;
	string _marca;
	char _genero;
	string _codigo;
	double _preco;
};

#endif
