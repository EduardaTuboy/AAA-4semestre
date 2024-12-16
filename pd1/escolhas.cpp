#include <bits/stdc++.h>
using namespace std;

int n;
vector<long long int> custos;
vector<long long int> MEMO;

long long int escolhasREC(int i)
{
    if (i == n - 1) // ultimo terno
        return 0;

    if (MEMO[i] != -1)
        return MEMO[i];

    // se ele escolher o terno i+1
    long long int escolha1 = abs(custos[i] - custos[i + 1]) + escolhasREC(i + 1);

    // se ele escolher o terno i+2 (verificando se nao passa do vetor)
    long long int escolha2 = (i + 2 < n) ? abs(custos[i] - custos[i + 2]) + escolhasREC(i + 2) : INT_MAX;

    // o minimo entre as duas escolhas
    MEMO[i] = min(escolha1, escolha2);

    return MEMO[i];
}

int main()
{
    cin >> n;
    custos.assign(n, 0);
    MEMO.assign(n, -1);

    for (int i = 0; i < n; i++)
    {
        cin >> custos[i];
    }

    cout << escolhasREC(0);
}
