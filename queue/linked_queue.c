#include "linked_queue.h"


queue_t* initLinkedQueue()
{
    queue_t *q = (queue_t *)malloc(sizeof(queue_t));
    
    if (q == NULL)
    {
        printf("·ÖÅäÄÚ´æÊ§°Ü!!! \n");
        return NULL;
    }

    q->front = NULL;
    q->rear = NULL;
    q->size = 0;
    return q;
}

bool isLinkedQueueEmpty(queue_t *q)
{
    return q->size == 0;
}
bool enLinkedQueue(queue_t *q, elemType e)
{
    
}
bool deLinkedQueue(queue_t *q, elemType *e);
bool peekLinkedQueue(queue_t *q, elemType *e);
int readLinkQueueLen(queue_t *q);
void destroyLinkedQueue(queue_t *q);