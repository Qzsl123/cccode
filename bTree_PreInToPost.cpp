//利用前序遍历和中序遍历得出后序遍历
#include <stdio.h>
#include <string.h>
using namespace std;
struct node{
    node *lchild;
    node *rchild;
    char c;
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
    printf("%c", T -> c);
}

node *build(int s1, int e1, int s2, int e2){
    node* root = creat();
    root -> c = str1[s1];
    int rootIdx;
    for(int i = s2; i <= e2; i++){
        if(str2[i] == str1[s1]){
            rootIdx = i;
            break;
        }
    }
    if(rootIdx != s2){
            root -> lchild = build(s1 + 1, s1 + rootIdx - s2, s2, rootIdx - 1);
        }
    if(rootIdx != e2){
        root -> rchild = build(s1 + rootIdx - s2 + 1, e1, rootIdx + 1, e2);
    } 
    return root;
}

int main(){
    while(scanf("%s", str1)){
        scanf("%s", str2);
        loc = 0;
        int len1 = strlen(str1);
        int len2 = strlen(str2);
        node *T = build(0, len1 - 1, 0, len2 - 1);
        postOrder(T);
        printf("\n");
    }
    return 0;
}