#include <iostream>
#include <string>
#include "biring.h"
#include "biringshuffle.h"

using namespace std;       

int main() {

    cout << "\n\n### PART 1: BiRing using Iterators (not pointers!) ###\n\n";
    
    BiRing<int, string> s1;
    s1.push_back(1, "Warsaw");
    s1.push_back(2, "New York");
    s1.push_back(1, "Paris");
    s1.push_front(4, "London");
    s1.push_front(8, "Cracow");

    cout << "S1: " << endl;
    s1.print();

    cout << "S1.empty() = " << s1.empty() << endl;
    cout << "S1.length() = " << s1.length() << endl;
    cout << "S1.exist(4, 'London') = " << s1.exist(4, "London") << endl;
    cout << "S1.exist(4, 'Tokyo') = " << s1.exist(4, "Tokyo") << endl;

    s1.pop_back();
    cout << "\n\nS1 after pop_back():\n";
    s1.print();

    s1.change(1, "Warsaw", 11, "Helsinki");
    cout << "\n\nS1 after change(1, 'Warsaw', 11, 'Helsinki'):\n";
    s1.print();

    s1.remove(4,"London");
    cout << "\n\nS1 after remove(4,'London'):\n";
    s1.print();

    BiRing<int, string> s2(s1);
    cout << "\n\nS2(S1):\n";
    s2.print();

    BiRing<int, string> s3;
    s3 = s2;
    cout << "\n\nS3 = S2:\n";
    s3.print();


    cout << "\n\n### PART 2: BiRing Shuffle ###\n\n";
    
    BiRing<int, string> s10;
    s10.push_back(7, "Moscow");
    s10.push_back(14, "Los Angeles");
    s10.push_back(5, "Chikago");
    s10.push_front(23, "Detroit");
    s10.push_front(36, "Caracas");

    cout << "BiRing first: " << endl;
    s10.print();

    BiRing<int, string> s11;
    s11.push_back(8, "Cleveland");
    s11.push_front(55, "San Francisco");
    s11.push_front(9, "San Diego");
    s11.push_front(17, "Phoenix");
    s11.push_front(27, "Dallas");

    cout << "\nBiRing second: " << endl;
    s11.print();

    BiRing<int, string> s12 = shuffle(s10, s11, 3, 2, 2);
    
    cout << "\nshuffle(first, second, 3, 2 , 2): " << endl;
    s12.print();

    BiRing<int, double> s20;
    s20.push_back(2, 3.13);
    s20.push_back(4, 4.5);

    BiRing<int, double> s21;
    s21.push_back(8, 7.42);
    s21.push_back(11, 2.352);
    s21.push_back(14, 1.567);

    cout << "\nBiRing first: " << endl;
    s20.print();

    cout << "\nBiRing second: " << endl;
    s21.print();

    BiRing<int, double> s22 = shuffle(s20, s21, 2, 3, 3);
    
    cout << "\nshuffle(first, second, 2, 3 , 3): " << endl;
    s22.print();


    return 0;
}