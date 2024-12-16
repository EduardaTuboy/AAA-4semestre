#include <bits/stdc++.h>
using namespace std;

vector<int> precos, paginas;
vector<vector<int>> MEMO;

int max_pgs_REC(int livro, int x)
{
    // nao tenho mais livros ou acabou meu orcamento
    if (livro == 0 || x == 0)
        return 0;

    if (MEMO[livro][x] != -1)
        return MEMO[livro][x];

    // se exceder o orcamento, eu pulo o livro e parto pros proximos
    if (precos[livro - 1] > x)
    {
        MEMO[livro][x] = max_pgs_REC(livro - 1, x);
    }
    else // senao, eu posso pegar ou nao o livro
    {
        int nao_pegar = max_pgs_REC(livro - 1, x);
        int pegar = paginas[livro - 1] + max_pgs_REC(livro - 1, x - precos[livro - 1]);

        MEMO[livro][x] = max(nao_pegar, pegar);
    }

    return MEMO[livro][x];
}

int main()
{
    int n, x;
    cin >> n >> x; // n = numero de livros e x = orçamento

    precos.assign(n, 0);
    paginas.assign(n, 0);

    for (int i = 0; i < n; i++)
        cin >> precos[i];

    for (int i = 0; i < n; i++)
        cin >> paginas[i];

    MEMO.assign(n + 1, vector<int>(x + 1, -1));

    int resultado = max_pgs_REC(n, x);

    cout << resultado;

    return 0;
}
