#include "itens.h"
#include "relogio.h"
#include "cinto.h"
#include "kit.h"
using namespace std;
#include <iostream>
#include "acessorio.h"
#include "recursos.h"

Itens::Itens()
{
    _cardinalidade_relogio=0;
    _cardinalidade_cinto=0;
    _cardinalidade_kit=0;
    _cardinalidade_embalagem=0;
}

void Itens::add_relogio(Relogio relogio)
{
    _itens_relogio[_cardinalidade_relogio] = relogio;
    _cardinalidade_relogio++;
}
void Itens::add_cinto(Cinto cinto)
{
    _itens_cinto[_cardinalidade_cinto] = cinto;
    _cardinalidade_cinto++;
}
void Itens::add_kit(Kit kit)
{
    _itens_kit[_cardinalidade_kit] = kit;
    _cardinalidade_kit++;
}
void Itens::add_embalagem(Embalagem embalagem)
{
    _itens_embalagem[_cardinalidade_embalagem] = embalagem;
    _cardinalidade_embalagem++;
}

void Itens::listar_relogios()
{
    for(int i=0; i<_cardinalidade_relogio; i++)
    {
        if(_itens_relogio[i].Nome() != Relogio().Nome())
        {
            cout<<"\n" << i << " - Nome: ";
            _itens_relogio[i].PrintNome();
            cout<<" || Preco: R$";
            _itens_relogio[i].PrintPreco();
            cout<<"\n";
        }
    }
}
void Itens::listar_cintos()
{
    for(int i=0; i<_cardinalidade_cinto; i++)
    {
        if(_itens_cinto[i].Nome() != Cinto().Nome())
        {
            cout<<"\n" << i << " - Nome: ";
            _itens_cinto[i].PrintNome();
            cout<<" || Preco: R$";
            _itens_cinto[i].PrintPreco();
            cout<<"\n";
        }
    }
}
void Itens::listar_kits()
{
    for(int i=0; i<_cardinalidade_kit; i++)
    {
        if(_itens_kit[i].Nome() != Kit().Nome())
        {
            cout<<"\n" << i << " - Nome: ";
            _itens_kit[i].PrintNomeKit();
            cout<<" || Preco: R$";
            _itens_kit[i].PrintPrecoKit();
            cout<<"\n";
        }
    }
}
void Itens::listar_embalagens()
{
    for(int i=0; i<_cardinalidade_embalagem; i++)
    {
        cout<<"\n" << i << " - Estampa: ";
        _itens_embalagem[i].PrintEstampa();
        cout<<"\n";
    }
}

double Itens::getPreco(int tipo, int index)
{
    switch(tipo)
    {
    case 1:
        return _itens_relogio[index].Preco();
        break;
    case 2:
        return _itens_cinto[index].Preco();
        break;
    case 3:
        return _itens_kit[index].Preco();
        break;
    }
    return 0;
}

string Itens::getNome(int tipo, int index)
{
    switch(tipo)
    {
    case 1:
        return _itens_relogio[index].Nome();
        break;
    case 2:
        return _itens_cinto[index].Nome();
        break;
    case 3:
        return _itens_kit[index].Nome();
        break;
    }
    return '\0';
}

Relogio Itens::selecionarRelogio(int i)
{
    Relogio RET = _itens_relogio[i];
    _itens_relogio[i] = Relogio();
    return RET;
}

Cinto Itens::selecionarCinto(int i)
{
    Cinto RET = _itens_cinto[i];
    _itens_cinto[i] = Cinto();
    return RET;
}

Kit Itens::selecionarKit(int i)
{
    Kit RET = _itens_kit[i];
    _itens_kit[i] = Kit();
    return RET;
}

Embalagem Itens::selecionarEmbalagem(int i)
{
    Embalagem RET = _itens_embalagem[i];
    return RET;
}

bool Itens::itemExistente(int tipo, int index)
{
    if(tipo == static_cast<int>(tipos_produto::_Relogio))
        return index<_cardinalidade_relogio;
    else if(tipo == static_cast<int>(tipos_produto::_Cinto))
        return index<_cardinalidade_cinto;
    else if(tipo == static_cast<int>(tipos_produto::_Kit))
        return index<_cardinalidade_kit;
    else if(tipo == static_cast<int>(tipos_produto::_Embalagem))
        return index<_cardinalidade_embalagem;
    return false;
}
