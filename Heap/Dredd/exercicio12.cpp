#include <iostream>   
#include <string>
#include <algorithm>
#include <stdexcept>

struct Atividade {
        int nota;
        int tentativas;
};

class Aluno {
    public:
        Aluno();
        Aluno(unsigned matr, const std::string& n, unsigned capAtiv);
        Aluno(const Aluno& umAluno); // construtor de cópia para evitar problemas
                                     // com atributos dinâmicos
        ~Aluno();
        void InserirAtividade(const Atividade& a);
        std::string Nome() const { return nome; }
        unsigned Matricula() { return matricula; }
        float Media() const;
        int Tentativas() const;
        bool compara(const Aluno umAluno); 
        Aluno& operator=(const Aluno& umAluno);
                                                
    private:
        unsigned matricula;
        std::string nome;
        unsigned capAtividades;
        Atividade* vetAtividades;
        unsigned nroAtividades;
};

Aluno::Aluno()
    : matricula(0), nome(""), capAtividades(0), nroAtividades(0) {
    vetAtividades = NULL;
}

Aluno::Aluno(unsigned matr, const std::string& n, unsigned capAtiv) 
    : matricula(matr), nome(n), capAtividades(capAtiv), nroAtividades(0) {
    vetAtividades = new Atividade[capAtiv];
}

Aluno::Aluno(const Aluno& umAluno) {
    matricula = umAluno.matricula;
    nome = umAluno.nome;
    capAtividades = umAluno.capAtividades;
    nroAtividades = umAluno.nroAtividades;
    vetAtividades = new Atividade[capAtividades];
    std::copy(umAluno.vetAtividades, umAluno.vetAtividades + capAtividades, vetAtividades);
}

Aluno::~Aluno() {
    delete[] vetAtividades;
}

Aluno& Aluno::operator=(const Aluno& umAluno) {
    matricula = umAluno.matricula;
    nome = umAluno.nome;
    capAtividades = umAluno.capAtividades;
    nroAtividades = umAluno.nroAtividades;
    delete[] vetAtividades;
    vetAtividades = new Atividade[capAtividades];
    std::copy(umAluno.vetAtividades, umAluno.vetAtividades + capAtividades, vetAtividades);
    return *this;
}

void Aluno::InserirAtividade(const Atividade& a) {
    vetAtividades[nroAtividades] = a;
    nroAtividades++;
}

float Aluno::Media() const {
    float soma = 0.0f;
    for (unsigned i = 0; i < nroAtividades; i++)       
        soma += float(vetAtividades[i].nota);  
    return soma / float(nroAtividades);
}

int Aluno::Tentativas() const {
    int tentativas = 0;
    for (unsigned i = 0; i < nroAtividades; i++)
        tentativas += vetAtividades[i].tentativas;
    return tentativas;
}

bool compara(const Aluno a1, const Aluno a2) {
    if (a1.Media() > a2.Media()) {
        return true;
    }
    else if ((a1.Media() == a2.Media()) and (a1.Tentativas() < a2.Tentativas())) {
        return true;
    } 
    else if ((a1.Tentativas() == a2.Tentativas()) and (a1.Nome() < a2.Nome())) {
        return true;
    }
    else { return false;}
}

typedef Aluno TDado;

class Heap {
    // classe Heap (max-heap, o maior fica na raiz/inicio)
    public:
        // Criar heap sem dados e com capacidade informada
        Heap(int cap);
        // Destruttor
        ~Heap();
        // Inserir um dado na heap
        void Inserir(const TDado& d);
        // Consulta a raiz
        TDado Raiz();
        // Retira e retorna a raiz
        TDado Retirar();
        // Verifica se a heap está vazia
        bool Vazia();
    protected:
        void ArrumarDescendo(int i);
        void ArrumarSubindo(int i);
        inline int Direito(int i);
        inline int Esquerdo(int i);
        inline int Pai(int i);
        int mCapacidade;
        int mTamanho;
        TDado* mVetDados;
};

using namespace std;

Heap::Heap(int cap) {
    mCapacidade = cap;
    mVetDados = new TDado[mCapacidade];
    mTamanho = 0;
}

Heap::~Heap() {
    delete[] mVetDados;
}

void Heap::ArrumarDescendo(int i) {
    int esq = Esquerdo(i);
    int dir = Direito(i);
    int maior = i;

    if ((esq < mTamanho) and (compara(mVetDados[esq], mVetDados[maior]))) {
        maior = esq;
    }
    
    if ((dir < mTamanho) and (compara(mVetDados[dir], mVetDados[maior]))) {
        maior = dir;
    }

    if (maior != i) {
        swap(mVetDados[i], mVetDados[maior]); // troca os valores de duas posições
        ArrumarDescendo(maior);
    }
}

void Heap::ArrumarSubindo(int i) {
    int p = Pai(i);
    if(compara(mVetDados[i], mVetDados[p]))
    {
        swap(mVetDados[i], mVetDados[p]);
        ArrumarSubindo(p);
    }
}

int Heap::Pai(int i) {
    return (i-1) / 2;
}

int Heap::Esquerdo(int i) {
    return 2*i+1;
}

int Heap::Direito(int i) {
    return 2*i+2;
}

TDado Heap::Raiz() {
    if (mTamanho == 0) 
        throw runtime_error("Heap vazia nao tem raiz");
    else
        return mVetDados[0];
}

TDado Heap::Retirar() {
    if (mTamanho == 0) 
        throw runtime_error("Heap vazia nao tem raiz");

    else{
        TDado aux = mVetDados[0];
        swap(mVetDados[0], mVetDados[mTamanho-1]);
        mTamanho--;
        ArrumarDescendo(0);
        return aux;
    }
}

bool Heap::Vazia() {
}

void Heap::Inserir(const TDado& d){
    if (mTamanho == mCapacidade) 
        throw runtime_error("Impossivel inserir em heap cheio.");
    else 
    {
        mVetDados[mTamanho] = d;
        ArrumarSubindo(mTamanho);
        mTamanho++;
    }
}

int main() {
    unsigned qtdeAlunos;
    cin >> qtdeAlunos;
    unsigned qtdeAtividades;
    cin >> qtdeAtividades;
    Heap heap(qtdeAlunos);
    Atividade atividade;
    string nome;
    unsigned matricula;
    for (unsigned i = 0; i < qtdeAlunos; i++) {
        cin >> matricula >> nome;
        Aluno aluno(matricula, nome, qtdeAtividades);
        for (unsigned i = 0; i < qtdeAtividades; i++) {
            cin >> atividade.nota >> atividade.tentativas;
            aluno.InserirAtividade(atividade);
        }
        heap.Inserir(aluno);
    }
    Aluno alunoDestaque(heap.Retirar());
    cout << '[' << alunoDestaque.Matricula() << "] " << alunoDestaque.Nome() << endl;
    return 0;
}