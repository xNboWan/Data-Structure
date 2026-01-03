/**
 * 文件名: queue.h
 * 作者: NboWan
 * 日期: 2026-1-3
 * 描述: 队列库函数头文件
 */

#ifndef LINKED_QUEUE_H
#define LINKED_QUEUE_H

#include "node.h"

#define QUEUE_SIZE 100


typedef struct
{
    node_t *front;
    node_t *rear;
    int size;
} queue_t;


/********************************************************函数声明*********************************************************/

queue_t* initLinkedQueue();


/************************************************************************************************************************/
#endif
