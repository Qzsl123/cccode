#include <stdio.h>
#include <string.h>
using namespace std;
struct node{
    node *lchild;
    node *rchild;
    int c;
}tree[50];

int loc;
node *creat(){
    tree[loc].lchild = tree[loc].rchild = NULL;
    return &tree[loc++];
}

char str1[30], str2[30];

void postOrder(node *T){
    if(T -> lchild != NULL){
        postOrder(T -> lchild);
    }
    if(T -> rchild != NULL){
        postOrder(T -> rchild);
    }
    printf("%d ", T -> c);
}

void preOrder(node *T){
     printf("%d ", T -> c);
    if(T -> lchild != NULL){
        preOrder(T -> lchild);
    }
    if(T -> rchild != NULL){
        preOrder(T -> rchild);
    }
}

void inOrder(node *T){
    if(T -> lchild != NULL){
        inOrder(T -> lchild);
    }
    printf("%d ", T -> c);
    if(T -> rchild != NULL){
        inOrder(T -> rchild);
    }
}

node *insert(node *T, int x){
    if(T == NULL){
        T = creat();
        T -> c = x;
        return T;
    }
    else if(x < T -> c){
        T -> lchild = insert(T -> lchild, x);
    }else if(x > T -> c){
        T -> rchild = insert(T -> rchild, x);
    }
    return T;
}

int main(){
    int n;
    while(scanf("%d", &n) != EOF){
        loc = 0;
        node *T = NULL;
        for(int i = 0; i < n; i++){
            int x;
            scanf("%d", &x);
            T = insert(T, x);
        }
        preOrder(T);
        printf("\n");
        inOrder(T);
        printf("\n");
        postOrder(T);
        printf("\n");
    }
    return 0;
}