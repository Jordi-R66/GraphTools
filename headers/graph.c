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

		for (gorder_t j=i+1; j < (gorder_t)(graph->Vertices.capacity); j++) {
			if (i != j) {
				Vertex vertexB = {j};

				ReducedEdge a = {vertexA, vertexB};
				ReducedEdge b = {vertexB, vertexA};

				bool validAB = !contains(&edges, &a);
				bool validBA = !contains(&edges, &b);

				bool goodToGo = (validAB && validBA) || (validAB && directed);

				printf("i = %u | j = %u | %s\n", a.A.VertexUid, a.B.VertexUid, goodToGo ? "True" : "False");
				//printf("(validAB && validBA) || (validAB && directed) = ( %u && %u) || ( %u && %u) = %u\n\n", validAB, validBA, validAB, directed, goodToGo);

				if (goodToGo) {
					Edge edge = {vertexA, vertexB, 1.f, directed};

					addElement(&graph->Edges, &edge);
					addElement(&edges, &a);
					compteur++;
					//printf("Compteur : %lu\n", compteur);
				}
			}
		}
	}

	FILE* fp = fopen("dumpEdges.hex", "w");
	fwrite(graph->Vertices.elements, graph->Vertices.elementSize, graph->Vertices.capacity, fp);
	fwrite(edges.elements, edges.elementSize, edges.capacity, fp);
	fclose(fp);

	freeList(&edges);
}

void deallocGraph(Graph* graph) {
	freeList(&graph->Edges);
	freeList(&graph->Vertices);
	memset(graph, 0, GRAPH_SIZE);
}
