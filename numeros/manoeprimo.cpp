#include <bits/stdc++.h>
using namespace std;

int n, m, tam_crivo = 1000001;
long long int operacoes = 0, primo = 0, min_operacoes = INT_MAX;
vector<vector<long long int>> matriz;
bitset<1000010> crivo;

// para debbug
void print_matriz()
{
    cout << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << matriz[i][j] << " ";
        }
        cout << endl;
    }
}

// criando o crivo para guardar os primos ate 10^6
void criar_crivo()
{
    crivo.set();
    crivo[0] = crivo[1] = 0;
    for (long long int i = 2; i < tam_crivo; ++i)
    {
        if (crivo[i])
        {
            for (long long int j = i * i; j <= tam_crivo; j += i)
                crivo[j] = 0;
        }
    }
}

// confere se eh primo, ou seja, se esta no crivo
bool eh_primo(long long int num)
{
    if (crivo[num] == 1)
        return true;
    return false;
}

// confere qual o primo mais proximo do numero
long long int primo_mais_prox(long long int num)
{
    for (int i = num; i < tam_crivo; i++)
    {
        if (eh_primo(i))
            return i;
    }
    cout << "merda";
    return -1;
}

// testo o numero minimo de operacoes na coluna
void confiro_coluna()
{

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            primo = primo_mais_prox(matriz[j][i]);
            operacoes += primo - matriz[j][i];
        }
        min_operacoes = min(operacoes, min_operacoes);
        operacoes = 0;
    }
}

// testo o numero minimo de operacoes na linha
void confiro_linha()
{

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            primo = primo_mais_prox(matriz[i][j]);
            operacoes += primo - matriz[i][j];
        }
        min_operacoes = min(operacoes, min_operacoes);
        operacoes = 0;
    }
}

int main()
{
    cin >> n >> m;
    matriz.assign(n, vector<long long int>(m, 0));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> matriz[i][j];
        }
    }
    // print_matriz();
    criar_crivo();
    confiro_linha();
    confiro_coluna();
    cout << min_operacoes;
    return 0;
}