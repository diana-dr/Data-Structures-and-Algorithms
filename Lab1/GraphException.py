class GraphException(Exception):
    def __init__(self, msg):
        self._msg = msg

    def msg(self):
        return self._msg
