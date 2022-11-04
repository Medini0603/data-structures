#include <stdio.h>
#include <stdlib.h>

typedef struct node1
{
    int info;
    struct node1 *link;
} node1;

typedef struct node2
{
    node1 *col;
    struct node2 *row;
} node2;

node1 *createnode1(node1 *);
node2 *createnode2(node2 *);