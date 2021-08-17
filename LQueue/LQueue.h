#ifndef LQUEUE_H_INCLUDED
#define LQUEUE_H_INCLUDED
#define MAX 10
//��ʽ���нṹ
typedef struct node
{
    void* data;                   //������ָ��
    struct node* next;            //ָ��ǰ������һ���
} Node;
typedef struct Lqueue
{
    Node* front;                   //��ͷ
    Node* rear;                    //��β
    int length;            //���г���
} LQueue;
typedef enum
{
    FALSE = 0, TRUE = 1
} Status;
//��ʼ������
void InitLQueue(LQueue* Q);
// ���ٶ���
void DestoryLQueue(LQueue* Q);
//�������Ƿ�Ϊ��
Status IsEmptyLQueue(const LQueue* Q);
//�������Ƿ�����
Status IsFullLQueue(const LQueue* Q);
//�鿴��ͷԪ��
Status GetHeadLQueue(LQueue* Q,void* e,int type);
//ȷ�����г���
int LengthLQueue(LQueue* Q);
//��Ӳ���
Status EnLQueue(LQueue* Q,void* data,int type);
//���Ӳ���
Status DeLQueue(LQueue* Q);
//��ն���
void ClearLQueue(LQueue* Q);
//������������
Status TraverseLQueue(const LQueue* Q, void (*foo)(void* q,int type),int type);
//��������
void LPrint(void* ptr,int type);
void datacpy(void* ptr, void* data, int type);
#endif // LQUEUE_H_INCLUDED