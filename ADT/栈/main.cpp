#include <iostream>
#include "stack.h"
#include "stack.cpp"

using namespace std;

int main()
{
    Stack<int> MyStack;
    int nSelected;
    bool IsQuit =  false;
    while(!IsQuit)
    {
        cout << "请输入栈操作指令: " << endl;
        cout << "1. 打印栈长度 " << endl;
        cout << "2. 入栈操作 " << endl;
        cout << "3. 出栈操作 " << endl;
        cout << "4. 清空栈" << endl;
        cout << "5. 取出栈顶元素" << endl;
        cout << "6. 退出 " << endl;

        cin >> nSelected;
        switch(nSelected)
        {
        case 1:
            cout << "栈当前长度为：" << endl;
            cout << MyStack.Length() << endl;
            break;
        case 2:
            cout << "请输入需要插入的数据：" << endl;
            int new_data;
            cin >> new_data;

            MyStack.Push(new_data);
            break;
        case 3:
            cout << "出栈" << endl;
            cout << "出栈数据为：" << MyStack.Pop() << endl;
            break;
        case 4:
            cout << "清空栈" << endl;
            MyStack.MakeEmpty();
            break;
        case 5:
            cout << "取出栈顶元素" << endl;
            cout << "栈顶元素为：" << MyStack.Top() << endl;
            break;
        case 6:
            IsQuit = true;
            break;
        default:
            cout << "此操作无效，请重新选择！" <<endl;
            break;
        }
    }
    return 0;
}
