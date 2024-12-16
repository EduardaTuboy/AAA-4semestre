#include <bits/stdc++.h>
using namespace std;

// grundy e faz XOR
// faça uma vez so o grundy

// conjunto C e maxstates 10.000
vi grundy(conjunto, maxstates)
{
    vi vet(maxstates + 1);
    // cria um conjunto max

    set<int> conj;

    // coloca elementos no conjunto (grundy)
    for (r : conjunto)
        se(i - elem >= 0)
            conj.insert(vet[i - elem]);

    // para depois pegar o minimo excludente: xor grandy(5) xor grandy(12)
    for (mex = 0; mex < conjsize; mex++)
        if (conj.count(mex)) // se n achei no conjunto (isso retorna o num elementos, se ta da 1 senao da 0)
            // minimo excludente n ta no conjunto
            vet[i] = mex;
    break;

    return vet;
}