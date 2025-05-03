#include "headers/graph.h"

#include <stdio.h>

void main() {
	Graph graph;

	initFullGraph(&graph, 128, false, false);
	fillGraph(&graph);

	List E = graph.Edges;
	List X = graph.Vertices;

	printf("M = %lu\n", E.capacity);
	deallocGraph(&graph);
}