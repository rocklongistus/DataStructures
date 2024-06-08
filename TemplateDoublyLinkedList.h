//
// Created by root on 6/8/24.
//

#ifndef DOUBLYLINKEDLIST_TEMPLATEDOUBLYLINKEDLIST_H
#define DOUBLYLINKEDLIST_TEMPLATEDOUBLYLINKEDLIST_H

#include <iostream>

template<typename T>
struct Node
{
    T data;
    Node<T> *prev;
    Node<T> *next;
};

template<typename T>
class TemplateDoublyLinkedList {
    Node<T> *head;
public:
    void addAtBeginning(T);
    void addAtGiven(T element, T pos);
    void addToList(T);
    void removeAtBeginning();
    void removeAtGiven(T pos);
    void removeFromEnd();
    void traverseList();
};

template<typename T>
void TemplateDoublyLinkedList<T>::addAtBeginning(T element) {
    auto *newNode = new Node<T>;
    newNode->data = element;
    if(head == nullptr)
    {
        newNode->next = nullptr;
        newNode->prev = head;
        head = newNode;
    }
    else
    {
        Node<T> *current = head;
        newNode->prev = head;
        newNode->next = current;
        current->prev = newNode;
        head = newNode;
    }
}

template<typename T>
void TemplateDoublyLinkedList<T>::addToList(T element) {
    auto *newNode = new Node<T>;
    newNode->data = element;
    if(head == nullptr)
    {
        head = newNode;
        newNode->prev = head;
        newNode->next == nullptr;
    }
    else
    {
        Node<T> *current = head;
        while(current->next != nullptr)
            current = current->next;
        current->next = newNode;
        newNode->prev = current;
        newNode->next = nullptr;
    }
}

template<typename T>
void TemplateDoublyLinkedList<T>::addAtGiven(T element, T pos) {
    if(head == nullptr)
        std::cout << "AddAtGiven::LIST IS EMPTY" << std::endl;
    else
    {
        Node<T> *current = head;
        while(current->next != nullptr || current->data == pos )
        {
            if(current->data == pos)
            {
                auto *newNode = new Node<T>;
                newNode->data = element;
                if(head == current)
                {
                    newNode->next = current;
                    newNode->prev = head;
                    current->prev = newNode;
                    head = newNode;
                }
                else
                {
                    newNode->next = current->next;
                    current->next->prev = newNode;
                    current->next = newNode;
                    newNode->prev = current;
                }
                return;
            }
            current = current->next;
        }
        std::cout << "ELEMENT NOT FOUND" << std::endl;
    }
}

template<typename T>
void TemplateDoublyLinkedList<T>::removeAtBeginning(){
    if(head == nullptr)
        std::cout << "RemoveBeg::LIST ALREADY EMPTY" << std::endl;
    else
    {
        Node<T> *current = head;
        if(current->next != nullptr)
            current->next->prev = head;
        head = current->next;
        std::cout << "RemoveBeg::DELETED ELEMENT: " << current->data << std::endl;
        delete current;
    }
}

template<typename T>
void TemplateDoublyLinkedList<T>::removeAtGiven(T pos) {
    if(head == nullptr)
        std::cout << "RemoveAtGiven::LIST ALREADY EMPTY" << std::endl;
    else
    {
        Node<T> *current = head;
        while(current->next != nullptr || current->data == pos)
        {
            if(current->data == pos)
            {
                current->next->prev = current->prev;
                if(current == head)
                    head = current->next;
                else
                    current->prev->next = current->next;
                std::cout << "RemoveAtGiven::DELETED ELEMENT: " << current->data << std::endl;
                delete current;
                return;
            }
            current = current->next;
        }
        std::cout << "RemoveAtGiven::ELEMENT NOT FOUND" << std::endl;
    }
}

template<typename T>
void TemplateDoublyLinkedList<T>::removeFromEnd() {
    if(head == nullptr)
        std::cout << "RemoveEnd::LIST ALREADY EMPTY" << std::endl;
    else
    {
        Node<T> *current = head;
        while(current->next != nullptr)
            current = current->next;
        std::cout << "RemoveEnd::DELETED ELEMENT: " << current->data << std::endl;
        if(current == head)
            head = nullptr;
        else
            current->prev->next = nullptr;
        delete current;
    }
}

template<typename T>
void TemplateDoublyLinkedList<T>::traverseList() {
    if(head == nullptr)
        std::cout << "Traversal::LIST IS EMPTY" << std::endl;
    else
    {
        Node<T> *current = head;
        while(current->next != nullptr)
        {
            std::cout << current->data << "->";
            current = current->next;
        }
        std::cout << current->data << std::endl;

        while(current->prev != head)
        {
            std::cout << current->data << "->";
            current = current->prev;
        }
        std::cout << current->data << "->";
        std::cout << current->prev->data << std::endl;
    }
    std::cout << std::endl;
}


#endif //DOUBLYLINKEDLIST_TEMPLATEDOUBLYLINKEDLIST_H
