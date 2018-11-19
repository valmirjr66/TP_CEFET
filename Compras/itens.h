#ifndef ITENS_H_INCLUDED
#define ITENS_H_INCLUDED
#include "relogio.h"
#include "cinto.h"
#include "kit.h"
#include "embalagem.h"
#include <string>

using namespace std;

class Itens
{
public:
    Itens();

	void add_relogio(Relogio relogio);
	void add_cinto(Cinto cinto);
	void add_kit(Kit kit);
	void add_embalagem(Embalagem embalagem);

	void listar_relogios();
    void listar_cintos();
	void listar_kits();
	void listar_embalagens();

	bool itemExistente(int tipo, int index);
	double getPreco(int tipo, int index);
	string getNome(int tipo, int index);

	Relogio selecionarRelogio(int i);
	Cinto selecionarCinto(int i);
	Kit selecionarKit(int i);
    Embalagem selecionarEmbalagem(int i);

private:
    Relogio _itens_relogio[100];
	int _cardinalidade_relogio;

	Cinto _itens_cinto[100];
	int _cardinalidade_cinto;

	Kit _itens_kit[100];
	int _cardinalidade_kit;

    Embalagem _itens_embalagem[100];
	int _cardinalidade_embalagem;
};

#endif
