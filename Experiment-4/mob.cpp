#include<iostream>
#include<string>
using namespace std;

class MobileRecharge{
    private:
     string mobno; //10 digit number, treated as string cuz no math done on it
     string currentPlan; //starts as none until first recharge
     double balance;   
     int validityLeft;  //days remaining, 0 until recharged

    public:
    //constructor only takes number and starting balance, plan stuff gets default values maybee i should add const since recharge plans will not change will not change 
    //since a new sim obviously has no active plan yet
    MobileRecharge(string num, double startBal) {
        mobno = num;
        balance = startBal;
        currentPlan = "None";
        validityLeft = 0;
    }

    //recharge overwrites the current plan completely, doesnt merge with old one
    void recharge(double amt, string plan, int validity) {
        balance += amt;
        currentPlan = plan;
        validityLeft = validity;
        cout << "\nRecharged Rs" << amt << " -> Plan: " << plan << endl;
    }

    //this method checks balance. and operator for double condition checking also also this deducts the amount
    //unlimited plan doesnt need the balance so skiping charge is reasnable i guess
    void deductBalance(double amt) {
    if (currentPlan == "Unlimited Calls + 1.5GB/day") {
        cout << "Unlimited plan active — no deduction for calls." << endl;
        return;  // skip charging entirely
    }
    //limited plan needs balance 
    //after passing parameter amt = 49.0 which is less than 20 so it will say insufficient bal changing parameter to less than 20 withh say deducting message.
    if (amt > 0 && amt <= balance) {   
        balance -= amt;
        cout << "Rs" << amt << " deducted for call/sms usage." << endl;
    } else {
        cout << "Insufficient balance!" << endl;
    }
}
//classic display methdod  
     void display() {
        cout << "\n[Mobile Account]" << endl;
        cout << "Mobile Number: " << mobno << endl;
        cout << "Current Plan: " << currentPlan << endl;
        cout << "Validity: " << validityLeft << " days" << endl;
        cout << "Balance: Rs" << balance << endl;
    }
};

int main() {
    MobileRecharge sim1("1122334455", 50.0); //paasing mobile numbers and starting balance via parameters
    MobileRecharge sim2("9988776655", 20.0); //setting initial ball low to it will trigger else statement in dedctbal method 
//displaying and calling methods with parameterized values
    sim1.display();
    sim2.display();

    sim1.recharge(199.0, "Unlimited Calls + 1.5GB/day", 28);
    sim1.deductBalance(20.0);

    sim2.recharge(49.0, "Talktime Only", 0);
    sim2.deductBalance(100.0);   //will fail, not enough balance

    sim1.display();
    sim2.display();

    return 0;
}