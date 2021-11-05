#include "headers.h"

ptrgraph createGraph(int num)
{
    ptrgraph g = (ptrgraph)malloc(sizeof(graph));

    g->num_vertices = num;

    g->gr = (listver)malloc(num * sizeof(headnode));

    for (int i = 0; i < num; i++) {
        g->gr[i].id = i;
        g->gr[i].head = NULL;
    }

    return g;
}

void newEdge(ptrgraph g, int src, int dest, int weight)
{
    int foundsrc = 0, founddest = 1;
    for(int i = 0; i < g->num_vertices; i++) {
        if (g->gr[i].id == src) {
            foundsrc = 1;
            break;
        }
    }
    for(int i = 0; i < g->num_vertices; i++) {
        if (g->gr[i].id == dest) {
            founddest = 1;
            break;
        }
    }

    if (foundsrc == 0 || founddest == 0) {
        printf("Enter valid vertex numbers\n");
        return;
    }

    if (g->gr[src].head == NULL) {
        g->gr[src].head = newNode(dest, weight);
    }
    else {
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
    int foundsrc = 0, founddest = 1;
    for(int i = 0; i < g->num_vertices; i++) {
        if (g->gr[i].id == src) {
            foundsrc = 1;
            break;
        }
    }
    for(int i = 0; i < g->num_vertices; i++) {
        if (g->gr[i].id == dest) {
            founddest = 1;
            break;
        }
    }

    if (foundsrc == 0 || founddest == 0) {
        printf("Enter valid vertex numbers\n");
        return;
    }

    ptrnode curr = g->gr[src].head, prev = NULL;

    while(curr != NULL && curr->dest != dest) {
        prev = curr;
        curr = curr->next;
    }

    if(curr == NULL) {
        printf("There is no edge from %d to %d. Please try again\n", src, dest);
        return;
    }

    if(prev != NULL) {
        prev->next = curr->next;
        free(curr);
    }
    else {
        g->gr[src].head = NULL;
        free(curr);
    }
    return;
}

void printGraph(ptrgraph g)
{
    for (int i = 0; i < g->num_vertices; i++) {
        printf("%d: ", g->gr[i].id);

        ptrnode n = g->gr[i].head;

        while(n != NULL) {
            printf("%d (%d) ", n->dest, n->weight);
            n = n->next;
        }

        printf("\n");
    }
}

void newVertex(ptrgraph g, int num)
{
    int foundver = 0;
    for(int i = 0; i < g->num_vertices; i++) {
        if (g->gr[i].id == num) {
            foundver = 1;
            break;
        }
    }

    if(foundver == 1 || num < 0) {
        printf("This vertex ID already exists or you entered an invalid number. Please try again\n");
        return;
    }

    g->num_vertices++;

    realloc(g->gr, g->num_vertices * sizeof(headnode));

    g->gr[g->num_vertices - 1].id = num;
    g->gr[g->num_vertices - 1].head = NULL;
}

void deleteVertex(ptrgraph g, int num)
{
    
}
