from copy import deepcopy
import random
import heapq
import queue
import sys

class DirectedGraph:
    def __init__(self, filename="graphs.txt"):
        self._numberVertices = 0
        self._numberEdges = 0
        self._vertices = []
        self._edges = {}
        self._neighIn = {}
        self._neighOut = {}
        self._filename = filename
        self._loadFile()
        self._tsp = []
        self._tspCost = 99999
        #self.randomGraph()

    def _initGraph(self):
        for vert in range(self._numberVertices):
            self._vertices.append(vert)
        for i in range(self._numberVertices):
            self._neighIn[i] = []
            self._neighOut[i] = []

    @property
    def numberVertices(self):
        return self._numberVertices

    @property
    def numberEdges(self):
        return self._numberEdges

    @property
    def vertices(self):
        return self._vertices

    @property
    def edges(self):
        return self._edges

    def neighIn(self, vertex):
        return self._neighIn[vertex]

    def neighOut(self, vertex):
        return self._neighOut[vertex]

    def addVertex(self, newVertex):
        self._vertices.append(newVertex)
        self._neighIn[newVertex] = []
        self._neighOut[newVertex] = []
        self._numberVertices += 1

    def addIn(self, vertex, newVertex):
        self._neighIn[vertex].append(newVertex)

    def addOut(self, vertex, newVertex):
        self._neighOut[vertex].append(newVertex)

    def addEdge(self, vertex1, vertex2, cost):
        self.addIn(vertex2, vertex1)
        self.addOut(vertex1, vertex2)
        self._edges[vertex1, vertex2] = cost

    def verifyEdge(self, vertex1, vertex2):
        if vertex2 in self.neighOut(vertex1):
            return True
        return False

    def degreeIn(self, vertex):
        return len(self._neighIn[vertex])

    def degreeOut(self, vertex):
        return len(self._neighOut[vertex])

    def modifyCost(self, vertex1, vertex2, newCost):
        self._edges[vertex1, vertex2] = newCost

    def removeEdge(self, vertex1, vertex2):
        self._edges.pop((vertex1, vertex2), None)
        self._neighOut[vertex1].remove(vertex2)
        self._neighIn[vertex2].remove(vertex1)

    def removeVertex(self, vertex):
        for vert in self._neighOut[vertex]:
            self._edges.pop((vertex, vert), None)
            self._neighIn[vert].remove(vertex)
        for vert in self._neighIn[vertex]:
            self._edges.pop((vert, vertex), None)
            self._neighOut[vert].remove(vertex)
        self._neighIn.pop(vertex, None)
        self._vertices.remove(vertex)
        self._neighOut.pop(vertex, None)
        self._numberVertices -= 1

    def copy(self):
        return deepcopy(self)

    def breadthFirstTraversalSearch(self, startVertex):
        que = queue.Queue()
        visited = []
        que.put(startVertex)
        visited.append(startVertex)
        while not que.empty():
            vertex = que.get()
            for vert in self.neighOut(vertex):
                if vert not in visited:
                    que.put(vert)
                    visited.append(vert)
        return visited

    def getSubgraphEdges(self, givenVertices):
        edges = []
        for vert in givenVertices:
            for v in self._neighOut[vert]:
                if (vert, v) not in edges and (v, vert) not in edges:
                    edges.append((vert, v))
        return edges

    def connectedGraphs(self):
        auxList = []
        number = 1
        for vert in self._vertices:
            if vert not in auxList:
                vertices = self.breadthFirstTraversalSearch(vert)
                edges = self.getSubgraphEdges(vertices)
                print("Subgraph " + str(number))
                print("Vertices: " + str(vertices))
                print("Edges: " + str(edges))
                print()
                for v in vertices:
                    auxList.append(v)
                #if len(auxList) != self._ctrl.numberVertices():
                    #break
                number += 1

    def dijkstra(self, startVertex, endVertex):
        que = []
        prev = {}
        dist = {}
        heapq.heappush(que, (0, startVertex))
        dist[startVertex] = 0
        while len(que) > 0:
            distCurrent, currentVertex = heapq.heappop(que)
            for vert in self.neighOut(currentVertex):
                if vert not in dist.keys() or dist[currentVertex] + self._edges[(currentVertex, vert)] < dist[vert]:
                    dist[vert] = dist[currentVertex] + self._edges[(currentVertex, vert)]
                    heapq.heappush(que, (dist[vert], vert))
                    prev[vert] = currentVertex
            if currentVertex == endVertex:
                return prev, dist[currentVertex]
        return None, 0

    def getCostPrim(self, list, vertex):
        for el in list:
            if el[1] == vertex:
                return el[0]
        return None

    def prim(self, startVertex):
        verticesCost = []
        prev = {}
        verticesCost.append([0, startVertex])
        prev[startVertex] = -1
        for vert in self._vertices:
            if vert != startVertex:
                heapq.heappush(verticesCost, [999999999, vert])
                prev[vert] = -1
        mst = []
        minCost = 0
        while len(verticesCost) > 0:
            cost, currentVert = heapq.heappop(verticesCost)
            if prev[currentVert] != -1:
                minCost += cost
                mst.append((prev[currentVert], currentVert))
            for vert in self._neighOut[currentVert]:
                verCost = self.getCostPrim(verticesCost, vert)
                if verCost != None:
                    if self._edges[vert, currentVert] < verCost:
                        verticesCost.remove([verCost, vert])
                        heapq.heappush(verticesCost, [self._edges[vert, currentVert], vert])
                        prev[vert] = currentVert
        return mst, minCost

    def verify(self, x, val):
        for i in range(len(x)-1):
            if x[i] == val:
                return False
        return True

    def getCost(self, x):
        cost = 0
        for i in range(len(x)-1):
            cost += self._edges[x[i], x[i+1]]
        return cost

    def backtracking(self, x, dim):
        if len(x) + 1 == dim:
            x.append(x[0])
            cost = self.getCost(x)
            if cost < self._tspCost:
                self._tspCost = cost
                self._tsp = deepcopy(x)
        if len(x) + 1 > dim:
            return
        x.append(0)
        for i in self._vertices:
            x[-1] = i
            if self.verify(x, i) and i in self.neighOut(x[-2]) and dim != len(x)+1 or self.verify(x, i) and i in self.neighOut(x[-2])and i in self.neighIn(x[0]) and dim == len(x)+1:
                self.backtracking(x[:], dim)

    def solveTSP(self):
        path = []
        #for vert in self.vertices:
        path.append(0)
        self.backtracking(path, self._numberVertices+1)
        #path.clear()
        return self._tsp, self._tspCost

    def _loadFile(self):
        try:
            f = open(self._filename, "r")
            line = f.readline()
            token = line.split(" ")
            self._numberVertices = int(token[0])
            self._numberEdges = int(token[1])
            self._initGraph()
            line = f.readline()
            while len(line) > 2:
                token = line.split(" ")
                self.addEdge(int(token[0]), int(token[1]), int(token[2].strip('\n')))
                line = f.readline()
        except IOError as e:
            print("Cannot load file!" + str(e))
        finally:
            f.close()

    def randomGraph(self):
        self._numberVertices = int(input("Give number of vertices for random graph: "))
        maxEdges = (self._numberVertices*(self._numberVertices - 1))
        self._numberEdges = int(input("Give number of edges for random graph: "))
        while self._numberEdges > maxEdges:
            self._numberEdges = int(input("Please introduce a number smaller than or equal to " + str(maxEdges) + ": "))
        c = 0
        self._initGraph()
        while c < self._numberEdges:
            vert1 = random.choice(range(self._numberVertices))
            vert2 = random.choice(range(self._numberVertices))
            cost = random.choice(range(-100, 100))
            if (vert1, vert2) not in self._edges.keys():
                self._edges[(vert1, vert2)] = cost
                self.addOut(vert1, vert2)
                self.addIn(vert2, vert1)
                c += 1
