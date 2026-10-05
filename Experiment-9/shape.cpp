#include <iostream> // Input/output stream
#include <cmath>    // Mathematical functions
 
const double PI = 3.14159; // Constant value for PI
 
// Base class
class Shape {
public:
    // Pure virtual function to calculate the area
    virtual double calculateArea() {
        std::cout << "\nthis is area " << std::endl;
    }

 
    // Pure virtual function to calculate the perimeter
    virtual double calculatePerimeter() {
         
        std::cout << "\nthis is perimeter " << std::endl;
    
    }
};
 
// Derived class: Circle
class Circle : public Shape {
private:
    double radius; // Radius of the circle
 
public:
    // Constructor
    Circle(double rad) : radius(rad) {}
 
    // Area of the circle
    double calculateArea()  {
        return PI * pow(radius, 2);
    }
 
    // Perimeter of the circle
    double calculatePerimeter()  {
        return 2 * PI * radius;
    }
};
 
// Derived class: Rectangle
class Rectangle : public Shape {
private:
    double length; // Length of the rectangle
    double width;  // Width of the rectangle
 
public:
    // Constructor
    Rectangle(double len, double wid) : length(len), width(wid) {}
 
    // Area of the rectangle
    double calculateArea()  {
        return length * width;
    }
 
    // Perimeter of the rectangle
    double calculatePerimeter()  {
        return 2 * (length + width);
    }
};
 
// Derived class: Triangle
class Triangle : public Shape {
private:
    double side1; // First side
    double side2; // Second side
    double side3; // Third side
 
public:
    // Constructor
    Triangle(double s1, double s2, double s3) : side1(s1), side2(s2), side3(s3) {}
 
    // Area of the triangle using Heron's formula
    double calculateArea()  {
        double s = (side1 + side2 + side3) / 2; // Semi-perimeter
        return sqrt(s * (s - side1) * (s - side2) * (s - side3));
    }
 
    // Perimeter of the triangle
    double calculatePerimeter() {
        return side1 + side2 + side3;
    }
};
 
int main() {
    // Create instances of different shapes
    Circle circle(7.0);               // Radius 7.0
    Rectangle rectangle(4.2, 8.0);    // Length 4.2, width 8.0
    Triangle triangle(4.0, 4.0, 3.2); // Sides 4.0, 4.0, 3.2
 
    // Circle
    std::cout << "Circle: " << std::endl;
    std::cout << "Area: " << circle.calculateArea() << std::endl;
    std::cout << "Perimeter: " << circle.calculatePerimeter() << std::endl;
 
    // Rectangle
    std::cout << "\nRectangle: " << std::endl;
    std::cout << "Area: " << rectangle.calculateArea() << std::endl;
    std::cout << "Perimeter: " << rectangle.calculatePerimeter() << std::endl;
 
    // Triangle
    std::cout << "\nTriangle: " << std::endl;
    std::cout << "Area: " << triangle.calculateArea() << std::endl;
    std::cout << "Perimeter: " << triangle.calculatePerimeter() << std::endl;
    return 0; // Successful completion
    
}