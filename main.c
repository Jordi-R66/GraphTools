#include "headers/graph.h"

#include <stdio.h>

void main() {
	Graph graph = {.properties = 3};

	printf("DIRECTED : %u\nWEIGHTED : %u\n", IS_DIRECTED(graph), IS_WEIGHTED(graph));
}