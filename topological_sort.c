#include "headers.h"

void topological_sort(ptrgraph g, int start, int *arr, ptrstack s)
{
    arr[start] = 1;

    // printf("%d ", start);

    ptrnode x = g->gr[start].head;

    while (x != NULL)
    {
        if (arr[x->dest] != 1)
        {
            topological_sort(g, x->dest, arr, s);
        }

        x = x->next;
    }

    push(s, start);
}

void topological_sort_init(ptrgraph g)
{
    int newarr[total_nodes];

    ptrstack s = newStack();

    for (int i = 0; i < total_nodes; i++)
    {
        newarr[i] = 0;
    }

    for (int i = 0; i < total_nodes; i++)
    {
        if (g->gr[i].status != -1 && newarr[i] != 1)
        {
            topological_sort(g, i, newarr, s);
        }
    }

    while(!isEmptyStack(s))
    {
        printf("%d ", pop(s));
    }

    printf("\n");
}
