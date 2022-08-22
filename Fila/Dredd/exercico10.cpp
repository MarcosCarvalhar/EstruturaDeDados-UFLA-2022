#include <iostream>

using namespace std;

class noh
{
	friend class fila;
	private:
		string dado;
		noh *proximo;
	public:
		noh(string d)
		{
			dado = d;
			proximo = NULL;	
		}	
};

class fila
{
	private:
		noh *inicio;
		noh *fim;
		int tamanho;
	public:
		fila()
		{
			inicio = NULL;
			fim = NULL;
			tamanho = 0;
		}
		~fila()
		{
			limpaFila();
		}
		void limpaFila()
		{
			while(tamanho != 0)
			{
				desenfileira();
			}
		}
		bool vazia() 
		{
			if (tamanho == 0)
			{
				return true;
			}
			else
			{
				return false;
			} 
		}
		int gettamanho()
		{
			return tamanho;
		}
		void enfileira(string d)
		{
			noh *novo = new noh(d);
			if(tamanho == 0)
			{
				inicio = novo;
			}
			else
			{
				fim->proximo = novo;
			}
			fim = novo;
			tamanho++;
		}
		string desenfileira()
		{
			string valor = inicio->dado;
			noh *aux = inicio;
			inicio = inicio->proximo;
			delete aux;
			tamanho--;
			if(vazia())
			{
				fim = NULL;
			} 
			return valor;
		}
};

int main()
{
	fila p, paux, fresultante;
	int quant;
	string s1;
	cin >> quant;
	int i = 0, j = 0;
	while(i < quant)
	{
		cin >> s1;
		p.enfileira(s1);
		i++;
	}
	
	int quantsubfila;
	cin >> quantsubfila;
	
	bool parou = false;
	
	while(!p.vazia() and !parou)
	{
		int encontrou = 0;
		while ((j < quantsubfila) and (!p.vazia()))
		{
			string dado = p.desenfileira();
			paux.enfileira(dado);
			if ((stoi(dado) < 0) and (encontrou == 0))
			{
				fresultante.enfileira(dado);
				encontrou = 1;
			}
			j++;
		}
		
		if (encontrou == 0)
		{
			if (paux.gettamanho() >= quantsubfila)
				fresultante.enfileira("inexistente");
			else 
				parou = true;
		}
				
		while(!p.vazia())
		{
			string dado = p.desenfileira();
			paux.enfileira(dado);
		}
		
		p.limpaFila();
		paux.desenfileira();
		
		while(!paux.vazia())
		{
			string dado = paux.desenfileira();
			p.enfileira(dado);
		}		
		j = 0;
		
		if (!(p.gettamanho() >= quantsubfila))
		{
			parou = true;
		}
		
	}
	
	while(!fresultante.vazia())
	{
		cout << fresultante.desenfileira() << " ";
	}
	
	return 0;
}