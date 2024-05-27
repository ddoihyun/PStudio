#include "stackIntList.h"
#include <iostream>
using namespace std;

MyStackIntList::MyStackIntList() { 
    top = nullptr; // intially set top of the Stack as nullptr;
    size = 0;
}

MyStackIntList::~MyStackIntList() {
    Node* p = top;
    while (top) {
        delete p;
        top = top->next;
        p = top;
    }
}

void MyStackIntList::push(int x) {
    Node* p = new Node;
    if (p == nullptr) {
        cout << "Stack Overflow!" << endl;
    }
    else {
        p->data = x;
        p->next = top;
        top = p;
        size++;
    }
}

int MyStackIntList::pop() { 
    Node* p = top;
    int x = -1;
    if (p == nullptr) {
        cout << "Stack Underflow!" << endl;
    }
    else {
        x = p->data;
        top = top->next;
        delete p;
        size--;
    }
    return x;
}

int MyStackIntList::isFull() { 
    Node* p = new Node;
    int r = p ? 0 : 1;
    delete p;
    return r;
}

int MyStackIntList::isEmpty() {
    return top ? 0 : 1;
}

void MyStackIntList::display() { 
    Node* p = top;
    cout << "Stack ("<< size << ") : ";
    while(p) {
        cout << p->data << " | ";
        p = p->next;
    }
    cout << endl;
}

int MyStackIntList::stackTop() {
    if (top)
        return top->data;
    else
        return -1;
}

