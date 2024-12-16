#include <bits/stdc++.h>
using namespace std;

// funcao que confere se o aluno que ler mais ler "maxpaginas", ainda sobra pagina para os outros
bool valido_max_pg(int paginas[], int n, int m, int maxpaginas)
{
    int num_estudantes = 1;
    int pgs_estudante_atual = 0;

    for (int i = 0; i < n; i++)
    {
        // vou para próximo estudante se eu passar de maxpaginas
        if (pgs_estudante_atual + paginas[i] > maxpaginas)
        {
            num_estudantes++;                 // adiciono outro estudante
            pgs_estudante_atual = paginas[i]; // dou a ele as paginas onde o anterior parou

            if (num_estudantes > m)
            {
                return false; // mais estudantes do que o permitido
            }
        }
        // se eu nao passar, o estudante le o proximo livro tambem
        else
        {
            pgs_estudante_atual += paginas[i];
        }
    }

    return true;
}
// funcao que faz a busca binaria dos chutes de quanto o aluno que ler mais pode ler a fim de ter
// o valor minimo
int busca_binaria(int paginas[], int n, int m)
{
    if (n < m)
        return -1; // caso em que ha menos livros que alunos (impossivel)

    // o minimo que o aluno que ler mais pode ler (o maior livro)
    int min = paginas[n - 1];

    // o maximo que o aluno que ler mais pode ler (todos os livros)
    int max = accumulate(paginas, paginas + n, 0);

    int resultado = max; // comeca no maximo, mas queremos achar um menor

    while (min <= max)
    {
        int meio = (min + max) / 2;

        // se o aluno ler o a quantidade "meio", vai sobrar para os outros, eh valido
        if (valido_max_pg(paginas, n, m, meio))
        {
            // resultado possivel, mas tem um melhor?
            resultado = meio;
            max = meio - 1; // vou para a metade inferior (aluno que le mais, ler menos)
        }
        // resultado nao eh valido, vai sobrar paginas sem serem lidas
        else
        {
            min = meio + 1; // vou para a metade supeiror (aluno que le mais, ler mais)
        }
    }
    return resultado;
}

int main()
{
    int n, m; // n = livros | m = estudantes
    cin >> n >> m;
    int paginas[n];
    int pagina;
    for (int i = 0; i < n; i++)
    {
        cin >> pagina;
        paginas[i] = pagina;
    }
    sort(paginas, paginas + n); // para usar busca binaria

    int minimo = busca_binaria(paginas, n, m);

    cout << minimo << endl;

    return 0;
}
