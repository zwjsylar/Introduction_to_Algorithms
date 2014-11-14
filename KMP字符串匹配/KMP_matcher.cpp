/**********************************************************************
KMP字符串匹配：
	函数：void KMP_Matcher(const char* T, const char *P)
	作用：在字符串T中匹配字符串P，并输出匹配位置
		时间复杂度：O(n) + O(m) n为字符串T的长度 m为字符串P的长度
		空间复杂度：O(m)
KMP字符串预处理：
	函数：void KMP_GetNext(const char *P, int *next)
	作用：KMP字符串预处理，将字符串P预处理的结果储存在数组next中	
		时间复杂度：O(m)
		空间复杂度：O(m)
************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**********************************************************************
KMP字符串预处理：
	函数：void KMP_GetNext(const char *P, int *next)
		P:		待处理的字符串
		next:	储存预处理结果的数组
	返回值：	无
	打印值：	无
	时间复杂度：O(m)
	空间复杂度：O(n)
************************************************************************/
void KMP_GetNext(const char *P, int *next)
{
	int m = strlen(P);
	/*
		由于数组下标变化，KMP算法里字符串匹配的下标是从1开始，而数组的下标从0开始，就需要next[1]=0变成next[0]=-1;
		相应的k的值也需要变化
	*/
	next[0] = -1;
	int k = -1;

	for(int q = 1; q < m; q++)
	{
		while(k > -1 && P[k+1] != P[q])
			k = next[k];
		if(P[k+1] == P[q])
			k += 1;
		next[q] = k;
	}
}

/**********************************************************************
KMP字符串预处理：
	函数：void KMP_Matcher(const char* T, const char *P)
		T:		待匹配的字符串
		P：		匹配的字符串
	返回值：	无
	打印值：	打印出next数组；打印出字符串的匹配位置
	时间复杂度：O(n) + O(m)
	空间复杂度：O(m)
************************************************************************/
void KMP_Matcher(const char* T, const char *P)
{
	int n = strlen(T);
	int m = strlen(P);

	int *next = (int *)malloc(sizeof(int) * m);

	KMP_GetNext(P, next);

	for( int i = 0; i < m; i++)
		printf("%d ", next[i]);
	printf("\n");

	int q = -1;
	for( int i = 0; i < n; i++)
	{
		while(q > -1 && P[q+1] != T[i])
			q = next[q];

		if(P[q+1] == T[i]) 
			q += 1;

		if(q + 1== m) //由于数组下标的变化，q的值会比m小1
		{
			printf("Success.\nPattern occurs with shift: %d\n", i - m);
			q = next[q];
		}
	}
}

int main()
{
	char *A = "bacbababababca";
	char *B = "ababababca";
	KMP_Matcher(A, B);
	system("pause");
	return 0;
}