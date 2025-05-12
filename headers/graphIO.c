#include "graphIO.h"

const char* READONLY_MODE = "r";

SizeT countLines(string filename) {
	FILE* fp = fopen(filename, READONLY_MODE);
	SizeT nEntries = 0;

	char c = 0;

	while (c != EOF) {
		c = fgetc(fp);

		if (c == '\n') {
			nEntries++;
		}
	}

	fclose(fp);

	return nEntries;
}

void LoadVerticesFromTSV(string filename, Graph* graph, FileType fileType) {
	char* endptr;

	char buffer[128];

	memset(buffer, 0, 128);

	size_t n_entries = countLines(filename);

	if (n_entries == 0) {
		return;
	}

	FILE* fp = fopen(filename, READONLY_MODE);

	initVertices(graph, (gorder_t)n_entries);

	uint8_t colNumber = 0;
	vertexId_t currentEntry = 0;

	vertexId_t id;
	Vertex Sommet;

	char c = 0;
	uint8_t currentField = 0;
	uint8_t fieldLength = 0;

	const char field_sep = fileType == CSV ? ',' : '\t';
	bool canLoad = false;

	while (c != EOF) {
		c = fgetc(fp);

		if (c == EOF) {
			break;
		}

		if ((c != field_sep) && (c != '\n')) {
			buffer[fieldLength++] = c;
		} else {

			switch (currentField) {
				case 0:
					id = strtoul(buffer, &endptr, 10);

					Sommet = (Vertex){id};
					canLoad = true;
					break;

				default:
					break;
			}

			if (canLoad) {
				addElement(&graph->Vertices, &Sommet);
				canLoad = false;
			}

			memset(buffer, 0, 128);
			fieldLength = 0;

			if (c == '\n') {
				currentField = 0;
				currentEntry++;
			} else {
				currentField++;
			}
		}
	}

	fclose(fp);

	shrinkToFit(&graph->Vertices);
}
