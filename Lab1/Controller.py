class Controller:
    def __init__(self, graph, validator):
        self._graph = graph
        self._validator = validator

    def numberVertices(self):
        return self._graph.numberVertices

    def vertices(self):
        return self._graph.vertices

    def edges(self):
        return self._graph.edges

    def neighIn(self, vertex):
        self._validator.verifyInteger(vertex)
        self._validator.verifyVertex(self._graph, vertex)
        return self._graph.neighIn(vertex)

    def neighOut(self, vertex):
        self._validator.verifyInteger(vertex)
        self._validator.verifyVertex(self._graph, vertex)
        return self._graph.neighOut(vertex)

    def addVertex(self, newVertex):
        self._validator.verifyInteger(newVertex)
        self._validator.verifyAlreadyVertex(self._graph, newVertex)
        self._graph.addVertex(newVertex)

    def addIn(self, vertex, newVertex):
        self._validator.verifyInteger(vertex)
        self._validator.verifyInteger(newVertex)
        self._validator.verifyVertex(self._graph, vertex)
        self._graph.addIn(vertex, newVertex)

    def addOut(self, vertex, newVertex):
        self._validator.verifyInteger(vertex)
        self._validator.verifyVertex(self._graph, vertex)
        self._validator.verifyInteger(newVertex)
        self._graph.addOut(vertex, newVertex)

    def addEdge(self, vertex1, vertex2, cost):
        self._validator.verifyInteger(vertex1)
        self._validator.verifyInteger(vertex2)
        self._validator.verifyVertex(self._graph, vertex1)
        self._validator.verifyVertex(self._graph, vertex2)
        self._validator.verifyAlreadyEdge(self._graph, vertex1, vertex2)
        self._graph.addEdge(vertex1, vertex2, cost)

    def verifyEdge(self, vertex1, vertex2):
        self._validator.verifyInteger(vertex1)
        self._validator.verifyInteger(vertex2)
        self._validator.verifyVertex(self._graph, vertex1)
        self._validator.verifyVertex(self._graph, vertex2)
        return self._graph.verifyEdge(vertex1, vertex2)

    def degreeIn(self, vertex):
        self._validator.verifyInteger(vertex)
        self._validator.verifyVertex(self._graph, vertex)
        return self._graph.degreeIn(vertex)

    def degreeOut(self, vertex):
        self._validator.verifyVertex(self._graph, vertex)
        self._validator.verifyInteger(vertex)
        return self._graph.degreeOut(vertex)

    def modifyCost(self, vertex1, vertex2, newCost):
        self._validator.verifyVertex(self._graph, vertex1)
        self._validator.verifyVertex(self._graph, vertex2)
        self._validator.verifyEdge(self._graph, vertex1, vertex2)
        self._graph.modifyCost(vertex1, vertex2, newCost)

    def removeEdge(self, vertex1, vertex2):
        self._validator.verifyVertex(self._graph, vertex1)
        self._validator.verifyVertex(self._graph, vertex2)
        self._validator.verifyEdge(self._graph, vertex1, vertex2)
        self._graph.removeEdge(vertex1, vertex2)

    def removeVertex(self, vertex):
        self._validator.verifyVertex(self._graph, vertex)
        return self._graph.removeVertex(vertex)

    def connectedGraphs(self):
        return self._graph.connectedGraphs()

    def dijkstra(self, startVertex, endVertex):
        self._validator.verifyVertex(self._graph, startVertex)
        self._validator.verifyVertex(self._graph, endVertex)
        return self._graph.dijkstra(startVertex, endVertex)

    def prim(self, startVertex):
        self._validator.verifyVertex(self._graph, startVertex)
        return self._graph.prim(startVertex)

    def solveTSP(self):
        return self._graph.solveTSP()

    def copy(self):
        return self._graph.copy()
