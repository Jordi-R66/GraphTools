#include "headers/graph.h"
#include "headers/graphIO.h"

#include <stdio.h>

void main() {
	Graph graph = parseFile("exemple_s.tsv", "exemple_l.tsv", TSV);

	printf("n = %zu\nm = %zu\n", graph.Vertices.n_elements, graph.Edges.n_elements);
	List degSeq = degreeSequence(&graph);

	printf("|S| = %zu\n", degSeq.n_elements);

	printf("S = (");

	for (SizeT i = 0; i < degSeq.n_elements; i++) {
		printf("%u", *(gorder_t*)getElement(&degSeq, i));

		if (i < (degSeq.n_elements - 1)) {
			printf(",");
		}
	}

	printf(")\n");

	deallocGraph(&graph);
}
