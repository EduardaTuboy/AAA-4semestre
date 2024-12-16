#include <bits/stdc++.h>
using namespace std;

#define primo_grande 1000000007

vector<vector<int>> labirinto, MEMO;
int n;

int caminhos(int i, int j)
{
    // se for um obstaculo, nao tem caminho
    if (labirinto[i][j] == '*')
        return 0;

    // chegamos no destino, adciona 1 caminho
    if (i == n - 1 && j == n - 1)
        return 1;

    if (MEMO[i][j] != -1)
        return MEMO[i][j];

    int num_caminhos = 0;

    if (i + 1 < n) // mov direita
        num_caminhos = (num_caminhos + caminhos(i + 1, j)) % primo_grande;

    if (j + 1 < n) // mov baixo
        num_caminhos = (num_caminhos + caminhos(i, j + 1)) % primo_grande;

    if (i + 1 < n && j + 1 < n) // mov diagonal
        num_caminhos = (num_caminhos + caminhos(i + 1, j + 1)) % primo_grande;

    return MEMO[i][j] = num_caminhos;
}

int main()
{
    cin >> n;
    labirinto.assign(n, vector<int>(n));
    MEMO.assign(n, vector<int>(n, -1));

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            char posicao;
            cin >> posicao;
            labirinto[i][j] = (posicao == '.') ? 0 : '*';
        }
    }

    int resultado = caminhos(0, 0) % primo_grande;
    cout << resultado;

    return 0;
}
