#pragma once

#include "common.h"

typedef struct Graph {
	List Vertices;
	List Edges;
} Graph;

#define GRAPH_SIZE sizeof(Graph);