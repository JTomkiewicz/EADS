#ifndef ITERATOR_H
#define ITERATOR_H

template <typename Key, typename Info>
class BiRing<Key,Info> :: iterator {

    friend class BiRing;

    private:

        Node* it;

    public:

        iterator();

        iterator(Node* n);

        Node& operator*()const;     // *it

        bool operator!=(const iterator& givenIterator) const;   // !=
        bool operator==(const iterator& givenIterator) const;   // ==

        iterator& operator++(); // ++it
        iterator& operator--(); // --it
        iterator& operator+=(int x);
        iterator& operator-=(int x);

        iterator(const iterator& givenIterator);
};

template <typename Key, typename Info>
class BiRing<Key,Info> :: const_iterator {

    friend class BiRing;

    private:

        Node* it;

    public:

        const_iterator();

        Node& operator*()const;     // *it

        bool operator!=(const const_iterator& givenIterator) const;     // !=
        bool operator==(const const_iterator& givenIterator) const;     // ==

        const_iterator& operator++();   // ++it
        const_iterator& operator--();   // --it
        const_iterator& operator+=(int x);
        const_iterator& operator-=(int x);

        const_iterator(const const_iterator &givenIterator);

};

#include "iterator.hpp"

#endif