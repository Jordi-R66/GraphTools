#!/bin/bash
clear
COMPILER="gcc"

SOURCES="main.c libs/myOwnCLib/memory/*.c libs/myOwnCLib/lists/list.c libs/myOwnCLib/endianness/endianness.c headers/*.c"

OUTPUT_DIR="output"

mkdir $OUTPUT_DIR

EXEC="GraphTools.elf"

ARGS="-Wall -masm=intel -Wno-main -s -O3 -std=gnu17 -m64"
#ARGS="-Wall -Wno-unused-variable -O3 -std=c17 -m64 -march=x86-64 -flto"

$COMPILER $ARGS $SOURCES -o $OUTPUT_DIR/$EXEC