#include <iostream>
#include <string>

using namespace std;

class noh {
    friend class fila;
    private: 
        string mValor;
        noh *mProximo;

    public:
        noh(string valor);

};

noh::noh(string valor) {
    mValor   = valor;
    mProximo = NULL;
}

class fila
{
private:
    noh *inicio;
    noh *fim; 
    unsigned mTamanho;

public:
    fila(/* args */);
    ~fila();
    
    unsigned tamanho();
    void enfileira(string valor);
    string desenfileira();
    void limpafila();
    bool vazia();
};

fila::fila(/* args */) {
    inicio = NULL;
    mTamanho = 0;
    fim = NULL;
}

fila::~fila() {
    limpafila();
}

void fila::enfileira(string valor) {
    noh *novo = new noh(valor);
    if (vazia()) {
        inicio = novo;
    }
    else {
        fim -> mProximo = novo;    
    }
    fim = novo;
    mTamanho++;
}

string fila::desenfileira() {
    string valor = inicio -> mValor;
    noh *temp = inicio;
    inicio = inicio -> mProximo;
    delete temp;
    mTamanho--;
    if (vazia()) {
        fim = NULL;
    }
    return valor;
}

void fila::limpafila() {
    while (not vazia()) {
        desenfileira();
    }
}

unsigned fila::tamanho() {
    return mTamanho;
}

bool fila::vazia() {
    if (mTamanho == 0)
    {
        return true;
    }
    else
    {
        return false;
    } 
}

int main(){
    fila f1;
    string valor, removido;
    int cont = 0, encontrado = 0, tamanho = 0;

    char opcao;
    
    while (opcao != 'S') 
    {
        cin  >> opcao;
        
        switch(opcao) {
            case 'E':
                cin.ignore();
                getline(cin, valor);
                f1.enfileira(valor);
                tamanho++;
            break;

            case 'D':
                cin.ignore();
                getline(cin, valor);
                while ((encontrado == 0) && (cont < tamanho))
                {
                    removido = f1.desenfileira();
                    if (removido == valor)
                    {
                        encontrado = 1;
                    }
                    else
                    {
                        f1.enfileira(removido);
                    }
                    cont++;
                }

                if(encontrado == 0) {
                    cout << "NAO ENCONTRADO" << endl;
                } 
                else {
                    cout << cont << endl;
                    cont = 0;
                    encontrado = 0;
                    tamanho--;
                    while (cont < tamanho) {
                        removido = f1.desenfileira();
                        cout << removido << endl;
                        f1.enfileira(removido);
                        cont++;
                    }
                    cont = 0;
                }
                
            break;
        }
    }

    return 0;
}