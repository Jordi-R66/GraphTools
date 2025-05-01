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

	/** @brief Set of booleans describing some properties
	 * From Rightmost bit to Leftmost
	 * 
	 * Bit 1 : Directed
	 * 
	 * Bit 2 : Weighted
	 */
	bool properties : 2;
} Graph;

#define DIRECTED_BIT 1
#define WEIGHTED_BIT 2

#define GRAPH_SIZE sizeof(Graph);
#define IS_DIRECTED(graph) ((graph.properties << (BOOL_BITS - DIRECTED_BIT)) >> (BOOL_BITS - 1))
#define IS_WEIGHTED(graph) ((graph.properties << (BOOL_BITS - WEIGHTED_BIT)) >> (BOOL_BITS - 1))