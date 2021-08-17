#define MAXQUEUE 10
//ѭ�����нṹ
typedef struct Aqueue
{
    void* data[MAXQUEUE];      //������
    int front;
    int rear;
    int length;        //���г���
    int b;
} AQueue;
void InitAQueue(AQueue* Q,int type);
void DestoryAQueue(AQueue* Q);
int IsFullAQueue(const AQueue* Q);
int IsEmptyAQueue(const AQueue* Q);
bool GetHeadAQueue(AQueue* Q,void* e,int type);
int LengthAQueue(const AQueue* Q);
int EnAQueue(AQueue* Q,void* data,int type);
int DeAQueue(AQueue* Q);
void ClearAQueue(AQueue* Q);
int TraverseAQueue(const AQueue* Q, void (*foo)(void* q,int type),int type);
void APrint(void* q,int type);
void datacpy(void* ptr, void* data, int type);