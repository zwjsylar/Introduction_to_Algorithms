#include <iostream>
#include "list.h"
#include "list.cpp"

using namespace std;

int main()
{
    List<int> MyList;
    int nSelected;
    bool IsQuit =  false;
    while(!IsQuit)
    {
        cout << "请输入链表操作指令: " << endl;
        cout << "1. 打印链表节点数 " << endl;
        cout << "2. 打印链表所有节点数据 " << endl;
        cout << "3. 在指定ID的节点后插入一个新节点 " << endl;
        cout << "4. 删除指定的数据 " << endl;
        cout << "5. 在链表最后插入一个新节点" << endl;
        cout << "6. 清空链表" << endl;
        cout << "7. 链表排序" << endl;
        cout << "8. 退出 " << endl;

        cin >> nSelected;
        switch(nSelected)
        {
        case 1:
            cout << "链表当前长度为：" << endl;
            cout << MyList.Length() << endl;
            break;
        case 2:
            cout << "链表当前数据为：" << endl;
            for(int i = 1; i <= MyList.Length(); i++)
            {
                cout << MyList.FindPosition(i) << " ";
            }
            cout << endl;
            break;
        case 3:
            cout << "请输入需要插入的位置：" << endl;
            int new_position;
            cin >> new_position;

            cout << "请输入需要插入的数据：" << endl;
            int new_data;
            cin >> new_data;

            MyList.Insert(new_data, new_position);
            break;
        case 4:
            cout << "请输入删除的数据：" << endl;
            int del_data;
            cin >> del_data;

            MyList.Delete(del_data);
            break;
        case 5:
            cout << "请输入需要在链表末尾添加的数据：" << endl;
            int append_data;
            cin >> append_data;

            MyList.Append(append_data);
            break;
        case 6:
            cout << "清空链表" << endl;
            MyList.MakeEmpty();
            break;
        case 7:
            cout << "链表排序" << endl;
            MyList.ListSort();
            break;
        case 8:
            IsQuit = true;
            break;
        default:
            cout << "此操作无效，请重新选择！" <<endl;
            break;
        }
    }
    return 0;
}
