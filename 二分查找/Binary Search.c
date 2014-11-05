/**********************************************************************
二分查找(循环实现)：

	函数：int BinSearch( int *Array, int len, int num)
	作用：返回数据在待查找数组的索引号（数据不在数组中则返回-1)	
		时间复杂度：O(lgn)
		空间复杂度：O(n)

二分查找(递归实现)：
	函数：int Binsearch1( int *Array, int len, int num)
	作用：返回数据在待查找数组的索引号（数据不在数组中则返回-1)	
		时间复杂度：O(lgn)
		空间复杂度：O(n)
************************************************************************/
#include <stdio.h>
#include <stdlib.h>

/**********************************************************************
二分查找：(循环实现)

	函数：int BinSearch( int *Array, int len, int num)
		Array:	待查找的有序数组
		len:	数组的长度
		num；	待查找的数据
	返回值：	返回待查找数据的索引号（若不在数组中，则返回-1）
	打印值：	无
	时间复杂度：O(lgn)
	空间复杂度：O(n)
************************************************************************/
int BinSearch( int *Array, int len, int num)
{
	int low = 0, high = len - 1;
	int mid;
	while( low <= high)
	{
		mid = low + (high - low) / 2;
		if( Array[mid] == num)
			return mid;
		else if( Array[mid] > num)
			high = mid - 1;
		else low = mid + 1;
	}
	return -1;
}

/**********************************************************************
二分查找：(递归实现)

	函数：int Binsearch1( int *Array, int len, int num)
		Array:	待查找的有序数组
		len:	数组的长度
		num；	待查找的数据
	返回值：	返回待查找数据的索引号（若不在数组中，则返回-1）
	打印值：	无	
	时间复杂度：O(lgn)
	空间复杂度：O(n)
************************************************************************/
int BinSearch1( int *Array, int low, int high, int num)
{
	if( low > high)
		return -1;
	int mid = low + (high - low) / 2;
	if( Array[mid] == num)
		return mid;
	else if( Array[mid] > num)
		return BinSearch1(Array, low, mid - 1, num);
	else return BinSearch1(Array, mid + 1, high, num);
}

int main()
{
	printf("hello world\n");
	int Arr[] = {1, 2, 3, 4, 5, 6, 7, 8};
	printf("%d\n", BinSearch1(Arr, 0, 7, 9));
	system("pause");
	return 0;
}