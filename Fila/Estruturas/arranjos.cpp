#include <iostream>

using namespace std;

class fila
{
    private:
        int primeiro, ultimo;
        int *estrutura;    

    public:
        fila();
        ~fila();

        bool vazia();
        bool cheia();
        int remover();
        //int printTamanho();
        void imprimir();
        void inserir(int valor);
};

fila::fila() {
    ultimo = 0;
    primeiro = 0;
    estrutura = new int[5];
}

fila::~fila() {
    delete[] estrutura;
}

void fila::inserir(int valor) {
    if (cheia()) {
        cout << "A fila esta cheia!" << endl;
    }
    else {
        estrutura[ultimo % 5] = valor;
        ultimo++;
    }    
}

int fila::remover() {
    if(vazia()) {
        cout << "A fila ja esta vazia!" << endl;
        return 0;
    }
    else {
        int dado = primeiro % 5;
        primeiro++;
        return estrutura[dado];
    }
}

void fila::imprimir() {
    
    cout << "Fila: [" << endl;
    for (int i=primeiro; i < ultimo; i++) 
    {
        cout << estrutura[i % 5] << ", ";
    }
    cout << endl << "]" << endl;
}

/*int fila::printTamanho() {
    return tamanho;
}*/

bool fila::vazia() {
    return (primeiro == ultimo);
}

bool fila::cheia() {
    return (ultimo-primeiro == 5);
}

int main(){
    fila f1;
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
                f1.inserir(valor);
            break;

            case 2:
                f1.remover();
            break;

            case 3:
                f1.imprimir();
            break;

            case 4:
                //f1.printTamanho();
            break;
        }
    }

    return 0;
}