#include <iostream>
#include <string>

using namespace std;

class noh {
    friend class pilha;
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

class pilha
{
private:
    noh * mTopo;
    int mTamanho;

public:
    pilha(/* args */);
    ~pilha();
    
    unsigned tamanho();
    void empilha(int valor);
    int desempilha();
    void limpaPilha();
    bool vazia();
};

pilha::pilha(/* args */) {
    mTopo = NULL;
    mTamanho = 0;
}

pilha::~pilha() {
    limpaPilha();
}

void pilha::empilha(int valor) {
    noh *novo = new noh(valor);
    novo -> mProximo = mTopo;
    mTopo = novo;
    mTamanho++;
}

int pilha::desempilha() {
    int valor = mTopo -> mValor;
    noh *temp = mTopo;
    mTopo = mTopo -> mProximo;
    delete temp;
    mTamanho--;
    return valor;
}

void pilha::limpaPilha() {
    while (not vazia()) {
        desempilha();
    }
}

unsigned pilha::tamanho() {
    return mTamanho;
}

bool pilha::vazia() {
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
    pilha p1;
    int num;
    cin >> num;

    while (num >= 0)
    {
        p1.empilha(num);
        cin >> num;
    }
    
    cout << "tamanho: "   << p1.tamanho() << endl;
    cout << "elementos: " << endl;

    while (not p1.vazia()) {
        cout << p1.desempilha() << " " << endl;
    }

    cout << endl;

    return 0;
}