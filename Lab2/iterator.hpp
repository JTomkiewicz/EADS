
template <typename Key, typename Info>
BiRing<Key, Info> :: iterator :: iterator() {
    it = nullptr;
}

template <typename Key, typename Info>
BiRing<Key, Info> :: iterator :: iterator(Node* n) {
    it = n;
}

template <typename Key, typename Info>
typename BiRing<Key, Info> :: Node& BiRing<Key, Info> :: iterator :: operator*()const {
    return *it;
}

template <typename Key, typename Info>
bool BiRing<Key, Info> :: iterator :: operator!=(const iterator& givenIterator) const {
    return it != givenIterator.it;
} 

template <typename Key, typename Info>
bool BiRing<Key, Info> :: iterator :: operator==(const iterator& givenIterator) const {
    return it == givenIterator.it;
} 

template <typename Key, typename Info>
typename BiRing<Key, Info> :: iterator& BiRing<Key, Info> :: iterator :: operator++() {
    it = it->next;
	return *this;
}

template <typename Key, typename Info>
typename BiRing<Key, Info> :: iterator& BiRing<Key, Info> :: iterator :: operator+=(int x) {
    for(int i=0; i<x ; i++)it = it->next;
		return *this;
}

template <typename Key, typename Info>
typename BiRing<Key, Info> :: iterator& BiRing<Key, Info> :: iterator :: operator-=(int x) {
    for(int i=0; i<x ; i++)it = it->prev;
		return *this;
}

template <typename Key, typename Info>
typename BiRing<Key, Info> :: iterator& BiRing<Key, Info> :: iterator :: operator--() {
    it = it->prev;
	return *this;
}

template <typename Key, typename Info>
BiRing<Key, Info> :: iterator :: iterator(const iterator& givenIterator){
    it = givenIterator.it;
}

template <typename Key, typename Info>
BiRing<Key, Info> :: const_iterator :: const_iterator() {
    it = nullptr;
}

template <typename Key, typename Info>
BiRing<Key, Info> :: const_iterator :: const_iterator(const const_iterator& givenIterator){
    it = givenIterator.it;
}

template <typename Key, typename Info>
typename BiRing<Key, Info> :: Node& BiRing<Key, Info> :: const_iterator :: operator*()const {
    return *it;
}

template <typename Key, typename Info>
bool BiRing<Key, Info> :: const_iterator :: operator!=(const const_iterator& givenIterator) const {
    return it != givenIterator.it;
} 

template <typename Key, typename Info>
bool BiRing<Key, Info> :: const_iterator :: operator==(const const_iterator& givenIterator) const {
    return it == givenIterator.it;
} 

template <typename Key, typename Info>
typename BiRing<Key, Info> :: const_iterator& BiRing<Key, Info> :: const_iterator :: operator++() {
    it = it->next;
	return *this;
}

template <typename Key, typename Info>
typename BiRing<Key, Info> :: const_iterator& BiRing<Key, Info> :: const_iterator :: operator--() {
    it = it->prev;
	return *this;
}

template <typename Key, typename Info>
typename BiRing<Key, Info> :: const_iterator& BiRing<Key, Info> :: const_iterator :: operator+=(int x) {
    for(int i=0; i<x ; i++)it = it->next;
		return *this;
}

template <typename Key, typename Info>
typename BiRing<Key, Info> :: const_iterator& BiRing<Key, Info> :: const_iterator :: operator-=(int x) {
    for(int i=0; i<x ; i++)it = it->prev;
		return *this;
}