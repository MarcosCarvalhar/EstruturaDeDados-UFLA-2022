#include <iostream>

using namespace std;

class pilha
{
    private:
        int tamanho;
        int *estrutura;    

    public:
        pilha();
        ~pilha();

        bool vazia();
        bool cheia();
        int remover();
        int printTamanho();
        void imprimir();
        void inserir(int valor);
};

pilha::pilha() {
    tamanho = 0;
    estrutura = new int[100];
}

pilha::~pilha() {
    delete[] estrutura;
}

void pilha::inserir(int valor) {
    if (cheia()) {
        cout << "A pilha esta cheia!" << endl;
    }
    else {
        estrutura[tamanho] = valor;
        tamanho++;
    }    
}

int pilha::remover() {
    if(vazia()) {
        cout << "A pilha ja esta vazia!" << endl;
    }
    else {
        tamanho--;
        return estrutura[tamanho];
    }
}

void pilha::imprimir() {
    
    cout << "Pilha: [" << endl;
    for (int i=0; i < tamanho; i++) 
    {
        cout << estrutura[i] << ", ";
    }
    cout << endl << "]" << endl;
}

int pilha::printTamanho() {
    return tamanho;
}

bool pilha::vazia() {
    return (tamanho == 0);
}

bool pilha::cheia() {
    return (tamanho == 100);
}

int main(){
    pilha p1;
    int valor;

    int opcao;
    
    while (opcao != 5) 
    {
        cout << "Menu:" << endl;
        cout << "1 - Inserir"  << endl;
        cout << "2 - Remover"  << endl;
        cout << "3 - Imprimir" << endl;
        cout << "4 - Tamanho"  << endl;
        cout << "5 - Sair"     << endl;
        cin  >> opcao;
        
        switch(opcao) {
            case 1:
                cin >> valor;
                p1.inserir(valor);
            break;

            case 2:
                p1.remover();
            break;

            case 3:
                p1.imprimir();
            break;

            case 4:
                p1.printTamanho();
            break;
        }
    }

    return 0;
}