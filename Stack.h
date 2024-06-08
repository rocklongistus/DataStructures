//
// Created by drahul on 28-12-2023.
//

#ifndef TEMPLATESTACK_STACK_H
#define TEMPLATESTACK_STACK_H

#include <cstddef>
#include <cstdint>
#include <iostream>
#include <exception>

class StackException : public std::exception {
private:
    std::string _m_msg;
public:
    explicit StackException(std::string msg) : _m_msg(std::move(msg)) {}

    const char *what() const noexcept override {
        return std::string("StackException::").append(_m_msg).c_str();
    }
};

template<typename T>
class Stack {
private:
    T *_m_data;
    size_t _m_size;
    int64_t _m_top;

public:
    explicit Stack(size_t size) : _m_size(size) {
        _m_data = new T[size];
        _m_top = -1;
        std::cout << "Stack with size " << size << " created" << std::endl;
    }

    ~Stack() {
        if (_m_data != nullptr)
            delete _m_data;
        std::cout << "~Stack:: Deleted" << std::endl;
    }

    size_t capacity() const { return _m_size; }

    size_t size() const { return static_cast<size_t>(_m_top + 1); }

    bool isEmpty() const {
        return _m_top == -1;
    }

    bool isFull() const {
        return _m_top == _m_size - 1;
    }

    T top() const {
        if (isEmpty()) throw StackException("TOP::Empty Stack");
        return _m_data[_m_top];
    }

    void push(T element) {
        if (isFull()) throw StackException("PUSH::Stack is Full");
        _m_data[++_m_top] = element;
        std::cout << "Stack::Push " << element << std::endl;
    }

    void pop() {
        if (isEmpty()) throw StackException("POP::Empty Stack");
        --_m_top;
        std::cout << "Stack::Pop " << _m_data[_m_top + 1] << std::endl;
    }

    void display() {
        if (isEmpty()) throw StackException("display::Empty Stack");
        std::cout << "Stack Contents are :: ";
        for (auto i = 0; i <= _m_top; i++) {
            std::cout << _m_data[i] << " ";
        }
        std::cout << std::endl;
    }
};


#endif //TEMPLATESTACK_STACK_H
