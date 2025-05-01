#!/bin/bash
clear
COMPILER="gcc"

SOURCES="main.c libs/myOwnCLib/lists/list.c libs/myOwnCLib/bits/bits.c headers/*.c"

OUTPUT_DIR="output"

mkdir $OUTPUT_DIR

EXEC="GraphTools.elf"

ARGS="-Wall -s -S -O0 -std=gnu17 -m64"
#ARGS="-Wall -Wno-unused-variable -O3 -std=c17 -m64 -march=x86-64 -flto"

echo $COMPILER $ARGS $SOURCES #-o $OUTPUT_DIR/$EXEC