// This problem was asked by Google.
// Given the root to a binary tree, implement serialize(root), which serializes the tree into a string, 
// and deserialize(s), which deserializes the string back into the tree.
// For example, given the following Node class
// class Node:
//     def __init__(self, val, left=None, right=None):
//         self.val = val
//         self.left = left
//         self.right = right
// The following test should pass:
// node = Node('root', Node('left', Node('left.left')), Node('right'))
// assert deserialize(serialize(node)).left.left.val == 'left.left'


#include <stdio.h> 
#define MARKER -1 
  
/* A binary tree Node has key, pointer to left and right children */
struct Node 
{ 
    int key; 
    struct Node* left, *right; 
}; 
  
/* Helper function that allocates a new Node with the 
   given key and NULL left and right pointers. */
Node* newNode(int key) 
{ 
    Node* temp = new Node; 
    temp->key = key; 
    temp->left = temp->right = NULL; 
    return (temp); 
} 
  
// This function stores a tree in a file pointed by fp 
void serialize(Node *root, FILE *fp) 
{ 
    // If current node is NULL, store marker 
    if (root == NULL) 
    { 
        fprintf(fp, "%d ", MARKER); 
        return; 
    } 
  
    // Else, store current node and recur for its children 
    fprintf(fp, "%d ", root->key); 
    serialize(root->left, fp); 
    serialize(root->right, fp); 
} 
  
// This function constructs a tree from a file pointed by 'fp' 
void deSerialize(Node *&root, FILE *fp) 
{ 
    // Read next item from file. If theere are no more items or next 
    // item is marker, then return 
    int val; 
    if ( !fscanf(fp, "%d ", &val) || val == MARKER) 
       return; 
  
    // Else create node with this item and recur for children 
    root = newNode(val); 
    deSerialize(root->left, fp); 
    deSerialize(root->right, fp); 
} 
  
// A simple inorder traversal used for testing the constructed tree 
void inorder(Node *root) 
{ 
    if (root) 
    { 
        inorder(root->left); 
        printf("%d ", root->key); 
        inorder(root->right); 
    } 
} 
  
/* Driver program to test above functions*/
int main() 
{ 
    struct Node *root        = newNode(20); 
    root->left               = newNode(8); 
    root->right              = newNode(22); 
    root->left->left         = newNode(4); 
    root->left->right        = newNode(12); 
    root->left->right->left  = newNode(10); 
    root->left->right->right = newNode(14); 
  
    FILE *fp = fopen("tree.txt", "w"); 
    if (fp == NULL) 
    { 
        puts("Could not open file"); 
        return 0; 
    } 
    serialize(root, fp); 
    fclose(fp); 

    Node *root1 = NULL; 
    fp = fopen("tree.txt", "r"); 
    deSerialize(root1, fp); 
  
    printf("Inorder Traversal of the tree constructed from file:\n"); 
    inorder(root1); 
  
    return 0; 
} 