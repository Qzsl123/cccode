/*
  author  : zsl
  problem : find the max width and height of the binary tree.
*/
#include <iostream>
using namespace std;

int width[1000], tree[17][2];//get the width of each level
int height = 0, maxwidth = 0;


void preorder(int root);
void inorder(int root);
void postorder(int root);

int main(int argc, char const *argv[])
{
	int n;
	cin >> n;
	for (int i = 1; i <= n; ++i)
	 {
	 	cin >> tree[i][0] >> tree[i][1];
	 } 
    preorder(1);
    cout << endl;
    inorder(1);
    cout << endl;
    postorder(1);

	return 0;
}

void preorder(int root){
	if (root == 0)
	{
		return;
	}
	cout << root << " ";
	preorder(tree[root][0]);
	preorder(tree[root][1]);
}
void inorder(int root){
	if (root == 0)
	{
		return;
	}
	
	inorder(tree[root][0]);
	cout << root << " ";
	inorder(tree[root][1]);
}
void postorder(int root){
	if (root == 0)
	{
		return;
	}
	postorder(tree[root][0]);
	postorder(tree[root][1]);
	cout << root <<" ";
}

/*
5
2 3
4 5
0 0
0 0
0 0
*/