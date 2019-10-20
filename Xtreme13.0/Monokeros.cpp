#include <bits/stdc++.h>
using namespace std;

int read_int() {
    int n = 0;
    char c = getchar_unlocked();
    while ( !( '0' <= c && c <= '9' ) ) {
        c = getchar_unlocked();
    }
    while ( '0' <= c && c <= '9' ) {
        n = n * 10 + c - '0';
        c = getchar_unlocked();
    }
    return n;
}
struct node 
{ 
    int key; 
    struct node *left, *right; 
}; 
struct node *newNode(int item) 
{ 
    struct node *temp =  (struct node *)malloc(sizeof(struct node)); 
    temp->key = item; 
    temp->left = temp->right = NULL; 
    return temp; 
} 
void inorder(struct node *root) 
{ 
    if (root != NULL) 
    { 
        inorder(root->left); 
        printf("%d \n", root->key); 
        inorder(root->right); 
    } 
} 
struct node* insert(struct node* node, int key) 
{ 
    if (node == NULL) return newNode(key); 
  
    if (key < node->key) 
        node->left  = insert(node->left, key); 
    else if (key > node->key) 
        node->right = insert(node->right, key);    
  
    return node; 
} 



int getLevelUtil(struct node *node,  
                 int data, int level) 
{ 
    if (node == NULL) 
        return 0; 
  
    if (node -> key == data) 
        return level; 
  
    int downlevel = getLevelUtil(node -> left,  
                                 data, level + 1); 
    if (downlevel != 0) 
        return downlevel; 
  
    downlevel = getLevelUtil(node->right,  
                             data, level + 1); 
    return downlevel; 
} 
int getLevel(struct node *node, int data) 
{ 
    return getLevelUtil(node, data, 1); 
} 
int main() 
{ 
    struct node *root = NULL; 
    long N,v;
    N = read_int();
    for (long i=0; i<N; i++) {
        v = read_int();
        root = insert(root, v); 
        cout << getLevel(root,v)<<endl; 
    }
    return 0; 
} 