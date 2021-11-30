#include "headers.h"

ptrminheapnode newMinHeapNode(int ver, int dist)
{
    ptrminheapnode minHeapNode = (ptrminheapnode)malloc(sizeof(minheapnode));
    minHeapNode->ver = ver;
    minHeapNode->dist = dist;
    return minHeapNode;
}

ptrminheap createMinHeap(int capacity)
{
    ptrminheap minHeap = (ptrminheap)malloc(sizeof(minheap));
    minHeap->position = (int *)malloc(capacity * sizeof(int));
    minHeap->size = 0;
    minHeap->capacity = capacity;
    minHeap->array = (ptrminheapnode *)malloc(capacity * sizeof(ptrminheapnode));
    return minHeap;
}

void swapMinHeapNode(ptrminheapnode *a, ptrminheapnode *b)
{
    ptrminheapnode t;
    t = *a;
    *a = *b;
    *b = t;
}

void minHeapify(ptrminheap minHeap, int idx)
{
    int smallest, left, right;
    smallest = idx;
    left = 2 * idx + 1;
    right = 2 * idx + 2;

    if (left < minHeap->size && minHeap->array[left]->dist < minHeap->array[smallest]->dist)
    {
        smallest = left;
    }

    if (right < minHeap->size && minHeap->array[right]->dist < minHeap->array[smallest]->dist)
    {
        smallest = right;
    }

    if (smallest != idx)
    {
        ptrminheapnode smallestNode = minHeap->array[smallest];
        ptrminheapnode idxNode = minHeap->array[idx];

        minHeap->position[smallestNode->ver] = idx;
        minHeap->position[idxNode->ver] = smallest;

        swapMinHeapNode(&minHeap->array[smallest], &minHeap->array[idx]);

        minHeapify(minHeap, smallest);
    }
}

int isHeapEmpty(ptrminheap minHeap)
{
    return minHeap->size == 0;
}

ptrminheapnode extractMin(ptrminheap minHeap)
{
    if (isHeapEmpty(minHeap))
        return NULL;

    ptrminheapnode root = minHeap->array[0];

    ptrminheapnode lastNode = minHeap->array[minHeap->size - 1];
    minHeap->array[0] = lastNode;

    minHeap->position[root->ver] = minHeap->size - 1;
    minHeap->position[lastNode->ver] = 0;

    --minHeap->size;
    minHeapify(minHeap, 0);

    return root;
}

void decreaseKey(ptrminheap minHeap, int v, int dist)
{
    int i = minHeap->position[v];

    minHeap->array[i]->dist = dist;

    while (i && minHeap->array[i]->dist < minHeap->array[(i - 1) / 2]->dist)
    {
        minHeap->position[minHeap->array[i]->ver] = (i - 1) / 2;
        minHeap->position[minHeap->array[(i - 1) / 2]->ver] = i;
        swapMinHeapNode(&minHeap->array[i], &minHeap->array[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

bool isInMinHeap(ptrminheap minHeap, int v)
{
    if (minHeap->position[v] < minHeap->size)
        return true;
    return false;
}