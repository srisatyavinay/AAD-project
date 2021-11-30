#include "headers.h"

void printArr(ptrgraph g, int dist[], int n)
{
    // printf("Vertex Distance from Source\n");
    for (int i = 0; i < n; ++i)
    {
        if(g->gr[i].status != -1)
        {
            printf("%d \t\t %d\n", i, dist[i]);
        }
    }
}

void dijkstra(ptrgraph g, int src)
{
    int V = total_nodes;

    int dist[V];

    ptrminheap minHeap = createMinHeap(V);

    // Initialize min heap with all
    // vertices. dist value of all vertices
    for (int v = 0; v < V; ++v)
    {
        if (g->gr[v].status != -1)
        {
            dist[v] = INT_MAX;
            minHeap->array[v] = newMinHeapNode(v, dist[v]);
            minHeap->position[v] = v;
        }
    }

    minHeap->array[src] = newMinHeapNode(src, dist[src]);
    minHeap->position[src] = src;
    dist[src] = 0;
    decreaseKey(minHeap, src, dist[src]);

    minHeap->size = g->num_vertices;

    while (!isHeapEmpty(minHeap))
    {
        ptrminheapnode minHeapNode = extractMin(minHeap);

        int u = minHeapNode->ver;

        ptrnode pCrawl = g->gr[u].head;
        while (pCrawl != NULL)
        {
            int v = pCrawl->dest;

            if (isInMinHeap(minHeap, v) && dist[u] != INT_MAX && pCrawl->weight + dist[u] < dist[v])
            {
                dist[v] = dist[u] + pCrawl->weight;

                decreaseKey(minHeap, v, dist[v]);
            }
            pCrawl = pCrawl->next;
        }
    }

    printArr(g, dist, V);
}
