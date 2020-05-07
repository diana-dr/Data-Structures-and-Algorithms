#Me - 6
from DirectedGraph import DirectedGraph
from GraphValidator import GraphValidator
from Controller import Controller
from UI import UI

graph = DirectedGraph()
validator = GraphValidator()
ctrl = Controller(graph, validator)
ui = UI(ctrl)

ui.runGraph()
#9 + 2, 9, 3*10