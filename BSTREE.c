#include <stdio.h>
#include <stdlib.h>

// Define the structure for a BST node
struct Node {
    int key;
    struct Node* left;
    struct Node* right;
};

// Function to create a new node
struct Node* createNode(int key) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->key = key;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Function to insert a key into the BST
struct Node* insert(struct Node* root, int key) {
    if (root == NULL) {
        return createNode(key);
    }

    if (key < root->key) {
        root->left = insert(root->left, key);
    } else if (key > root->key) {
        root->right = insert(root->right, key);
    }

    return root;
}

// Function to search for a key in the BST
struct Node* search(struct Node* root, int key) {
    if (root == NULL || root->key == key) {
        return root;
    }

    if (key < root->key) {
        return search(root->left, key);
    }

    return search(root->right, key);
}

// Inorder traversal of the BST
void inorderTraversal(struct Node* root) {
    if (root != NULL) {
        inorderTraversal(root->left);
        printf("%d ", root->key);
        inorderTraversal(root->right);
    }
}

int main() {
    struct Node* root = NULL;
    int inputValue;
    char choice;

    do {
        printf("Enter a value to insert into the BST: ");
        scanf("%d", &inputValue);
        root = insert(root, inputValue);

        printf("Do you want to insert another value? (y/n): ");
        scanf(" %c", &choice);
    } while (choice == 'y' || choice == 'Y');

    printf("Inorder Traversal: ");
    inorderTraversal(root);
    printf("\n");

    int searchKey;
    struct Node* result;

    printf("Enter a value to search for in the BST: ");
    scanf("%d", &searchKey);
    result = search(root, searchKey);

    if (result != NULL) {
        printf("Search for %d: Found\n", searchKey);
    } else {
        printf("Search for %d: Not Found\n", searchKey);
    }

    return 0;
}
