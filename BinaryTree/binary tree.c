#include <stdio.h>
#include <stdlib.h>

struct node{
    int key_value;
    struct node *left;
    struct node *right;
};


void destroy_tree(struct node* leaf){
    if (leaf != NULL){
        destroy_tree(leaf->left);
        destroy_tree(leaf->right);
        free( leaf );
    }

}
struct node *New_node(int key){
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->key_value = key;
    temp->left = temp->right = NULL;
    return temp;

};

struct node *insert(struct node *leaf, int key){
    //if the tree is empty, return a new node
    if (leaf == NULL) return New_node(key);
    //Otherwise, recur down the tree
    if (key < leaf->key_value)
        leaf->left = insert(leaf->left, key);
    else if (key > leaf->key_value)
        leaf->right = insert(leaf->right, key);

    //return the unchanged leaf pointer
    return leaf;
}

struct node *search(int key, struct node *leaf){
    if (leaf != NULL){
        if (key == leaf->key_value){
            return leaf;
        }
        else if(key < leaf->key_value){
            return search(key, leaf->left);
        }
        else if (key > leaf->key_value){
            return search(key, leaf->right);
        }
    }
    else return 0;
};

void postorder(struct node *leaf){
    if(leaf != NULL){
        postorder(leaf->left);
        postorder(leaf->right);
        printf("%d ", leaf->key_value);
    }
}

void inorder(struct node *leaf){
    if (leaf!=NULL){
        inorder(leaf->left);
        printf("%d ", leaf->key_value);
        inorder(leaf->right);
    }
}

void preorder(struct node *leaf){
    if (leaf!=NULL){
        printf("%d ", leaf->key_value);
        preorder(leaf->left);
        preorder(leaf->right);
    }
}

int main(){
    struct node *root = NULL;
    root = insert(root, 20);
    insert (root, 5);
    insert (root, 12);
    insert (root, 3);

    printf("\nInorder: ");
    inorder(root);

    printf("\nPreorder: ");
    preorder(root);

    printf("\nPostorder: ");
    postorder(root);
    printf("\n");

    system("PAUSE");
    return 0;
}
