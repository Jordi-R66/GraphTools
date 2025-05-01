#pragma once

#include "common.h"

typedef struct Vertex {
	size_t VertexUid;
} Vertex;

typedef struct Edge {
	size_t VertexA, VertexB;
} Edge;

typedef struct Graph {
	List Vertices;
	List Edges;

	// From Right to Left
	// Bit 1 : Directed
	// Bit 2 : Weighted
	bool properties : 2;
} Graph;

#define GRAPH_SIZE sizeof(Graph);