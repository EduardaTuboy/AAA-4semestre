#include <bits/stdc++.h>
using namespace std;

int n, m;                        // n farmacias, m arestas
vector<vector<int>> mapa;        // mapa da cidade (grafo)
vector<vector<bool>> disponivel; // matriz de quais arestas estao disponiveis
int caminho_atual = 0;
int maior_caminho = INT_MIN;

void copia_mapa()
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            disponivel[i][j] = mapa[i][j];
        }
    }
}

void imprimir_matriz()
{
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            if (disponivel[i][j])
            {
                cout << " ";
                cout << setw(2) << setfill('0') << j;
            }
            else
            {
                cout << " ";
                cout << "--";
            }
        }
        cout << endl;
    }
    cout << endl;
}

void backtracking(int farmacia)
{
    // nesse caso, nao tem condicao de parada! pode haver farmacias que nunca chegarei
    if (caminho_atual > maior_caminho)
    {
        maior_caminho = caminho_atual;
    }

    for (int nova_farmacia = 0; nova_farmacia < n; nova_farmacia++)
    {
        if (disponivel[farmacia][nova_farmacia])
        {
            caminho_atual++;
            disponivel[farmacia][nova_farmacia] = false;
            disponivel[nova_farmacia][farmacia] = false;
            backtracking(nova_farmacia);
            caminho_atual--;
            disponivel[farmacia][nova_farmacia] = true;
            disponivel[nova_farmacia][farmacia] = true;
        }
    }
}

int main()
{
    cin >> n >> m; // leitura inicial
    int x, y;
    while (n != 0 && m != 0) // loop ate que n == m == 0
    {
        mapa.assign(n, vector<int>(n, 0));
        disponivel.assign(n, vector<bool>(n, false));
        // completando o mapa
        for (int i = 0; i < m; i++)
        {
            cin >> x >> y;
            mapa[x][y] = 1;
            mapa[y][x] = 1;
        }

        copia_mapa(); // inicializar a matriz de disponivel

        // reseta pro proximo caso de teste o caminho atual e o maior caminho
        caminho_atual = 0;
        maior_caminho = INT_MIN;

        for (int i = 0; i < n; i++)
        {
            backtracking(i); // testo iniciando de todas as farmacias
        }
        cout << maior_caminho << endl;
        cin >> n >> m;
    }
    return 0;
}
