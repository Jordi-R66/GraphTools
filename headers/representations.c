#include "representations.h"

Matrix adjacencyMatrix(Graph* graph) {
	SizeT n = graph->Vertices.n_elements;

	Matrix mat;

	mat.rows = n;
	mat.cols = n;

	allocMatrix(&mat);

	for (SizeT e = 0; e < graph->Edges.n_elements; e++) {
		Edge* edge = (Edge*)getElement(&graph->Edges, e);

		Vertex a, b;

		a = *edge->VertexA;
		b = *edge->VertexB;

		SizeT posA = 0, posB = 0;
		bool aDefined = false, bDefined = false;

		for (SizeT v = 0; v < graph->Vertices.n_elements && (!aDefined || !bDefined); v++) {
			Vertex* vertex = (Vertex*)getElement(&graph->Vertices, v);

			if (vertex->VertexUid == a.VertexUid) {
				posA = v;
				aDefined = true;
			}

			if (vertex->VertexUid == b.VertexUid) {
				posB = v;
				bDefined = true;
			}
		}

		printf("posA = %lu | posB = %lu\n", posA, posB);

		value_t valAB = getMatrixCase(&mat, posB, posA);
		value_t valBA = getMatrixCase(&mat, posA, posB);

		printf("posA = %lu | posB = %lu\n", posA, posB);

		setMatrixCase(&mat, valAB + 1, posB, posA);
		setMatrixCase(&mat, valBA + 1, posA, posB);
	}

	return mat;
}