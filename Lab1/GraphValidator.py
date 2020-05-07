from GraphException import GraphException


class GraphValidator:

    def verifyEdge(self, g, vertex1, vertex2):
        if not g.verifyEdge(vertex1, vertex2):
            raise GraphException("There is no edge between " + str(vertex1) + " and " + str(vertex2))

    def verifyInteger(self, number):
        if type(number) != int:
            raise GraphException("All data must be an integer! ")

    def verifyAlreadyEdge(self, g, vertex1, vertex2):
        if g.verifyEdge(vertex1, vertex2):
            raise GraphException("There is already an edge between " + str(vertex1) + " and " + str(vertex2))

    def verifyVertex(self, g, vertex):
        if vertex not in g.vertices:
            raise GraphException("The vertex does not exist in the graph!")

    def verifyAlreadyVertex(self, g, vertex):
        if vertex in g.vertices:
            raise GraphException("The vertex already exists in the graph!")
