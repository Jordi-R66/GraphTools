#pragma once

#include "graph.h"

#define OVERRIDE_MATRIX_VALUE_TYPE
#define VALUE_TYPE gorder_t

#include "../libs/myOwnCLib/matrices/matrix.h"

Matrix adjacencyMatrix(Graph* graph);