#include "headers.h"

ptrq newQueue()
{
    ptrq q = (ptrq)malloc(sizeof(queue));

    q->front = NULL;
    q->rear = NULL;

    return q;
}

ptrqnode newQueueNode(int num)
{
    ptrqnode qn = (ptrqnode)malloc(sizeof(qnode));

    qn->num = num;
    qn->next = NULL;

    return qn;
}

void enqueue(ptrq q, int num)
{
    ptrqnode qn = newQueueNode(num);

    if (q->rear != NULL)
    {
        q->rear->next = qn;
        q->rear = qn;
    }
    else
    {
        q->rear = qn;
        q->front = qn;
    }
}

int dequeue(ptrq q)
{
    if (q->front != NULL)
    {
        int ret = q->front->num;

        ptrqnode temp = q->front;

        q->front = q->front->next;

        if (q->front == NULL)
        {
            q->rear = NULL;
        }

        return ret;
    }
    else
    {
        return -1;
    }
}

int isEmpty(ptrq q)
{
    if (q->rear == NULL)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
