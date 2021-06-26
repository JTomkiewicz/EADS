
template<typename Key, typename Info>
BiRing<Key,Info> :: BiRing() {      //constructor
    head = nullptr;
    count = 0; 
}

template<typename Key, typename Info>
BiRing<Key,Info> :: ~BiRing() {     //destructor
    clear();
}

template<typename Key, typename Info>   //0 if not, 1 if yes
bool BiRing<Key,Info> :: empty() { 
    return(head == nullptr);
}

template<typename Key, typename Info>   //size
int BiRing<Key,Info> :: length() { 
    return count;
}

template<typename Key, typename Info>    //add element to the end of BiRing
void BiRing<Key, Info> :: push_back(const Key &k, const Info &i) {

    Node *newElement = new Node;
    BiRing<Key, Info>::iterator itnew = newElement; //iterator for newElement

    (*itnew).nodeKey = k;
    (*itnew).nodeInfo = i;

    if((*this).begin() == nullptr) {    //if biring empty
        head = newElement;
        BiRing<Key, Info>::iterator it = (*this).begin();
        (*it).next = head;
        (*it).prev = head;
        count++;
        return;
    }

    BiRing<Key, Info>::iterator it = (*this).begin();
    while(it != this->end())++it;   //iterator for the last element

    BiRing<Key, Info>::iterator ithead = (*this).begin();   //iterator for head

    (*it).next = newElement;
    count++;
    (*itnew).next = &*ithead;
    (*ithead).prev = newElement;
    (*itnew).prev = &*it;
}

template<typename Key, typename Info>    //add element to the front of BiRing
void BiRing<Key, Info> :: push_front(const Key &k, const Info &i) {
    Node *newElement = new Node;
    BiRing<Key, Info>::iterator itnew = newElement; //iterator for newElement

    (*itnew).nodeKey = k;
    (*itnew).nodeInfo = i;

    if((*this).begin() == nullptr) {    //if biring empty
        head = newElement;
        BiRing<Key, Info>::iterator it = (*this).begin();
        (*it).next = head;
        (*it).prev = head;
        count++;
        return;
    }

    BiRing<Key, Info>::iterator ithead = (*this).begin();   //iterator for head
    BiRing<Key, Info>::iterator itend = (*this).end();   //iterator for end
    
    (*itnew).next = head;
    (*itnew).prev = &*itend;
    head = newElement;
    (*itend).next = newElement;
    count++;
}

template<typename Key,typename Info>    //removes whole BiRing
void BiRing<Key, Info> :: clear() {

    BiRing<Key, Info>::iterator it = (*this).begin();
    BiRing<Key, Info>::iterator it2 = it;

    for(int i=0 ; i < count; i++) {
        it2 = it;
        ++it;
        (*this).erase(it2);
    }

    count = 0;
}

template<typename Key,typename Info>    //removes last element of BiRing
void BiRing<Key, Info> :: pop_back() {

    if(count == 1) {
        clear();
        return;
    }
    
    BiRing<Key, Info>::iterator ithead = (*this).begin(); //it for new head
    BiRing<Key, Info>::iterator itend = (*this).end(); //it for new end

    BiRing<Key, Info>::iterator itdelete = itend;   //it to delete
    --itend;
    (*itend).next = (*itdelete).next;
    (*ithead).prev = (*itdelete).prev;
    (*this).erase(itdelete);
    count--;
}

template<typename Key, typename Info>   //prints BiRing
void BiRing<Key, Info> :: print() {

	BiRing<Key, Info>::iterator it = (*this).begin();

    cout << "###############" << endl;
    do {
        cout << (*it).nodeKey << " " << (*it).nodeInfo << endl;
        ++it;
    } while(it != this->end());

    if(count != 1)cout << (*it).nodeKey << " " << (*it).nodeInfo << endl;

    cout << "###############" << endl;
}

template<typename Key, typename Info>   //1 if element exist in BiRing, 0 if not
bool BiRing<Key, Info> :: exist(const Key &k, const Info &i) {

    BiRing<Key, Info>::iterator it = (*this).begin();

    do {
        if((*it).nodeKey == k && (*it).nodeInfo == i) return true;
        ++it;
    } while(it != this->end());

    if(count != 1 && (*it).nodeKey == k && (*it).nodeInfo == i)return true;

    return false;
}

template<typename Key, typename Info>   //change the value of the node
void BiRing<Key, Info> :: change(const Key &kold, const Info &iold,const Key &knew, const Info &inew) {

    BiRing<Key, Info>::iterator it = (*this).begin();

    do {
        if((*it).nodeKey == kold && (*it).nodeInfo == iold) {
            (*it).nodeKey = knew;
            (*it).nodeInfo = inew;
        }
        ++it;
    } while(it != this->end());

    if(count != 1 && (*it).nodeKey == kold && (*it).nodeInfo == iold) {
        (*it).nodeKey = knew;
        (*it).nodeInfo = inew;
    }
}

template<typename Key, typename Info>   //delete exact Node
bool BiRing<Key, Info> :: remove(const Key &k, const Info &i) {

    BiRing<Key, Info>::iterator ithead = (*this).begin();

    if(head == nullptr)return false;

    if(count == 1 && (*ithead).nodeKey == k && (*ithead).nodeInfo == i) { //if 1 element and head to delete
        
        clear();
        return true;
    }

    if(count != 1 && (*ithead).nodeKey == k && (*ithead).nodeInfo == i) {
        
        BiRing<Key, Info>::iterator itend = (*this).end(); //it for new end
        BiRing<Key, Info>::iterator itdelete = ithead;   //it to delete

        ++ithead;
        (*itend).next = (*itdelete).next;
        (*ithead).prev = (*itdelete).prev;
        head = &*ithead;
        (*this).erase(itdelete);
        count--;
        return true;
    }

    BiRing<Key, Info>::iterator itend = (*this).end();
    ++ithead;
    ++itend;
    do {
        if((*ithead).nodeKey == k && (*ithead).nodeInfo == i) {
            
            BiRing<Key, Info>::iterator itdelete = ithead;   //it to delete

            ++ithead;
            (*itend).next = (*itdelete).next;
            (*ithead).prev = (*itdelete).prev;
            (*this).erase(itdelete);
            count--;

            return true;
        }
        ++itend;
        ++ithead;
    } while(ithead != this->end());

    if(count != 1 && (*ithead).nodeKey == k && (*ithead).nodeInfo == i) {
            BiRing<Key, Info>::iterator itdelete = ithead;   //it to delete

            ++ithead;
            (*itend).next = (*itdelete).next;
            (*ithead).prev = (*itdelete).prev;
            (*this).erase(itdelete);
            count--;

        return true;
    }

    return false;
}

template<typename Key, typename Info>   //copy constructor
BiRing<Key, Info> :: BiRing(const BiRing<Key,Info>& b) {

    head = nullptr;
    Node *temp = b.head;
    BiRing<Key, Info>::iterator it = temp;


    for(int i=0; i < b.count ; i++) {
        push_back((*it).nodeKey, (*it).nodeInfo);
        ++it;
    }
}

template<typename Key, typename Info>   //assignment operator
const BiRing<Key, Info>& BiRing<Key,Info> :: operator =(const BiRing<Key, Info> &b){

    if(&b != this) {
        if((*this).begin() != nullptr) {
            clear();
        }

        Node *temp = b.head;
        BiRing<Key, Info>::iterator it = temp;
        
        for(int i=0; i < b.count ; i++) {
        push_back((*it).nodeKey, (*it).nodeInfo);
        ++it;
        }
    }

    return *this;
}

