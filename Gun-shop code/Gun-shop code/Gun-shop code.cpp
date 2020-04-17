#include <iostream>
using namespace std;

struct USER
{
	string fname;
	string sname;
	string lname;
	long int USN; //UNIQUE SITIZEN NUMBER (ЕГН)
	long int telephone_number;
	bool license;
};

void createOrder() {

}

void readallOrders() {

}

void deleteanorder() {

}

void updateanorder() {

}

void startuptext() {
    cout << "Welcome to our gun shop programme!\n";
    cout << "What would you like to do" << endl;
    cout << "1. Create a gun order." << endl;
    cout << "2. Show all your gun orders." << endl;
    cout << "3. Update an order." << endl;
    cout << "4. Delete an order." << endl;
    cout << "0. Exit." << endl;
}

int main()
{
    int ans;
    while (true) {
        switch(ans) {
            case 1:
                    break;
            case 2:
                    break;
            case 3:
                    break;
            case 4:
                    break;
            case 0:
            system("cls");
            cout << "Thank you for using our program!";
            return 0;
        }
    }
}

