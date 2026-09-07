#include <iostream>
using namespace std;

int area(int s);
int area(int l, int b);
float area(float r);
float area(float base, float height);

int main() {
    int side, length, breadth;
    float radius, base, height;

    cout << "Enter side of a square: ";
    cin >> side;

    cout << "Enter length and breadth of rectangle: ";
    cin >> length >> breadth;

    cout << "Enter radius of circle: ";
    cin >> radius;

    cout << "Enter base and height of triangle: ";
    cin >> base >> height;

    cout << "Area of square is " << area(side) << endl;
    cout << "Area of rectangle is " << area(length, breadth) << endl;
    cout << "Area of circle is " << area(radius) << endl;
    cout << "Area of triangle is " << area(base, height) << endl;

    return 0;
}

int area(int s) {
    return s * s;
}

int area(int l, int b) {
    return l * b;
}

float area(float r) {
    return 3.14f * r * r;
}

float area(float base, float height) {
    return (base * height) / 2;
}