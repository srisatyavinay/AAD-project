#include "headers.h"

void bellman_ford(ptrgraph g, int src)
{
    int distance[total_nodes];

    for(int i = 0; i < total_nodes; i++)
    {
        distance[i] = INT_MAX;
    }

    distance[src] = 0;

    for(int i = 0; i < total_nodes - 1; i++)
    {
        for(int j = 0; j < total_nodes; j++)
        {
            ptrnode x = g->gr[j].head;

            while(distance[j] != INT_MAX && x != NULL)
            {
                int y = x->dest;
                if(distance[j] + x->weight < distance[y])
                {
                    distance[y] = distance[j] + x->weight;
                }
                x = x->next;
            }
        }
    }

    for(int j = 0; j < total_nodes; j++)
    {
        ptrnode x = g->gr[j].head;

        while(distance[j] != INT_MAX && x != NULL)
        {
            int y = x->dest;
            if(distance[j] + x->weight < distance[y])
            {
                printf("Graph has a negative cycle\n");
                return;
            }
            x = x->next;
        }
    }

    for(int i = 0; i < total_nodes; i++)
    {
        printf("%d \t\t %d\n", i, distance[i]);
    }
}
