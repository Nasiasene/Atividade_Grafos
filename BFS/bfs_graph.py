import queue

class Grafo:
    def __init__(self, numero_vertices):
        self.n_vertices = numero_vertices
        self.matriz = [[0] * self.n_vertices for i in range(self.n_vertices)]  #matriz de adjacência.
        self.lista = [[] for i in range(self.n_vertices)]  #lista de adjacência.

#---------------------------------- Busca em largura(BFS) ----------------------------------#
    def bfs(self, source): 
        fila = queue.Queue()
        fila.put(source)

        ant = [-1 for i in range(self.n_vertices)]
        dist = [-1 for i in range(self.n_vertices)]
        dist[source] = 0
        is_visited = [False for i in range(self.n_vertices)]
        is_visited[source] = 0

        #
        while (fila.empty() != True):
            p = fila.get()

            for ver in self.lista[p]:
                if (is_visited[ver] == False):
                    dist[ver] = dist[p] + 1
                    ant[ver] = p
                    fila.put(ver)
                    is_visited[ver] = True

        return dist, ant
    

    def print_path(self, v1 ,v2, ant): #Retona o melhor caminho entre os vertices
        path = []
        vert2 = v2

        if ant[v2] == -1:
            print(f"Não existe nenhum caminho entre os vértices {v1} e {v2}.")
    
        while (v2 != v1):
            path.append(v2)
            v2 = ant[v2]

        path.append(v1)
        path.reverse()

        print(f"\nMelhor caminho entre os vértices {v1} e {vert2}:\n", " -> ".join(map(str, path)))