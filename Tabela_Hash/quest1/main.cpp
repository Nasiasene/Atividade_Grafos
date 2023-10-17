#include <iostream>
#include <vector>
#include <list>

class TabelaHashDupla {
private:
    static const int tamanho_primeiro_nivel = 10;
    int tamanho_segundo_nivel;
    std::vector<std::vector<std::list<int>>> primeiro_nivel;

public:
    TabelaHashDupla(int tamanho) : tamanho_segundo_nivel(tamanho / tamanho_primeiro_nivel) {
        primeiro_nivel.resize(tamanho_primeiro_nivel);
    }

    int hash_primeiro_nivel(int chave) {
        return chave % tamanho_primeiro_nivel;
    }

    int hash_segundo_nivel(int chave) {
        return (chave / tamanho_primeiro_nivel) % tamanho_segundo_nivel;
    }

    void inserir(int chave) {
        int indice_primeiro = hash_primeiro_nivel(chave);
        int indice_segundo = hash_segundo_nivel(chave);
        primeiro_nivel[indice_primeiro][indice_segundo].push_back(chave);
    }

    bool buscar(int chave) {
        int indice_primeiro = hash_primeiro_nivel(chave);
        int indice_segundo = hash_segundo_nivel(chave);

        for (int valor : primeiro_nivel[indice_primeiro][indice_segundo]) {
            if (valor == chave) {
                return true;
            }
        }
        return false;
    }
};

int main() {
    int tamanho_da_tabela = 100;  // Tamanho da tabela
    TabelaHashDupla minha_tabela(tamanho_da_tabela);

    // Inserindo um objeto
    int chave = 42;
    minha_tabela.inserir(chave);

    // Procurando um objeto
    bool encontrado = minha_tabela.buscar(chave);
    
    if (encontrado) {
        std::cout << "Chave " << chave << " encontrada na tabela." << std::endl;
    } else {
        std::cout << "Chave " << chave << " não encontrada na tabela." << std::endl;
    }

    return 0;
}