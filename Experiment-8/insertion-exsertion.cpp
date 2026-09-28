#include <iostream>
using namespace std;
 
class Complex {
private:
    int real, imag;
 
public:
    Complex(int r = 0, int i = 0) : real(r), imag(i)
    {
    }
 
    //these must be friend (non-member) functions
    //the left operand is cin/cout, not our object, so they can't be member functions
    //they need friend access because real and imag are private
    friend ostream& operator<<(ostream& out, const Complex& c);
    friend istream& operator>>(istream& in, Complex& c);
};
 
//cout << c1; -> prints the object in a + bi form
ostream& operator<<(ostream& out, const Complex& c)
{
    out << c.real;
    if (c.imag >= 0)
        out << " + " << c.imag << "i";
    else
        out << " - " << -c.imag << "i";
 
    //return the stream so chaining like cout << a << b works
    return out;
}
 
//cin >> c1; -> reads real and imaginary parts
//object is taken by non-const reference because we are changing it
istream& operator>>(istream& in, Complex& c)
{
    cout << "enter real part: ";
    in >> c.real;
    cout << "enter imaginary part: ";
    in >> c.imag;
    return in;
}
 
int main()
{
    Complex c1, c2;
 
    cout << "first complex number" << endl;
    cin >> c1;
    cout << "second complex number" << endl;
    cin >> c2;
 
    cout << "\nc1 = " << c1 << endl;
    cout << "c2 = " << c2 << endl;
 
    return 0;
}