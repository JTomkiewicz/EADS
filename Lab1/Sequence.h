#ifndef SEQUENCE
#define SEQUENCE

#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;


template<typename T>
class Sequence {

    struct Node {

        T data;
        Node* next;
    };

    struct Node* head;
    int count;
    
    public:

    Sequence();
    Sequence(const Sequence<T>& s);
    ~Sequence();

    bool isEmpty();
    void addElementToEnd(T n);
    void addElementToBeg(T n);
    void print();
    int length();
    void removeElement(T n);
    void removeSequence();

    const Sequence &operator =(const Sequence<T> &s);

};


/*template<typename T> //constructor
Sequence<T> :: Sequence() {

    head = nullptr;
    count = 0;
}


template<typename T> //removes whole Sequence
void Sequence<T> :: removeSequence() {

    Node *temp;

    while(head != nullptr) {
        temp = head;
        head = head->next;
        delete temp;
    }

    count = 0;
}

template<typename T> //destructor
Sequence<T> :: ~Sequence() {

    removeSequence();
}


template<typename T> //return 1 if Sequence empty, 0 if not
bool Sequence<T> :: isEmpty() {

    return(head == nullptr);
}


template<typename T>     //add element to the end of Sequence
void Sequence<T> :: addElementToEnd(T n) {

        Node *newElement = new Node;
        Node *temp = head;

        newElement->data = n;

        if(temp == nullptr) {
            head = newElement;
            count++;
            return;
        }

        while(temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newElement;
        count++;
        newElement->next = nullptr;

    }


template<typename T>     //add element to the beginning of Sequence
void Sequence<T> :: addElementToBeg(T n) {

        Node *newElement = new Node;

        newElement->data = n;

        if(head == nullptr) {
            head = newElement;
            count++;
            return;
        }

        newElement->next = head;
        head = newElement;
        count++;
    }


template<typename T>     //print all elements in Sequence
void Sequence<T> :: print() {

        Node *temp = head;

        cout << "###BEG###" << endl;
        while(temp) {
            cout << temp->data << endl;
            temp = temp->next;
        }
        cout << "###END###" << endl;

    }

    
template<typename T>     //returns length of Sequence
int Sequence<T> :: length() {

    return count;
}


template<typename T>     //removes element from Sequence
void Sequence<T> :: removeElement(T n) {

        Node *temp = head; 

        if(head == nullptr) {
            cout << "Sequence empty!" << endl;
            return;
        }

        if(head->data == n) {
            head = temp->next;
            delete temp;
            count--;
            return;
        }

        bool thingExist = false;

        while(temp != nullptr) {
            if(temp->data == n) {
                thingExist = true;
                break;
            }
            temp = temp->next;
        }

        if(thingExist == false) {
            cout << "There is no such thing in Sequence!" << endl;
            return;
        }

        temp = head;
        Node *temp2 = temp;

        while(temp != nullptr) {
            if(temp->data == n) {

                if(temp->next == nullptr) {
                    temp2->next = nullptr;
                    delete temp;
                    count--;
                    return;
                }
                else {
                    temp2->next = temp->next;
                    delete temp;
                    count--;
                    return;
                }
                
            }

            temp2 = temp;
            temp = temp->next;
        }
}


template<typename T>    //copy constructor
Sequence<T> :: Sequence(const Sequence<T> &s) {

    head = nullptr;
    Node *temp = s.head;

    while(temp != nullptr) {
        addElementToEnd(temp->data);
        temp = temp->next;
    }
    
}


template<typename T>    //assignment operator
const Sequence<T>& Sequence<T>::operator =(const Sequence<T> &s) {

    if(&s != this) {
        if(this->head != nullptr) {
            Node *temp = this->head;

            while(head != nullptr) {
                temp = head->next;
                delete head;
                head = temp;
            } 
        }

        Node *temp = s.head;
        while(temp) {
            addElementToEnd(temp->data);
            temp = temp->next;
        }
    }

    return *this;
}*/

#include "biring.hpp"

#endif