#include <bits/stdc++.h>
using namespace std;

int n, tam_crivo = 1000001;
vector<long long int> primos;
long long int num;
bitset<1000010> crivo;

// criando o crivo para guardar os primos ate 10^6
void criar_crivo()
{
    crivo.set();
    crivo[0] = crivo[1] = 0;
    for (long long int i = 2; i < tam_crivo; ++i)
    {
        if (crivo[i])
        {
            for (long long int j = i * i; j <= tam_crivo; j += i)
                crivo[j] = 0;
            primos.push_back(i);
        }
    }
}

bool eh_primo(long long int num)
{
    if (crivo[num] == 1)
        return true;
    return false;
}

int calculo_divisores(long long int num)
{
    if (eh_primo(num))
        return 2;
    // cout << "numero eh:" << num << endl;
    int num_dividores = 1, num_atual = num;
    map<int, int> decomposicao;
    for (int i = 0; i < primos.size(); i++)
    {
        if (num_atual % primos[i] == 0)
        {
            // cout << "num" << num_atual << " primos[i]:" << primos[i] << endl;
            num_atual /= primos[i];
            // cout << "num eh" << num_atual << endl;
            decomposicao[primos[i]]++;
            // cout << "decomposicao" << decomposicao[primos[i]] << endl;
            i--;
            if (num_atual == 1) // ja fatorei todo o numero
                break;
        }
    }
    // numero nao eh primo
    for (int j = 0; j < decomposicao.size(); j++)
        num_dividores *= (decomposicao[primos[j]] + 1);
    return num_dividores;
}

int main()
{
    cin >> n;
    criar_crivo();
    for (int i = 0; i < n; i++)
    {
        cin >> num;
        cout << calculo_divisores(num) << endl;
    }
    return 0;
}
