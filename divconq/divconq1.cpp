#include <bits/stdc++.h>
using namespace std;

struct Ponto
{
    int x, y;
};

// distacia euclidiana
double distancia(const Ponto &p1, const Ponto &p2)
{
    return sqrt((p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y));
}

// funcoes de comparar as coordenadas para ordenar os pontos
bool compararX(const Ponto &a, const Ponto &b)
{
    return a.x < b.x;
}

bool compararY(const Ponto &a, const Ponto &b)
{
    return a.y < b.y;
}

// funcao para achar a menor distancia entre 3 pontos
double menor_distancia_3pontos(vector<Ponto> &pontos, int inicio, int fim)
{
    double menor_dist = DBL_MAX; // seta a menor_dist para "infinito"
    for (int i = inicio; i < fim; ++i)
    {
        for (int j = i + 1; j < fim; ++j)
        {
            menor_dist = min(menor_dist, distancia(pontos[i], pontos[j]));
        }
    }
    return menor_dist;
}

// funcao para achar a menor distancia na faixa
double menor_dist_faixaL(vector<Ponto> &faixa_L, double delta)
{
    double menor_dist = delta; // eh a menor que temos por enquanto

    // ordenando pela coordenada y
    sort(faixa_L.begin(), faixa_L.end(), compararY);

    // comparando de dois em dois pontos que tenham o deltaY menor que a menor distancia, pois
    // se forem maiores, na distancia euclidiana vai passar da menor distancia, ja que deltaX temos
    // o maximo que eh a menor distancia
    for (int i = 0; i < faixa_L.size(); ++i)
    {
        for (int j = i + 1; j < faixa_L.size() && (faixa_L[j].y - faixa_L[i].y) < menor_dist; ++j)
        {
            menor_dist = min(menor_dist, distancia(faixa_L[i], faixa_L[j]));
        }
    }

    return menor_dist;
}

double par_mais_proximo_rec(vector<Ponto> &pontos, int inicio, int fim)
{
    // se tiver 3 pontos, conquisto (acho a menor distancia entre eles)
    if (fim - inicio <= 3)
    {
        return menor_distancia_3pontos(pontos, inicio, fim);
    }

    // se tiver mais que 3 pontos, ir divindo no meio
    int meio = (inicio + fim) / 2;
    Ponto ponto_meio = pontos[meio];

    // encontrando por recursao as menores distancias de cada lado
    double delta_esq = par_mais_proximo_rec(pontos, inicio, meio);
    double delta_dir = par_mais_proximo_rec(pontos, meio, fim);

    // delta eh a menor distancia entre os dois lados
    double delta = min(delta_esq, delta_dir);

    // criando a faixa L (esta entre os dois lados do plano cartesiano)
    // faixa eh necessaria pois a menor distancia pode estar na faixa e nao em cada lado
    vector<Ponto> faixa_L;
    for (int i = inicio; i < fim; ++i)
    {
        // faixa tera comprimento menor que 2.delta pois delta eh a menor dist por enquanto
        // selecionando os pontos dentro da faixa
        if (abs(pontos[i].x - ponto_meio.x) < delta)
        {
            faixa_L.push_back(pontos[i]);
        }
    }

    // dado os pontos, procura-se a menor distancia entre os pontos nessa faixa
    return min(delta, menor_dist_faixaL(faixa_L, delta));
}

// dividindo o vetor de pontos para conquistar suas distancias quando houver poucos pontos
double par_mais_proximo(vector<Ponto> &pontos)
{
    // ordenando os pontos pela coordenada x
    sort(pontos.begin(), pontos.end(), compararX);

    // recursao
    return par_mais_proximo_rec(pontos, 0, pontos.size());
}

int main()
{
    vector<Ponto> pontos;
    int n, x, y;
    Ponto ponto;

    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> x >> y;
        ponto.x = x;
        ponto.y = y;
        pontos.push_back(ponto);
    }
    // fixed evita que float saia em notacao cientifica
    // setprecision seta para duas casas apos o ponto
    cout << fixed << setprecision(2);

    cout << par_mais_proximo(pontos) << endl;

    return 0;
}
