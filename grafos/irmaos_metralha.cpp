#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> grafo, grafo_transposto, DAG;
vector<long long> fortunas, scc_fortuna, PD;
vector<int> visitado, id_comp;
stack<int> pilha;
int n, m;

void dfs(int v)
{
    visitado[v] = 1;
    for (int vizinho : grafo[v])
        if (!visitado[vizinho])
            dfs(vizinho);
    pilha.push(v);
}

void dfs_transposto(int v, vector<int> &componentes)
{
    visitado[v] = 1;
    componentes.push_back(v);
    for (int vizinho : grafo_transposto[v])
        if (!visitado[vizinho])
            dfs_transposto(vizinho, componentes);
}

int main()
{
    cin >> n >> m;

    grafo.assign(n + 1, vector<int>());
    grafo_transposto.assign(n + 1, vector<int>());
    fortunas.assign(n + 1, 0);
    visitado.assign(n + 1, 0);
    id_comp.assign(n + 1, -1);

    for (int i = 1; i <= n; ++i)
        cin >> fortunas[i];

    for (int i = 0; i < m; ++i)
    {
        int a, b;
        cin >> a >> b;
        grafo[a].push_back(b);
        grafo_transposto[b].push_back(a); // montando o transposto
    }

    // percorrendo o grafo com DFS e guardando a ordem em uma pilha
    for (int i = 1; i <= n; ++i)
        if (!visitado[i])
            dfs(i);

    // achando os fortemente conexos e formando os "super vertices"
    fill(visitado.begin(), visitado.end(), 0);
    while (!pilha.empty())
    {
        int v = pilha.top();
        pilha.pop();
        if (!visitado[v])
        {
            vector<int> componentes;
            dfs_transposto(v, componentes);

            // registrando comp fortementes conectados
            int id = scc_fortuna.size();
            long long fortunas_comp = 0;
            for (int comp : componentes)
            {
                id_comp[comp] = id;
                fortunas_comp += fortunas[comp];
            }
            scc_fortuna.push_back(fortunas_comp);
        }
    }

    // criando o DAG
    DAG.assign(scc_fortuna.size(), vector<int>());

    for (int u = 1; u <= n; ++u)
        for (int v : grafo[u])
            if (id_comp[u] != id_comp[v])
                DAG[id_comp[u]].push_back(id_comp[v]);

    // PD no DAG para encontrar a maior soma de fortunas
    PD.assign(scc_fortuna.size(), 0);

    for (int i = 0; i < (int)scc_fortuna.size(); ++i)
        PD[i] = scc_fortuna[i];

    for (int u = 0; u < (int)DAG.size(); ++u)
        for (int v : DAG[u])
            PD[v] = max(PD[v], PD[u] + scc_fortuna[v]);

    // a maior quantia eh o elem maximo da PD
    long long max_fortuna = 0;
    for (long long quantia : PD)
        max_fortuna = max(max_fortuna, quantia);

    cout << max_fortuna;

    return 0;
}
