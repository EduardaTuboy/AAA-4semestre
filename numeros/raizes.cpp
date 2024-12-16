#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
int p;
vector<ll> raizes;

void calcular_raizes_modulo()
{
    vector<ll> quadrados(p, -1);

    // calculando todos os s*s mod p
    for (ll s = 0; s < p; s++) // ll no s senao da overflow no s*s, pois sairia em int o resultado
    {
        ll quadrado = (s * s) % p;
        if (quadrados[quadrado] == -1)
            quadrados[quadrado] = s; // guardo o menor s que faz com que s^2 mod p = x mod p
    }

    for (int x = 0; x < p; x++)
        raizes[x] = quadrados[x];
}

int main()
{
    cin >> p;
    raizes.assign(p, -1);

    calcular_raizes_modulo();

    for (int i = 0; i < p; i++)
        cout << raizes[i] << (i == p - 1 ? "" : " ");

    return 0;
}
