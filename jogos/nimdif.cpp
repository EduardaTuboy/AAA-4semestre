#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

const int MAX_STICKS = 10001;
int grundy[MAX_STICKS];
vector<int> c;

// calcula os numeros de grundy
void calcular_grundy(int max_sticks)
{
    memset(grundy, 0, sizeof(grundy));

    for (int i = 1; i <= max_sticks; ++i)
    {
        vector<bool> mex(MAX_STICKS, false);

        for (int move : c)
            if (i >= move)
                mex[grundy[i - move]] = true;

        for (int j = 0; j < MAX_STICKS; ++j)
            if (!mex[j])
            {
                grundy[i] = j;
                break;
            }
    }
}

// verifica se um estado e vencedor
char verificar_estado(const vector<int> &pilhas)
{
    int xor_total = 0;
    for (int sticks : pilhas)
        xor_total ^= grundy[sticks];
    if (xor_total == 0)
        return 'L';
    else
        return 'W';
}

int main()
{
    int tamanho_c;
    cin >> tamanho_c;
    c.resize(tamanho_c);
    for (int i = 0; i < tamanho_c; ++i)
        cin >> c[i];

    // calcula os numeros de grundy ate o maior valor possivel de sticks
    calcular_grundy(MAX_STICKS - 1);

    int m;
    cin >> m;
    while (m != 0)
    {
        int p;
        cin >> p;
        vector<int> pilhas(p);
        for (int i = 0; i < p; ++i)
            cin >> pilhas[i];

        cout << verificar_estado(pilhas);
        m--;
    }

    cout << endl;
    return 0;
}
