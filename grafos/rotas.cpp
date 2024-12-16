#include <bits/stdc++.h>
using namespace std;

// busca em profundidade
void dfs(int node, const vector<vector<int>> &grafo, vector<int> &visitado)
{
    visitado[node] = 1;
    // percorro a linha node (os vizinhos)
    for (int neighbor : grafo[node])
        if (!visitado[neighbor])
            dfs(neighbor, grafo, visitado);
}

int eh_fortemente_conectado(int N, const vector<vector<int>> &grafo)
{
    // vejo se o grafo eh conectado
    vector<int> visitado(N + 1, 0);
    dfs(1, grafo, visitado);
    for (int i = 1; i <= N; ++i)
        if (!visitado[i])
            return 0;

    // vejo se eh fortemente conectado fazendo o transposto
    vector<vector<int>> transposto(N + 1);
    for (int u = 1; u <= N; ++u)
        for (int v : grafo[u])
            transposto[v].push_back(u);

    fill(visitado.begin(), visitado.end(), 0); // reseto o vetor de visitados
    dfs(1, transposto, visitado);
    for (int i = 1; i <= N; ++i)
        if (!visitado[i])
            return 0;
    return 1;
}

int main()
{
    int N, M;
    while (cin >> N >> M && !(N == 0 && M == 0))
    {
        vector<vector<int>> grafo(N + 1); // grafo da relacao de pessoas
        for (int i = 0; i < M; ++i)
        {
            int u, v, r;
            cin >> u >> v >> r;
            grafo[u].push_back(v);
            if (r == 2)
                grafo[v].push_back(u); // faz para os dois lados
        }
        // para saber se houve amor total, precisamos ver se o grafo eh fortemente conectado
        cout << eh_fortemente_conectado(N, grafo) << endl;
    }
    return 0;
}
