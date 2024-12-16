#include <bits/stdc++.h>
using namespace std;

// busca em profundidade para ver se da para distribuir os processos
bool dfs(int letra, map<int, vector<int>> &grafo, vector<int> &processo_usado, vector<int> &processos_visitados)
{
    for (int processador : grafo[letra])
    {
        if (processos_visitados[processador])
            continue;
        processos_visitados[processador] = 1;

        // se o processo esta livre ou pode realocar outra tarefa
        if (processo_usado[processador] == -1 || dfs(processo_usado[processador], grafo, processo_usado, processos_visitados))
        {
            processo_usado[processador] = letra;
            return true;
        }
    }
    return false;
}

void eh_possivel_rodar_tarefas(const vector<string> &tarefas)
{
    // grafo em mapa onde chave eh o indice da tarefa e o vetor os processadores
    map<int, vector<int>> grafo;
    // demanda de cada tarefa com base no indice da tarefa
    map<int, int> tarefa_demanda;
    int contador_tarefas = 0;

    // para cada tarefa
    for (const string &tarefa : tarefas)
    {
        char letra = tarefa[0];
        // transformando um numero que esta em char em sua versao int
        int demanda = tarefa[1] - '0';

        // distribuindo cada tarefa em um processador
        int indice = 3;
        vector<int> processadores; // vetor de processadores disponiveis para determinada tarefa

        while (tarefa[indice] != ';')
        {
            processadores.push_back(tarefa[indice] - '0');
            indice++;
        }

        // monta as arestas do grafo, conectando os processadores com indice das tarefas
        for (int processador : processadores)
            grafo[contador_tarefas].push_back(processador);

        tarefa_demanda[contador_tarefas] = demanda;
        contador_tarefas++;
    }

    // vetor para guardar se o processo esta rodando uma tarefa ou nao (-1)
    vector<int> processo_usado(10, -1);

    // distribuindo as tarefas nos processadores
    for (const auto &[letra, demanda] : tarefa_demanda) // separando em tuplas
    {
        for (int i = 0; i < demanda; i++)
        {
            vector<int> processos_visitados(10, 0); // processadores usados
            if (dfs(letra, grafo, processo_usado, processos_visitados) == false)
            {
                cout << "NO" << endl;
                return;
            }
        }
    }
    cout << "YES" << endl;
    return;
}

int main()
{
    string linha;
    vector<string> tarefas;
    // enquanto tiver linha disponivel para leitura
    while (getline(cin, linha))
    {
        // se a linha lida for vazia e ainda tem tarefas para serem processadas
        if (linha.empty() && !tarefas.empty())
        {
            // eu processador essas tarefas
            eh_possivel_rodar_tarefas(tarefas);
            tarefas.clear();
        }
        // senao, ainda tenho tarefas para serem lidas
        else
            tarefas.push_back(linha);
    }
    // se ainda sobrou tarefas mesmo quando acabou as linhas vazias (ultimo caso de tarefas)
    if (!tarefas.empty())
        eh_possivel_rodar_tarefas(tarefas);

    return 0;
}
