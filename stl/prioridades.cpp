#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, tempo_execucao, K, ID, T;
    string query; // para consumir a constante "query" da consulta
    cin >> n;
    // min heap com cada elemento sendo uma tupla para que a consulta executada e menor tempo de execucao sempre esteja no inicio
    // min heap precisa do elemento, o container para armazenar os elementos e se eh  em ordem crescente ou decrescente
    priority_queue<std::tuple<int, int, int>,
                   vector<std::tuple<int, int, int>>,
                   greater<std::tuple<int, int, int>>>
        ordem_consultas;
    // vetor com as primeiras consultas
    vector<int> primeiras_consultas;
    // leitura das leituras e insercao na min heap
    for (int i = 0; i < n; i++)
    {
        cin >> query >> ID >> T;
        ordem_consultas.push(make_tuple(T, ID, T)); // inserir no final da fila, não precisa indicar aonde pois o tipo já indica
    }
    cin >> K;
    // vou calculando as primeiras consultas ate que eu alcance K iteracoes
    while (primeiras_consultas.size() < K)
    {
        tuple<int, int, int> current = ordem_consultas.top(); // pego o primeiro da heap
        ordem_consultas.pop();                                // tiro da heap
        // extraio os valores dessa tupla
        tempo_execucao = get<0>(current);
        ID = get<1>(current);
        T = get<2>(current);
        // insiro no final do vetor a consulta que acabou de ser executada
        primeiras_consultas.push_back(ID);
        // coloco na heap a proxima execucao da consulta com esse determinado ID (e a heap organiza em que executou primeiro)
        ordem_consultas.push(make_tuple(tempo_execucao + T, ID, T));
    }
    // para cada ID chamado de id, eu imprimo e pulo linha
    for (int id : primeiras_consultas)
    {
        cout << id << endl;
    }
    return 0;
}