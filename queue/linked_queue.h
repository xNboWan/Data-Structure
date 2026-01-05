/**
 * 文件名: linked_queue.h
 * 作者: NboWan
 * 日期: 2026-1-3
 * 描述: 链表队列库函数头文件
 * 编码格式:gbk
 */

#ifndef LINKED_QUEUE_H
#define LINKED_QUEUE_H

#include "node.h"

typedef struct
{
    node_t *front;
    node_t *rear;
    int size;
} linked_queue_t;

/********************************************************函数声明*********************************************************/

linked_queue_t *initLinkedQueue();
bool isLinkedQueueEmpty(linked_queue_t *q);
bool enLinkedQueue(linked_queue_t *q, elemType e);
bool deLinkedQueue(linked_queue_t *q, elemType *e);
bool peekLinkedQueue(linked_queue_t *q, elemType *e);
int readLinkedQueueLen(linked_queue_t *q);
void destroyLinkedQueue(linked_queue_t *q);

/************************************************************************************************************************/
#endif
