#ifndef __STACK_H__
#define __STACK_H__

#include <stdlib.h>

template <class T>
struct Node{
    T Element;
    Node<T> *next;
};

template <class T>
class Stack{
private:
    Node<T> *head =  new Node<T>;
    Node<T> *top;
    int length;
    Node<T>* top_node();

public:
    Stack();
    bool IsEmpty();
    bool MakeEmpty();
    void Push(T element);
    T Top();
    T Pop();
    int Length();
    ~Stack();
};
#endif // __STACK_H__
