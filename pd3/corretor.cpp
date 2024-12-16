#include <bits/stdc++.h>
using namespace std;

string s1, s2;
int tam_s1, tam_s2;
vector<vector<int>> MEMO;
vector<vector<string>> sequencia;

// funcao que diz se caracter eh ou nao uma vogal
bool eh_vogal(char c)
{
    return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');
}

// funcao que calcula qual dos 3 casos a troca eh
int troca(char c1, char c2)
{
    if (c1 == c2)
        return 0;
    else if ((eh_vogal(c1) && eh_vogal(c2)) || (!eh_vogal(c1) && !eh_vogal(c2)))
        return 1;
    else
        return 3;
}

// funcao que corta as partes iniciais iguais entre as duas palavras
void corte_partes_iguais()
{
    int num_iguais = 0;
    while (num_iguais < tam_s1 && num_iguais < tam_s2)
    {
        if (s1[num_iguais] == s2[num_iguais])
            num_iguais++;
        else
            break;
    }

    s1 = s1.substr(num_iguais);
    s2 = s2.substr(num_iguais);

    tam_s1 = s1.size();
    tam_s2 = s2.size();
}

// caso trivial
void inicializacao_matrizes()
{
    // faco o caso trivial, que eh remover toda a palavra antiga e inserir cada caracter da nova
    for (int i = 1; i <= tam_s1; i++)
    {
        MEMO[i][0] = i * 2;
        sequencia[i][0] = sequencia[i - 1][0] + "R:" + s1[i - 1];
    }
    for (int j = 1; j <= tam_s2; j++)
    {
        MEMO[0][j] = j * 2;
        sequencia[0][j] = sequencia[0][j - 1] + "I:" + s2[j - 1];
    }
}

pair<int, string> transformacao_strings()
{
    // corto as partes iguais e atualizo as strings s1 e s2
    corte_partes_iguais();

    // defino o tamanho para MEMO (matriz de custos) e para as sequencia tomadas
    MEMO.assign(tam_s1 + 1, vector<int>(tam_s2 + 1, 0));
    sequencia.assign(tam_s1 + 1, vector<string>(tam_s2 + 1, ""));

    // faco o caso trivial, que eh remover toda a palavra antiga e inserir cada caracter da nova
    inicializacao_matrizes();

    // completar a MEMO e a sequencia com as operacoes minimas
    for (int i = 1; i <= tam_s1; i++)
    {
        for (int j = 1; j <= tam_s2; j++)
        {
            int custo_remover = MEMO[i - 1][j] + 2;
            int custo_inserir = MEMO[i][j - 1] + 2;
            int custo_trocar = MEMO[i - 1][j - 1] + troca(s1[i - 1], s2[j - 1]);

            MEMO[i][j] = min({custo_remover, custo_inserir, custo_trocar});

            if (MEMO[i][j] == custo_remover)
                sequencia[i][j] = sequencia[i - 1][j] + "R:" + s1[i - 1];
            else if (MEMO[i][j] == custo_inserir)
                sequencia[i][j] = sequencia[i][j - 1] + "I:" + s2[j - 1];
            else
            {
                if (s1[i - 1] != s2[j - 1])
                    sequencia[i][j] = sequencia[i - 1][j - 1] + "T:" + s1[i - 1] + "-" + s2[j - 1];
                else
                    sequencia[i][j] = sequencia[i - 1][j - 1];
            }
        }
    }

    return pair<int, string>(MEMO[tam_s1][tam_s2], sequencia[tam_s1][tam_s2]);
}

int main()
{
    cin >> s1 >> s2;
    tam_s1 = s1.size();
    tam_s2 = s2.size();

    // calcular o custo e as acoes da transformacao de s1 a s2
    pair<int, string> resultado = transformacao_strings();
    int custo = resultado.first;
    string acoes = resultado.second;

    if (custo == 0)
        cout << "0\nnada a fazer";
    else
    {
        cout << custo << endl;
        cout << acoes;
    }

    return 0;
}
