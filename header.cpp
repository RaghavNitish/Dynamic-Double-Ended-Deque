#include <iostream>
#include "header.h"
#include <string>
#include <exception>

//my exception class which handles exceptions when failures are detected for certain deque operations 
class myexception: public std::exception
{
  virtual const char* what() const throw()
  {
    return "failure\n";
  }
} deque_empty;

//Constructor for Node class
Node::Node(){
    prev = NULL;
    next = NULL;

    data = 0;
}

//Constructor for deque class
deque::deque(){
    head = NULL;
    tail = NULL;
    count = 0;
}

//Destructor for deque class
deque::~deque(){
    if (count != 0){
        Node* temp;
        while (head != NULL){
            temp = head;
            head = head->next;
            delete temp;
        }
        count = 0;
        tail = NULL;
    }
}

//Takes an integer and adds the element at the front of the deque data structure
void deque::enqueue_front(int i){
    Node* temp = new Node;

    temp->data = i;
    
    //If deque is empty
    if (head == NULL && tail == NULL){
        head = temp;
        tail = temp;
    } 
    //If deque is not empty
    else{
        temp->next = head;
        head->prev = temp;
        head = temp;
    }
    count++;
    std::cout << "success\n";
}

//Takes an integer and adds the element at the back of the deque data structure
void deque::enqueue_back(int i){
    Node* temp = new Node;
    
    temp->data = i;

    //If deque is empty
    if (head == NULL && tail == NULL){
        head = temp;
        tail = temp;
    }
    //If deque is not empty
    else{
        tail->next = temp;
        temp->prev = tail;
        tail = temp;
    }
    count++;
    std::cout << "success\n";
}

//Removes an element from the front of the deque data structure
void deque::dequeue_front(){
    try{
        if (head == NULL && tail == NULL){
            throw deque_empty;
        }
    }
    catch(std::exception &obj){
        std::cout << obj.what();
    }

    if (head != NULL && tail != NULL){
        Node* temp = head;
        if (temp->next != NULL){
            (temp->next)->prev = NULL;
            head = temp->next;
        }
        else {
            head = NULL;
            tail = NULL;
        }
        delete temp; 
        count--;
        std::cout << "success\n";
    }
}

//Removes an element from the back of the deque data structure
void deque::dequeue_back(){
    try{
        if (head == NULL && tail == NULL){
            throw deque_empty;
        }
    }
    catch(std::exception &obj){
        std::cout << obj.what();
    }
    if (head != NULL && tail != NULL){
        Node* temp = tail;
        if (temp->prev != NULL){
            (temp->prev)->next = NULL;
            tail = temp->prev;
        }
        else{
            head = NULL;
            tail = NULL;
        }

        delete temp;
        count--;
        std::cout << "success\n";
    }
}

//Clears the content of the deque data structure only if the deque is not empty
void deque::clear(){
    if (count != 0){
        Node* temp;
        while (head != NULL){
            temp = head;
            head = head->next;
            delete temp;
        }
        std::cout << "success\n";
        count = 0;
        tail = NULL;
    }
}

//Takes an integer and compares this number to the data in the first node
void deque::front(int i){
    try{
        if (head == NULL){
            throw deque_empty;
        }
        else if (head->data != i){
            throw deque_empty;
        }
    }

    catch(std::exception &obj){
        std::cout << obj.what();
    }

    if (head != NULL){
        if (head->data == i){
            std::cout << "success\n";
        }
    }
}

//Takes an integer and compares this number to the data in the last node 
void deque::back(int i){
    try{
        if (tail == NULL){
            throw deque_empty;
        }

        else if (tail->data != i){
            throw deque_empty;
        } 
    }
    catch(std::exception &obj){
        std::cout << obj.what();
    }
    if (tail != NULL){
        if (tail->data == i){
            std::cout << "success\n";
        }
    }
}

//Checks to see if the deque data structure is empty
void deque::empty(){
    if (count == 0){
        std::cout << "success\n";
    }
    else{
        std::cout << "failure\n";
    }
}

//Returns the size of the deque data structure
void deque::size(){
    std::cout << "size is " << count << "\n";
}

//Prints all values stored in the nodes of the deque data structure 2 times. 
//Once from the front to the back of the deque and another time from back to front. 
void deque::print(){
    if (count != 0){
        Node* temp = head;
        while (temp != NULL){
            if (temp->next != NULL){
                std::cout << temp->data << " ";
            }
            else if (temp->next == NULL){
                std::cout << temp->data;
            }
            temp = temp->next;
        }
        std::cout << std::endl;

        temp = tail;
        while (temp != NULL){
            if (temp->prev != NULL){
                std::cout << temp->data << " ";
            }
            else if (temp->prev == NULL){
                std::cout << temp->data;
            }
            temp = temp->prev;
        }
        std::cout << std::endl;
    }

}