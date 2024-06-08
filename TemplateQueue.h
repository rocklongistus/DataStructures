//
// Created by root on 6/7/24.
//

#ifndef TEMPLATEQUEUE_TEMPLATEQUEUE_H
#define TEMPLATEQUEUE_TEMPLATEQUEUE_H

#include <iostream>

template<typename T>
class TemplateQueue {
    T *data;
    int front{}, rear{};
    size_t MAX{};
public:
    explicit TemplateQueue(size_t);
    void enqueue(T);
    T dequeue();
    bool isFull();
    bool isEmpty();
    void display();
};

template<typename T>
TemplateQueue<T>::TemplateQueue(size_t size) : MAX(size) {
    front = -1;
    rear = -1;
    data = new T[MAX];
}

template<typename T>
void TemplateQueue<T>::enqueue(T element) {
    if(isFull())
    {
        std::cout << "OVERFLOW" << std::endl;
    }
    else if(isEmpty())
    {
        front = rear = 0;
        data[rear] = element;
        std::cout << "data[" << rear << "] = " << data[rear] << std::endl;
    }
    else {
        data[++rear] = element;
        std::cout << "data[" << rear << "] = " << data[rear] << std::endl;
    }
}

template<typename T>
T TemplateQueue<T>::dequeue() {
    if(isEmpty())
    {
        std::cout << "UNDERFLOW" << std::endl;
        return -1;
    }
    else
    {
        int val = data[front];
        front++;
        if(front > rear)
            front = rear = -1;
        return val;
    }
}

template<typename T>
bool TemplateQueue<T>::isFull() {
    if(rear == MAX - 1)
        return true;
    else return false;
}

template<typename T>
bool TemplateQueue<T>::isEmpty() {
    if(front == -1 && rear == -1)
        return true;
    else return false;
}

template<typename T>
void TemplateQueue<T>::display() {
    if(!isEmpty())
    {
        for (int i = front; i <= rear; ++i)
            std::cout << data[i] << " ";
        std::cout << std::endl;
    }
}

#endif //TEMPLATEQUEUE_TEMPLATEQUEUE_H
