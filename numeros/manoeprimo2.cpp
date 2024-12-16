#include <bits/stdc++.h>
using namespace std;

int n;
vector<long long int> primos;

bool eh_primo(long long int num)
{
    if (num < 2)
        return false;
    for (long long int i = 2; i * i <= num; ++i) // indo ate a raiz
    {
        if (num % i == 0)
            return false;
    }
    return true;
}

int calculo_divisores(long long int num)
{
    if (eh_primo(num)) // se eh primo, ja sei que tem 2 divisores
        return 2;

    int num_divisores = 1;
    map<long long int, int> decomposicao;
    long long int num_atual = num;

    for (long long int primo : primos)
    {
        if (primo * primo > num_atual) // calculo so ate a raiz do numero
            break;
        while (num_atual % primo == 0)
        {
            decomposicao[primo]++; // guardo em um mapa o expoente para cada primo
            num_atual /= primo;    // atualiza o numero
        }
    }

    // adiciono o que sobrou do numero
    if (num_atual > 1)
        decomposicao[num_atual]++;

    // calculo do numero dos divisores
    for (auto [primo, expoente] : decomposicao)
    {
        num_divisores *= (expoente + 1);
    }

    return num_divisores;
}

int main()
{
    cin >> n;

    // calculando alguns primos manualmente
    for (long long int i = 2; i <= 100000; ++i)
    {
        if (eh_primo(i))
            primos.push_back(i);
    }

    for (int i = 0; i < n; ++i)
    {
        long long int num;
        cin >> num;
        cout << calculo_divisores(num) << endl;
    }

    return 0;
}
