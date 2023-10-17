#include <iostream>
#include <vector>
#include <list>
#include <unordered_map>

class TabelaHashDupla {
private:
    static const int tamanho_primeiro_nivel = 10;
    int tamanho_segundo_nivel;
    std::vector<std::vector<std::unordered_map<int, int>>> primeiro_nivel;

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

    void inserir(int chave, int objeto) {
        int indice_primeiro = hash_primeiro_nivel(chave);
        int indice_segundo = hash_segundo_nivel(chave);
        primeiro_nivel[indice_primeiro][indice_segundo][chave] = objeto;
    }

    int buscar(int chave) {
        int indice_primeiro = hash_primeiro_nivel(chave);
        int indice_segundo = hash_segundo_nivel(chave);

        if (primeiro_nivel[indice_primeiro][indice_segundo].find(chave) != primeiro_nivel[indice_primeiro][indice_segundo].end()) {
            return primeiro_nivel[indice_primeiro][indice_segundo][chave];
        }
        return -1;  // Retorno padrão para indicar que o objeto não foi encontrado
    }
};

int main() {
    int tamanho_da_tabela = 100;  // Tamanho da tabela
    TabelaHashDupla minha_tabela(tamanho_da_tabela);

    // Inserindo objetos
    minha_tabela.inserir(42, 1001);
    minha_tabela.inserir(55, 2002);
    minha_tabela.inserir(19, 3003);

    // Procurando objetos
    int chave = 55;
    int resultado = minha_tabela.buscar(chave);
    
    if (resultado != -1) {
        std::cout << "Chave " << chave << " encontrada. Valor do objeto: " << resultado << std::endl;
    } else {
        std::cout << "Chave " << chave << " não encontrada na tabela." << std::endl;
    }

    return 0;
}