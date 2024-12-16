#include <bits/stdc++.h>
using namespace std;

int compare(const void *a, const void *b)
{
    // cast
    const tuple<int, int> *tarefa_a = static_cast<const tuple<int, int> *>(a);
    const tuple<int, int> *tarefa_b = static_cast<const tuple<int, int> *>(b);

    // comparando o primeiro valor, se for igual, compara o segundo
    if (get<0>(*tarefa_a) == get<0>(*tarefa_b))
        return get<1>(*tarefa_a) - get<1>(*tarefa_b);
    else
        return get<0>(*tarefa_a) - get<0>(*tarefa_b);
}

// o que faz dar o maior custo depende que as tuplas estejam odenadas
int main()
{
    int n, t, d, x = 0;
    long long int custo = 0; // senao estoura com int :(
    cin >> n;
    tuple<int, int> tarefas[n];

    for (int i = 0; i < n; i++)
    {
        cin >> t >> d;
        tarefas[i] = make_tuple(t, d);
    }

    qsort(tarefas, n, sizeof(tuple<int, int>), compare);
    for (int i = 0; i < n; i++)
    {
        custo += get<1>(tarefas[i]) - (get<0>(tarefas[i]) + x);
        x = get<0>(tarefas[i]) + x;
    }
    cout << custo;

    return 0;
}