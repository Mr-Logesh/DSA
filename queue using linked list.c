#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Queue {
    struct Node* front;
    struct Node* rear;
};

// Function to initialize the queue
void initialize(struct Queue* queue) {
    queue->front = NULL;
    queue->rear = NULL;
}

// Function to check if the queue is empty
int isEmpty(struct Queue* queue) {
    return (queue->front == NULL);
}

// Function to enqueue (insert) an element into the queue
void enqueue(struct Queue* queue, int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed.\n");
        return;
    }
    newNode->data = data;
    newNode->next = NULL;
    
    if (isEmpty(queue)) {
        queue->front = queue->rear = newNode;
    } else {
        queue->rear->next = newNode;
        queue->rear = newNode;
    }
}

// Function to dequeue (remove) an element from the queue
int dequeue(struct Queue* queue) {
    if (isEmpty(queue)) {
        printf("Queue Underflow! Cannot dequeue from an empty queue.\n");
        return -1;
    }
    
    struct Node* temp = queue->front;
    int data = temp->data;
    
    if (queue->front == queue->rear) {
        queue->front = queue->rear = NULL;
    } else {
        queue->front = queue->front->next;
    }
    
    free(temp);
    
    return data;
}

// Function to get the front element of the queue
int front(struct Queue* queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty, cannot get front element.\n");
        return -1;
    }
    return queue->front->data;
}

// Function to display the elements in the queue
void display(struct Queue* queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty.\n");
        return;
    }
    
    printf("Queue elements: ");
    struct Node* temp = queue->front;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// Function to free the memory allocated for the queue
void freeQueue(struct Queue* queue) {
    while (!isEmpty(queue)) {
        dequeue(queue);
    }
}

int main() {
    struct Queue myQueue;
    initialize(&myQueue);

    enqueue(&myQueue, 10);
    enqueue(&myQueue, 20);
    enqueue(&myQueue, 30);

    display(&myQueue);

    printf("Front element: %d\n", front(&myQueue));

    dequeue(&myQueue);

    display(&myQueue);

    freeQueue(&myQueue);

    return 0;
}
