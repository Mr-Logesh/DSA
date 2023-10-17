#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Process {
    int process_id;
    int burst_time;
    int remaining_time;
} Process;


typedef struct Node {
    Process process;
    struct Node* next;
} Node;

typedef struct ProcessQueue {
    Node* front;
    Node* rear;
} ProcessQueue;

void initializeQueue(ProcessQueue* queue) {
    queue->front = queue->rear = NULL;
}


void enqueue(ProcessQueue* queue, Process process) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->process = process;
    newNode->next = NULL;

    if (queue->rear == NULL) {
        queue->front = queue->rear = newNode;
        return;
    }

    queue->rear->next = newNode;
    queue->rear = newNode;
}


Process dequeue(ProcessQueue* queue) {
    if (queue->front == NULL) {
        Process emptyProcess = { -1, 0, 0 };
        return emptyProcess;
    }

    Node* temp = queue->front;
    queue->front = queue->front->next;

    if (queue->front == NULL) {
        queue->rear = NULL;
    }

    Process process = temp->process;
    free(temp);

    return process;
}


void roundRobin(ProcessQueue* queue, int time_quantum) {
    Process current_process;
    while (queue->front != NULL) {
        current_process = dequeue(queue);
        if (current_process.remaining_time > time_quantum) {
            printf("Running process %d for time quantum %d\n", current_process.process_id, time_quantum);
            current_process.remaining_time -= time_quantum;
            enqueue(queue, current_process);
        } else {
            printf("Running process %d for time quantum %d\n", current_process.process_id, current_process.remaining_time);
        }
    }
}

int main() {
    ProcessQueue processQueue;
    initializeQueue(&processQueue);


    Process process1 = { 1, 10, 10 };
    Process process2 = { 2, 5, 5 };
    Process process3 = { 3, 8, 8 };

    
    enqueue(&processQueue, process1);
    enqueue(&processQueue, process2);
    enqueue(&processQueue, process3);

    int time_quantum = 2;


    roundRobin(&processQueue, time_quantum);

    return 0;
}
