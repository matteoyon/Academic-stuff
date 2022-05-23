#pragma once

#include <stdio.h>
#include <stdlib.h>

typedef int *Heap;

int father(int i);

void heapify_up(Heap h, int i);

void heapify_down(Heap h, int i, int n);

void swap(Heap h, int i, int j);

