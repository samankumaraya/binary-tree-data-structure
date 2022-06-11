#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node* left;
    struct node* right;

}BST;

BST* newNode(int info){
    BST* node = (BST*) malloc(sizeof(BST));

    node->data = info;
    node->left = NULL;
    node->right= NULL;

    return(node);

}

BST* insert(BST* root, int key){

    if(root == NULL)
        return newNode(key);

    if (key < root->data)
        root->left = insert(root->left,key);

    if ( key > root->data)
        root->right = insert(root->right, key);

    return root;

}

BST* search(BST* root, int key){

    if(root == NULL)
        return NULL;

    if( root->data == key)
        return root;
    if (key < root->data)
        return search(root->left,key);

    if ( key > root->data)
        return search(root->right, key);

}

BST* minVal(BST *root){

    BST* temp = root;
    while (temp->left != NULL){

        temp = temp->left;
    }
    return (temp);
}
 int maxVal(BST *root){

    BST* temp = root;
    while (temp->right != NULL){

        temp = temp->right;
    }
    return (temp->data);
}

BST* delete(BST* root, int key){

    BST* temp;

    if (root == NULL)
        return root;

    if (key < root->data)
        root->left =  delete(root->left, key);

    if (key > root->data)
        root->right = delete(root->right, key);

    if(key == root->data){

        if((root->left == NULL) && (root->right==NULL)){
            temp = root;
            free(root);
            return temp;
        }
        else if ((root->left == NULL) && (root->right!=NULL)){
            temp = root->right;
            root->data = temp->data;
            free(temp);
            return(root);
        }
        else if ((root->left != NULL) && (root->right==NULL)){
            temp = root->left;
            root->data = temp->data;
            free(temp);
            return(root);
        }

        else{
            temp = minVal(root->right);
            root->data = temp->data;
            free(temp);
            return(root);
        }


    }


}


void printPostOrder(struct node* node){

    if (node == NULL)
        return;

    printPostOrder(node->left);
    printPostOrder(node->right);
    printf ("%d  ",node->data);
}

void printInOrder(struct node* node){

    if (node == NULL)
        return;

    printInOrder(node->left);
    printf ("%d  ",node->data);
    printInOrder(node->right);

}

void printPreOrder(struct node* node){

    if (node == NULL)
        return;

    printf ("%d  ",node->data);
    printPreOrder(node->left);

    printPreOrder(node->right);

}

int main(){

    BST* root = NULL;

    root = insert (root, 9);
    root = insert (root, 10);
    root = insert (root, 17);
    root = insert (root, 4);
    root = insert (root, 3);
    root = insert (root, 7);
    root = insert (root, 1);
    printPreOrder(root);

    BST* temp;
    temp =  search (root, 5);

    if (temp == NULL)
        printf("\n Key not found...");
    else
        printf("\n Key found...");

    //printf("\n The minimum value is %d ", minVal(root));
    printf("\n The maximum value is %d \n\n\n", maxVal(root));

    temp=delete(root,9);
     printPreOrder(root);

    }
