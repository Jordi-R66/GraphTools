#include "headers/graph.h"

#include <stdio.h>

void main() {
	Graph graph;

	initFullGraph(&graph, 5, false, false);

	List E = graph.Edges;
	List X = graph.Vertices;

	printf("M = %lu\n", E.capacity);
	fillGraph(&graph);

	printf("n = %lu\nm = %lu\n", X.n_elements, E.n_elements);
	deallocGraph(&graph);
}