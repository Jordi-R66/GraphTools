#pragma once

#include "common.h"

#ifdef __32_BITS__
	#define VERTEX_TYPE uint16_t
	#define ORDER_TYPE uint16_t
	#define SIZE_TYPE uint32_t
#elif defined(__64_BITS__)
	#define VERTEX_TYPE uint32_t
	#define ORDER_TYPE uint32_t
	#define SIZE_TYPE uint64_t
#endif

typedef VERTEX_TYPE vertexId_t;
typedef ORDER_TYPE gorder_t;
typedef SIZE_TYPE gsize_t;

typedef struct Vertex {
	vertexId_t VertexUid;
} Vertex;

typedef struct Edge {
	vertexId_t VertexA, VertexB;
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

#define GRAPH_SIZE sizeof(Graph)
#define VERTEX_SIZE sizeof(Vertex)
#define EDGE_SIZE sizeof(Edge)

#define MAX_DIRECTED_EDGES(Vertices) (Vertices * (Vertices - 1))
#define MAX_UNDIRECTED_EDGES(Vertices) (MAX_DIRECTED_EDGES(Verices) >> 1)

#define IS_DIRECTED(graph) GET_BIT(graph.properties, DIRECTED_BIT)
#define IS_WEIGHTED(graph) GET_BIT(graph.properties, WEIGHTED_BIT)

void initGraph(Graph* graph);