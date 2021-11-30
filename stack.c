#include "headers.h"

ptrstack newStack()
{
    ptrstack s = (ptrstack)malloc(sizeof(stack));

    s->front = NULL;

    return s;
}

ptrstacknode newStackNode(int num)
{
    ptrstacknode sn = (ptrstacknode)malloc(sizeof(stacknode));

    sn->next = NULL;
    sn->val = num;

    return sn;
}

void push(ptrstack s, int num)
{
    ptrstacknode sn = newStackNode(num);

    if(s->front == NULL)
    {
        s->front = sn;
    }
    else
    {
        sn->next = s->front;
        s->front = sn;
    }
}

int pop(ptrstack s)
{
    if(s->front == NULL)
    {
        return -1;
    }
    else
    {
        int a = s->front->val;
        ptrstacknode now = s->front;
        s->front = s->front->next;
        free(now);
        return a;
    }
}

int isEmptyStack(ptrstack s)
{
    if(s->front == NULL)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
