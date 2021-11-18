#include "headers.h"

ptrgraph createGraph(int num)
{
    ptrgraph g = (ptrgraph)malloc(sizeof(graph));

    g->num_vertices = num;

    g->gr = (listver)malloc(num * sizeof(headnode));

    for (int i = 0; i < num; i++)
    {
        g->gr[i].id = i;
        g->gr[i].status = 0;
        g->gr[i].head = NULL;
    }

    return g;
}

void newEdge(ptrgraph g, int src, int dest, int weight)
{
    if(src < 0 || dest < 0)
    {
        printf("Enter valid vertex ID\n");
        return;
    }
    int foundsrc = 0, founddest = 0;
    // for(int i = 0; i < total_nodes; i++)
    // {
    //     if (g->gr[i].id == src && g->gr[i].status != -1)
    //     {
    //         foundsrc = 1;
    //         break;
    //     }
    // }
    // for(int i = 0; i < total_nodes; i++)
    // {
    //     if (g->gr[i].id == dest)
    //     {
    //         founddest = 1;
    //         break;
    //     }
    // }

    // printf("======%d %d %d=============", src, dest, total_nodes);

    if(src < total_nodes && g->gr[src].status != -1)
    {
        foundsrc = 1;
    }
    if(dest < total_nodes && g->gr[dest].status != -1)
    {
        founddest = 1;
    }

    if (foundsrc == 0 || founddest == 0)
    {
        printf("Enter valid vertex numbers\n");
        return;
    }

    if (g->gr[src].head == NULL)
    {
        g->gr[src].head = newNode(dest, weight);
    }
    else
    {
        ptrnode n = newNode(dest, weight);
        n->next = g->gr[src].head;
        g->gr[src].head = n;
    }
    return;
}

ptrnode newNode(int dest, int weight)
{
    ptrnode n = (ptrnode)malloc(sizeof(node));

    n->dest = dest;
    n->weight = weight;
    n->next = NULL;
    
    return n;
}

void deleteEdge(ptrgraph g, int src, int dest)
{
    if(src < 0 || dest < 0)
    {
        printf("Enter valid vertex ID\n");
        return;
    }
    int foundsrc = 0, founddest = 0;
    // for(int i = 0; i < g->num_vertices; i++)
    // {
    //     if (g->gr[i].id == src)
    //     {
    //         foundsrc = 1;
    //         break;
    //     }
    // }
    // for(int i = 0; i < g->num_vertices; i++)
    // {
    //     if (g->gr[i].id == dest)
    //     {
    //         founddest = 1;
    //         break;
    //     }
    // }

    if(src < total_nodes && g->gr[src].status != -1)
    {
        foundsrc = 1;
    }
    if(dest < total_nodes && g->gr[dest].status != -1)
    {
        founddest = 1;
    }

    if (foundsrc == 0 || founddest == 0)
    {
        printf("Enter valid vertex numbers\n");
        return;
    }

    ptrnode curr = g->gr[src].head, prev = NULL;

    while(curr != NULL && curr->dest != dest)
    {
        prev = curr;
        curr = curr->next;
    }

    if(curr == NULL)
    {
        printf("There is no edge from %d to %d. Please try again\n", src, dest);
        return;
    }

    if(prev != NULL)
    {
        prev->next = curr->next;
        free(curr);
    }
    else
    {
        g->gr[src].head = NULL;
        free(curr);
    }
    return;
}

void deleteEdge2(ptrgraph g, int src, int dest)
{
    // if(src < 0 || dest < 0)
    // {
    //     printf("Enter valid vertex ID\n");
    //     return;
    // }
    int foundsrc = 0, founddest = 0;
    // for(int i = 0; i < g->num_vertices; i++)
    // {
    //     if (g->gr[i].id == src)
    //     {
    //         foundsrc = 1;
    //         break;
    //     }
    // }
    // for(int i = 0; i < g->num_vertices; i++)
    // {
    //     if (g->gr[i].id == dest)
    //     {
    //         founddest = 1;
    //         break;
    //     }
    // }

    if(src < total_nodes && g->gr[src].status != -1)
    {
        foundsrc = 1;
    }
    if(dest < total_nodes && g->gr[dest].status != -1)
    {
        founddest = 1;
    }

    if (foundsrc == 0 || founddest == 0)
    {
        // printf("Enter valid vertex numbers\n");
        return;
    }

    ptrnode curr = g->gr[src].head, prev = NULL;

    while(curr != NULL && curr->dest != dest)
    {
        prev = curr;
        curr = curr->next;
    }

    if(curr == NULL)
    {
        // printf("There is no edge from %d to %d. Please try again\n", src, dest);
        return;
    }

    if(prev != NULL)
    {
        prev->next = curr->next;
        free(curr);
    }
    else
    {
        g->gr[src].head = NULL;
        free(curr);
    }
    return;
}

void printGraph(ptrgraph g)
{
    for (int i = 0; i < total_nodes; i++)
    {
        if(g->gr[i].status != -1)
        {
            printf("%d: ", g->gr[i].id);

            ptrnode n = g->gr[i].head;

            while(n != NULL)
            {
                printf("%d (%d) ", n->dest, n->weight);
                n = n->next;
            }

            printf("\n");
        }
    }
}

void newVertex(ptrgraph g, int num)
{
    if(num < 0)
    {
        printf("Enter valid vertex ID\n");
        return;
    }

    int foundver = 0;

    if(num < total_nodes && g->gr[num].status != -1)
    {
        foundver = 1;
    }

    if(foundver == 1)
    {
        printf("This vertex ID already exists or you entered an invalid number. Please try again\n");
        return;
    }

    total_nodes++;

    g->num_vertices++;

    g->gr = realloc(g->gr, total_nodes * sizeof(headnode));

    g->gr[total_nodes - 1].id = num;
    g->gr[total_nodes - 1].status = 0;
    g->gr[total_nodes - 1].head = NULL;

}

void deleteVertex(ptrgraph g, int num)
{
    if(num < 0 || num >= total_nodes)
    {
        printf("Enter valid vertex ID\n");
        return;
    }

    if(g->gr[num].status != -1)
    {
        g->num_vertices--;

        ptrnode prev = NULL, curr = g->gr[num].head;
        
        if(g->gr[num].head != NULL)
        {
            while(curr != NULL)
            {
                prev = curr;
                curr = curr->next;
                free(prev);
            }
        }

        for(int i = 0; i < total_nodes; i++)
        {
            if(g->gr[i].status != -1)
            {
                deleteEdge2(g, i, num);
            }
        }

        g->gr[num].status = -1;
    }
    else
    {
        printf("This vertex has already been deleted before\n");
        return;
    }
}
