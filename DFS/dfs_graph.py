import queue

class Grafo:
    def __init__(self, numero_vertices):
        self.n_vertices = numero_vertices
        self.matriz = [[0] * self.n_vertices for i in range(self.n_vertices)]  #matriz de adjacência.
        self.lista = [[] for i in range(self.n_vertices)]  #lista de adjacência.

#---------------------------------- Busca em profundidade(DFS) ----------------------------------#
    def dfs(self, source):
        is_visited = [False for i in range(self.n_vertices)]
        elementos = []
        pilha = []

        pilha.append(source)

        while pilha:
            vert = pilha.pop()

            if is_visited[vert] == False:
                elementos.append(vert)
                is_visited[vert] = True

                for vizinho in self.lista[vert]:
                    if is_visited[vizinho] == False:
                        pilha.append(vizinho)

        return elementos