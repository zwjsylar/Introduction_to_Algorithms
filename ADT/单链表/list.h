#ifndef __LIST_H__
#define __LIST_H__

#include <stdlib.h>


template <class T>
struct Node
{
    T Element;
    Node<T> *next;
};

template <class T>
class List
{

private:
    Node<T> *head= new Node<T>;
    int length;

public:
    List();
    void MakeEmpty();
    bool IsEmpty();
    int Length();
    bool Insert(T element, int position);
    bool Delete(T element);
    int FindElement(T element);
    T FindPosition(int position);
    bool Append(T element);
    void ListSort();
    ~List();
};


#endif // __LIST_H__
