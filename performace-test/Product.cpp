#include<iostream>
#include<string>
using namespace std;
class Product {
    private:
     string P_Name;
     string P_ID;
     int P_Price;
     int P_Quantity;
    public:
     Product(string p, string pid, int P, int q) {
        P_Name = p;
        P_ID = pid;
        P_Price = P;
        P_Quantity = q;
     }
     void get_data() {
        cout << "Enter product Quantity for " << P_Name << " : ";
        cin >> P_Quantity;
    }
      int bill() {
        int b = P_Price * P_Quantity;
        cout << "Total bill is : " << b << endl;
        return b;
    }
     void put_data() {
        int b = P_Price * P_Quantity;
        cout << "Product Name is : " << P_Name << endl;
        cout << "Product ID is : " << P_ID << endl;
        cout << "Bill is : " << b << endl;
        cout << "Product quantity is : " << P_Quantity << endl;
    }
};

int main() {
    
    Product chalk("Chalks", "101", 20, 5);
    chalk.get_data();
    chalk.bill();
    chalk.put_data();

    Product pen("Pens", "103", 40, 10);
    pen.get_data();
    pen.bill();
    pen.put_data();

    Product duster("dusters", "103", 10, 2);
    duster.get_data();
    duster.bill();
    duster.put_data();

    return 0;
}