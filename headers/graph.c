#include "graph.h"

Graph createGraph() {
	Graph graph;

	memset(&graph, 0, GRAPH_SIZE);

	initializeList(&graph.Vertices, 10, VERTEX_SIZE);
	initializeList(&graph.Edges, 0, EDGE_SIZE);
}