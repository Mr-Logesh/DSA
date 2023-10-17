#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

struct Queue {
    int arr[MAX_SIZE];
    int front, rear;
};

// Function to initialize the queue
void initialize(struct Queue* queue) {
    queue->front = -1;
    queue->rear = -1;
}
int isEmpty(struct queue*queue){
  return(queue->front==-1);
}
int isFULL(struct queue*queue){
  return(queue->rear==MAX-SIZE-1);
}
void enqueue(struct queue*queue,int item)
{
  if(isFULL(queue)){
printf("queue is full\n"):
return;
  }
if(isEmpty(queue))
  queue->front=0;
queue->rear++;
queue->arr[queue->rear]=iteam;
}
int dequeue(struct queue*queue){
  if(isEmpty (queue)){
printf("queue is Empty\n");
return -1;
  }
int iteam=queue->arr[queue->front];
queue->front++;
if(queue->front=queue->rear)
    queue->front=queue->rear=-1;
return item;
}
int main(){
    struct queue*queue=create queue();
enqueue(queue,10);
enqueue(queue,20);
enqueue(queue,30);
printf("Dequeue item=%d\n",dequeue(queue));
printf("Dequeue item=%d\n",dequeue(queue));
return 0;
}
