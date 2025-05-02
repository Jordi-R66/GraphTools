#include "graph.h"

void initGraph(Graph* graph) {
	memset(graph, 0, GRAPH_SIZE);
}

void initVertices(Graph* graph, gorder_t maxOrder) {
	initializeList(&graph->Vertices, maxOrder, VERTEX_SIZE);
}

void initEdges(Graph* graph, gsize_t maxSize) {
	initializeList(&graph->Edges, maxSize, EDGE_SIZE);
}

void initFullGraph(Graph* graph, gorder_t order, bool directed, bool weighted) {
	initGraph(graph);

	gsize_t graphSize = directed ? MAX_DIRECTED_EDGES(order) : MAX_UNDIRECTED_EDGES(order);

	initVertices(graph, order);
	initEdges(graph, graphSize);

	graph->properties = (directed) + (weighted << (WEIGHTED_BIT - 1));
}

void fillGraph(Graph* graph) {
	bool directed = IS_DIRECTED(graph);

	for (gorder_t i=0; i < graph->Edges.capacity; i++) {
		Vertex vertexA = {i};
		for (gorder_t j=0; j < graph->Edges.capacity; j++) {
			if (i != j) {
				Vertex vertexB = {j};

				Edge edge = {i, j, 1.f, directed};

				addElement(&graph->Edges, &edge);
			}
		}
	}
}