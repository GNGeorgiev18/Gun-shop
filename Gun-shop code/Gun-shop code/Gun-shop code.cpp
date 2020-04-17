#include <iostream>
using namespace std;

struct USER;
{
	string fname;
	string sname;
	string lname;
	long int telephone_number;
	long int USN; //UNIQUE SITIZEN NUMBER (ЕГН)
	enum LICENSES license;
};

USER user[10];

enum LICENSES{license1, license2, license3, none};

void checkUser()
{
	cout << "First Name: ";
	cin >> user[0].fname;
	cout << "Second Name: ";
	cin >> user.sname;
	cout << "Last Name: ";
	cin >> user.lname;
	cout << "First telephone_number: ";
	cin >> user.telephone_number;
	cout << "USN: ";
	cin >> user.USN;
	
}

void createOrder() 
{

}

void deleteanorder() 
{

}

void sortprice()
{

}

void findOrder() 
{

}

void readallOrders() 
{

}

void updateanorder() 
{

}

void startup() 
{
    cout << "Welcome to our gun shop programme!\n";
    cout << "What would you like to do" << endl;
}

void startuptext() 
{
    cout << "1. Create a gun order." << endl;
    cout << "2. Show all your gun orders." << endl;
    cout << "3. Update an order." << endl;
    cout << "4. Delete an order." << endl;
    cout << "0. Exit." << endl;
}

int main()
{
	int ans{};
    startup();
	user[0] = { "Ivan", "Stoikov", "Sotirov", "0887405818", "0123456789" };
    while (true) 
	{
        startuptext();
		cin >> ans;
        switch(ans) 
		{
            case 1:
                    checkUser();
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

