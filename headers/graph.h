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
	uint8_t properties : 2;
} Graph;

#define DIRECTED_BIT 1
#define WEIGHTED_BIT 2

#define GRAPH_SIZE sizeof(Graph);
#define IS_DIRECTED(graph) GET_BIT(graph.properties, DIRECTED_BIT, 8)
#define IS_WEIGHTED(graph) GET_BIT(graph.properties, WEIGHTED_BIT, 8)
