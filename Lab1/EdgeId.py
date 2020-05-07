class EdgeId:
    def __init__(self, id, edge, cost):
        self._id = id
        self._edge = edge
        self._cost = cost

    @property
    def id(self):
        return self._id

    @property
    def edge(self):
        return self._edge

    @property
    def cost(self):
        return self._cost
