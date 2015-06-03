#include "list.h"

template <class T>
List<T>::List()
{
    head->Element = 0;
    head->next = NULL;
    length = 0;
}

template <class T>
void List<T>::MakeEmpty()
{
    Node<T> *p;
    if( head->next == NULL)
        return;
    while( head->next != NULL)
    {
        p = head->next;
        delete head;
        length--;
        head = p;
        head->Element = 0;
    }
}

template <class T>
bool List<T>::IsEmpty()
{
    if( head == NULL)
        return true;
    else return false;
}

template <class T>
int List<T>::Length()
{
    return length;
}

template <class T>
bool List<T>::Insert(T element, int position)
{
    if( position > length || position < 0)
        return false;

    Node<T> *p;
    p = head;

    while(position > 0)
    {
        p = p->next;
        position--;
    }

    Node<T> *new_node = new Node<T>;
    if( new_node == NULL)
        return false;

    new_node->Element = element;
    new_node->next = p->next;
    p->next = new_node;

    length++;
    return true;
}

template <class T>
bool List<T>::Delete(T element)
{
    Node<T> *p, *temp_node;
    p = head;

    if(head->next == NULL)
        return false;

    while(p->next->next != NULL && p->next->Element != element)
    {
        p = p->next;
    }

    if(p->next->next == NULL && p->next->Element != element)
        return false;

    temp_node = p->next;
    p->next = temp_node->next;
    delete temp_node;

    length--;
    return true;
}

template <class T>
int List<T>::FindElement(T element)
{
    Node<T> *p;
    int temp_count = 1;
    p = head->next;

    while(p != NULL && p->Element != element)
    {
        p = p->next;
        temp_count++;
    }

    if(p == NULL)
        return -1;

    return temp_count;
}

template <class T>
T List<T>::FindPosition(int position)
{
    if(position > length || position <= 0)
        return -1;

    Node<T> *p;
    p = head;

    for( int i = 1; i <= position; i++)
        p = p->next;

    return p->Element;
}

template <class T>
bool List<T>::Append(T element)
{
    Node<T> *p = head;
    for( int i = 1; i <= length; i++)
    {
        p = p->next;
    }
    Node<T> *new_node = new Node<T>;

    if(new_node == NULL)
        return false;

    p->next = new_node;
    new_node->Element = element;
    new_node->next = NULL;
    length++;
    return true;
}

template <class T>
void List<T>::ListSort()
{
    Node<T> *tail, *p;

    if( head->next == NULL || head->next->next == NULL )
        return;

    p = head;
    tail = NULL;
    while(head->next->next != tail)
    {
        p = head;
        while(p->next->next != tail)
        {
            if( p->next->Element > p->next->next->Element)
            {
                Node<T> *temp_node;
                temp_node = p->next;
                p->next = temp_node->next;
                temp_node->next = p->next->next;
                p->next->next = temp_node;
            }
            p = p->next;
        }
        tail = p->next;
    }
}

template <class T>
List<T>::~List()
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
}
