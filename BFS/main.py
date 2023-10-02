from bfs_graph import Grafo

def gerar_grafo(fileName):
  file = open(fileName, 'r')
  n_vertices = int(file.readline())

  grafo = Grafo(n_vertices)

  linha = 0
  for l in file:
    l.strip()
    numeros = l.split("\t")
    coluna = 0
    for i in numeros:
      if (coluna == grafo.n_vertices):
        break

      grafo.matriz[linha][coluna] = int(i)
      if (grafo.matriz[linha][coluna] > 0):
        grafo.lista[linha].append(coluna)

      coluna += 1

    linha += 1

  return grafo

#-------------------------------------------------------- TESTE --------------------------------------------------------#
#pcv10:
print("--------------------------------------------------------\nTESTE PCV10:\n")

grafo_10 = gerar_grafo("PCV/pcv10.txt")
matriz = grafo_10.matriz
print("\nMatriz de adj:\n")
for i in matriz:
  print(i)

lista = grafo_10.lista
print("\n\nLista de adj:\n")
for i in lista:
  print(i)

grafo_10.print_path(2, 6, grafo_10.bfs(2)[1])
grafo_10.print_path(2, 8, grafo_10.bfs(2)[1])