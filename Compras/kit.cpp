#include "cinto.h"
#include "relogio.h"
#include "kit.h"
#include <string>
using namespace std;
#include <iostream>
#include "recursos.h"

Kit::Kit(string nomeKit, Relogio relogio, Cinto cinto, char generoKit, string codigoKit)
{
    _nomeKit = nomeKit;
    _relogio = relogio;
    _cinto = cinto;
    _generoKit = generoKit;
    _codigoKit = codigoKit;
    _precoKit = (_relogio.Preco()+_cinto.Preco())*(1-descontoKit);
}
Kit::Kit()
{
    _nomeKit = "-";
    _relogio = Relogio();
    _cinto = Cinto();
    _generoKit = '-';
    _codigoKit = "-";
    _precoKit = 0;
}

void Kit::GravarKit()
{
    _relogio.Gravar();
}

void Kit::EmbalarKit()
{
    _precoKit += 7;
}

void Kit::PrintPrecoKit()
{
    cout<<(_relogio.Preco()+_cinto.Preco())*(1-descontoKit);
}

void Kit::PrintNomeKit()
{
    cout<<_nomeKit;
}

void Kit::ListarKit()
{
    cout<< "Nome: " << _nomeKit << "\n"
        << "Relogio: ";
    _relogio.PrintNome();
    cout<< "\n"
        << "Cinto: ";
    _cinto.PrintNome();
    cout<< "\n"
        << "Genero: " << _generoKit << "\n"
        << "Codigo: " << _codigoKit << "\n"
        << "Preco: " << _precoKit << "\n";
}

double Kit::Preco() const
{
    return (_relogio.Preco()+_cinto.Preco())*(1-descontoKit);
}

string Kit::Nome() const
{
    return _nomeKit;
}
