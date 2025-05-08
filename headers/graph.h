#pragma once

#include "common.h"

#ifdef __32_BITS__
	#define VERTEX_TYPE uint16
	#define ORDER_TYPE uint16
	#define SIZE_TYPE uint32

	#define EDGE_DIR_LIMIT 477182180
	#define VERTEX_DIR_LIMIT 21845
	#define EDGE_UNDIR_LIMIT 477204171
	#define VERTEX_UNDIR_LIMIT 30894
#elif defined(__64_BITS__)
	#define VERTEX_TYPE uint32
	#define ORDER_TYPE uint32
	#define SIZE_TYPE uint64

	#define EDGE_DIR_LIMIT 1418980312323369600
	#define VERTEX_DIR_LIMIT 1191209601
	#define EDGE_UNDIR_LIMIT 1418980312060338378
	#define VERTEX_UNDIR_LIMIT 1684624773
#endif

typedef VERTEX_TYPE vertexId_t;
typedef ORDER_TYPE gorder_t;
typedef SIZE_TYPE gsize_t;

#pragma pack(1)
typedef struct Vertex {
	vertexId_t VertexUid;
} Vertex;

typedef struct Edge {
	Vertex* VertexA;
	Vertex* VertexB;
	float weight;
	bool directed;
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
	uint8 properties : 2;
} Graph;
#pragma pack()

#define DIRECTED_BIT 1
#define WEIGHTED_BIT 2

#define GRAPH_SIZE sizeof(Graph)
#define VERTEX_SIZE sizeof(Vertex)
#define EDGE_SIZE sizeof(Edge)

#define MAX_DIRECTED_EDGES(Vertices) (gsize_t)((gsize_t)Vertices * ((gsize_t)Vertices - 1))
#define MAX_UNDIRECTED_EDGES(Vertices) (MAX_DIRECTED_EDGES(Vertices) >> 1)

#define IS_DIRECTED(graph) GET_BIT(graph->properties, DIRECTED_BIT)
#define IS_WEIGHTED(graph) GET_BIT(graph->properties, WEIGHTED_BIT)

void initGraph(Graph* graph);
void initVertices(Graph* graph, gorder_t maxOrder);
void initEdges(Graph* graph, gsize_t maxSize);
void initFullGraph(Graph* graph, gorder_t order, bool directed, bool weighted);
void fillGraph(Graph* graph);
void deallocGraph(Graph* graph);

List degreeSequence(Graph* graph);