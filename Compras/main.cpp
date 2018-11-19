using namespace std;

#include "relogio.h"
#include "kit.h"
#include "cinto.h"
#include "itens.h"
#include "embalagem.h"
#include "recursos.h"
#include <string>

Itens itens = Itens();

void CadastroPrevio();
void Abertura();
int EscolhaTipoProduto();
void ListagemProdutos(int);
int EscolhaItemProduto(int);
bool Questionar(string);
bool PainelFinal(string, double);

struct Nota
{
    double preco;
    string nome;
    string mensagem;
    bool gravado;
    bool embalado;
    Embalagem embalagem;
};

int main()
{
    CadastroPrevio();
    Abertura();

    Nota compra;
    compra.embalado = compra.gravado = false;

    do
    {
        int tipo_produto = EscolhaTipoProduto();
        ListagemProdutos(tipo_produto);
        int item_produto = EscolhaItemProduto(tipo_produto);

        Relogio _relogio_selecionado = Relogio();
        Cinto _cinto_selecionado = Cinto();
        Kit _kit_selecionado = Kit();

        if(tipo_produto == (tipos_produto::_Relogio))
            _relogio_selecionado = itens.selecionarRelogio(item_produto);
        else if(tipo_produto == (tipos_produto::_Cinto))
            _cinto_selecionado = itens.selecionarCinto(item_produto);
        else if(tipo_produto == (tipos_produto::_Kit))
            _kit_selecionado = itens.selecionarKit(item_produto);

        if(tipo_produto!=static_cast<int>(tipos_produto::_Cinto) && Questionar("Deseja gravar"))
        {
            int i = 0;
            do
            {
                cout<<"\nFavor digitar um texto de ate 15 caracteres para ser gravado\n";
                cin.ignore();
                getline( cin, compra.mensagem );
                cin.clear();

                for(i=0; compra.mensagem[i]!='\0'; i++);
            }
            while(i<=0 && i>=15);
            compra.gravado=true;

            if(tipo_produto==(tipos_produto::_Relogio))
                _relogio_selecionado.Gravar();
            else if(tipo_produto==(tipos_produto::_Kit))
                _kit_selecionado.GravarKit();
        }

        if(Questionar("Desejas embalar"))
        {
            int escolha_embalagem;
            do
            {
                cout<<"\nEscolha uma estampa:\n";
                itens.listar_embalagens();
                cin>>escolha_embalagem;
            }
            while(!(itens.itemExistente(tipos_produto::_Embalagem, escolha_embalagem)));
            compra.embalado=true;
            compra.embalagem = itens.selecionarEmbalagem(escolha_embalagem);

            if(tipo_produto==(tipos_produto::_Relogio))
                _relogio_selecionado.Embalar();
            else if(tipo_produto==(tipos_produto::_Cinto))
                _cinto_selecionado.Embalar();
            else if(tipo_produto==(tipos_produto::_Kit))
                _kit_selecionado.EmbalarKit();
        }

        if(tipo_produto == tipos_produto::_Relogio)
        {
            compra.nome = _relogio_selecionado.Nome();
            compra.preco = _relogio_selecionado.Preco();
        }
        else if(tipo_produto == tipos_produto::_Cinto)
        {
            compra.nome = _cinto_selecionado.Nome();
            compra.preco = _cinto_selecionado.Preco();
        }
        else if(tipo_produto == tipos_produto::_Kit)
        {
            compra.nome = _kit_selecionado.Nome();
            compra.preco = _kit_selecionado.Preco();
        }

        cout<<"\n";
    }
    while(!PainelFinal(compra.nome, compra.preco));

    cout<<"\nNota da compra\n"
        <<"Item: " <<compra.nome << "\n"
        <<"R$" << compra.preco << "\n";
    if(compra.gravado)
        cout<<"Texto gravado: " << compra.mensagem << "\n";
    if(compra.embalado)
        cout<<"Embalado com a estampa: \"" << compra.embalagem.Estampa() <<"\"";

    cout<<"\n\nCompra realizada! Nao volte mais, pfvr ;-;\n\n";
    return 0;
}

void CadastroPrevio()
{
    Relogio relogios[6] =
    {
        Relogio('A', "Montblanc", "Rolex", 'M', "513", 350, 2018, 5),
        Relogio('D', "Generation", "Orient", 'F', "609", 278, 2018, 2),
        Relogio('D', "Unique", "Rolex", 'M', "111", 355, 2017, 7),
        Relogio('A', "Primary", "Rolex", 'F', "203", 400, 2018, 1),
        Relogio('A', "Feeling", "X-games", 'M', "158", 188, 2015, 5),
        Relogio('D', "SilverKey", "Orient", 'F', "700", 290, 2018, 6)
    };
    for(int i=0; i<6; i++)
        itens.add_relogio(relogios[i]);

    Cinto cintos[6] =
    {
        Cinto("M", "Usual-line", "Off white", 'M', "555", 80),
        Cinto("M", "Original", "Supreme", 'F', "888", 150),
        Cinto("G", "First", "Cobra d'agua", 'M', "801", 30),
        Cinto("GG", "Lux", "Off white", 'F', "903", 70),
        Cinto("P", "Usual-line", "Off white", 'F', "530", 50),
        Cinto("PP", "Luck", "Imager", 'M', "107", 20)
    };
    for(int i=0; i<6; i++)
        itens.add_cinto(cintos[i]);

    Kit kits[3] =
    {
        Kit("Kit casual masculino", relogios[0], cintos[0], 'M', "799"),
        Kit("Kit casual feminino", relogios[1], cintos[4], 'F', "781"),
        Kit("Kit especial feminino", relogios[3], cintos[1], 'F', "099"),
        Kit("Kit especial masculino", relogios[2], cintos[0], 'M', "097")
    };
    for(int i=0; i<3; i++)
        itens.add_kit(kits[i]);

    Embalagem embalagens[4] =
    {
        Embalagem("Flores", "Grande"),
        Embalagem("Estrelas", "Grande"),
        Embalagem("Azul liso", "Pequena"),
        Embalagem("Infantil", "Pequena")
    };
    for(int i=0; i<4; i++)
        itens.add_embalagem(embalagens[i]);

    cout<<"Repositorio atualizado\n";
}

void Abertura()
{
    cout<<"-----------------------------";
    cout<<"\n\n~/LOJA DOS MOSFETEIROS :D/~\n";
    cout<<"\nSeja muito bem-vindo(a)\n"
        <<"\n";
}

int EscolhaTipoProduto()
{
    int tipo_produto_escolha;

    cout<<"Qual produto desejas comprar?\n"
        <<"\nUse o teclado numerico para escolher\n";

    cout<< tipos_produto::_Relogio <<"-Relogio" << "\n"
        << tipos_produto::_Cinto << "-Cinto" << "\n"
        << tipos_produto::_Kit <<"-Kit" << "\n";

    cin>>tipo_produto_escolha;

    return tipo_produto_escolha;
}

void ListagemProdutos(int tipo_produto)
{
    switch(tipo_produto)
    {
    case (tipos_produto::_Relogio):
        itens.listar_relogios();
        break;
    case (tipos_produto::_Cinto):
        itens.listar_cintos();
        break;
    case (tipos_produto::_Kit):
        itens.listar_kits();
        break;
    default:
        cout<<"\nErro 616 - Produto inexistente";
        exit(1);
        break;
    }
}

int EscolhaItemProduto(int tipo)
{
    int item_produto;
    do
    {
        cout<<"\nQual item desejas comprar?"
            <<"\n-Use o teclado numerico para escolher-\n";
        cin>>item_produto;
    }
    while(!(itens.itemExistente(tipo, item_produto)));
    return item_produto;
}

bool Questionar(string texto)
{
    cout<< "\n" << texto << "?";
    cout<< "\n1 - SIM"
        << "\n0 - NAO\n";

    int digito;
    cin>>digito;

    return digito != 0;
}

bool PainelFinal(string nome, double preco)
{
    cout<<"\nVoce comprou: "
        <<nome
        <<"\nPor: R$"
        <<preco << "\n";

    return Questionar("Confirma");
}
