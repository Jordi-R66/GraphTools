#include "graph.h"

void initGraph(Graph* graph) {
	memset(graph, 0, GRAPH_SIZE);
}

void initVertices(Graph* graph, gsize_t maxOrder) {
	initializeList(&graph->Vertices, maxOrder, VERTEX_SIZE);
}