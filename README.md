# Atividades_ED
Respositório destinado a duas atividades da matéria de Estrutura de Dados ministrada pelo professor Gilberto.


#ATIVIDADE 1(Grafos):
+ Implemente a estrutura grafo com representação em: Matriz de Adjacência e Lista de Adjacência. Depois implemente as seguintes atividades:

-  Leitor dos arquivos e carregamento das estruturas do grafo
-  Busca em largura (BFS)
    - Criar uma função que imprima o caminho entre dois vértices s e t formado pelo BFS. Indicar que “não há
      caminho entre os vértices” caso não haja o caminho.
-  Buca em Profundidade (DFS)
    - Reimplemente o DFS com auxílio de uma pilha para
      eliminar a recursão da implementação.

#ATIVIDADE 2(Tabela Hash):
1. Implementar uma estrutura de tabela hash para armazenar n objetos
com encadeamento separado duplo. No encadeamento duplo existem
dois níveis de endereçamento, nos dois o mapeamento da chave ao
endereço se dá por uma função hash. A figura abaixo ilustra o
esquema de encadeamento separado duplo.

a. No primeiro nível crie um vetor com 10 ponteiros para vetores.
Aplique a função hash para direcionar o elemento da chave c
em uma das outras tabelas do segundo nível;
b. No segundo nível cada tabela é composta por um vetor de n/10
listas de objetos a serem armazenados. Uma segunda função
hash diferente da primeira deve ser definida para direcionar a
chave c em uma das listas específicas


2. Implemente as funções hash específica de cada nível de
endereçamento, além dos métodos de inserção de novos objetos a
partir de suas chaves únicas e recuperação de objetos já cadastrados a
partir da chave única.
