/**********************************************************************
最优二叉查找树的期望搜索代价：（封装）

	函数：double OptimalBST(double *p, double *q, int n)
	作用：返回最优二叉查找树的期望代价并输出最优二叉查找树
		时间复杂度：O(n^3)
		空间复杂度：O(n^2)

最优二叉查找树的期望搜索代价：（未封装）

	函数：double OptimalBST(double *p, double *q, int n, double **e, int **root)
	作用：返回最优二叉查找树的期望代价
		时间复杂度：O(n^3)
		空间复杂度：O(n^2)

打印最优二叉查找树：(未封装)

	函数：void PrintOptimalBST(int first, int last, int **root)
	作用：	输出最优二叉查找树
	时间复杂度：O(n)
	空间复杂度：O(n^2)
************************************************************************/
#include <stdio.h>
#include <stdlib.h>

#define Inf 0x7fffffff
/**********************************************************************
最优二叉查找树的期望搜索代价：(未封装)

	函数：double OptimalBST(double *p, double *q, int n, double **e, int **root)
		p:		关键字序列（k1,k2……kn)对应的概率数组
		q:		虚拟键（d0,d1……dn）对应的概率数组
		n:		二叉查找树的节点数
		e:		用于储存二叉查找树的搜索代价
		root:	记录包含关键字ki,ki+1……kn的子树的根
	返回值：	返回最优二叉查找树的期望代价
	打印值：	无
	时间复杂度：O(n^3)
	空间复杂度：O(n^2)
************************************************************************/
double Find_OptimalBST(double *p, double *q, int n, double **e, int **root)
{
	int i, j, l ,r;
	double Min;

	double **w = (double **) malloc( sizeof(double *) * (n + 2));
	for( i = 0; i <= n + 1; i++)
		w[i] = (double *) malloc(sizeof(double) * (n + 1));
	for( i = 0; i <= n + 1; i++)
		for( j = 0; j <= n; j++)
			w[i][j] = 0;
	
	for( i = 1; i <= n + 1; i++)
	{
		e[i][i-1] = q[i-1];
		w[i][i-1] = q[i-1];
	}

	for(l = 1; l <= n; l++)
		for(i = 1; i <= n - l +1; i++)
		{
			j = i + l -1;
			e[i][j] = Inf;
			w[i][j] = w[i][j-1] + p[j] + q[j];
			for( r = i; r <= j; r++)
			{
				Min = e[i][r-1] + e[r+1][j] + w[i][j];
				if( Min <e[i][j])
				{
					e[i][j] = Min;
					root[i][j] = r;
				}
			}
		}

		return e[1][n];
}

/**********************************************************************
打印最优二叉查找树：(未封装)

	函数：void PrintOptimalBST(int first, int last, int **root)
		first:		起始节点序号
		last:		最大节点序号
		root:	记录包含关键字ki,ki+1……kn的子树的根
	返回值：	无
	打印值：	输出最优二叉查找树
	时间复杂度：O(n)
	空间复杂度：O(n^2)
************************************************************************/
void PrintOptimalBST(int first, int last, int **root)
{
	if( first > last)
		return;
	//中序遍历
	printf("%d ", root[first][last]);
	PrintOptimalBST(first,root[first][last] - 1, root);
	PrintOptimalBST(root[first][last] + 1, last, root);
	/*
	//前序遍历
	PrintOptimalBST(first,root[first][last] - 1, root);
	printf("%d ", root[first][last]);
	PrintOptimalBST(root[first][last] + 1, last, root);

	//后序遍历
	
	PrintOptimalBST(first,root[first][last] - 1, root);
	PrintOptimalBST(root[first][last] + 1, last, root);
	printf("%d ", root[first][last]);
	*/
	
}
/**********************************************************************
最优二叉查找树的期望搜索代价：（封装）

	函数：double OptimalBST(double *p, double *q, int n)
		p:		关键字序列（k1,k2……kn)对应的概率数组
		q:		虚拟键（d0,d1……dn）对应的概率数组
		n:		二叉查找树的节点数

	返回值：	返回最优二叉查找树的期望代价
	打印值：	无
	时间复杂度：O(n^3)
	空间复杂度：O(n^2)
************************************************************************/
double OptimalBST(double *p, double *q, int n)
{
	int i, j;
	double E_T;
	int **root = (int **) malloc( sizeof(int *) * (n + 2));
	double **e = (double **) malloc( sizeof(double *) * (n + 2));

	for( i = 0; i <= n + 1; i++)
	{
		e[i] = (double *) malloc(sizeof(double) * (n + 1));
		root[i] = (int *) malloc(sizeof(int) * (n + 1));
	}
	for( i = 0; i <= n + 1; i++)
		for( j = 0; j <= n; j++)
		{
			e[i][j] = 0;
			root[i][j] = 0;
		}
	E_T = Find_OptimalBST(p, q, n, e, root);
	PrintOptimalBST(1, n, root);
	printf("\n");
	return E_T;
}
		
		
int main()
{
	double p[6] = {0,0.15, 0.10, 0.05, 0.10, 0.20};
	double q[6] = {0.05, 0.10, 0.05, 0.05, 0.05, 0.10};
	double E;	
	E = OptimalBST(p, q, 5);
	printf("%f\n", E);
	system("pause");
	return 0;
}