#include <iostream>
using namespace std;

void createOrder() {

}

void readallOrders() {

}

void deleteanorder() {

}

void updateanorder() {

}

void startup() {
    cout << "Welcome to our gun shop programme!\n";
    cout << "What would you like to do" << endl;
}

void startuptext() {
    cout << "1. Create a gun order." << endl;
    cout << "2. Show all your gun orders." << endl;
    cout << "3. Update an order." << endl;
    cout << "4. Delete an order." << endl;
    cout << "0. Exit." << endl;
}

int main()
{
    int ans;
    startup();
    while (true) {
        startuptext();
        switch(ans) {
            case 1:
                    createOrder();
                    break;
            case 2:
                    readallOrders();
                    break;
            case 3:
                    updateanorder();
                    break;
            case 4:
                    deleteanorder();
                    break;
            case 0:
            system("cls");
            cout << "Thank you for using our program!";
            return 0;
        }
    }
}

