#include <iostream>
#include <string>
 
// Base class
class Employee {
protected:
    std::string name;
    double salary;
 
public:
    Employee(std::string n, double s) : name(n), salary(s) {}
 
    // Virtual function: derived classes define their own bonus rule
    virtual double calculateBonus() const {
        return 0.05 * salary; // Default rule: 5% of salary
    }
 
    virtual void display() const {
        std::cout << "Name: " << name << std::endl;
        std::cout << "Salary: " << salary << std::endl;
        std::cout << "Bonus: " << calculateBonus() << std::endl;
    }
 
    // Virtual destructor
    virtual ~Employee() {}
};
 
// Derived class: Manager
class Manager : public Employee {
private:
    int teamSize;
 
public:
    Manager(std::string n, double s, int team) : Employee(n, s), teamSize(team) {}
 
    // Rule: 20% of salary + 2000 per team member
    double calculateBonus() const override {
        return 0.20 * salary + 2000 * teamSize;
    }
 
    void display() const override {
        std::cout << "Role: Manager" << std::endl;
        Employee::display();
    }
};
 
// Derived class: Developer
class Developer : public Employee {
private:
    int projectsCompleted;
 
public:
    Developer(std::string n, double s, int projects) : Employee(n, s), projectsCompleted(projects) {}
 
    // Rule: 10% of salary + 5000 per completed project
    double calculateBonus() const override {
        return 0.10 * salary + 5000 * projectsCompleted;
    }
 
    void display() const override {
        std::cout << "Role: Developer" << std::endl;
        Employee::display();
    }
};
 
int main() {
    // Base class pointers pointing to derived objects
    Employee* employees[] = {
        new Manager("Rahul", 80000, 5),
        new Developer("Priya", 60000, 3)
    };
 
    // Same call, different bonus rule depending on the actual object
    for (Employee* e : employees) {
        e->display();
        std::cout << std::endl;
    }
 
    for (Employee* e : employees) {
        delete e;
    }
 
    return 0;
}