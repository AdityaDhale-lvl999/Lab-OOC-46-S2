#include<iostream>
using namespace std;
class Rectangle {
    public :
     float area;
     Rectangle () {
        area = 0;

     }
     Rectangle (int a , int b){
        area = a * b;

     }
     void disp(){
        cout << area << endl;
     }
};
int main (){
    Rectangle O;
    Rectangle O2 (10 , 20);
    O.disp();
    O2.disp();
    return 0;

}