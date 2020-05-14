#include <iostream>
#include <string>
#include <exception>

class Node{
    public:
        Node* prev;
        Node* next;
        int data;

        Node(); //default constructor
};

class deque{
    Node* head;
    Node* tail;
    unsigned int count;

public:
    deque(); //constructor
    ~deque(); //destructor
    void enqueue_front(int i);
    void enqueue_back(int i);
    void dequeue_front();
    void dequeue_back();
    void clear();
    void front(int i);
    void back(int i);
    void empty();
    void size();
    void print();
};

