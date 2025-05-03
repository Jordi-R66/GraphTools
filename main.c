#include "headers/graph.h"

#include <stdio.h>

void main() {
	Graph graph;

	initFullGraph(&graph, 5, false, false);
	fillGraph(&graph);

	List E = graph.Edges;

	printf("M = %lu\n", E.capacity);
	deallocGraph(&graph);
}