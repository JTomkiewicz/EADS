#ifndef BIRING_H
#define BIRING_H

#include <iostream>

using namespace std;

template<typename Key, typename Info>
class BiRing {

    private:

        struct Node {

            Key nodeKey;
            Info nodeInfo;
            Node* next;
            Node* prev;
        };

        Node* head;
        int count;

    public: 

        class iterator;
        class const_iterator;

        iterator begin() { return head; }   //begin()
        iterator end() { return head->prev; }   //end()

        const_iterator begin() const { return head; }   //begin()
        const_iterator end() const { return head->prev; }   //end()

        void erase(iterator& givenIterator ) {  //erase()
            delete &*givenIterator;
            givenIterator = nullptr;
        }

        BiRing();
        BiRing(const BiRing<Key,Info>& b);
        ~BiRing();

        bool empty();
        bool exist(const Key &k, const Info &i);
        void push_back(const Key &k, const Info &i);
        void push_front(const Key &k, const Info &i);
        void pop_back();
        void change(const Key &kold, const Info &iold, const Key &knew, const Info &inew);
        bool remove(const Key &k, const Info &i);
        int length();
        void clear();
        void print();

        const BiRing &operator =(const BiRing<Key, Info> &b);
        
};

#include "biring.hpp"
#include "iterator.h"

#endif