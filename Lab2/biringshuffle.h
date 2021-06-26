#include "biring.h"
#include "iterator.h"

template <typename Key, typename Info>
BiRing<Key, Info> shuffle(BiRing<Key, Info>& first, BiRing<Key, Info>& second, int nbfirst, int nbsecond, int reps) {

    BiRing<Key, Info> newRing;

    if(nbfirst <= 0 || nbsecond <= 0) return newRing;

    if(first.length() == 0 || second.length() == 0)return newRing;
    
    if(reps < 1)return newRing;

    auto itfir = first.begin();
    auto itsec = second.begin();

    for (int i=0; i<reps; i++) {

        for(int j=0; j<nbfirst; j++) {
            newRing.push_back((*itfir).nodeKey, (*itfir).nodeInfo);
            ++itfir;
        }
        for(int k=0; k<nbsecond; k++) {
            newRing.push_back((*itsec).nodeKey, (*itsec).nodeInfo);
            ++itsec;
        }
    }

    return newRing;
}