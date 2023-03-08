/* 
 * This program demonstrates the data structure of a binary tree 
 * Your task is specified in the exam 
*/ 
#include <stdio.h> 
#include <stdlib.h> 
 
// This is one node of the tree 
typedef struct { 
    int data;               // data which is stored in the node 
    void* left;      // pointer to the left sub-tree 
    void* right;     // pointer to the right sub-tree 
} Node; 
 
/* 
 * This function creates an empty nde 
 */ 
Node * CreateNode(int val) 
{ 
    Node *p;        // pointer to the new node 
 
    // create the node 
    p = (Node *) malloc(sizeof(Node)); 
 
    // store the value 
    p->data = val; 
 
    // Left and right child for node 
    // will be initialized to null 
    p->left = NULL; 
    p->right = NULL; 
 
    // return the new node 
    return p; 
}


Node * delete_node(int val, Node *root) {
    if (root == NULL) {
        return NULL; // node not found
    }
    if (val < root->data) {
        root->left = deleteNode(val, root->left);
    } else if (val > root->data) {
        root->right = deleteNode(val, root->right);
    } else {
        if (root->left == NULL) {
            Node *temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            Node *temp = root->left;
            free(root);
            return temp;
        } else {
            Node *temp = findMin(root->right);
            root->data = temp->data;
            root->right = deleteNode(temp->data, root->right);
        }
    }
    return root;
}
//Encontramos el mas pequeno del subtree de la derecha que es el que tenemos que intercambiar con el nodo que queremos eliminar
Node *findMin(Node *root) {
    while (root->left != NULL) {
        root = root->left;
    }
    return root;
}


void deleteTree(Node *root) {
    if(root->left == NULL && root->right == NULL) {
        free(root);
    }
    else if(root->left != NULL && root->right == NULL) {
        delete_node(root->left);
    }
    else if(root->right != NULL && root->left == NULL) {
        delete_node(root->right);
    }
    else {
        deleteTree(root->left);
        deleteTree(root->right);
    }
}
 
/* 
 * Main - create a simple tree 
 */ 
int main() 
{ 
 
    /*create root*/ 
    Node* root = CreateNode((int)'X'); 
 
    // create two sub-trees 
    root->left = CreateNode('ED'); 
    root->right = CreateNode(0xFFF); 
 
    // and one more sub-tree 
    ((Node *)root->left)->left = CreateNode(68); 
    ((Node *)root->right)->left = CreateNode(1); 
 
    return 0; 
} 