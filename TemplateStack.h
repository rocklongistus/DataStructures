//
// Created by root on 6/7/24.
//

#ifndef STACK_TEMPLATESTACK_H
#define STACK_TEMPLATESTACK_H

#include <cstdio>
#include <iostream>

template<typename T>
class TemplateStack {
    T *data;
    size_t SIZE{};
    int top{};
public:
    explicit TemplateStack(size_t);
    void push(T);
    void pop();
    void peek();
    bool isFull();
    bool isEmpty();
    void display();
};

template<typename T>
TemplateStack<T>::TemplateStack(size_t size) : SIZE(size){
    data = new T[SIZE];
    top = -1;
}

template<typename T>
void TemplateStack<T>::push(T element) {
    if(isFull())
        std::cout << "STACK IS FULL, CANNOT INSERT" << std::endl;
    else
    {
        data[++top] = element;
        std::cout << "PUSHED ELEMENT IS : " << data[top] << " Index : " << top <<std::endl;
    }
}

template<typename T>
void TemplateStack<T>::pop() {
    if(isEmpty())
        std::cout << "STACK IS ALREADY EMPTY" << std::endl;
    else
    {
        std::cout << "POPPED ELEMENT " << data[top] << std::endl;
        top--;
    }
}

template<typename T>
void TemplateStack<T>::display() {
    if(top == -1)
        std::cout << "STACK IS EMPTY" << std::endl;
    else
    {
        for(size_t i = 0; i <= top; i++)
            std::cout << data[i] << " ";
        std::cout << std::endl;
    }
}

template<typename T>
bool TemplateStack<T>::isFull() {
    if(top == SIZE - 1)
        return true;
    else
        return false;
}

template<typename T>
void TemplateStack<T>::peek() {
    if(!isEmpty())
        std::cout << "TOP ELEMENT IS: " << data[top] << std::endl;
}

template<typename T>
bool TemplateStack<T>::isEmpty(){
    if(top == -1)
        return true;
    else
        return false;
}


#endif //STACK_TEMPLATESTACK_H
