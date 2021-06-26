#ifndef FILEMANAGEMENT
#define FILEMANAGEMENT

#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
#include <algorithm>
#include "Counter.h"

using namespace std;


string workOnString(string s) { //lower letters and work with "." "," etc
    
    while( (int)s[0] == 46 || (int)s[0] == 44 || (int)s[0] == 34 || (int)s[0] == 63 || (int)s[0] == 33 || (int)s[0] == 40 || (int)s[0] == 41 || (int)s[0] == 39 || (int)s[s.size()-1] == 46 || (int)s[s.size()-1] == 44 || (int)s[s.size()-1] == 63 || (int)s[s.size()-1] == 33|| (int)s[s.size()-1] == 40|| (int)s[s.size()-1] == 41 || (int)s[s.size()-1] == 39 || (int)s[s.size()-1] == 34 ) {

        if((int)s[0] == 46 || (int)s[0] == 44 || (int)s[0] == 63 || (int)s[0] == 33 || (int)s[0] == 40 || (int)s[0] == 41 || (int)s[0] == 39 || (int)s[0] == 34 )s.erase(0,1);

        if((int)s[s.size()-1] == 46 || (int)s[s.size()-1] == 44 || (int)s[s.size()-1] == 63 || (int)s[s.size()-1] == 33|| (int)s[s.size()-1] == 40|| (int)s[s.size()-1] == 41 || (int)s[s.size()-1] == 39 || (int)s[s.size()-1] == 34 )s.erase(s.size()-1,1);

    }

    for(int i=0; i<s.size(); i++) {
        s[i] = tolower(s[i]);
    }

    return s;
}


int count_words(Counter<string>& cut,ifstream& source) { //send words from text to counter

    if(!source.is_open()) {
        cout << "error while loading file" << endl;
        return 0;
    }

    string t;

    while(source >> t) {
        t = workOnString(t);
        cut.addElement(t);
    }
    
    source.close();

    return cut.length();
}

#endif