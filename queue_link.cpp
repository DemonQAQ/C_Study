#include <function.h>
#include <stdio.h>
#include <stdlib.h>


QUEUE_TYPE *create(QUEUE_TYPE *_queue)
{
    QUEUE_TYPE *temp_p = _queue;
    if (!_queue) //空指针时
        temp_p = (QUEUE_TYPE *)malloc(sizeof(QUEUE_TYPE));
    if (!temp_p)
    {
        return _queue;
    }
    else
    {
        temp_p->queues = (QUEUE_NODE_TYPE *)malloc(sizeof(QUEUE_NODE_TYPE));
        if (!temp_p->queues)
            exit(-1);
        else
        {
            temp_p->queues->value = QUEUE_NODE_INDEX_VALUE;
            temp_p->queues->next = NULL;
            temp_p->head = NULL;
            temp_p->rear = NULL;
            return temp_p;
        }
    }
}

QUEUE_TYPE *inqueue(QUEUE_TYPE *_queue, QUEUE_NODE_VALUE_TYPE *value)
{
    if (!_queue)
        return _queue;
    else
    {
        QUEUE_NODE_TYPE *new_node = (QUEUE_NODE_TYPE *)malloc(sizeof(QUEUE_NODE_TYPE));
        if (!new_node)
            exit(-1);
        else
        {
            new_node->value = value;
            new_node->next = NULL;
            if (!_queue->rear) //空队列时将新节点接入链表
            {
                _queue->queues->next = new_node;
                _queue->head = new_node;
                _queue->rear = new_node;
            }
            else //将新节点接入队尾
            {
                _queue->rear->next = new_node;
                _queue->rear = new_node;
            }
            return _queue;
        }
    }
}

QUEUE_NODE_VALUE_TYPE *dequeue(QUEUE_TYPE *_queue)
{
    if (!_queue)
        exit(-1);
    else
    {
        QUEUE_NODE_VALUE_TYPE *temp_value = _queue->head->value;
        QUEUE_NODE_TYPE *temp_p = _queue->head;
        _queue->queues->next = temp_p->next; //更新队头位置
        _queue->head = _queue->queues->next;
        if (temp_p == _queue->rear)
            _queue->rear = NULL;
        free(temp_p);
        return temp_value;
    }
}

QUEUE_TYPE *reset(QUEUE_TYPE *_queue)
{
    QUEUE_NODE_TYPE *temp_p = _queue->head;
    _queue->queues->next = NULL;
    _queue->head = NULL;
    _queue->rear = NULL;
    free(temp_p);
    return _queue;
}