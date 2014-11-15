/**********************************************************************
快速排序：
	函数：void QuickSort(int Array[], int low, int high)
	作用：对数组Array排序
		时间复杂度：O(nlgn)
		空间复杂度：O(1)

随机化快速排序：
	函数：void RandomQuickSort(int Array[], int low, int high)
	作用：对数组Array排序
		时间复杂度：O(nlgn)
		空间复杂度：O(1)

插入排序：
	函数：void InsertSort(int Array[], int low, int high)
	作用：对数组Array排序
		时间复杂度：O(n^2)
		空间复杂度：O(1)

冒泡排序：
	函数：void BubbleSort(int Array[], int low, int high)
	作用：对数组Array排序
		时间复杂度：O(n^2)
		空间复杂度：O(1)

最大堆调整：
	函数：void HeapAdjust(int Array[], int i, int nLength)
	作用：对数组Array排序
		时间复杂度：O(lgn)
		空间复杂度：O(1)

堆排序：
	函数：void HeapSort(int Array[], int length)
	作用：对数组Array排序
		时间复杂度：O(nlgn)
		空间复杂度：O(1)

希尔排序：
	函数：void ShellSort(int Array[], int length)
	作用：对数组Array排序
		时间复杂度：O(n^2)
		空间复杂度：O(1)
************************************************************************/

#include <iostream>
#include <cstdlib>
#include <ctime>

#define SWAP(a,b) {int temp = a; a = b; b = temp;}

using namespace std;

/**********************************************************************
交换两个整形数据（引用实现）：
	函数：void Swap( int &a, int &b)
		a:	待交换的数据
		b:	待交换的数据
	返回值：	无
	打印值：	无
	时间复杂度：O(1)
	空间复杂度：O(1)
************************************************************************/
void Swap( int &a, int &b)
{
    int temp = a;

    a = b;

    b = temp;
}

/**********************************************************************
交换两个整形数据（指针实现）：
	函数：void SWap( int &a, int &b)
		a:	待交换的数据
		b:	待交换的数据
	返回值：	无
	打印值：	无
	时间复杂度：O(1)
	空间复杂度：O(1)
************************************************************************/
void SWap( int *a, int *b)
{
    int temp = *a;

    *a = *b;

    *b = temp;
}

/**********************************************************************
快速排序：
	函数：void QuickSort(int Array[], int low, int high)
		Array:	待排序的数组
		low:	数组的起始位置
		high:	数组的结束位置
	返回值：	无
	打印值：	无
	时间复杂度：O(nlgn)
	空间复杂度：O(1)
************************************************************************/
void QuickSort(int Array[], int low, int high) //快速排序
{
    if( low >= high)

        return ;

    int first = low;

    int last = high;

    int key = Array[first];

    while(first < last)
    {
        while( Array[last] >= key && first < last) last--;

        Array[first] = Array[last];

        while( Array[first] <= key && first < last) first++;

        Array[last] = Array[first];
    }

    Array[first] = key;

    QuickSort(Array, low, first - 1);

    QuickSort(Array, last + 1, high);

}

/**********************************************************************
随机化快速排序：
	函数：void RandomQuickSort(int Array[], int low, int high)
		Array:	待排序的数组
		low:	数组的起始位置
		high:	数组的结束位置
	返回值：	无
	打印值：	无
	时间复杂度：O(nlgn)
	空间复杂度：O(1)
************************************************************************/
void RandomQuickSort(int Array[], int low, int high) //随机化快速排序
{
    if( low >= high)

        return;

    srand(time(0));

    int index = rand() % (high - low) + low;

    int Temp = Array[index];

    Array[index] = Array[high];

    Array[high] = Temp;

    int first = low;

    int last = high;

    int key = Array[last];

    while( first < last)
    {
        while( Array[first] <= key && first < last) first++;

        Array[last] = Array[first];

        while( Array[last] >= key && first < last) last--;

        Array[first] = Array[last];
    }

    Array[first] = key;

    RandomQuickSort(Array, low, first - 1);

    RandomQuickSort(Array, last + 1, high);
}

/**********************************************************************
插入排序：
	函数：void InsertSort(int Array[], int low, int high)
		Array:	待排序的数组
		low:	数组的起始位置
		high:	数组的结束位置
	返回值：	无
	打印值：	无
	时间复杂度：O(n^2)
	空间复杂度：O(1)
************************************************************************/
void InsertSort(int Array[], int low, int high) //插入排序
{
    int key;

    int i, j;

    for( j = 1; j <= high; j++)
    {
        key = Array[j];

        i = j - 1;

        while( i >= 0 && Array[i] >= key )
            {
                Array[i+1] = Array[i];

                i--;
            }
        Array[i+1] = key;
    }
}

/**********************************************************************
冒泡排序：
	函数：void BubbleSort(int Array[], int low, int high)
		Array:	待排序的数组
		low:	数组的起始位置
		high:	数组的结束位置
	返回值：	无
	打印值：	无
	时间复杂度：O(n^2)
	空间复杂度：O(1)
************************************************************************/
void BubbleSort(int Array[], int low, int high) //冒泡排序
{
    int i, j;

    for( i = 0; i <= high; i++)

        for( j = high; j >= i+1; j--)
        {
            if(Array[j] < Array[j-1])
            {
                int temp = Array[j];

                Array[j] = Array[j-1];

                Array[j-1] = temp;
            }
        }
}

/**********************************************************************
最大堆调整：
	函数：void HeapAdjust(int Array[], int i, int nLength)
		Array:		待排序的数组
		i:			根节点在数组的序号
		nlength:	数组的长度
	返回值：	无
	打印值：	无
	时间复杂度：O(lgn)
	空间复杂度：O(1)
************************************************************************/
void HeapAdjust(int Array[], int i, int nLength) //最大堆堆调整
{
    int nChild;

    int nTemp;

    for( ; 2 * i + 1 < nLength; i = nChild)
    {
        nChild = 2 * i + 1; //父节点位置为i，则子节点的位置为2*i + 1(这里是按照数组下标，首个位置下标为0)

        //得到子节点中较大的结点
        if(nChild < nLength - 1 && Array[nChild+1] > Array[nChild])

            nChild++;

        //如果较大的结点大于父结点，那么将较大的子节点往上移动，替换它的父结点
        if(Array[i] < Array[nChild])
        {
            nTemp = Array[i];

            Array[i] = Array[nChild];

            Array[nChild] = nTemp;
        }
        else break;//否则退出循环
    }
}

/**********************************************************************
堆排序：
	函数：void HeapSort(int Array[], int length)
		Array:	待排序的数组
		length:	数组的长度
	返回值：	无
	打印值：	无
	时间复杂度：O(nlgn)
	空间复杂度：O(1)
************************************************************************/
void HeapSort(int Array[], int length) //堆排序
{
    int tmp;
    //调整序列的前半部分元素，调整完之后第一个元素是序列的最大的元素
    //length/2-1是最后一个非叶节点，此处"/"为整除
    for( int i = length/2 - 1; i >= 0; i--)

        HeapAdjust(Array, i, length);

    for( int i = length - 1; i > 0; i--)
    {
        //把第一个元素和当前的最后一个元素交换
        //保证当前的最后一个位置的元素都是现在这个序列之中最大的
        tmp = Array[i];

        Array[i] = Array[0];

        Array[0] = tmp;
        //不断缩小调整Heap的范围，每一次调整完毕保证第一个元素是当前序列的最大值
        HeapAdjust(Array, 0, i);
    }
}

/**********************************************************************
希尔排序：
	函数：void ShellSort(int Array[], int length)
		Array:	待排序的数组
		length:	数组的长度
	返回值：	无
	打印值：	无
	时间复杂度：O(nlgn)
	空间复杂度：O(1)
************************************************************************/
void ShellSort(int Array[], int length) //希尔排序
{
    int d = length/2;

    int i,j;

    int temp;

    while(d >= 1)
    {
        for(i = d; i < length; i++)
        {
            temp = Array[i];

            j = i - d;

            while( j >= 0 && Array[j] > temp)
            {
                Array[j + d] = Array[j];

                j = j - d;
            }
            Array[j + d] = temp;
        }
        d /= 2;
    }
}

int
main()
{
    int TempArray[10] = {12, 3, 45, 1, 43, 98, 2, 122, 1, 45};

//    cout << "Please input ten numbers:\n";
//
//    for( int i = 0; i < 10; i++)
//    cin >> TempArray[i];

    //QuickSort(TempArray, 0, 9);

    //InsertSort(TempArray, 0, 9);

    //BubbleSort(TempArray, 0, 9);

    //HeapSort(TempArray, 10);

    //RandomQuickSort(TempArray, 0, 9);

    ShellSort(TempArray, 10);

    cout << "After sort:\n";

    for( int i = 0; i < 10; i++)
        cout << TempArray[i] << " ";

	system("pause");
    return 0;
}
