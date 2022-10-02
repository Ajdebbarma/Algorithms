
class Graph:

    def __init__(self, vertices):
        self.V = vertices
        self.graph = []

    def addEdge(self, u, v, w):
        self.graph.append([u, v, w])

    def printArr(self, dist):
        print("Vertex Distance from Source")
        for i in range(self.V):
            print("{0}\t\t{1}".format(i, dist[i]))

    def BellmanFord(self, src):

        dist = [float("Inf")] * self.V
        dist[src] = 0


        for _ in range(self.V - 1):
            for u, v, w in self.graph:
                if dist[u] != float("Inf") and dist[u] + w < dist[v]:
                    dist[v] = dist[u] + w


        for u, v, w in self.graph:
            if dist[u] != float("Inf") and dist[u] + w < dist[v]:
                print("Graph contains negative weight cycle")
                return

        self.printArr(dist)

n = (int)(input("Enter the no. of edges = "))
g = Graph(n)
print("Enter the source, destination, weight one by one:")
for i in range(n):
    src = (int)(input("Enter source: "))
    dest = (int)(input("Enter destination: "))
    weight = (int)(input("Enter weight: "))
    g.addEdge(src, dest, weight)

g.BellmanFord(0)
