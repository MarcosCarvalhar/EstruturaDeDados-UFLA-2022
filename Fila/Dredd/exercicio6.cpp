#include <iostream>

using namespace std;

class fila
{
    private:
        int primeiro, ultimo;
        int tamanho, max;
        int *estrutura;    

    public:
        fila(int capacidade);
        ~fila();

        bool vazia();
        bool cheia();
        int remover();
        void informacoes(int &tam, int &inicio, int &fim);
        void imprimir();
        void inserir(int valor);
};

fila::fila(int capacidade) {
    max = capacidade;
    ultimo = -1;
    tamanho = 0;
    primeiro = -1;
    estrutura = new int[max];
}

fila::~fila() {
    delete[] estrutura;
}

void fila::inserir(int valor) {
    if (cheia() == false) {
        ultimo++;
        ultimo = ultimo % max;
        estrutura[ultimo] = valor;
        if (vazia())
        {        
            primeiro++;
        }
        tamanho++;
    }   
}

int fila::remover() {
    int dado;
    if(vazia()) {
        dado = -1;
    }
    else {
        dado = estrutura[primeiro];
        tamanho--;
        if (vazia())
        {
            primeiro = -1;
            ultimo = -1;
        }
        else {
            primeiro++;
            primeiro = primeiro % max;
        }
    }
    return dado;
}

void fila::informacoes(int &tam, int &inicio, int &fim) {
    tam = tamanho;
    inicio = primeiro;
    fim = ultimo;
}

bool fila::vazia() {
    return (tamanho == 0);
}

bool fila::cheia() {
    return (tamanho >= max);
}

int main(){
    int valor, capacidade, tam, inicio, fim;
    int removido, cont=0;
    cin >> capacidade;
    fila f1(capacidade);

    char opcao;
    
    while (opcao != 't') 
    {
        cin  >> opcao;
        
        switch(opcao) {
            case 'e':
                cin >> valor;
                f1.inserir(valor);
            break;

            case 'd':
                cout << f1.remover() << endl;
            break;

            case 'i':
                f1.informacoes(tam, inicio, fim);
                cout << "tamanho="    << tam << " ";
                cout << "capacidade=" << capacidade << " ";
                cout << "inicio="     << inicio << " ";
                cout << "fim="        << fim << endl;

                while (cont < tam) {
                    removido = f1.remover();
                    cout << removido << " ";
                    f1.inserir(removido);
                    cont++;
                }
                cout << endl;
                cont=0;
            break;
        }
    }

    return 0;
}