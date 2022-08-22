#include <iostream>

using namespace std;

typedef string Dado;

class noh {
    friend class lista;
    private:
        const Dado dado;
        noh* proximo;
        noh* anterior;
    public:
        noh(Dado d = 0);
};

noh::noh(Dado d) : dado(d) {
    proximo = NULL;
    anterior = NULL;
}

class lista {
    private:
        noh* primeiro;
        noh* ultimo;
        int tamanho;
    public:
        lista();
        ~lista();
        void insere(Dado dado);
        void inverte();
        void imprime();
        void imprimeReversa();
        inline bool vazia();
};

// constrói uma lista inicialmente vazia
lista::lista() {
    tamanho = 0;
    primeiro = NULL;
    ultimo = NULL;
}

lista::~lista() {
    noh* iter = primeiro;
    noh* proximo = NULL;
    while (iter != NULL) {
        proximo = iter->proximo;
        delete iter;
        iter = proximo;
    }
}

// método básico que *percorre* a lista, imprimindo seus elementos
void lista::imprime() {
    noh* aux = primeiro;
    while (aux != NULL) {
        cout << aux->dado << " ";
        aux = aux->proximo;
    }
    cout << endl;
}

void lista::imprimeReversa() {
    noh* aux = ultimo;
    while (aux != NULL) {
        cout << aux->dado << " ";
        aux = aux->anterior;
    }
    cout << endl;
}

// insere por padrão no final da lista
void lista::insere(Dado dado) {
    noh *novo = new noh(dado);
    if (vazia()) 
    {
        primeiro = novo;
        ultimo = novo;
    }
    else
    {
        ultimo->proximo = novo;
        novo->anterior = ultimo;
        ultimo = novo;
    }
    tamanho++;    
}

void lista::inverte() {
    ultimo->proximo = ultimo->anterior;
    ultimo->anterior = NULL;
    noh *aux = ultimo;
    noh *aux2;
    int cont = tamanho-1;
    while (cont > 0)
    {
        aux = aux->proximo;
        aux2 = aux->anterior;
        aux->anterior = aux->proximo;
        aux->proximo  = aux2;
        cont--;
    }
    aux = ultimo;
    ultimo = primeiro;
    primeiro = aux;
}

// verifica se a lista está vazia
inline bool lista::vazia() {
    return (primeiro == NULL);
}

int main() { // NÃO MODIFIQUE!
    lista minhaLista;
    char opcao;
    Dado valor;
    cin >> opcao;
    while (opcao != 'Q') {
        switch(opcao) {
            case 'I':
                cin >> valor;
                minhaLista.insere(valor);
                break;
            case 'X':
                minhaLista.inverte();
                break;
            case 'P':
                minhaLista.imprime();
                break;
            case 'R':
                minhaLista.imprimeReversa();
                break;
        }
        cin >> opcao;
    }
    minhaLista.imprime();
    minhaLista.imprimeReversa();
    return 0;
}