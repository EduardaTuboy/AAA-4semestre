#include <bits/stdc++.h>
using namespace std;

string s;
string p;

// funcao para calcular o vetor de prefixo
vector<int> calcular_lps(const string &padrao)
{
    int m = padrao.size();
    vector<int> borda(m, 0);
    int tam = 0; // tamanho do prefixo atual
    int i = 1;

    while (i < m)
    {
        if (padrao[i] == padrao[tam])
        {
            tam++;
            borda[i] = tam;
            i++;
        }
        else
        {
            if (tam != 0)
            {
                tam = borda[tam - 1];
            }
            else
            {
                borda[i] = 0;
                i++;
            }
        }
    }

    return borda;
}

int main()
{
    getline(cin, s);
    getline(cin, p);

    // tamanho da string e do padrao
    int n = s.size();
    int m = p.size();

    // vetor para armazenar os indices onde o padrao e encontrado
    vector<int> ocorrencias;

    // calcular o vetor borda para o padrao
    vector<int> borda = calcular_lps(p);

    // indices para percorrer a string e o padrao
    int i = 0; // indice para s
    int j = 0; // indice para p

    // percorrer a string s para encontrar o padrao usando KMP
    while (i < n)
    {
        if (s[i] == p[j])
        {
            i++;
            j++;
        }

        if (j == m)
        {
            // padrao encontrado, armazenando o indice da ocorrencia
            ocorrencias.push_back(i - j);
            j = borda[j - 1];
        }
        else if (i < n && s[i] != p[j])
        {
            if (j != 0)
            {
                j = borda[j - 1];
            }
            else
            {
                i++;
            }
        }
    }

    // quantidade de ocorrencias encontradas
    int q = ocorrencias.size();

    if (q >= 100)
        cout << q << endl;

    else
    {
        cout << q << endl;
        for (int i = 0; i < q; i++)
            cout << ocorrencias[i] << endl;
    }

    return 0;
}
