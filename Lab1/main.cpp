#include <iostream>
#include <string>
#include <fstream>
#include "Sequence.h"
#include "FileManagement.h"
#include <chrono>
using namespace std;       

                //########     ######     ########       #######
                //##         ##      ##   ##      ##   ##
                //#####      ##########   ##      ##     #####
                //##         ##      ##   ##      ##          ##
                //########   ##      ##   ########     #######

int main() {

    //FIRST PART OF TASK WITH SEQUENCE

    /*cout << "\n\nPART 1 SEQUENCE\n\n";

    cout << "\nSequence<double> s1: " << endl;
    Sequence<double> s1;

    s1.addElementToEnd(2.3);
    s1.addElementToEnd(4.1);
    s1.addElementToEnd(5.19812);
    s1.addElementToBeg(3.1333);

    s1.print();


    cout << "Is s1 empty?: " << s1.isEmpty() << endl;
    cout << "How many elements in s1?: " << s1.length() << endl;


    cout << "\nSequence s2( s1 ):" << endl;
    Sequence<double> s2( s1 );
    s2.print();


    cout << "\nSequence s3 = s1: " << endl;
    Sequence<double> s3;
    s3 = s1;
    s3.print();


    cout << "\ns1 after removing 4.1 and 2.3: " << endl;
    s1.removeElement(4.1);
    s1.removeElement(2.3);
    s1.print();


    cout << "\nSequence<string> s4:" << endl;
    Sequence<string> s4;
    s4.addElementToEnd("cat");
    s4.addElementToEnd("dog");
    s4.addElementToEnd("car");
    s4.addElementToBeg("window");
    s4.print();*/


    //SECOUND PART OF TASK WITH COUNTER AND TXT FILES

    cout << "\n\nPART 2 COUNTER\n";

    Counter<string> counter_file;
    ifstream source;

    auto start = chrono::high_resolution_clock::now();

    source.open("OnTheOriginOfSpecies.txt");       //HERE CHANGE IF FILE WITH DIFFERENT NAME
    int sum = count_words(counter_file,source);



    auto stop = chrono::high_resolution_clock::now();

    auto dur = chrono::duration_cast<chrono::milliseconds>(stop - start);

    counter_file.print();

    cout << "Nr of words in txt: " << sum << endl;

    cout << "CZAS: " << dur.count() << '\n';

    return 0;
}