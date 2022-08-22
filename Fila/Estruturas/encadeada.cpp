#include <iostream>
#include <string>

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
    int num;
    cin >> num;

    while (num >= 0)
    {
        f1.enfileira(num);
        cin >> num;
    }
    
    cout << "tamanho: "   << f1.tamanho() << endl;
    cout << "elementos: " << endl;

    while (not f1.vazia()) {
        cout << f1.desenfileira() << " " << endl;
    }

    cout << endl;

    return 0;
}