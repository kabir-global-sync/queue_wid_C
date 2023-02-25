#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

struct Queue
{
    int size;
    int front;
    int rear;
    int *que;
};

void enqueue(struct Queue *q, int ele)
{
    if (q->rear == q->size)
    {
        printf("Queue Overflow\n");
    }
    else
    {
        q->rear++;

        q->que[q->rear] = ele;
        
    }
}

void dequeue(struct Queue *q)
{
    if (q->rear<q->front)
    {
        printf("Queue Underflow\n");
    }
    else
    {
        int item = q->que[q->front];
        printf("Dequeued Element:%d\n", item);
        q->front++;
    }
}

void traverse(struct Queue *q)
{
    if (q->front>q->rear)
    {
        printf("Empty Queue\n");
    }
    else if (q->rear == q->front)
    {
        printf("%d <-Front,Rear\n", q->que[q->rear]);
    }
    else
    {
        printf("%d<-Front\n", q->que[q->front]);
        for (int i = q->front+1; i < q->rear; i++)
        {
            printf("%d\n", q->que[i]);
        }
        printf("%d<-Rear\n", q->que[q->rear]);
    }
}

int main()
{
    struct Queue queue;
    queue.size = 5;
    queue.front = 0;
    queue.rear = -1;
    queue.que = (int *)calloc(queue.size, sizeof(int));
    int user;
    while (true)
    {
        printf("1.ENQUEUE\n2.DEQUEUE\n3.TRAVERSE\n4.EXIT\nINPUT HERE:");
        scanf("%d", &user);
        int e;
        if(user==1){
            printf("Enter item:");
            scanf("%d",&e);
            enqueue(&queue,e);
        }
        else if(user==2){
            dequeue(&queue);
        }
        else if(user==3){
            traverse(&queue);
        }else{
            break;
        }
    }
    return 0;
}