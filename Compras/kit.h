#ifndef KIT_H_INCLUDED
#define KIT_H_INCLUDED
using namespace std;
#include "relogio.cpp"
#include "cinto.cpp"
#include <string>

class Kit
{
public:
	Kit(string nomeKit, Relogio relogio, Cinto cinto, char generoKit, string codigoKit);
	Kit();
	void GravarKit();
	void EmbalarKit();
	void PrintPrecoKit();
    void PrintNomeKit();
    void ListarKit();
    double Preco() const;
    string Nome() const;

private:
	string _nomeKit;
	Relogio _relogio;
	Cinto _cinto;
	char _generoKit;
	string _codigoKit;
	double _precoKit;
};

#endif
