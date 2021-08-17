#ifndef LQUEUE_H_INCLUDED
#define LQUEUE_H_INCLUDED
#define MAX 10
//链式队列结构
typedef struct node
{
    void* data;                   //数据域指针
    struct node* next;            //指向当前结点的下一结点
} Node;
typedef struct Lqueue
{
    Node* front;                   //队头
    Node* rear;                    //队尾
    int length;            //队列长度
} LQueue;
typedef enum
{
    FALSE = 0, TRUE = 1
} Status;
//初始化队列
void InitLQueue(LQueue* Q);
// 销毁队列
void DestoryLQueue(LQueue* Q);
//检查队列是否为空
Status IsEmptyLQueue(const LQueue* Q);
//检查队列是否已满
Status IsFullLQueue(const LQueue* Q);
//查看队头元素
Status GetHeadLQueue(LQueue* Q,void* e,int type);
//确定队列长度
int LengthLQueue(LQueue* Q);
//入队操作
Status EnLQueue(LQueue* Q,void* data,int type);
//出队操作
Status DeLQueue(LQueue* Q);
//清空队列
void ClearLQueue(LQueue* Q);
//遍历函数操作
Status TraverseLQueue(const LQueue* Q, void (*foo)(void* q,int type),int type);
//操作函数
void LPrint(void* ptr,int type);
void datacpy(void* ptr, void* data, int type);
#endif // LQUEUE_H_INCLUDED