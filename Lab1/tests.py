import unittest
from DirectedGraph import DirectedGraph


class testGraph(unittest.TestCase):
    def setUp(self):
        self._g = DirectedGraph(5, 7)

    def testCreate(self):
        self._g.addVertex(1)
        self._g.addEdge([1, 2])
        #self._g.addEdgesAndCost([1, 2], 3)
        self.assertEqual([1], self._g.vertices)
        self.assertEqual([[1, 2]], self._g.edges)
        #self.assertEqual({[1, 2]: 3}, self._g.costDict)
