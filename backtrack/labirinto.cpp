#include <bits/stdc++.h>
using namespace std;

// variaveis compartilhadas
int m, n; // m linhas e n colunas
int menor_caminho = INT16_MAX;
int caminhos_possiveis = 0;
int tam_caminho_atual = 0;                                // tamanho caminho atual
vector<tuple<int, int>> obstaculos;                       // coordenadas dos obstáculos
int movimento[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}}; // movimento para 4 direções
vector<vector<bool>> visitado;                            // matriz para marcar visitados

bool valido(int linha, int coluna)
{
    if (linha >= 0 && linha < m && coluna >= 0 && coluna < n && !visitado[linha][coluna])
    {
        for (const auto &coordenada : obstaculos)
        {
            if (get<0>(coordenada) == linha && get<1>(coordenada) == coluna)
            {
                return false;
            }
        }
        return true;
    }
    return false;
}

void backtracking(int linha, int coluna)
{
    if (linha == m - 1 && coluna == n - 1) // chegou no fim!
    {
        if (tam_caminho_atual < menor_caminho)
        {
            menor_caminho = tam_caminho_atual;
        }
        caminhos_possiveis++;
        return;
    }

    visitado[linha][coluna] = true;

    for (int i = 0; i < 4; i++)
    {
        int nova_linha = linha + movimento[i][0];
        int nova_coluna = coluna + movimento[i][1];
        if (valido(nova_linha, nova_coluna))
        {
            tam_caminho_atual++;
            backtracking(nova_linha, nova_coluna);
            tam_caminho_atual--;                       // desfaz o movimento
            visitado[nova_linha][nova_coluna] = false; // desmarca a posição
        }
    }
}

int main()
{
    cin >> m >> n;
    visitado.resize(m, vector<bool>(n, false)); // inicializa a matriz de visitados

    int x, y;
    while (cin >> x >> y)
    {
        obstaculos.push_back(make_tuple(x, y));
    }
    visitado[0][0] = true; // inicio do percurso ja esta visitado
    backtracking(0, 0);
    cout << caminhos_possiveis << " " << (menor_caminho == INT16_MAX ? 0 : menor_caminho);

    return 0;
}
