#include <iostream>

using namespace std;

class noh {
    friend class fila;
    private: 
        int mValor;
        noh *mProximo;

    public:
        noh(int valor);

};

noh::noh(int valor) {
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
    void enfileira(int valor);
    int desenfileira();
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

void fila::enfileira(int valor) {
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

int fila::desenfileira() {
    int valor = inicio -> mValor;
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
    int valor, K, removido, tamanho;
    int cont = 0, qSub = 0;
    
    cin >> tamanho;
    for (int i = 0; i < tamanho; i++)
    {
        cin >> valor;
        f1.enfileira(valor);
    }
    
    cin >> K;
    
    while (cont < tamanho) 
    {
        while (cont < K)
        {
            removido = f1.desenfileira();
            f1.enfileira(removido);
            if(removido < 0) {
                cout << removido << " ";
                cont = K;
            }
            else {
                cont++;
            }
        }
        cont ++;
        removido = f1.desenfileira();
        f1.enfileira(removido);
    }
    
    return 0;
}