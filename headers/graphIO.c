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
