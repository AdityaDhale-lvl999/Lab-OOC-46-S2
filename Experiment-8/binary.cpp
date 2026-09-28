#include <iostream>
using namespace std;
 
class Distance {
public:
    int feet, inch;
 
    //default constructor, needed so we can write Distance d3;
    Distance()
    {
        this->feet = 0;
        this->inch = 0;
    }
 
    Distance(int f, int i)
    {
        this->feet = f;
        this->inch = i;
    }
 
    //left operand is the calling object (this), right operand comes in as d2
    //passed by reference so we don't copy the whole object
    Distance operator+(Distance& d2)
    {
        //temp object to hold the answer
        Distance d3;
        d3.feet = this->feet + d2.feet;
        d3.inch = this->inch + d2.inch;
 
        //hand the result back
        return d3;
    }
};
 
int main()
{
    Distance d1(8, 9);
    Distance d2(10, 2);
    Distance d3;
 
    //compiler turns this into d1.operator+(d2)
    d3 = d1 + d2;
 
    cout << "\nTotal Feet & Inches: " << d3.feet << "'" << d3.inch;
    return 0;
}
 