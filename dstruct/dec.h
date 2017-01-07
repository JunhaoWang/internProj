#include "ll.h"
#include<iostream>
#include<assert.h>

template <typename T>
class Deck {
private:
    List<T> data;
public:
    Deck() {};
    void push_front(T val) {
        data.push_front(val);
    }
    void push_back(T val) {
        data.push_back(val);
    }
    void pop_front() {
        assert(getSize()>0);
        data.pop_front();
    }
    void pop_back() {
        assert(getSize()>0);
        data.pop_back();
    }
    void clear() {
        data.clear();
    }
    int getSize() {
        return data.getSize();
    }   
    bool empty(){
        return getSize() == 0;
    }

    T & front(){
        assert(getSize()>0);
        return data.getEnd()->getVal();
    }
    T & back(){
        assert(getSize()>0);
        return data.getRoot()->getVal();
    }
};

template <typename T>
class Stack: public Deck<T> {
    public:
        void push(T val) {
            this->push_front(val);
        }
        void pop(){
            this->pop_front(); 
        }
        T & top(){
            return this->front();
        }
};

template <typename T>
class Queue: public Deck<T> {
    public:
        void push(T val) {
            this->push_back(val);
        }
        void pop(){
            this->pop_front(); 
        }
        T & top(){
            return this->front();
        }
};


