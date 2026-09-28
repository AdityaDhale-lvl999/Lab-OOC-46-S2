#include <iostream>
using namespace std;
 
class Distance {
public:
    int feet, inch;
 
    //constructor to set the starting values
    Distance(int f, int i)
    {
        this->feet = f;
        this->inch = i;
    }
 
    //overloaded unary (-), no arguments because it works on the object itself
    //in this lab it decrements both values instead of negating them
    void operator-()
    {
        feet--;
        inch--;
        cout << "\nFeet & Inches(Decrement): " << feet << "'" << inch;
    }
};
 
int main()
{
    Distance d1(8, 9);
 
    //calls d1.operator-()
    -d1;
 
    return 0;
}
