#include <bits/stdc++.h>
using namespace std;

class UnionFind
{
private:
    typedef vector<int> vi;
    vi pai;             // pai de cada vertice
    vi tam;             // tamanho dos componentes (representados pela raiz)
    int num_comp;       // numero de componentes
    int tam_maior_comp; // tamanho do maior componente

public:
    UnionFind(int n)
    {
        pai.assign(n, 0);
        tam.assign(n, 1); // todos os componentes sao formados por 1 vertice
        num_comp = n;
        tam_maior_comp = 1; // inicializa com o tamanho do maior componente
        for (int i = 0; i < n; i++)
            pai[i] = i; // cada vertice tem ele mesmo como pai
    }

    // encontrar a raiz de um vertice i com compressao de caminho
    int find(int i)
    {
        if (pai[i] == i) // se o pai de i eh ele mesmo
            return i;
        return pai[i] = find(pai[i]); // compressao de caminho
    }

    // verificar se dois elementos estao no mesmo conjunto
    bool sameSet(int i, int j)
    {
        return find(i) == find(j);
    }

    // unir dois componentes
    bool unite(int i, int j)
    {
        int raiz_i = find(i);
        int raiz_j = find(j);

        if (raiz_i == raiz_j) // ja estao no mesmo conjunto
            return false;

        // uniao onde o menor conjunto vai para o maior
        if (tam[raiz_i] > tam[raiz_j])
        {
            pai[raiz_j] = raiz_i;
            tam[raiz_i] += tam[raiz_j];
            tam_maior_comp = max(tam_maior_comp, tam[raiz_i]);
        }
        else
        {
            pai[raiz_i] = raiz_j;
            tam[raiz_j] += tam[raiz_i];
            tam_maior_comp = max(tam_maior_comp, tam[raiz_j]);
        }

        num_comp--; // uni componentes, entao subtrai
        return true;
    }

    int get_num_comp()
    {
        return num_comp;
    }

    int get_tam_maior_comp()
    {
        return tam_maior_comp;
    }
};

int main()
{
    int n, m;
    cin >> n >> m;

    UnionFind contatos(n);

    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        a--;                  // ajusta para indice 0
        b--;                  // ajusta para indice 0
        contatos.unite(a, b); // une os componentes
        // imprime o numero de componentes e o tamanho do maior
        cout << contatos.get_num_comp() << " " << contatos.get_tam_maior_comp() << endl;
    }

    return 0;
}
