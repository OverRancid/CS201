//OverRancid#0590
//Akshat Nagpal, 2022mcb1255
#include <stdio.h>          //Parental Advisory         
#include <stdlib.h>        //Explicit Content

int max(int a, int b){return (a>b)? a: b;}
#define ever ;;

typedef struct BTnode{
    int n;             
    int *key;          
    int leaf;         
    struct BTnode **c; 
}BTree;

int t;
BTree *root = NULL;

BTree *B_TREE_CREATE(){
    BTree *new = (BTree *)malloc(sizeof(BTree));                  
    new->leaf = 1;                                        
    new->n = 0;                                          
    new->key = (int *)malloc((2 * t - 1) * sizeof(int)); 
    new->c = (BTree **)malloc((2 * t) * sizeof(BTree)); 
    return new;                                          
}

void B_TREE_SPLIT_CHILD(BTree *node, int i){
    BTree *right = B_TREE_CREATE();
    BTree *y = node->c[i-1]; 
    right->leaf = y->leaf;   
    right->n = t-1;

    for(int j=0; j<t-1; j++){
        right->key[j] = y->key[j + t];
    }
    if(!y->leaf){
        for (int j = 0; j < t; j++){
            right->c[j] = y->c[j + t];
        }
    }
    y->n = t - 1;
    for (int j = node->n; j >= i; j--){
        node->c[j + 1] = node->c[j];
    }
    node->c[i] = right;
    for (int j = node->n - 1; j >= i - 1; j--){
        node->key[j + 1] = node->key[j];
    }
    node->key[i - 1] = y->key[t - 1];
    node->n++;
}

void B_TREE_INSERT_NONFULL(BTree *node, int k){
    int i = (node->n) - 1;
    if (node->leaf == 1){
        while (i >= 0 && k < node->key[i]){
            node->key[i + 1] = node->key[i];
            i--;
        }
        node->key[i + 1] = k;
        node->n++;
    }
    else{
        while (i >= 0 && k < node->key[i]){
            i--;
        }
        i++;
        if (node->c[i]->n == 2 * t - 1){
            B_TREE_SPLIT_CHILD(node, i + 1);
            if (k > node->key[i]){
                i++;
            }
        }
        B_TREE_INSERT_NONFULL(node->c[i], k);
    }
}

void B_TREE_INSERT(BTree *node, int k){
    BTree *temp = node;
    if (temp->n == 2 * t - 1){
        BTree *temp2 = B_TREE_CREATE();
        root = temp2;
        temp2->leaf = 0;
        temp2->c[0] = temp;
        B_TREE_SPLIT_CHILD(temp2, 1);
        B_TREE_INSERT_NONFULL(temp2, k);
    }
    else{
        return B_TREE_INSERT_NONFULL(temp, k);
    }
}

BTree* B_TREE_SEARCH(BTree *node, int val){
    int i = 0;
    while (i < node->n && val > node->key[i]){
        i++;
    }
    if (i < node->n && val == node->key[i]){
        return node;
    }
    else if (node->leaf){
        return NULL;
    }
    else{
        return B_TREE_SEARCH(node->c[i], val);
    }
}

int B_TREE_MIN(BTree *node){
    while (!node->leaf){
        node = node->c[0];
    }
    return node->key[0];
}

void B_TREE_INORDER_TRAVERSE(BTree *node){
    if (node->leaf){
        for (int i = 0; i < node->n; i++){
            printf("%d ", node->key[i]);
        }
    }
    else{
        int i;
        for (i = 0; i < node->n; i++){
            B_TREE_INORDER_TRAVERSE(node->c[i]);
            printf("%d ", node->key[i]);
        }
        B_TREE_INORDER_TRAVERSE(node->c[i]);
    }
}

int getPredecessor(BTree* node, int idx){
    BTree* temp = node->c[idx]; 
    while(!temp->leaf){
        temp = temp->c[temp->n];
    }
    return temp->key[temp->n-1];
}

int getSuccessor(BTree* node, int idx){
    BTree* temp = node->c[idx+1];
    while(!temp->leaf){
        temp = temp->c[0];   
    }
    return temp->key[0];    
}

void merge(BTree* node, int idx){
    BTree* child = node->c[idx];     
    BTree* sibling = node->c[idx+1]; 
    
    child->key[t-1] = node->key[idx];
    int j;
    for(j=0; j<sibling->n; ++j){
        child->key[j+t] = sibling->key[j];
    }
    if(!child->leaf){
        for(j=0; j<=sibling->n; ++j){
            child->c[j+t] = sibling->c[j];
        }
    }

    for(j=idx+1; j<node->n; j++){
        node->key[j-1] = node->key[j];
    }
    for(j=idx+2; j<=node->n; j++){
        node->c[j-1] = node->c[j];  
    }

    child->n += sibling->n+1;   node->n--;
    return;
}

void B_TREE_DELETE(BTree* root, int val){
    BTree* node = B_TREE_SEARCH(root ,val);
    if(node==NULL){
        return;
    }
    int i;
    for(i=0; i<node->n; i++){
        if(node->key[i] == val){
            break;
        }
    }

    if(node->leaf){
        int j;
        for(j=i+1; j<node->n; ++j){
            node->key[j-1] = node->key[j];
        }
        node->n--;   
        return; 
    }
    else{
        int k = node->key[i];
        if(node->c[i]->n>=t){
            int pre = getPredecessor(node, i);
            node->key[i] = pre;
            B_TREE_DELETE(node->c[i], pre);
        }
        else if(node->c[i+1]->n >= t){
            int suc = getSuccessor(node, i);
            node->key[i] = suc;
            B_TREE_DELETE(node->c[i+1], suc);
        }
        else{
            merge(node, i);
            B_TREE_DELETE(node->c[i], val);
        }
    }
    return;
}

int main(){
    printf("Enter the minimum degree of the B-Tree t : ");
    scanf("%d", &t);

    root = B_TREE_CREATE();
    char cs[7];
    printf("Enter your choice (first/second): ");
    scanf("%s",&cs);
    if(cs[1]=='i'){
        int n;
        printf("Enter the number of integers n: ");
        scanf("%d", &n);
        for (int i = n; i > 0; i--){
        B_TREE_INSERT(root, i);
        }
        B_TREE_INORDER_TRAVERSE(root);
    }
    else{
        char choice;
        printf("Menu:\nI: Insertion\nS: Search\nM: Minimum\nT: Inorder Traversal\nD: Delete\nE: Exit \n");
        for(ever){
            char choice;
            choice = getchar();
            fflush(stdout); fflush(stdin); fflush(stderr);
            if (choice == 'I' || choice == 'i'){
                int n;
                printf("Enter number of elements you wanted to enter : ");
                scanf("%d", &n);
                printf("Enter %d numbers to insert : ", n);
                while (n--)
                {
                    int temp;
                    scanf("%d", &temp);
                    B_TREE_INSERT(root, temp);
                }
                printf("------------------------------------------------------\n");
            }
            else if (choice == 'S' || choice == 's'){
                int n;
                printf("Enter element to search : ");
                scanf("%d", &n);
                BTree* check = B_TREE_SEARCH(root, n);
                if(check==NULL){
                    printf("Not Present\n");
                }
                else{
                    printf("Present\n");
                }
                printf("------------------------------------------------------\n");
            }
            else if (choice == 'M' || choice == 'm'){
                int ans = B_TREE_MIN(root);
                printf("Minimum element is: %d\n", ans);
                printf("------------------------------------------------------\n");
            }
            else if (choice == 'T' || choice == 't'){
                printf("Inorder traversal is : ");
                B_TREE_INORDER_TRAVERSE(root);
                printf("\n");
                printf("------------------------------------------------------\n");
            }
            else if(choice =='D' || choice=='d'){
                printf("Enter number to delete\n");
                int val;
                scanf("%d", &val);
                B_TREE_DELETE(root, val);
                printf("------------------------------------------------------\n");
            }
            else if (choice == 'E' || choice == 'e'){
                break;
            }
            else{
                continue;
            }
        }
    }
    return 0;
}
