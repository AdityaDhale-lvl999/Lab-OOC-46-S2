#include<iostream>
using namespace std;
class Vehicle
{
    public:
    void display()
    {
        cout<<"\n This is a Vehicle \n";
    }
};
class Car : public Vehicle
{
    public:
    Car()
    {
        cout<<"\n This Vehicle is Car \n";
    }
};
class Bus : public Vehicle
{
    public:
    Bus()
    {
        cout<<"\n This Vehicle is Bus \n";
    }
};
int main()
{
    Car obj1;
    Bus obj2;
    return 0;
}