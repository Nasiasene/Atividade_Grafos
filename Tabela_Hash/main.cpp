#include <iostream>
#include <vector>
#include <list>

using namespace std;

class HashDupla {
private:
    static const int tamanho_primeiro = 10;
    int tamanho_segundo;
    vector<vector<list<int>>> lista;

public:
    HashDupla(int tamanho) {
        lista.resize(tamanho_primeiro);
        tamanho_segundo = (tamanho / tamanho_primeiro);
        for (int i = 0; i < tamanho_primeiro; i++) {
            lista[i].resize(tamanho_segundo);
        }
    }

    int hash_primeiro(int chave) {return chave % tamanho_primeiro;}
    int hash_segundo(int chave) {return (chave / tamanho_primeiro) % tamanho_segundo;}

    void inserir(int chave);
    void remover(int valor);
    bool buscar(int chave);
};

void HashDupla::inserir(int chave) {
    int indice_primeiro = hash_primeiro(chave);
    int indice_segundo = hash_segundo(chave);
    lista[indice_primeiro][indice_segundo].push_back(chave);
}

void HashDupla::remover(int valor) {
    int indice_primeiro = hash_primeiro(valor);
    int indice_segundo = hash_segundo(valor);

    for (auto i = lista[indice_primeiro][indice_segundo].begin(); i != lista[indice_primeiro][indice_segundo].end(); ++i) { //percorre toda a lista.
        if (*i == valor) {
            lista[indice_primeiro][indice_segundo].remove(*i);
            break;
        }
    }
}

bool HashDupla::buscar(int chave) {
    int indice_primeiro = hash_primeiro(chave);
    int indice_segundo = hash_segundo(chave);

    for (int v : lista[indice_primeiro][indice_segundo]) {
        if (v == chave) {
            return true;
        }
    }
    return false;
}

int main() {
    int tam = 100;  // Tamanho da tabela
    HashDupla tabela(tam);

    // Inserindo chaves
    int key1 = 2, key2 = 20, key3 = 13; 
    tabela.inserir(key1);
    tabela.inserir(key2);
    tabela.inserir(44);

    // Procurando chaves
    bool encontrado_k1 = tabela.buscar(key1);
    
    if (encontrado_k1) {
        cout << key1 << " esta na tabela." << endl;
    } else {
        cout << key1 << " nao esta na tabela." << endl;
    }

    bool encontrado_k3 = tabela.buscar(key3); //NÃO ESTÁ NA TABELA
    
    if (encontrado_k3) {
        cout << key3 << " esta na tabela." << endl;
    } else {
        cout << key3 << " nao esta na tabela." << endl;
    }


    tabela.remover(key1);
    bool novo_enc_k1 = tabela.buscar(key1);
    if (novo_enc_k1) {
        cout << key1 << " esta na tabela." << endl;
    } else {
        cout << key1 << " nao esta na tabela." << endl;
    }

    return 0;
}