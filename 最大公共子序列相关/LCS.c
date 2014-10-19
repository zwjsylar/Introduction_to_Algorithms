/**********************************************************************
最大公共子序列(不连续）：

	函数：int Lcs_length( char *str1, char *str2, int **c, int **b)
	作用：返回最大公共子序列长度	
		时间复杂度：O(mn)
		空间复杂度：O(mn)

	函数：void Print_Lcs( char *str, int **b, int i, int j)
	作用：输出最大公共子序列
		输出最大公共子序列：
		时间复杂度：O(m+n)
		空间复杂度：O(mn)

	函数：void Find_Lcs( char *str1, char *str2)
	作用：输出最大公共子序列及其长度：
		时间复杂度：构建矩阵花费了O(MN)的时间，回溯时花费了O（M+N)的时间，两者相加最终花费了O(MN)的时间。
		空间复杂度：构建矩阵花费了O(MN)的空间，标记函数也花费了O(MN)的空间，两者相加最终花费了O(MN)的空间。

最大公共子串（连续）

	函数：void Find_conLCS( char *str1, char *str2) 
	作用：输出最大公共子串及长度：	
		时间复杂度：O(mn)
		空间复杂度：O(mn)

	函数：void Find_conLCS1( char *longstr, char *shortstr)
	作用：改进后的函数，输出最大公共子串及其长度
		时间复杂度：O(mn)
		空间复杂度：O(len(shortstr))

最大递增子序列：
	函数：int Find_LIS( int *Array, int len)
	作用：返回最大递增子序列长度（采用动态规划思想）
		时间复杂度：O(n^2)
		空间复杂度：O(n)

	函数：int BinSearch( int *Array, int len, int num)（有修改的二分查找）
	作用：返回num需要插入的位置（由于待插入的数据一定小于或等于数组的元素，则直接返回low）
		时间复杂度：O(lgn)
		空间复杂度：O(n)

	函数：int Find_LIS1( int *Array, int len)
	作用：返回最大递增子序列长度（采用二分查找）
		时间复杂度：O(nlgn)
		空间复杂度：O(n)
************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define EQUAL	1	//EQUAL表示c[i][j]是由c[i-1][j-1]+1来的=====此时两个序列有相同的字符
#define UP		2	//UP表示c[i][j]是由c[i-1][j]来的============此时两个序列没有相同的字符
#define LEFT	3	//LEFT表示c[i][j]是由[ci][j-1]来的==========此时两个序列没有相同的字符


/**************************************************************
函数：int Lcs_length( char *str1, char *str2, int **c, int **b)
输入：	str1:	待比较字符串1
		str2:	待比较字符串2
		**c:	储存最大公共子序列长度
		**b:	储存最大公共子序列检索路径

返回值：str1和str2最大公共子序列
时间复杂度：O(mn)
空间复杂度：O(mn)
***************************************************************/
int Lcs_length( char *str1, char *str2, int **c, int **b)
{
	int len1 = strlen(str1),
		len2 = strlen(str2);
	int i,j;
	for( i = 1; i <= len1; i++)
		c[i][0] = 0;
	for ( j = 0; j <= len2; j++)
		c[0][j] = 0;
	for(  i = 1; i <= len1; i++)
		for( j = 1; j <= len2; j++)
		{	
			/*******************************
			使用i-1和j-1
			算法导论书上写的是比较str1[i]和str[j]，但是算法导论书上的两个序列下标是由1开始的
			这里使用i-1以及j-1是由于数组的下标从0开始
			********************************/
			if( str1[i-1] == str2[j-1] )											
			{
				c[i][j] = c[i-1][j-1] + 1;
				b[i][j] = EQUAL; 
			}
			else if (c[i-1][j] >= c[i][j-1])
				{
					c[i][j] = c[i-1][j];
					b[i][j] = UP;
				}
			else 
				{
					c[i][j] = c[i][j-1];
					b[i][j] = LEFT;
				}
		}
		return c[len1][len2];
}

/**************************************************************
函数：void Print_Lcs( char *str, int **b, int i, int j
		str:	待比较字符串1
		**b:	储存最大公共子序列检索路径
		i:		待比较字符串1的长度
		j:		待比较字符串2的长度

返回值：无
打印值：输出字符串1和字符串2的最长公共子序列
时间复杂度：O(m+n)
空间复杂度：O(m+n)
***************************************************************/
void Print_Lcs( char *str, int **b, int i, int j)
{
	if( i == 0 || j == 0)
		return;
	if( b[i][j] == EQUAL)
	{
		Print_Lcs(str, b, i - 1, j - 1);
		printf("%c ", str[i-1]);
	}
	else if ( b[i][j] == UP )
		Print_Lcs(str, b, i - 1, j);
	else 
		Print_Lcs(str, b, i , j - 1);
}

/**************************************************************
函数：void Find_Lcs( char *str1, char *str2)
		str1:	待比较字符串1
		str2:	待比较字符串2
返回值：无
打印值：输出最大公共子序列长度以及最大公共子序列
时间复杂度：O(mn)
空间复杂度：O(mn)
***************************************************************/
void Find_Lcs( char *str1, char *str2)
{
	int i,j,length;
	int len1 = strlen(str1),
		len2 = strlen(str2);
	//申请二维数组
	int **c = (int **)malloc(sizeof(int*) * (len1 + 1));
	int **b = (int **)malloc(sizeof(int*) * (len1 + 1));
	for( i = 0; i<= len1; i++ )	////这个等号之前没加，导致内存泄漏
	{
		c[i] = (int *)malloc(sizeof(int) * (len2 + 1));
		b[i] = (int *)malloc(sizeof(int) * (len2 + 1));
	}

	//将c[len1][len2]和b[len1][len2]初始化为0
	for ( i = 0; i<= len1; i++)
		for( j = 0; j <= len2; j++)
		{
			c[i][j] = 0;
			b[i][j] = 0;
		}
	
	//计算LCS的长度
	length = Lcs_length(str1, str2, c, b);
	printf("The number of the Longest-Common-Subsequence is %d\n", length);
	
	//利用数组b输出最长子序列
	printf("The Longest-Common-Subsequence is: ");
	Print_Lcs(str1, b, len1, len2);
	printf("\n");

	//动态内存释放
	for ( i = 0; i <= len1; i++)
	{
		free(c[i]);
		free(b[i]);
	}
	free(c);
	free(b);
}

/**************************************************************
函数：void Find_conLCS( char *str1, char *str2)
		str1:	待比较字符串1
		str2:	待比较字符串2
返回值：无
打印值：输出最大公共子串长度以及最大公共子串
时间复杂度：O(mn)
空间复杂度：O(mn)
***************************************************************/
void Find_conLCS( char *str1, char *str2)
{
	int i,j;
	int len = 0, end = -1, start = 0;
	int len1 = strlen(str1),
		len2 = strlen(str2);

	int **c = (int **)malloc(sizeof(int *) * (len1 + 1));
	for( i = 0; i <= len1; i++ )
		c[i] = (int *)malloc(sizeof(int) * (len2 + 1));
	
	for( i = 0; i <= len1; i++ )	//这里必须要把动态申请的二位数组清零，否则会有bug
		for( j = 0; j <= len2; j++ )
			c[i][j] = 0;

	for( i = 1; i <= len1; i++ )
		for( j = 1; j <= len2; j++ )
		{
			if( str1[i-1] == str2[j-1])
				c[i][j] = c[i-1][j-1] + 1;
			if( c[i][j] > len)
			{
				len = c[i][j];
				end = j;
			}
		}
	start = end - len + 1;
	printf("The number of Longest of continuous subsequence is : %d\n", len);
	printf("The longest of continuous subsequence is :");
	for( j = start; j <= end; j++)
		printf("%c ", str2[j-1]);
	printf("\n");

	for( i = 0; i <= len1; i++ )
		free(c[i]);
	free(c);
}

/**************************************************************
函数：void Find_conLCS1( char *longstr, char *shortstr)
		longstr:	待比较字符串1
		shotrstr:	待比较字符串2
返回值：无
打印值：输出最大公共子串长度以及最大公共子串
时间复杂度：O(mn)
空间复杂度：O(len(shortstr))
***************************************************************/
void Find_conLCS1( char *longstr, char *shortstr)
{
	int i, j;
	int len1 = strlen(longstr),
		len2 = strlen(shortstr);
	int len = 0, end = -1, start;

	int *c = (int *)malloc(sizeof(int) * (len2 + 1));
	
	for( i = 0; i <= len2; i++ )
		c[i] = 0;
	
	for( i = 0; i <= len1; i++)
		for( j = len2-1; j >= 0; j--)	//这里需要逆着对比，否则上一行的c[j-1]的值会被覆盖
		{
			if( longstr[i] == shortstr[j])
			{
				if( i == 0 || j == 0 )
					c[j] = 1;
				else c[j] = c[j-1] +1;
			}
			else c[j] = 0;
		
			if( c[j] > len)
			{
				len = c[j];
				end = j;
			}
		}

	start = end - len + 1;
	printf("The number of Longest of substring is : %d\n", len);
	printf("The longest of continuous subsequence is :");
	for( i = start; i <= end; i++ )
		printf("%c ", shortstr[i]);
	printf("\n");

	free(c);
}

/**************************************************************
函数：int Find_LIS( int *Array, int len)
		array:	待遍历的序列
		len:	待遍历序列的长度
返回值：最大递增子序列长度
打印值：输出最大递增子序列及其长度
时间复杂度：O(n^2)
空间复杂度：O(n)

输入这个：int arr2[]={-1,2,4,3,4,5,6,1,2,3,4,5,6,7,-7};
    		int n2=15;
还是会出现错误，待解决
int Find_LIS( int *Array, int len)
{
	int i,j;
	int count = 1, last = -1;
	int *lis = (int *)malloc(sizeof(int) * len);
	int *index = (int *)malloc(sizeof(int) * len);

	for( i = 0; i < len; i++)
	{
		lis[i] = 1;
		index[i] = 0;
	}

	for(i = 1; i < len; i++)
		for(j = 0; j < i; j++)
		{
			if( Array[i] > Array[j] && lis[j] + 1 >= lis[i])//满足这个条件的一定是当前的最长递增子序列
			{
				lis[i] = lis[j] + 1;
				if( lis[i] > count)	//后来加的
				{
					index[lis[j] - 1] = j; //用于查找最大递增子序列：lis[j]-1的原因是：用于数组下标时需要减1（从1开始到count）
					count = lis[j];
					last = i;	//记录最长递增子序列中的最大那个值  的索引值
				}
			}		
		}

	index[count++] = last;
	for(i = 0; i < len; i++)
		printf("%d ", lis[i]);
	printf("\n");
	for( i = 0; i< count; i++)
		printf("%d ", index[i]);
	
	printf("最大递增子序列为：");
	for( i = 0;i < count; i++)
		printf("%d ", Array[index[i]]);
	printf("\n");

	free(lis);
	free(index);
	return count;
}
***************************************************************/


/**************************************************************
函数：int Find_LIS( int *Array, int len)
		array:	待遍历的序列
		len:	待遍历序列的长度
返回值：最大递增子序列长度
打印值：输出最大递增子序列长度
时间复杂度：O(n^2)
空间复杂度：O(n)
***************************************************************/
int Find_LIS( int *Array, int len)
{
	int i, j, maxlen = 0;
	int *lis = (int *)malloc(sizeof(int) * len);
	
	for(i = 0; i < len; i++)
	{
		lis[i] = 1;
		for(j = 0; j < i; j++)
		{
			if( Array[i] > Array[j] && lis[j] + 1 > lis[i])//满足这个条件的一定是当前的最长递增子序列
				lis[i] = lis[j] + 1;
		}
		if( lis[i] > maxlen)
			maxlen = lis[i];
	}
	return maxlen;
}

/**************************************************************
函数：int BinSearch( int *Array, int len, int num)
		Array:	待插入的有序数组
		len:	有序数组的长度
		num:	待插入的数据
返回值：数据需要插入的位置
打印值：无
时间复杂度：O(lg N)
空间复杂度：O(n)
***************************************************************/
int BinSearch( int *Array, int len, int num)
{
	int low = 0, high = len - 1, mid;
	
	while(low <= high)
	{
		mid = low + ( high - low ) / 2;
		if(num == Array[mid])
			return mid;
		else if( num < Array[mid])
			high = mid - 1;
		else low = mid + 1;	
	}
	return low;
}

/**************************************************************
函数：int Find_LIS1( int *Array, int len)
		array:	待遍历的序列
		len:	待遍历序列的长度
返回值：最大递增子序列长度
打印值：输出最大递增子序列长度
时间复杂度：O(nlgn)
空间复杂度：O(n)
***************************************************************/
int Find_LIS1(int *Array, int len)
{
	int i, nMax = 0, pos;

	int *B = (int *)malloc(sizeof(int) * len);
	B[0] = Array[0];

	for( i = 1; i < len; i++)
	{
		if( Array[i] > B[nMax])
			B[++nMax] = Array[i];
		else //Array[i]小于或等于数组B中的元素
		{
			/***********************************************************************************************
			找出Array[i]需要插入的位置，如果Array[i]不再数组中，则会有B[pos] < Array[i] < B[pos+1]
			找出符合的pos，再姜B[pos]更新成Array[i]
			************************************************************************************************/
			pos = BinSearch(B, nMax, Array[i]);
												
			B[pos] = Array[i];
		}
	}

	return (nMax + 1); //数组B下标由0开始，计算个数时需要+1
}

int main()
{
	char x[10] = "abcdefghi";
	char y[10] = "bdeghibjk";
	int arr[]={100,-1,4,2,3,5,6,-7};
	//100, -1, 4, 2, 3, 5, 6, -7
    int n=8;
	int arr1[]={1,2,3,4,5,6,7,-1,2,4,3,4,5,6,-7};
    	int n1=15;
	int arr2[]={-1,2,4,3,4,5,6,1,2,3,4,5,6,7,-7};
    	int n2=15;

	printf("%d\n",Find_LIS(arr2,n2));
	Find_Lcs(x,y);
	Find_conLCS1(x,y);
	system("pause");
}