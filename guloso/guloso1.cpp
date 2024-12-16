#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, num;
    cin >> n;
    int posicoes[n + 1];
    posicoes[0] = 0;
    int ant = posicoes[0];
    int rodadas = 1; // conta a primeira rodada

    for (int i = 0; i < n; i++)
    {
        cin >> num;
        posicoes[num] = i;
    }
    // guardo as posicoes de cada numero em posicoes[] e vejo se a posicao do elemento (atual) eh
    // menor que a posicao do elemento anterior, se for, soma 1 rodada
    for (int elem : posicoes)
    {
        rodadas += (elem < ant); // se for verdadeiro, incrementa 1 (true = 1)
        ant = elem;
    }
    cout << rodadas;

    return 0;
}