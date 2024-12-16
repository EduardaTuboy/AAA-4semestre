#include <bits/stdc++.h>
using namespace std;

int n, s; // n cidades, cidade inicial s
vector<vector<long long>> distancias, MEMO;

long long busca_passeio_curto(int cidade_atual, int passeio)
{

    // caso base: todos as cidades foram visitadas, volto a cidade s
    if (passeio == (1 << n) - 1)
        return distancias[cidade_atual][s];

    if (MEMO[cidade_atual][passeio] != -1)
        return MEMO[cidade_atual][passeio];

    long long passeio_mais_curto = INT_MAX;

    // passeio por todos as cidades
    for (int prox_cidade = 0; prox_cidade < n; prox_cidade++)
    {
        // se ja visitei a prox cidade ou eh uma distancia 0, pula
        if (passeio & (1 << prox_cidade) || distancias[cidade_atual][prox_cidade] == 0)
            continue;

        // calculo os passeios possiveis para as proximas cidades
        long long passeio_atual =
            distancias[cidade_atual][prox_cidade] +
            busca_passeio_curto(prox_cidade, passeio | (1 << prox_cidade));

        // pego o caminho mais curto
        passeio_mais_curto = min(passeio_mais_curto, passeio_atual);
    }

    // depois de calcular tudo, eu atualizo a MEMO com o mais curto possivel
    return MEMO[cidade_atual][passeio] = passeio_mais_curto;
}

int main()
{
    cin >> n >> s;
    distancias.assign(n, vector<long long>(n));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> distancias[i][j];
        }
    }
    // creio uma MEMO, onde as linhas sao as cidades, e as colunas os passeios possiveis em bitmask
    MEMO.assign(n, vector<long long>(1 << n, -1));
    int passeio_inicial = (1 << s); // a cidade s esta visitada

    long long passeio_mais_curto = busca_passeio_curto(s, passeio_inicial);

    if (passeio_mais_curto == INT_MAX)
        passeio_mais_curto = -1;
    else
        passeio_mais_curto = passeio_mais_curto;

    cout << passeio_mais_curto;

    return 0;
}
