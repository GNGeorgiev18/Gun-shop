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

struct GUN {
	string name;
	enum TYPE type;
	double value;
};

struct ORDER {
	USER creator;
	GUN guns[3];
	int total = 0;
	bool isCreated = false;
};

///Global Variables

USER user[10]; // All Users
USER loggedin; // The person that is logged in.
GUN allguns[45]; // All the guns!
ORDER orders[10]; //All the orders!

enum LICENSES { license1, license2, license3 }; // All Licenses
enum TYPE { Pistol, Rifle, SMG, Shotgun }; // Types Of Guns

bool IsRegistered = false; // /If anybody is loggged in


void minuses(int amount) {
	cout << endl;
	for (int i = 1; i <= amount; i++) {
		cout << "-";
	}
	cout << endl;
}



string couttypes(LICENSES ae) { // Counts and returns in string the type of License.
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

string numWord(int input) {
	if (input == 1)
		return "st";
	if (input == 2)
		return "nd";
	if (input == 3)
		return "rd";
	if (input > 3)
		return "th";
}

bool check_usn(string usn, USER userask) {  // Checks the USN (EGN) 

	if (userask.USN == usn) {
		return true;
	}
	else {
		return false;
	}
}

bool checkt_number(string num, USER userask) { // Checks Telephone Number

	if (userask.telephone_number == num) {
		return true;
	}
	else {
		return false;
	}
}

bool check_names(string one, string two, string three) { // Checks inputed names if they exist. They return bool typee.
	for (int i = 0; i < 10; i++)
	{
		if (user[i].fname == one and user[i].sname == two and user[i].lname == three) {
			return true;
		}
	}
	return false;
}

USER getUserbyNames(string f, string s, string l) { // Gets Useer by all of the names.
	for (int i = 0; i < 10; i++)
	{
		if (user[i].fname == f, user[i].sname == s, user[i].lname == l) {
			return user[i];
		}
	}
}

void checkLicense() // Checks if the person has license.
{
	string name1, name2, name3, usn, num;
	cout << "Type First Second and Last Name: ";
	cin >> name1 >> name2 >> name3;
	if (check_names(name1, name2, name3) == true) {
		system("CLS");
		USER you = getUserbyNames(name1, name2, name3);
		string numb;
		cout << "Enter USN: "; cin >> numb;
		while (cin.fail()) {

			cout << "Enter a number, please!" << endl;

			cin.clear();

			cin.ignore(256, '\n');

			cin >> EnteredNumbers[0];

		}
		system("cls");
		cout << endl << "License: ";
		if (check_usn(numb, you) == true) {
			loggedin = you;
			cout << couttypes(you.license) << endl;
			cout << "Welcome " << you.fname << "!" << endl;
			IsRegistered = true;
		}
		else {
			IsRegistered = false;
			cout << "None";
		}
	}
	else {
		system("cls");
		cout << "License: None";
	}
	cout << endl << endl;
}

void showGuns() // Shows out the guns
{
	for (int i = 0; i < 10; i++)
	{
		cout << i + 1 << ". " << allguns[i].name << " = " << "$" << allguns[i].value << endl;
	}
	return;
}

void showOrders() { // Shows all Orders that have vales
	for (int i = 0; i < 10; i++) {
		if (orders[i].isCreated != false) {
			cout << "Order #" << i + 1 << "  [" << orders[i].creator.fname << "]  " << " - $" << orders[i].total << endl;
		}
	}
}


bool isNullOrder() //  Checks if there is an empty order slot
{
	for (int i = 0; i < 10; i++)
	{
		if (orders[i].isCreated != true)
		{
			return true;
		}
	}
	return false;
}

int getNullOrder() // Find an order that is NULL
{
	for (int i = 0; i < 10; i++)
	{
		if (orders[i].isCreated == false)
		{
			return i;
		}
	}
	return -1;
}

int countAllOrders() {
	int counter = 0;
	for (int i = 0; i < 10; i++) {
		if (orders[i].isCreated == true) {
			counter++;
		}
	}
	return counter;
}

void cleanOrder(int id) { // Deletes Edited Stuff in an Order
	GUN emptygun = {};
	orders[id].total = 0;
	for (int i = 0; i < 3; i++)
		orders[id].guns[i] = emptygun;
}


void createOrder()
{
	GUN emptygun = {};
	int num = getNullOrder();
	if (num == -1) {
		minuses(50);
		cout << "All orders are full!" << endl;
		minuses(50);
		return;
	}
	int amount = 0;
	int total = 0;
	while (true)
	{
		minuses(50);
		cout << "1. Select a gun!" << endl;
		cout << "2. Cancel a gun!" << endl;
		cout << "3. Proceed to checkout!" << endl;
		cout << "0. Cancel the Order." << endl;
		minuses(50);
		int input;
		cin >> input;
		while (cin.fail()) {

			cout << "Enter a number, please!" << endl;

			cin.clear();

			cin.ignore(256, '\n');

			cin >> EnteredNumbers[0];

		}
		switch (input)
		{
		case 1:
		{
			int gun1;
			if (amount >= 3) { minuses(50); cout << "Only 3 Guns are allowed per user to buy." << endl; minuses(50); break; }
			system("CLS");
			minuses(50);
			showGuns();
			minuses(50);
			cout << endl;
			cin >> gun1;
			while (cin.fail()) {

				cout << "Enter a number, please!" << endl;

				cin.clear();

				cin.ignore(256, '\n');

				cin >> EnteredNumbers[0];

			}
			if (isNullOrder() == true && amount < 3)
			{
				for (int i = 0; i < 10; i++)
				{
					if (gun1 == i)
					{
						orders[num].guns[amount] = allguns[i - 1];
						amount++;
						total += allguns[i - 1].value;
						minuses(50);
						cout << "Gun has been added!" << endl;
						minuses(50);
					}
				}
			}
			break;
		}
		case 2:
		{
			int gun1;
			if (amount <= 0) {
				minuses(50);
				cout << "No guns Found in the Cart!" << endl;
				minuses(50);
				break;
			}
			system("CLS");
			minuses(50);
			for (int i = 0; i < amount; i++)
			{
				cout << i + 1 << ". " << orders[num].guns[i].name << " - $" << orders[num].guns[i].value << endl;
			}


			minuses(50);
			cout << "Please enter a gun's position number." << endl;
			cin >> gun1;
			while (cin.fail()) {

				cout << "Enter a number, please!" << endl;

				cin.clear();

				cin.ignore(256, '\n');

				cin >> EnteredNumbers[0];

			}
			minuses(50);

			if (gun1 > amount) { minuses(50); cout << "Please enter a valid gun slot!"; minuses(50); }

			for (int i = gun1; i <= amount; i++)
			{
				if (i != amount) {
					orders[num].guns[i - 1] = orders[num].guns[i];
				}
				else {
					orders[num].guns[i] = emptygun;
				}
				amount--;
				total -= allguns[gun1 - 1].value;
				minuses(50);
				cout << "Gun has been removed." << endl;
				minuses(50);
			}
			break;
		}
		case 3:
		{
			if (amount <= 0) { minuses(50); cout << "No guns have been added to the cart!" << endl; minuses(50); break; }
			minuses(50);
			cout << "Would you like to purchase the following guns: " << endl;
			for (int i = 0; i < amount; i++)
				cout << orders[num].guns[i].name << " - $" << orders[num].guns[i].value << endl;
			cout << endl << endl;
			minuses(50);
			minuses(50);
			cout << "Total: $" << total << endl;
			minuses(50);
			cout << "1. Yes" << endl << "2. No" << endl;
			int a; cin >> a;
			while (cin.fail()) {

				cout << "Enter a number, please!" << endl;

				cin.clear();

				cin.ignore(256, '\n');

				cin >> EnteredNumbers[0];

			}
			minuses(50);
			switch (a) {
			case 1: {
				orders[num].creator = loggedin;
				orders[num].isCreated = true;
				orders[num].total = total;
				cout << endl << "The order has been created!" << endl;
				minuses(50);
				return;
			}
			case 2: {
				cout << endl << "The order has been canceled." << endl;
				cleanOrder(num);
				break;
			}
			}
			break;
		}
		case 0: {
			cleanOrder(num);
			cout << endl << "Order has been canceled!" << endl;
			break;
		}
		}
	}
}

void deleteanorder()
{
	ORDER emptyOrder = {};
	minuses(50);
	showOrders();
	minuses(50);

	cout << "Which order would you like to delete?" << endl;
	cout << "Please answer with the beggining number of the order!" << endl;

	minuses(50);
	int ans; cin >> ans;
	while (cin.fail()) {

		cout << "Enter a number, please!" << endl;

		cin.clear();

		cin.ignore(256, '\n');

		cin >> EnteredNumbers[0];

	}
	minuses(50);

	if (orders[ans - 1].isCreated == false) { minuses(50); cout << "The " << ans << numWord(ans) << " order has not been found."; minuses(50); }

	for (int i = ans; i <= countAllOrders() + 1; i++) {
		if (i != countAllOrders()) {
			orders[i - 1] = orders[i];
		}
		else {
			orders[i - 1] = emptyOrder;
		}
	}
	cout << "The " << ans << numWord(ans) << " order has been removed." << endl;
}

void readallOrders()
{
	cout << "All Orders: " << endl;
	minuses(50);
	if (orders[0].isCreated == false) {
		cout << "No orders have been made yet!" << endl;
		minuses(50);
		return;
	}
	for (int i = 0; i < 10; i++) {
		if (orders[i].isCreated == true) {
			cout << "Order #" << i + 1 << "  [" << orders[i].creator.fname << "]  " << " - $" << orders[i].total << endl;
		}
	}
	minuses(50);
}
//A bunch of texts
void startup()
{
	cout << "Welcome to our gun shop programme!\n";
	cout << "What would you like to do" << endl;
}


void startuptext()
{
	cout << "1. Log in a member and check license." << endl;
	cout << "0. Exit." << endl;
}

void ordertext() {
	cout << "1. Create an Order" << endl;
	cout << "2. Show Orders" << endl;
	cout << "3. Delete an Order" << endl;
	cout << "0. Exit the account" << endl;
}


int main()
{

	// Gun Variables
	allguns[0] = { "SD9 VE",Pistol,395.00 };
	allguns[1] = { "Glock 18",Pistol,3000.00 };
	allguns[2] = { "Springfield Hellcat",Pistol,569.00 };
	allguns[3] = { "Colt M4 CQB", SMG, 1225.00 };
	allguns[4] = { "Colt M4 Commando", SMG, 1099.00 };
	allguns[5] = { "FN M249 Para", SMG , 7899.00 };
	allguns[6] = { "Beretta 1301", Shotgun, 930.00 };
	allguns[7] = { "Remington 870P", Shotgun, 545.00 };
	//--
	int ans{};
	startup();
	// All Users
	user[0] = { "Ivan", "Stoikov", "Sotirov", "0887405818", "0123456789",license2 };
	user[1] = { "Georgi", "Georgiev", "Sotirov", "0884568312", "0832340987",license1 };
	user[2] = { "Ivailo", "Ivanov", "Bonev", "0884378475", "3928930495",license2 };
	user[3] = { "Angel", "Iordanov", "Dimov", "0883758473", "3748329282",license3 };
	user[4] = { "Qnislav", "Tihomirov", "Atanasov", "0888378234", "3456789345",license1 };
	user[5] = { "Angel", "Veselinov", "Zhelyazkov", "0888888888", "1234567890", license3 };
	user[6] = { "Georgi", "Nedqlkov", "Georgiev", "0887777777","2345678901",license3 };
	user[7] = { "admin", "admin", "admin", "1","1",license3 };

	while (true)
	{
		if (IsRegistered == false) {
			startuptext();
		}
		else {
			ordertext();
		}

		cin >> ans;
		while (cin.fail()) {

			cout << "Enter a number, please!" << endl;

			cin.clear();

			cin.ignore(256, '\n');

			cin >> EnteredNumbers[0];

		}

		if (IsRegistered != true) {
			switch (ans)
			{
			case 1: {
				checkLicense();
				break;
			}
			case 0: {
				system("cls");
				cout << "Thank you for using our program!";
				return 0;
			}
			default: {
				continue;
			}
			}
		}
		else {
			switch (ans)
			{
			case 1: {
				createOrder();
				break;
			}
			case 2: {
				readallOrders();
				break;
			}

			case 3: {
				deleteanorder();
				break;
			}
			case 0: {
				minuses(50);
				cout << "User has logged out!";
				minuses(50);
				IsRegistered = false;
				break;
			}
			default: {
				continue;
			}
			}
		}

	}
}
