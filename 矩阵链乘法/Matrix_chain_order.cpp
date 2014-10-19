/**********************************************************************
矩阵链乘法：(未封装)

	函数：void MatrixChainOrder(int *p, int n, int **m, int **s)
	作用：计算矩阵链乘法相乘的最小次数	
		时间复杂度：O(n^3)
		空间复杂度：O(n^2)

构造矩阵链乘法的最小次数：(未封装)
	函数：void PrintOptimalPapens( int **s, int i, int j)
	作用：打印出矩阵是如何相乘的	
	**	时间复杂度：O(n)
		空间复杂度：O(n^2)

矩阵链乘法：(封装)
	函数：void MaxtrixOrder(int *p, int n)
	作用：打印出矩阵是如何相乘的;打印矩阵相乘的最小次数
		时间复杂度：O(n^3)
		空间复杂度：O(n^2)
************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#define Inf 0x7fffffff
/**********************************************************************
矩阵链乘法：(未封装)

	函数：void MatrixChainOrder(int *p, int n, int **m, int **s)
		p:	n个矩阵的维数组成的数组p[n+1]维
		n:	矩阵个数
		m：	矩阵相乘的最小次数
		s:	储存计算m时取得的最优代价处的k的值
	返回值：	无
	打印值：	无
	时间复杂度：O(n^3)
	空间复杂度：O(n^2)
************************************************************************/
void MatrixChainOrder(int *p, int n, int **m, int **s)
{
	int i, j, l, k, q;
	for( i = 1; i <= n; i++)
  		m[i][i] = 0;
	for( l = 2; l <= n; l++)
		for(i = 1; i <= n - l + 1; i++)
		{
			j = i + l - 1;
			m[i][j] = Inf;
			
			for( k = i; k < j ; k ++)
			{
				q = m[i][k] + m[k+1][j] + p[i-1]*p[k]*p[j];
				if( q < m[i][j])
				{
					m[i][j] = q;
					s[i][j] = k;
				}
			}
		}
}
/**********************************************************************
构造矩阵链乘法的最小次数：(未封装)

	函数：void PrintOptimalPapens( int **s, int i, int j)
		s:	储存计算m时取得的最优代价处的k的值
		i:	第i个数组的索引号
		j:	第j个数组的索引号
	返回值：	无
	打印值：	打印出矩阵是如何相乘的
**	时间复杂度：O(n)
	空间复杂度：O(n^2)
************************************************************************/
void PrintOptimalPapens( int **s, int i, int j)
{
	if( i == j )
		printf("A%d", i);
	else
	{
		printf("(");
		PrintOptimalPapens(s, i, s[i][j]);
		PrintOptimalPapens(s, s[i][j]+1, j);
		printf(")");
	}
}

/**********************************************************************
矩阵链乘法：(封装)

	函数：void MaxtrixOrder(int *p, int n)
		p:	n个矩阵的维数组成的数组p[n+1]维
		n:	矩阵个数	
	返回值：	无
	打印值：	打印出矩阵是如何相乘的;打印矩阵相乘的最小次数
**	时间复杂度：O(n)
	空间复杂度：O(n^2)
************************************************************************/
void MaxtrixOrder(int *p, int n)
{
	int i, j;
	int **m = (int **) malloc(sizeof(int *) * (n + 1));
	int **s = (int **) malloc(sizeof(int *) * (n + 1));
	for( i = 0; i < n + 1; i++)
	{
		m[i] = (int *) malloc(sizeof(int) * (n + 1));
		s[i] = (int *) malloc(sizeof(int) * (n + 1));
	}
	for( i = 0; i < n + 1; i++)
		for( j = 0; j < n + 1; j++)
		{
			m[i][j] = 0;
			s[i][j] = 0;
		}
	MatrixChainOrder(p, n, m, s);
	PrintOptimalPapens(s, 1, n);
	printf("\n%d\n",m[1][n]);
}
int main()
{
	int p[] = {30,35,15,5,10,20,25};
	MaxtrixOrder(p,6);//数组是1*n+1维的，矩阵个数是n
	system("pause");
	return 0;
}