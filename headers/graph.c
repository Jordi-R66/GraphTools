#include "graph.h"

typedef struct ReducedEdge {
	Vertex A, B;
} ReducedEdge;

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

	List edges = {.initialized=false};

	initializeList(&edges, graph->Edges.capacity, sizeof(ReducedEdge));

	gsize_t compteur = 0;

	for (gorder_t i=0; i < (gorder_t)graph->Vertices.capacity; i++) {
		Vertex vertexA = {i};

		addElement(&graph->Vertices, &vertexA);

		for (gorder_t j=0; j < (gorder_t)(graph->Vertices.capacity); j++) {
			if (i != j) {
				Vertex vertexB = {j};

				ReducedEdge a = {vertexA, vertexB};
				ReducedEdge b = {vertexB, vertexA};

				bool validAB = !contains(&edges, &a);
				bool validBA = !contains(&edges, &b);

				Vertex *aPtr, *bPtr;

				bool goodToGo = (validAB && validBA) || (validAB && directed);

				if (goodToGo) {
					aPtr = (Vertex*)calloc(1, VERTEX_SIZE);
					bPtr = (Vertex*)calloc(1, VERTEX_SIZE);

					*aPtr = vertexA;
					*bPtr = vertexB;

					Edge edge = {aPtr, bPtr, 1.f, directed};

					addElement(&graph->Edges, &edge);
					addElement(&edges, &a);
					compteur++;
				}
			}
		}
	}

	freeList(&edges);
}

void deallocGraph(Graph* graph) {
	for (SizeT i=0; i < graph->Edges.n_elements; i++) {
		Edge* edgePtr = (Edge*)getElement(&graph->Edges, i);

		free(edgePtr->VertexA);
		free(edgePtr->VertexB);
	}

	freeList(&graph->Edges);
	freeList(&graph->Vertices);
	memset(graph, 0, GRAPH_SIZE);
}

List degreeSequence(Graph* graph) {
	List output;

	initializeList(&output, graph->Vertices.n_elements, sizeof(gorder_t));

	List* edges = &graph->Edges;
	List* vertices = &graph->Vertices;
	Edge* edge;

	for (gorder_t i = 0; i < vertices->n_elements; i++) {
		Vertex* ref = (Vertex*)getElement(vertices, i);

		gorder_t degree = 0;

		for (gsize_t j = 0; j < edges->n_elements; j++) {
			edge = (Edge*)getElement(edges, j);

			bool isA = equalMemory(edge->VertexA, ref, VERTEX_SIZE), isB = equalMemory(edge->VertexB, ref, VERTEX_SIZE);

			if ((isA && !isB) || (!(edge->directed || isA) && isB)) {
				degree++;
			}
		}

		addElement(&output, &degree);
	}

	sortList(&output, NULL);

	return output;
}