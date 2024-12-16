#include <bits/stdc++.h>
using namespace std;

const int MAX_GRUNDY = 4;          // maximo numero de sticks que podem ser retirados + 1
vector<int> grundy(MAX_GRUNDY, 0); // tabela de numeros de grundy

// calcula os numeros de grundy
void calcula_grundy()
{
    grundy[0] = 0;
    for (int i = 1; i < MAX_GRUNDY; ++i)
    {
        bool mex[MAX_GRUNDY] = {false}; // marca quais valores podem ser alcancados
        if (i - 1 >= 0)
            mex[grundy[i - 1]] = true;
        if (i - 2 >= 0)
            mex[grundy[i - 2]] = true;
        if (i - 3 >= 0)
            mex[grundy[i - 3]] = true;

        // calcula o menor valor que nao pode ser alcancado
        for (int j = 0; j < MAX_GRUNDY; ++j)
        {
            if (!mex[j])
            {
                grundy[i] = j;
                break;
            }
        }
    }
}

int main()
{
    calcula_grundy(); // inicializa os numeros de grundy
    int t;
    cin >> t;

    int saldo = 20; // saldo inicial

    while (t--)
    {
        int n;
        cin >> n;

        vector<int> pilhas(n);
        for (int i = 0; i < n; ++i)
            cin >> pilhas[i];

        // calcula o nim-sum (XOR de todos os grundy das pilhas)
        int nim_sum = 0;
        for (int sticks : pilhas)
            nim_sum ^= grundy[sticks % MAX_GRUNDY]; // apenas resto relevante

        // determina resultado da rodada
        if (nim_sum == 0)
            saldo -= 20;
        else
            saldo += 20;
    }

    cout << saldo << endl;

    return 0;
}