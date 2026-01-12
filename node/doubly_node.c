/**
 * 文件名：doubly_node.c
 * 作者：NboWan
 * 日期：2026-1-9
 * 描述：双向链表库源文件
 * 编码格式:utf8
 * 补充说明:双向链表, pos从头节点开始计数, pos初始值为0
 */

#include "doubly_node.h"

/*********************************************************函数定义********************************************************/

/**
 * 私有函数,
 * 用于创建新节点
 */
static doubly_node_t *createNewDoublyNode(elemType e)
{
    doubly_node_t *doubly_node = (doubly_node_t *)malloc(sizeof(doubly_node_t));
    if (!doubly_node)
    {
        return NULL;
    }

    doubly_node->data = e;
    doubly_node->prev = NULL;
    doubly_node->next = NULL;

    return doubly_node;
}

/**
 * 初始化双向链表,
 * 返回值为指向链表的指针
 */
doubly_linked_list_t *initDoublyNode(void)
{
    doubly_linked_list_t *DL = (doubly_linked_list_t *)malloc(sizeof(doubly_linked_list_t));
    if (!DL)
    {
        return NULL;
    }
    DL->size = 0;
    DL->head = NULL;
    DL->tail = NULL;

    return DL;
}

/**
 * 判断是否为空
 */
bool isDoublyNodeEmpty(doubly_linked_list_t *DL)
{
    if (!DL)
    {
        return false;
    }
    return DL->size == 0;
}

/**
 * 清空链表并释放内存,
 * 释放完之后, DL是野指针, 再次访问会导致程序崩溃
 */
void destroyDoublyNode(doubly_linked_list_t *DL)
{
    if (!DL)
    {
        return;
    }
    doubly_node_t *current_doubly_node = DL->head;
    while (current_doubly_node)
    {
        doubly_node_t *current_doubly_node_next = current_doubly_node->next;
        free(current_doubly_node);
        current_doubly_node = current_doubly_node_next;
    }
    free(DL);
}

/**
 * 头插法
 */
bool insertDoubleHead(doubly_linked_list_t *DL, elemType e)
{
    if (!DL)
    {
        return false;
    }
    doubly_node_t *new_doubly_node = createNewDoublyNode(e);
    if (new_doubly_node == NULL)
    {
        return false;
    }

    if (isDoublyNodeEmpty(DL) == true)
    {
        DL->head = new_doubly_node;
        DL->tail = new_doubly_node;
    }
    else
    {
        new_doubly_node->next = DL->head;
        DL->head->prev = new_doubly_node;
        DL->head = new_doubly_node;
    }

    DL->size++;
    return true;
}

/**
 * 尾插法
 */
bool insertDoubleTail(doubly_linked_list_t *DL, elemType e)
{
    if (!DL)
    {
        return false;
    }

    doubly_node_t *new_doubly_node = createNewDoublyNode(e);
    if (new_doubly_node == NULL)
    {
        return false;
    }

    DL->size++;

    if (isDoublyNodeEmpty(DL) == true)
    {
        DL->head = new_doubly_node;
        DL->tail = new_doubly_node;
        return true;
    }

    new_doubly_node->prev = DL->tail;
    DL->tail->next = new_doubly_node;
    DL->tail = new_doubly_node;
    return true;
}

/**
 * 传入参数pos以在任意下标创建新的节点
 */
bool insertDoublyNodeWithPos(doubly_linked_list_t *DL, int pos, elemType e)
{
    if (!DL || pos < 0 || pos > DL->size)
    {
        return false;
    }

    if (pos == 0) // 头节点pos为0
    {
        insertDoubleHead(DL, e);
        return true;
    }

    if (pos == DL->size)
    {
        insertDoubleTail(DL, e);
        return true;
    }

    doubly_node_t *current_doubly_node = DL->head;
    doubly_node_t *doubly_node_to_insert = createNewDoublyNode(e);

    if (doubly_node_to_insert == NULL)
    {
        return false;
    }

    for (int i = 1; i < pos; i++)
    {
        current_doubly_node = current_doubly_node->next;
    }

    doubly_node_to_insert->next = current_doubly_node->next;
    doubly_node_to_insert->prev = current_doubly_node; // 将添加的节点的前后指针指向前后节点

    if (current_doubly_node->next != NULL) // 更新前后节点指针
    {
        current_doubly_node->next->prev = doubly_node_to_insert;
    }

    current_doubly_node->next = doubly_node_to_insert;

    DL->size++;
    return true;
}

/**
 * 删除头节点
 */
bool deleteDoubleHead(doubly_linked_list_t *DL, elemType *e)
{
    if (!DL || !DL->head)
    {
        return false;
    }

    doubly_node_t *doubly_node_to_delete = DL->head;
    *e = doubly_node_to_delete->data;

    if (DL->head == DL->tail)
    {
        DL->head = NULL;
        DL->tail = NULL;
    }
    else
    {
        DL->head = DL->head->next;
        DL->head->prev = NULL;
    }
    free(doubly_node_to_delete);
    DL->size--;
    return true;
}

/**
 * 删除尾节点
 */
bool deleteDoubleTail(doubly_linked_list_t *DL, elemType *e)
{
    if (!DL || !DL->tail)
    {
        return false;
    }

    doubly_node_t *doubly_node_to_delete = DL->tail;
    *e = doubly_node_to_delete->data;

    if (DL->head == DL->tail)
    {
        DL->head = NULL;
        DL->tail = NULL;
    }
    else
    {
        DL->tail = DL->tail->prev;
        DL->tail->next = NULL;
    }
    free(doubly_node_to_delete);
    DL->size--;
    return true;
}

/**
 * 传入参数pos以在任意位置删除节点
 */
bool deleteDoublyWithPos(doubly_linked_list_t *DL, int pos, elemType *e)
{
    if (!DL || !DL->head || pos < 0 || pos >= DL->size)
    {
        return false;
    }

    if (pos == 0)
    {
        deleteDoubleHead(DL, e);
        return true;
    }

    if (pos == DL->size - 1)
    {
        deleteDoubleTail(DL, e);
        return true;
    }

    doubly_node_t *current_doubly_node = DL->head;

    for (int i = 0; i < pos; i++)
    {
        current_doubly_node = current_doubly_node->next;
    }

    *e = current_doubly_node->data;
    current_doubly_node->next->prev = current_doubly_node->prev;
    current_doubly_node->prev->next = current_doubly_node->next;
    free(current_doubly_node);
    DL->size--;
    return true;
}

/**
 * 私有函数,
 * 交换变量值
 */
static void switchNum(elemType *a, elemType *b)
{
    elemType temp;
    temp = *b;
    *b = *a;
    *a = temp;
}

/**
 * 颠倒链表
 */
bool reverseDoublyLinkedList(doubly_linked_list_t *DL)
{
    if (!DL || !DL->head)
    {
        return false;
    }

    if (DL->size < 2)
    {
        return true;
    }
    doubly_node_t *forward_doubly_node = DL->head;
    doubly_node_t *backward_doubly_node = DL->tail;

    for (int i = 0; i < DL->size / 2; i++)
    {
        switchNum(&forward_doubly_node->data, &backward_doubly_node->data);
        forward_doubly_node = forward_doubly_node->next;
        backward_doubly_node = backward_doubly_node->prev;
    }
    return true;
}

/**
 * 传入参数pos以更改任意位置数据值
 */
bool updateDoublyNode(doubly_linked_list_t *DL, int pos, elemType e)
{
    if (!DL || !DL->head || pos < 0 || pos >= DL->size)
    {
        return false;
    }

    doubly_node_t *current_doubly_node = DL->head;

    for (int i = 0; i < pos; i++)
    {
        current_doubly_node = current_doubly_node->next;
    }

    current_doubly_node->data = e;
    return true;
}

/**
 * 从头节点开始查找数据,
 * 返回值为节点下标值
 */
int findDoublyNode(doubly_linked_list_t *DL, elemType e)
{
    if (!DL || !DL->head)
    {
        return -1;
    }

    doubly_node_t *current_doubly_node = DL->head;
    int pos = 0;

    while (current_doubly_node != NULL)
    {
        if (current_doubly_node->data == e)
        {
            return pos;
        }
        pos++;
        current_doubly_node = current_doubly_node->next;
    }

    return -1;
}

/**
 * 读取链表长度
 */
int readDoublyNodeLen(doubly_linked_list_t *DL)
{
    if (!DL)
    {
        return -1;
    }
    return DL->size;
}

/**
 * 正向遍历列表
 */
bool readDoublyNodeListForward(doubly_linked_list_t *DL)
{
    if (!DL)
    {
        return false;
    }

    doubly_node_t *current_doubly_node = DL->head;

    while (current_doubly_node != NULL)
    {
        printf("%d \n", current_doubly_node->data);
        current_doubly_node = current_doubly_node->next;
    }

    return true;
}

/**
 * 反向遍历列表
 */
bool readDoublyNodeListBackward(doubly_linked_list_t *DL)
{
    if (!DL)
    {
        return false;
    }

    doubly_node_t *current_doubly_node = DL->tail;

    while (current_doubly_node != NULL)
    {
        printf("%d \n", current_doubly_node->data);
        current_doubly_node = current_doubly_node->prev;
    }

    return true;
}

/**
 * 传入参数pos以读取任意位置数据值
 */
bool readDoublyNodeWithPos(doubly_linked_list_t *DL, int pos, elemType *e)
{
    if (!DL || !DL->head || pos < 0 || pos >= DL->size)
    {
        return false;
    }

    doubly_node_t *current_doubly_node = DL->head;

    for (int i = 0; i < pos; i++)
    {
        current_doubly_node = current_doubly_node->next;
    }

    *e = current_doubly_node->data;
    return true;
}

/*************************************************************************************************************************/