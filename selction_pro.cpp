#include <iostream>
#include <cstdlib>
#include <ctime>

#define SWAP(a,b) { int TEMP = a; a = b; b = TEMP; }

using namespace std;

int RandomIzed_Select(int Array[], int low, int high, int i)
{
    if(low == high)

        return Array[low];

    if(i > high - low + 1 || i <= 0)

        return -1;

    srand(time(0));

    int index = rand() % (high - low) + low;

    SWAP(Array[index], Array[high]);

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

    int k = first - low + 1;

    if(i == k)

        return Array[first];

    else if(i < k)

        return RandomIzed_Select(Array, low, first - 1, i);

    else return RandomIzed_Select(Array, last + 1, high, i - k);

}

int main()
{
    int TempArray[10] = {4, 5, 7, 1, 3, 2, 6, 8, 9, 0};

    int Index;


    while( (cout << "请输入需要数组中第几小的数据：",cin >> Index) )
    {
        int TempData = RandomIzed_Select(TempArray, 0, 9, Index);

        cout << "数组中第" << Index << "小的数据为" << TempData << endl;

        cout << "数组为：" << endl;

        for( int i = 0; i < 10; i++)

            cout << TempArray[i] << " ";

        cout << endl;
    }

    return 0;
}
