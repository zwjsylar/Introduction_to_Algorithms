#include "stack.h"

template <class T>
Stack<T>::Stack()
{
    head->Element = 0;
    head->next = NULL;
    top = head;
    length = 0;
}

template <class T>
bool Stack<T>::IsEmpty()
{
    if( top->next == NULL)
        return true;
    else return false;
}

template <class T>
bool Stack<T>::MakeEmpty()
{
    if(head->next == NULL)
        return true;

    Node<T> *p;
    while(head->next != NULL)
    {
        p = head->next;
        delete head;
        length--;
        head = p;
    }
    top = NULL;
}

template <class T>
void Stack<T>::Push(T element)
{
    Node<T> *new_node = new Node<T>;
    if( new_node == NULL)
        return;
    new_node->Element = element;

    top = head;
    while(top->next != NULL)
        top = top->next;

    new_node->next = top->next;
    top->next = new_node;
    length++;
}

template <class T>
T Stack<T>::Pop()
{
    T element;
    Node<T>* temp_node;
    top = head;
    if(top->next == NULL)
        return -1;
    while(top->next->next != NULL)
        top = top->next;

    temp_node = top->next;
    top->next = top->next->next;

    element = temp_node->Element;
    delete(temp_node);
    length--;
    return element;
}

template <class T>
int Stack<T>::Length()
{
    return length;
}

template <class T>
T Stack<T>::Top()
{
    top = head;
    while(top->next != NULL)
        top = top->next;
    if(top != head)
        return top->Element;
    else return -1;
}

template <class T>
Stack<T>::~Stack()
{
    Node<T> *p;
    if( head == NULL)
        return;
    while(head != NULL)
    {
        p = head->next;
        delete head;
        length--;
        head = p;
    }
    top = NULL;
}
