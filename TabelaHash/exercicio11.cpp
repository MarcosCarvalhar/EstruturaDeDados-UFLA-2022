#include <iostream>

using namespace std;

struct DadoHash
{
	string sPalavra;
	string sSignificado;
};

class Hash
{
	private:
		DadoHash *TabelaHash;
		DadoHash DADO;
		int iCapacidade;
		int iTamanho;
		int funcaoHash(string _sPalavra)
		{
			return (_sPalavra.size()) % iCapacidade;
		}
	public:
		Hash(int _iCapacidade = 23)
		{
			iCapacidade = _iCapacidade;
			TabelaHash = new DadoHash[iCapacidade];
			for (int i = 0; i < iCapacidade; i++)
			{
				TabelaHash[i].sPalavra = "-1";
				TabelaHash[i].sSignificado = "-1";
			}
			iTamanho = 0;
		}
		string Buscar(string _sPalavra, bool bImprimir)
		{
			int iPos = funcaoHash(_sPalavra);
			int iPosFinal = iPos;
			bool bEncontrou = false;
			do
			{
				DADO = TabelaHash[iPos];
				if (DADO.sPalavra == _sPalavra)
				{
					bEncontrou = true;
					if (bImprimir)
						cout << "[" << DADO.sPalavra << "] => " << DADO.sSignificado << endl;
					
				}
				iPos = (iPos + 1) % iCapacidade;
			} while ((iPos != iPosFinal) and (!bEncontrou));
			
			if (!bEncontrou)
			{
				if (bImprimir)
					cout << "[" << _sPalavra << "] => " << "NULL" << endl;
				return "-1";
			} else
			{
				return _sPalavra;
			}
		}
				
		void Inserir(string _sPalavra, string _sSignificado)
		{
			int iPos = funcaoHash(_sPalavra);
			if ((iTamanho < iCapacidade) and (Buscar(_sPalavra, false) == "-1"))
			{
				while (TabelaHash[iPos].sPalavra != "-1")
				{
					iPos = (iPos + 1) % iCapacidade;
				}
				TabelaHash[iPos].sPalavra = _sPalavra;
				TabelaHash[iPos].sSignificado = _sSignificado;
				iTamanho++;
			}
		}
		~Hash(){
			delete[] TabelaHash;
		};
};

int main()
{
	Hash Dicionario;
	
	
	string sPalavra;
	string sSignificado;
	int iQuantidadePalavras;
	cin >> iQuantidadePalavras;
	cin.ignore();
	for (int i = 0; i < iQuantidadePalavras; i++)
	{
		getline(cin, sPalavra, ' ');
		getline(cin, sSignificado, '\n');
		
		Dicionario.Inserir(sPalavra, sSignificado);
	}
	
	string sPalavraBusca;
	cin >> sPalavraBusca;
	while (sPalavraBusca != "-1")
	{
		Dicionario.Buscar(sPalavraBusca, true);
		
		cin >> sPalavraBusca;
	}

	return 0;
}