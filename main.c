#include "headers/graph.h"

#include <stdio.h>

void main() {
	Graph graph;

	initFullGraph(&graph, 128, true, false);
	fillGraph(&graph);

	List degSeq = degreeSequence(&graph);

	for (SizeT i = 0; i < degSeq.n_elements; i++) {
		printf("%u\n", *(gorder_t*)getElement(&degSeq, i));
	}

	deallocGraph(&graph);
}
