//
// Created by root on 6/7/24.
//

#ifndef LINKEDLIST_TEMPLATELINKEDLIST_H
#define LINKEDLIST_TEMPLATELINKEDLIST_H

#include <iostream>

template<typename T>
struct Node
{
    T data;
    Node *next{nullptr};
};

template<typename T>
class TemplateLinkedList {
    Node<T> *head;
public:
    explicit TemplateLinkedList();
    void addAtBeginning(T);
    void addAtGiven(T element, T pos);
    void addToList(T);
    void removeAtBeginning();
    void removeAtGiven(T pos);
    void removeFromEnd();
    void traverseList();
};

template <typename T>
TemplateLinkedList<T>::TemplateLinkedList() {
    head = nullptr;
}

template<typename T>
void TemplateLinkedList<T>::addAtBeginning(T element) {
    auto *newNode = new Node<T>;
    newNode->data = element;
    newNode->next = head;
    head = newNode;
}

template<typename T>
void TemplateLinkedList<T>::addAtGiven(T element, T pos) {
    if(head == nullptr)
        std::cout << "LIST IS EMPTY" << std::endl;
    else
    {   auto *newNode = new Node<T>;
        newNode->data = element;
        Node<T> *current = head;
        while(current->next != nullptr || current->data == pos)
        {
             if(current->data == pos)
             {
                newNode->next = current->next;
                current->next = newNode;
                return;
             }
             current = current->next;
        }
        std::cout << "ELEMENT NOT FOUND" << std::endl;
    }
}

template<typename T>
void TemplateLinkedList<T>::removeAtBeginning() {
    if(head == nullptr)
        std::cout << "LIST IS ALREADY EMPTY" << std::endl;
    else
    {
        Node<T> *current = head;
        head = current->next;
        delete current;
    }
}

template<typename T>
void TemplateLinkedList<T>::removeAtGiven(T pos) {
    if (head == nullptr)
        std::cout << "LIST IS ALREADY EMPTY" << std::endl;
    else {
        Node<T> *current = head;
        Node<T> *prev;
        while(current->next != nullptr || current->data == pos)
        {
            if(current->data == pos)
            {
                if(head == current)
                    head = current->next;
                else
                    prev->next = current->next;
                delete current;
                return;
            }
            prev = current;
            current = current->next;
        }
    }
}

template<typename T>
void TemplateLinkedList<T>::addToList(T element) {
    auto *newData = new Node<T>;
    newData->data = element;

    if(head == nullptr)
        head = newData;
    else
    {
        Node<T> *current = head;
        while(current->next != nullptr)
            current = current->next;
        current->next = newData;
    }
}

template<typename T>
void TemplateLinkedList<T>::removeFromEnd() {
    if(head == nullptr)
        std::cout << "EMPTY LIST" << std::endl;
    else
    {
        Node<T> *current = head;
        Node<T> *prev;
        while(current->next != nullptr)
        {
            prev = current;
            current = current->next;
        }
        std::cout << "DELETED ELEMENT: " << current->data << std::endl;
        prev->next = nullptr;
        delete current;
    }
}

template<typename T>
void TemplateLinkedList<T>::traverseList() {
    if(head == nullptr)
        std::cout << "EMPTY LIST" << std::endl;
    else
    {
        Node<T> *current = head;
        while (current->next != nullptr) {
            std::cout << current->data << " ";
            current = current->next;
        }
        std::cout << current->data << std::endl;
    }
}


#endif //LINKEDLIST_TEMPLATELINKEDLIST_H
