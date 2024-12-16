#include <bits/stdc++.h>
using namespace std; // para usar "cin" sem precisar escrever "std.cin"

int main()
{

    int T;    // numero de casos teste
    int N;    // numero de linhas das materias que o CDF sabe e os dias que ele demora
    cin >> T; // colocando o valor lido em T
    string materia;
    int dias;
    int D; // numero de dias pra fazer o codigo

    for (int t = 0; t < T; t++)
    {
        cout << "Case " << t + 1 << ": ";
        cin >> N;
        map<string, int> repertorio_cdf; // guardo as materias e dias em um mapa
        // guardo todas as N materias e dias por meio do for abaixo
        for (int n = 0; n < N; n++)
        {
            cin >> materia >> dias;
            repertorio_cdf[materia] = dias;
        }
        // comparo as materias do cdf e a do professor, se o cdf souber, comparo os dias com D
        cin >> D >> materia;
        // se nao achei a materia no repertorio do cdf ou a materia passou do prazo maximo
        if (repertorio_cdf.find(materia) == repertorio_cdf.end() || repertorio_cdf[materia] > D + 5)
        {
            cout << "Deu ruim! Va trabalhar";
        }
        // senao se a materia esta dentro do prazo
        else if (repertorio_cdf[materia] <= D)
        {
            cout << "Ufa!";
        }
        // senao se a materia esta atrasada (poderia ser apenas um else, mas quis deixar claro a condicao)
        else if (repertorio_cdf[materia] >= D && repertorio_cdf[materia] <= D + 5)
        {
            cout << "Atrasado";
        }

        cout << endl; // \n sem deixar buffer sujo
    }
    return 0;
}