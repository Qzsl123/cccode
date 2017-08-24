/*
  author  : zsl
  problem : find the max width and height of the binary tree.
*/
#include <iostream>
using namespace std;

int width[1000], tree[17][2];//get the width of each level
int height = 0, maxwidth = 0;


void DFS(int i, int deep){
	if (deep > height)
	{
		height = deep;
	}
	width[deep]++;

	if (tree[i][0])
	{
		DFS(tree[i][0], deep+1);
	}
	if (tree[i][1])
	{
		DFS(tree[i][1], deep+1);
	}
}

int main(int argc, char const *argv[])
{
	int n;
	cin >> n ;
	for (int i = 1; i <= n; ++i)
	 {
	 	cin >> tree[i][0] >> tree[i][1];
	 } 

	DFS(1,1);

	for (int i = 0; i < 1000; ++i)
	{
		if (maxwidth < width[i])
		{
			maxwidth = width[i];
		}
	}

	cout << maxwidth <<" "<< height;
	return 0;
}