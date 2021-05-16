#pragma once
#ifndef FUNTION
#define QUEUE_VALUE_TYPE binary_tree
#define BTTREE_VALUE_TYPE int
#define QUEUE_NODE_INDEX_VALUE 0
#define QUEUE_TYPE queue
#define QUEUE_NODE_TYPE queue_node
#define QUEUE_NODE_VALUE_TYPE binary_tree

struct binary_tree
{
    BTTREE_VALUE_TYPE value;
    binary_tree *lchild;
    binary_tree *rchild;
};
struct queue_node
{
    QUEUE_VALUE_TYPE *value;
    queue_node *next;
};
struct queue
{
    queue_node *head;
    queue_node *rear;
    queue_node *queues;
};

QUEUE_TYPE *create(QUEUE_TYPE *_queue);
QUEUE_TYPE *inqueue(QUEUE_TYPE *_queue, QUEUE_NODE_VALUE_TYPE *value);
QUEUE_NODE_VALUE_TYPE *dequeue(QUEUE_TYPE *_queue);
QUEUE_TYPE *reset(QUEUE_TYPE *_queue);

#endif
