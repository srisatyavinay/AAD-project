// Header files to be included
#include <stdio.h>
#include <stdlib.h>

#ifndef __HEADERS_H
#define __HEADERS_H

//typedefs for convinience
typedef struct Node node;
typedef node* ptrnode;
typedef struct Headnode headnode;
typedef headnode* listver;
typedef struct Graph graph;
typedef graph* ptrgraph;

//global variables
int num_ver;

//structure definitions
struct Node {
    int dest;
    int weight;
    ptrnode next;
};

struct Headnode {
    int invalid;
    ptrnode head;
};

struct Graph {
    int num_vertices;
    listver gr;
};

//function declarations
ptrgraph createGraph(int);
void newEdge(ptrgraph, int, int);
void deleteEdge(ptrgraph, int, int);
void newNode(ptrgraph, int);
void deleteNode(ptrgraph, int);
void printGraph(ptrgraph);

#endif
