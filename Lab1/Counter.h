#ifndef COUNTER
#define COUNTER

#include <iostream>
#include <cstring>
#include <cstdlib>
using namespace std;

template<typename T>
class Counter {

    struct Node {

        T data;
        int number;
        Node* next;
    };

    struct Node* head;
    int count;
    
    public:

    Counter();
    ~Counter();

    void addElement(T n);
    void print();
    void removeCounter();
    int length();

};


template<typename T> //constructor
Counter<T> :: Counter() {

    head = nullptr;
    count = 0;
}

template<typename T> //destructor
Counter<T> :: ~Counter() {

    removeCounter();
}


template<typename T>     //add element to the Counter
void Counter<T> :: addElement(T n) {

    
        Node *newElement = new Node;
        Node *temp = head;

        newElement->data = n;
        newElement->number++;

        if(temp == nullptr) {
            head = newElement;
            count++;
            return;
        }

        if(n == head->data) {
            head->number++;
            count++;
            return;
        }

        while(temp->next != nullptr) {
            
            if(n == temp->data) {
                temp->number++;
                count++;
                return;
            }

            temp = temp->next;
        }

        if(temp->data == n) {
            temp->number++;
            count++;
            return;
        }

        temp->next = newElement;
        count++;
        newElement->next = nullptr;

    }


    template<typename T>     //print all elements in Counter [alphabetical order]
    void Counter<T> :: print() {

        Node *temp = head;

        cout << "\n\n########" << endl;

        while(temp) {
            cout << temp->data << "    how_many: " << temp->number << endl;
            temp = temp->next;
        }
        cout << "########\n\n";

    }

    template<typename T> //removes whole Counter
    void Counter<T> :: removeCounter() {

    Node *temp;

    while(head != nullptr) {
        temp = head;
        head = head->next;
        delete temp;
    }

    count = 0;
}


template<typename T>     //returns length of Counter
int Counter<T> :: length() {

    return count;
}

#endif