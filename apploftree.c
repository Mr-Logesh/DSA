#include <stdio.h>
#define MAX_SIZE 100
struct Node {
    int data;
};

struct Node tree[MAX_SIZE];

void insert(int data, int index) {
    if (index < MAX_SIZE) {
        tree[index].data = data;
    } else {
        printf("Binary tree is full. Cannot insert %d.\n", data);
    }
}


void printTree(int index, int n) {
    if (index < n && tree[index].data != -1) {
        printf("%d ", tree[index].data);
        printTree(2 * index + 1, n); 
        printTree(2 * index + 2, n); 
    }
}

int main() {
    int n;
    printf("Enter the number of elements in the binary tree: ");
    scanf("%d", &n);

    printf("Enter the elements of the binary tree (use -1 for empty nodes):\n");
    for (int i = 0; i < n; i++) {
        int data;
        scanf("%d", &data);
        insert(data, i);
    }

    printf("Binary tree elements:\n");
    printTree(0, n); 

    return 0;
}
