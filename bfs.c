#include "headers.h"

void bfs_init(ptrgraph g)
{
    int newarr[total_nodes];

    for (int i = 0; i < total_nodes; i++)
    {
        newarr[i] = 0;
    }

    for (int i = 0; i < total_nodes; i++)
    {
        if (g->gr[i].status != -1 && newarr[i] != 1)
        {
            bfs(g, i, newarr);
        }
    }

    printf("\n");
}

void bfs_init2(ptrgraph g, int src)
{
    int newarr[total_nodes];

    for (int i = 0; i < total_nodes; i++)
    {
        newarr[i] = 0;
    }

    if (src < total_nodes && src >= 0 && g->gr[src].status != -1)
    {
        bfs(g, src, newarr);
    }
    else
    {
        printf("This vertex does not exists or it is deleted. Please try again\n");
    }

    printf("\n");
}

void bfs(ptrgraph g, int start, int *arr)
{
    // printf("%d ", start);

    ptrq q = newQueue();

    enqueue(q, start);

    arr[start] = 2;

    while (!isEmpty(q))
    {
        int st = dequeue(q);

        arr[st] = 1;

        printf("%d ", st);

        ptrnode x = g->gr[st].head;

        while (x != NULL)
        {
            if (arr[x->dest] == 0)
            {
                enqueue(q, x->dest);
                arr[x->dest] = 2;
            }
            x = x->next;
        }
    }
}
