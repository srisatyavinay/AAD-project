#include "headers.h"

void Prims(ptrgraph g)
{
    int V = total_nodes;
    int key[V];
    int parent[V];
 
    ptrminheap minHeap = createMinHeap(V);
 
    for (int v = 1; v < V; ++v) {
        parent[v] = -1;
        key[v] = INT_MAX;
        minHeap->array[v] = newMinHeapNode(v, key[v]);
        minHeap->position[v] = v;
    }
 
    key[0] = 0;
    minHeap->array[0] = newMinHeapNode(0, key[0]);
    minHeap->position[0] = 0;
 
    minHeap->size = V;
 
    while (!isHeapEmpty(minHeap)) {

        ptrminheapnode minHeapNode = extractMin(minHeap);
        int u = minHeapNode->ver;
 
        ptrnode pCrawl = g->gr[u].head;
        while (pCrawl != NULL) {
            int v = pCrawl->dest;

            if (isInMinHeap(minHeap, v) && pCrawl->weight < key[v]) {
                key[v] = pCrawl->weight;
                parent[v] = u;
                decreaseKey(minHeap, v, key[v]);
            }

            pCrawl = pCrawl->next;
        }
    }

    printPrimArr(parent, V);
}

void printPrimArr(int arr[], int n)
{
    for (int i = 1; i < n; ++i)
        printf("%d - %d\n", arr[i], i);
}