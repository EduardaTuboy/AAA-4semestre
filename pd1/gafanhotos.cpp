#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> saltos, MEMO;

int saltosREC(int pos)
{
    // cheguei no final
    if (pos == n - 1)
        return 0;

    // se eu cair na mesma casa, eu ja calculei quantos pulos eu levo dessa posicao ate o final
    if (MEMO[pos] != -1)
        return MEMO[pos];

    int min_saltos = INT_MAX;

    // conferindo as opcoes de salto para o indice que estou
    for (int i = 1; i <= saltos[pos] && pos + i < n; i++)
    {
        int prox_salto = saltosREC(pos + i);
        if (prox_salto != INT_MAX)
            min_saltos = min(min_saltos, prox_salto + 1);
    }

    MEMO[pos] = min_saltos;
    return MEMO[pos];
}

int main()
{
    cin >> n;

    saltos.assign(n, 0);
    MEMO.assign(n, -1);

    for (int i = 0; i < n; i++)
        cin >> saltos[i];

    int resultado = saltosREC(0);

    if (resultado == INT_MAX) // nao achei uma quantidade de saltos que leva ao final do trecho
        cout << "Salto impossivel" << endl;
    else
        cout << resultado;

    return 0;
}
