#include<iostream>
#include<string>
using namespace std;

class student {
    public:
        string name;
        int rollno;
        float marks;

    public:
        void inputDetails() {
            cout << "Enter Student Name: ";
            getline(cin >> ws, name);
            cout << "Enter Roll No: ";
            cin >> rollno ;
            cout << "Enter Marks: ";
            cin >> marks;
            rollno=46;
         }
        

        void displayDetails() const {
            cout << "\n----Student Details ---- \n";
            cout << "Name : " << name << endl;
            cout << "Roll No. : " << rollno << endl;
           cout << "Marks: " << marks << endl;
      }
};

int main() {
    student s,s1;
    s.inputDetails();
    s.displayDetails();
    s.rollno;
    s1.inputDetails();
    s1.displayDetails();
    s1.rollno;
    return 0;
}