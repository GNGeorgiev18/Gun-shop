#include <iostream>
#include <string>
using namespace std;



struct USER
{
	string fname;
	string sname;
	string lname;
	string telephone_number;
	string USN; //UNIQUE SITIZEN NUMBER (ЕГН)
	enum LICENSES license;
};

USER user[10];

enum LICENSES { license1, license2, license3, none };


string couttypes(LICENSES ae) {
	if (ae == license1) {
		return "Low Caliber";
	}
	else if (ae == license2) {
		return "Medium Caliber";
	}
	else if (ae == license3) {
		return "High Caliber";
	}
}



bool check_usn(string usn, USER userask) {

	if (userask.USN == usn) {
		return true;
	}
	else {
		return false;
	}
}

bool checkt_number(string num, USER userask) {

	if (userask.telephone_number == num) {
		return true;
	}
	else {
		return false;
	}
}

bool check_names(string one, string two, string three) {
	for (int i = 0; i <= 10; i++)
	{
		if (user[i].fname == one and user[i].sname == two and user[i].lname == three) {
			return true;
		}
	}
	return false;
}

USER getUserbyNames(string f, string s, string l) {
	for (int i = 0; i <= 10; i++)
	{
		if (user[i].fname == f, user[i].sname == s, user[i].lname == l) {
			return user[i];
		}
	}
}

void checkLicense()
{
	string name1, name2, name3, usn, num;
	cout << "Type First Second and Last Name: ";
	cin >> name1 >> name2 >> name3;
	if (check_names(name1, name2, name3) == true) {
		USER you = getUserbyNames(name1, name2, name3);
		string numb;
		cout << "Enter USN: "; cin >> numb;
		system("cls");
		cout << endl << "License: ";
		if (check_usn(numb, you) == true) {
			cout << couttypes(you.license);
		}
		else {
			cout << "None";
		}
	}
	else {
		system("cls");
		cout << "License: None";
	}
	cout << endl << endl;
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
	user[0] = { "Ivan", "Stoikov", "Sotirov", "0887405818", "0123456789",license2 };
	user[1] = { "Georgi", "Georgiev", "Sotirov", "0884568312", "0832340987",license1 };
	user[2] = { "Ivailo", "Ivanov", "Bonev", "0884378475", "3928930495",license2 };
	user[3] = { "Angel", "Iordanov", "Dimov", "0883758473", "3748329282",license3 };
	user[4] = { "Qnislav", "Tihomirov", "Atanasov", "0888378234", "3456789345",license1 };
	while (true)
	{
		startuptext();
		cin >> ans;
		switch (ans)
		{
		case 1:
			checkLicense();
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