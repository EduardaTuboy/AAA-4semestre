#include <bits/stdc++.h>
using namespace std;

long long int modpow(int base, int exp, int mod)
{
    if (exp == 0)
        return (1 % mod);
    long long int resultado = modpow(base, exp / 2, mod);
    resultado = (resultado * resultado) % mod;
    if (exp % 2 != 0) // se for impar
        resultado = (resultado * base) % mod;
    return resultado;
}

int main()
{
    int n, a, b, c;
    int p = 1000000007;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a >> b >> c;
        long long int exp = modpow(b, c, p - 1);
        cout << modpow(a, exp, p) << endl;
    }

    return 0;
}