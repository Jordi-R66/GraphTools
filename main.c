#include "headers/graph.h"

#include <stdio.h>

void main() {
	Graph graph;

	initFullGraph(&graph, 1024, false, false);
	fillGraph(&graph);

	List E = graph.Edges;

	printf("M = %lu\n", E.capacity);
	char c;

	while (c != 'E') {
		scanf("%c", &c);
	}
	deallocGraph(&graph);
}