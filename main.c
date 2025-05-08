#include "headers/graph.h"

#include <stdio.h>

void main() {
	Graph graph;

	initFullGraph(&graph, 8, true, false);
	fillGraph(&graph);

	List E = graph.Edges;

	printf("M = %lu\n", E.capacity);

	deallocGraph(&graph);
}
