#pragma once

#include "common.h"
#include "graph.h"

typedef enum FileType {
	UNKNOWN = 0,
	CSV = 1,
	TSV = 2
} FileType;

typedef enum {
	A_ID = 0,
	B_ID = 1,
	TYPE = 2
} EdgesFields;

SizeT countLines(string filename);

Graph parseFile(string VerticesFile, string EdgesFile, FileType fileType);
