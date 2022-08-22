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
		void geraBinario(int quant)
		{
			int i = 0;
			enfileira("1");
			while(i < quant)
			{
				string s1 = inicio->dado;
				string s2 = s1;
				enfileira(s1 + "0");
				enfileira(s2 + "1");
				cout << desenfileira()  << " ";
				i++;
			}
		}
		/*void generatePrintBinary(int n)
		{
    		queue<string> q;
    		q.push("1");
    		while (n--) 
			{
       		 	string s1 = q.front();
       		 	q.pop();
        		cout << s1 << "\n";
        		string s2 = s1;
        		q.push(1s1.append("0"));
        		q.push(s2.append("1"));
   	 		}
		}*/
};

/*void generate(int n)
{
    queue<string> q;
    q.push("1"); 
    int i = 1;
    while (i++ <= n)
    {
        q.push(q.front() + "0");
        q.push(q.front() + "1");
        cout << q.front() << ' ';
        q.pop();
    }
}*/

int main()
{
	fila p;
	int quant;
	string s1, s2;
	cin >> quant;
	p.geraBinario(quant);
	return 0;
}
