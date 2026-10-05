#include <iostream>
 
// Abstract base class
class Vehicle {
public:
    // Pure virtual functions
    virtual void start() const = 0;
    virtual void stop() const = 0;
 
    // Virtual destructor so derived destructors run when deleting via base pointer
    virtual ~Vehicle() {}
};
 
// Derived class: Car
class Car : public Vehicle {
public:
    void start() const override {
        std::cout << "Car started: engine on, ready to drive." << std::endl;
    }
 
    void stop() const override {
        std::cout << "Car stopped: brakes applied, engine off." << std::endl;
    }
};
 
// Derived class: Bike
class Bike : public Vehicle {
public:
    void start() const override {
        std::cout << "Bike started: kick/self-start, ready to ride." << std::endl;
    }
 
    void stop() const override {
        std::cout << "Bike stopped: brakes applied, engine off." << std::endl;
    }
};
 
int main() {
    // Base class pointers pointing to derived class objects
    Vehicle* vehicles[] = { new Car(), new Bike() };
 
    // Same call, different behavior depending on the actual object (runtime polymorphism)
    for (Vehicle* v : vehicles) {
        v->start();
        v->stop();
        std::cout << std::endl;
    }
 
    // Free memory
    for (Vehicle* v : vehicles) {
        delete v;
    }
 
    return 0;
}
 