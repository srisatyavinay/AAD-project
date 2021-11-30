// Header files to be included
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <stdbool.h>

#ifndef __HEADERS_H
#define __HEADERS_H

//typedefs for convinience
typedef struct Node node;
typedef node *ptrnode;
typedef struct Headnode headnode;
typedef headnode *listver;
typedef struct Graph graph;
typedef graph *ptrgraph;

typedef struct Queue queue;
typedef queue *ptrq;
typedef struct Queuenode qnode;
typedef qnode *ptrqnode;

typedef struct MinHeapNode minheapnode;
typedef minheapnode* ptrminheapnode;
typedef struct MinHeap minheap;
typedef minheap* ptrminheap;

typedef struct Stack stack;
typedef stack* ptrstack;
typedef struct Stacknode stacknode;
typedef stacknode* ptrstacknode;

//global variables
int total_nodes;

//graph datastructure structure definitions

struct Node
{
    int dest;
    int weight;
    ptrnode next;
};

struct Headnode
{
    // int invalid;
    int id;
    int status; //0->normal, -1->deleted
    ptrnode head;
};

struct Graph
{
    int num_vertices;
    listver gr;
};

//queue datastructure structure definitions

struct Queuenode
{
    int num;
    ptrqnode next;
};

struct Queue
{
    ptrqnode front, rear;
};

//stack datastructure strcuture defintions

struct Stack
{
    ptrstacknode front;
};

struct Stacknode
{
    int val;
    ptrstacknode next;
};

//minheap datastructure defintions
struct MinHeapNode
{
    int ver;
    int dist;
};

struct MinHeap
{
    int size;
    int capacity;
    int *position;
    ptrminheapnode* array;
};

//graph function declarations
ptrgraph createGraph(int);
void newEdge(ptrgraph, int, int, int);
void deleteEdge(ptrgraph, int, int);
void deleteEdge2(ptrgraph, int, int);
ptrnode newNode(int, int);
void newVertex(ptrgraph, int);
void deleteVertex(ptrgraph, int);
void printGraph(ptrgraph);
void exitFunction(ptrgraph g);

//dfs function declarations
void dfs(ptrgraph, int, int *);
void dfs_init(ptrgraph);
void dfs_init2(ptrgraph, int);

//bfs function declarations
void bfs(ptrgraph, int, int *);
void bfs_init(ptrgraph);
void bfs_init2(ptrgraph, int);

//queue function declarations
ptrq newQueue();
ptrqnode newQueueNode(int);
void enqueue(ptrq, int);
int dequeue(ptrq);
int isEmpty(ptrq q);

//stack function declarations
ptrstack newStack();
ptrstacknode newStackNode(int);
void push(ptrstack, int);
int pop(ptrstack);
int isEmptyStack(ptrstack);

//minheap function declarations
ptrminheapnode newMinHeapNode(int, int);
ptrminheap createMinHeap(int);
void swapMinHeapNode(ptrminheapnode*, ptrminheapnode*);
void minHeapify(ptrminheap, int);
int isHeapEmpty(ptrminheap);
ptrminheapnode extractMin(ptrminheap);
void decreaseKey(ptrminheap, int, int);
bool isInMinHeap(ptrminheap, int);

//dijkstra function declarations
void printArr(ptrgraph, int dist[], int);
void dijkstra(ptrgraph, int);

//bellaman ford function declarations
void bellman_ford(ptrgraph, int);

//prim's algorithm
void Prims(ptrgraph);
void printPrimArr(int arr[], int);

//topological sort function declarations
void topological_sort(ptrgraph, int, int *, ptrstack s);
void topological_sort_init(ptrgraph);

#endif
