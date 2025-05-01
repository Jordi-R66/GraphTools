#include "headers/graph.h"

#include <stdio.h>

void main() {
	Graph graph;

	graph.properties = 1;

	printf("DIRECTED : %u\nWEIGHTED : %u\n", IS_DIRECTED(graph), IS_WEIGHTED(graph));
}