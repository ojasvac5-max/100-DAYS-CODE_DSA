#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};
struct Node* newNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->left = node->right = NULL;
    return node;
}
int countNodes(struct Node* root) {
    if (root == NULL) return 0;
    return 1 + countNodes(root->left) + countNodes(root->right);
}
bool isCBT(struct Node* root, int index, int totalNodes) {
    if (root == NULL) return true;

    if (index >= totalNodes) return false;

    return isCBT(root->left, 2 * index + 1, totalNodes) &&
           isCBT(root->right, 2 * index + 2, totalNodes);
}
bool isMinHeap(struct Node* root) {
    if (root == NULL) return true;
    if (root->left == NULL && root->right == NULL)
        return true;
    if (root->right == NULL) {
        return (root->data <= root->left->data) &&
               isMinHeap(root->left);
    }
    return (root->data <= root->left->data &&
            root->data <= root->right->data) &&
           isMinHeap(root->left) &&
           isMinHeap(root->right);
}
bool isHeap(struct Node* root) {
    int totalNodes = countNodes(root);
    return isCBT(root, 0, totalNodes) && isMinHeap(root);
}