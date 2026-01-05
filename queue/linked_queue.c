/**
 * 文件名: linked_queue.c
 * 作者: NboWan
 * 日期: 2026-1-4
 * 描述: 链表队列库函数源文件
 * 编码格式:gbk
 */

#include "linked_queue.h"

/**
 * 初始化队列
 */
linked_queue_t *initLinkedQueue()
{
    linked_queue_t *q = (linked_queue_t *)malloc(sizeof(linked_queue_t));

    if (q == NULL)
    {
        printf("内存空间不足, 分配内存失败!!! \n");
        return NULL;
    }

    q->front = NULL;
    q->rear = NULL;
    q->size = 0;
    return q;
}

/**
 * 判断队列是否为空
 */
bool isLinkedQueueEmpty(linked_queue_t *q)
{
    return q->size == 0;
}

/**
 * 入队操作
 */
bool enLinkedQueue(linked_queue_t *q, elemType e)
{
    node_t *new_node = (node_t *)malloc(sizeof(node_t));
    if (!new_node)
    {
        printf("内存空间不足, 分配内存失败!!! \n");
        return false;
    }

    new_node->data = e;
    new_node->next = NULL;

    if (isLinkedQueueEmpty(q))
    {
        q->front = q->rear = new_node;
    }
    else
    {
        q->rear->next = new_node;
        q->rear = new_node;
    }
    q->size++;
    return true;
}

/**
 * 出队操作
 */
bool deLinkedQueue(linked_queue_t *q, elemType *e)
{
    if (isLinkedQueueEmpty(q))
    {
        printf("队列为空,出队失败!!! \n");
        return false;
    }

    node_t *node_to_delete = q->front;

    *e = q->front->data;
    if (q->size == 1)
    {
        q->front = q->rear = NULL;
    }
    else
    {
        q->front = q->front->next;
    }

    q->size--;
    free(node_to_delete);

    return true;
}

/**
 * 查看队头元素
 */
bool peekLinkedQueue(linked_queue_t *q, elemType *e)
{
    if (isLinkedQueueEmpty(q))
    {
        printf("队列为空,查看失败!!! \n");
        return false;
    }

    *e = q->front->data;
    return true;
}

/**
 * 获取队列长度
 */
int readLinkedQueueLen(linked_queue_t *q)
{
    return q->size;
}

/**
 * 删除队列并释放内存
 */
void destroyLinkedQueue(linked_queue_t *q)
{
    if (q == NULL)
    {
        return;
    }
    for (int i = 0; i < q->size;)
    {
        elemType temp;
        deLinkedQueue(q, &temp);
    }
    free(q);
    printf("删除成功!!! \n");
}