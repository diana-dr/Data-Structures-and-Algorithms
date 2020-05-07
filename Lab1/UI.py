class UI:
    def __init__(self, controller):
        self._ctrl = controller

    def menu(self):
        print("Type: ")
        print("0 - To exit the program ")
        print("1 - To get the number of vertices")
        print("2 - To parse the set of vertices")
        print("3 - To see if there is an edge between 2 vertices")
        print("4 - To get the in degree and out degree of a vertex")
        print("5 - To parse the inbound edges of a vertex")
        print("6 - To parse the outbound edges of a vertex")
        print("7 - To modify the information attached to an edge")
        print("8 - To remove an edge")
        print("9 - To remove a vertex")
        print("10 - To add a vertex")
        print("11 - To add an edge")
        print("12 - To make a copy of the graph")
        print("13 - To see the connected components of this graph")
        print("14 - To see the lowest cost walk between two given vertices")
        print("15 - To see the minimum spanning tree")
        print("16 - To see the solution for the TSP")

    def numberVerticesUI(self):
        print("The number of vertices: " + str(self._ctrl.numberVertices()))

    def parseVerticesUI(self):
        for vert in self._ctrl.vertices():
            print(vert)
        print("\n")

    def verifyEdgeUI(self):
        try:
            vertex1 = int(input("Give first vertex: "))
            vertex2 = int(input("Give second vertex: "))
            if self._ctrl.verifyEdge(vertex1, vertex2):
                print("There is an edge!")
            else:
                print("There is NO edge!")
        except Exception as e:
            print(str(e))

    def inOutDegreeUI(self):
        try:
            vertex = int(input("Enter vertex: "))
            print("In degree: " + str(self._ctrl.degreeIn(vertex)))
            print("Out degree: " + str(self._ctrl.degreeOut(vertex)))
        except Exception as e:
            print(str(e))

    def parseInboundUI(self):
        try:
            vertex = int(input("Enter vertex: "))
            print("Inbound vertices: ")
            for vert in self._ctrl.neighIn(vertex):
                print(str(vert) + " ")
        except Exception as e:
            print(str(e))

    def parseOutboundUI(self):
        try:
            vertex = int(input("Enter vertex: "))
            print("Outbound vertices: ")
            for vert in self._ctrl.neighOut(vertex):
                print(str(vert) + " ")
            print("\n")
        except Exception as e:
            print(str(e))

    def modifyInformationEdgeUI(self):
        try:
            vertex1 = int(input("Enter first vertex: "))
            vertex2 = int(input("Enter second vertex: "))
            newCost = int(input("Enter the new cost of the edge: "))
            self._ctrl.modifyCost(vertex1, vertex2, newCost)
            print(self._ctrl.edges())
        except Exception as e:
            print(str(e))

    def removeEdgeUI(self):
        try:
            vertex1 = int(input("Enter first vertex: "))
            vertex2 = int(input("Enter second vertex: "))
            self._ctrl.removeEdge(vertex1, vertex2)
        except Exception as e:
            print(str(e))

    def removeVertexUI(self):
        try:
            vertex = int(input("Enter vertex: "))
            self._ctrl.removeVertex(vertex)
        except Exception as e:
            print(str(e))

    def addVertexUI(self):
        try:
            vertex = int(input("Enter vertex: "))
            self._ctrl.addVertex(vertex)
        except Exception as e:
            print(str(e))

    def addEdgeUI(self):
        try:
            vertex1 = int(input("Enter first vertex: "))
            vertex2 = int(input("Enter second vertex: "))
            cost = int(input("Enter cost: "))
            self._ctrl.addEdge(vertex1, vertex2, cost)
        except Exception as e:
            print(str(e))

    def makeCopyUI(self):
        return self._ctrl.copy()

    def connectedGraphsUI(self):
        self._ctrl.connectedGraphs()

    def printWalk(self, prev, vertex, startVertex):
        if vertex != startVertex:
            self.printWalk(prev, prev[vertex], startVertex)
        print(vertex)

    def findMinCostWalkUI(self):
        try:
            vertex1 = int(input("Enter first vertex: "))
            vertex2 = int(input("Enter second vertex: "))
            prev, cost = self._ctrl.dijkstra(vertex1, vertex2)
            if cost != 0:
                self.printWalk(prev, vertex2, vertex1)
                print("Cost: " + str(cost))
            else:
                print("No walk between the 2 vertices!")
        except Exception as e:
            print(str(e))

    def printMST(self):
        for vert in self._ctrl.vertices():
            mst, minCost = self._ctrl.prim(vert)
            if len(mst) != self._ctrl.numberVertices() - 1:
                print("No minimum spanning tree can be made!")
            else:
                print("Minimum spanning tree from vertex " + str(vert) + ": ")
                for edge in mst:
                    print(edge)
                print("Minimum cost: " + str(minCost))

    def printTSPsolution(self):
        path, cost = self._ctrl.solveTSP()
        if path != []:
            print("The solution of the TSP is: " + str(path))
            print("Cost: " + str(cost))
        else:
            print("There is no solution for the TSP!")

    def runGraph(self):
        commandDict = {1: self.numberVerticesUI, 2: self.parseVerticesUI, 3: self.verifyEdgeUI, 4: self.inOutDegreeUI, 5: self.parseInboundUI, 6: self.parseOutboundUI, 7: self.modifyInformationEdgeUI, 8: self.removeEdgeUI, 9: self.removeVertexUI, 10: self.addVertexUI, 11: self.addEdgeUI, 12: self.makeCopyUI, 13: self.connectedGraphsUI, 14: self.findMinCostWalkUI, 15: self.printMST, 16: self.printTSPsolution}
        while True:
            self.menu()
            command = int(input("Enter command: "))
            if command == 0:
                return
            else:
                commandDict[command]()
