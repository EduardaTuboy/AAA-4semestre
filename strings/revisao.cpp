#include <bits/stdc++.h>
using namespace std;

// trie para armazenar as palavras e contar os prefixos
struct NoTrie
{
    unordered_map<char, NoTrie *> filhos;
    int contador_prefixo; // conta quantas palavras possuem esse prefixo

    NoTrie() : contador_prefixo(0) {}
};

// raiz da trie global
NoTrie *raiz = new NoTrie();

// funcao para adicionar uma palavra na trie
void adicionar_palavra(const string &palavra)
{
    NoTrie *atual = raiz;
    for (char caractere : palavra)
    {
        if (atual->filhos.find(caractere) == atual->filhos.end())
            atual->filhos[caractere] = new NoTrie();
        atual = atual->filhos[caractere];
        atual->contador_prefixo++;
    }
}

// funcao para remover uma palavra da trie
void remover_palavra(const string &palavra)
{
    NoTrie *atual = raiz;
    for (char caractere : palavra)
    {
        if (atual->filhos.find(caractere) == atual->filhos.end())
        {
            return; // palavra nao existe
        }
        atual = atual->filhos[caractere];
        atual->contador_prefixo--;
    }
}

// funcao para contar palavras com determinado prefixo
int contar_prefixo(const string &prefixo)
{
    NoTrie *atual = raiz;
    for (char caractere : prefixo)
    {
        if (atual->filhos.find(caractere) == atual->filhos.end())
        {
            return 0;
        }
        atual = atual->filhos[caractere];
    }
    return atual->contador_prefixo;
}

int main()
{
    int num_op;
    cin >> num_op;

    while (num_op--)
    {
        int tipo_operacao;
        string palavra;
        cin >> tipo_operacao >> palavra;

        if (tipo_operacao == 1)
        {
            adicionar_palavra(palavra);
        }
        else if (tipo_operacao == 2)
        {
            remover_palavra(palavra);
        }
        else if (tipo_operacao == 3)
        {
            cout << contar_prefixo(palavra) << endl;
        }
    }

    return 0;
}
