#include <iostream>

using namespace std;

typedef int TipoItem;

class No
{
  public:
  TipoItem valor;
  No* proximo;
};

class filadinamica{ 

    private:
    No* primeiro; 
    No* ultimo; 

    public:
    filadinamica(); 
    ~filadinamica();   
    bool estavazio(); 
    bool estacheio(); 
    void inserir(TipoItem item);
    TipoItem remover(); 
    void imprimir(); 
    int espia();
  
};

    filadinamica::filadinamica() 
    {
        primeiro = NULL;
        ultimo = NULL;
    }

    filadinamica::~filadinamica() 
    {
        No* temp;
        while (primeiro != NULL){
            temp = primeiro;
            primeiro = primeiro->proximo;
            delete temp;
        }
        ultimo = NULL;
    }

    bool filadinamica::estavazio() 
    {
        return (primeiro == NULL);
    }

    bool filadinamica::estacheio() 
    {
        No* temp;
        try{
            temp = new No;
            delete temp;
            return false;
        } catch(bad_alloc exception){
            return true;
        }
    }

    void filadinamica::inserir(TipoItem item) 
    {
        if (estacheio()){
            cout << "A Fila esta cheia!\n";
        } else{
            No* NoNovo = new No;
            NoNovo->valor = item;
            NoNovo->proximo = NULL;
            if (primeiro == NULL){
                primeiro = NoNovo;
            } else{
                ultimo->proximo = NoNovo;
            }
            ultimo = NoNovo;
        }
    }

    TipoItem filadinamica::remover() 
    {
        if (estavazio()){
            cout << "A fila esta vazia!\n";
            return 0;
        } else{
            No* temp = primeiro;
            TipoItem item = primeiro->valor;
            primeiro = primeiro->proximo;
            if (primeiro == NULL){
                ultimo = NULL;
            }
            delete temp;
            return item;
        }
    }

    void filadinamica::imprimir() 
    {
        No* temp = primeiro;
        cout << "";
        while (temp != NULL){
            cout << temp->valor << " ";
            temp = temp->proximo;
        }
        cout << "\n";
    }

    int filadinamica::espia(){
        return primeiro->valor;
    }

int main(){
    filadinamica fila1,fila2,filaFinal,aux;
    int valor;
    TipoItem item1, item2;

    cin >> item1;
    for(int i = 0; i < item1; i++){
        cin >> valor;
        fila1.inserir(valor);
    }

    cin >> item2;
    for(int i = 0; i < item2; i++){
        cin >> valor;
        fila2.inserir(valor);
    }


        while (!fila1.estavazio() or !fila2.estavazio()){
        if (!fila1.estavazio()){
            if (!fila2.estavazio()){
                if (fila1.espia() > fila2.espia()){
                    aux.inserir(fila2.remover());
                } else{
                    aux.inserir(fila1.remover());
                }
            }else{
                aux.inserir(fila1.remover());
            }
        }else{
            aux.inserir(fila2.remover());
        }

        while (!fila1.estavazio() and fila1.espia() == aux.espia()){
            fila1.remover();
        }

        while (!fila2.estavazio() and fila2.espia() == aux.espia()){
            fila2.remover();
        }
         filaFinal.inserir(aux.remover());
    }

    while (!filaFinal.estavazio()){
        cout << filaFinal.remover() << " ";
    }



    return 0;
}