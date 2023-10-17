from dfs_graph import Grafo

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
#pcv4:
print("--------------------------------------------------------\nTESTE PCV4:\n")

grafo_4 = gerar_grafo("PCV/pcv4.txt")
matriz = grafo_4.matriz
print("\nMatriz de adj:\n")
for i in matriz:
  print(i)

lista = grafo_4.lista
print("\n\nLista de adj:\n")
for i in lista:
  print(i)

print(f"\n\nDFS:\n{grafo_4.dfs(3)}")