#include "headers.h"

void dfs(ptrgraph g, int start, int *arr)
{
    arr[start] = 1;

    printf("%d ", start);

    ptrnode x = g->gr[start].head;

    while (x != NULL)
    {
        if (arr[x->dest] != 1)
        {
            dfs(g, x->dest, arr);
        }

        x = x->next;
    }
}

void dfs_init(ptrgraph g)
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
            dfs(g, i, newarr);
        }
    }

    printf("\n");
}

void dfs_init2(ptrgraph g, int src)
{
    int newarr[total_nodes];

    for (int i = 0; i < total_nodes; i++)
    {
        newarr[i] = 0;
    }

    if (src < total_nodes && src >= 0 && g->gr[src].status != -1)
    {
        dfs(g, src, newarr);
    }
    else
    {
        printf("This vertex does not exists or it is deleted. Please try again\n");
    }

    printf("\n");
}
