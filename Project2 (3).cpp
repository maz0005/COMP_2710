/*
Marco Zuniga
903662273
Project2.cpp
How to compile:
1. Make sure file is saved and open command prompt.
2. Change directory to 'Documents' by entering 'cd Directory'.
3. Compile by entering the following: "g++ -o Project1 Project2.cpp".
4. Execute the program by entering "./hw2".
The slides from class was the only resource 
used to complete this project.
*/
/**
How code works:
The main program will bring you to the main menu. After loggin in by providing the correct credentials,
one will be sent through methods from the options structure. These methods will handle all other inputs, and options that
the user is given. Eventually exiting out a certain amount of times, you will be brought back to the main method where you can fully 
quit the program.
*/
#include <fstream>
#include <cstddef>
#include <iostream>
#include <cstdlib>
#include <string>
#include <cassert>
#include <cstring>
#include <vector> 
#include <fstream>
#include <algorithm>
using namespace std;


/**
Used to hold all chararacteristics of a brnach staff member
*/

class Employee {
public:
Employee(string nameIn, string passwordIn, string positionIn);
Employee();
//Returns the userName of the employee
string getUserName();
//Returns the password of the employee
string getPassword();
//Returns the position of the employee
string getPosition();
//Prints the menu for the employee based off the position
void menu();
//Sets the userName
void setName(string nameIn);
//Sets the password
void setPassword(string passwordIn);
//Sets the position
void setPosition(string positionIn);
private:
//Holds the user name of the employee
string userName;
//Holds the password for the employee
string password;
//Holds the position for the employee
string position;
};

struct Account {
public:
Account();
//increments accountCount
void incrementCount();
//Returns the first account number
string getAccount1();
//returns the second account number
string getAccount2();
//Returns accountCount
int getCount();
//Sets a value for accountCount. Only used when reading from file.
void setCount(int countIn);
//Sets the account type fro account 1
void setAccount1Type(string accountIn);
//Sets the account type for account 2
void setAccount2Type(string accountIn);
//Sets the account number for account 1
void setAccount1(string accountIn);
//Sets the account number for account 2
void setAccount2(string sccountIn);
//Sets the balance for account 1
void setAccountBalance1(double amountIn);
//Sets the balance for account 2
void setAccountBalance2(double amountIn);
//Adds the value in the parameter to the balance in account 1 and returns the new value.
double addAccount1Balance(double amountIn);
//Adds the value in the parameter to the balance in account 2 and returns the new value.
double addAccount2Balance(double amountIn);
//Subtracts the value in the parameter to the balance in account 1 and returns the new value.
double subAccount1Balance(double amountIn);
//Subtracts the value in the parameter to the balance in account 2 and returns the new value.
double subAccount2Balance(double amountIn);
//Returns the account type for account 1
string getAccount1Type();
//Returns the amount type for account 2
string getAccount2Type();
//Returns the balance for account 1
double getAccount1Balance();
//Returns the balance for account 2
double getAccount2Balance();

private:
//Holds how many accounts the client has. Max is 2
int accountCount;
//Holds the type of account for account 1
string account1Type;
//Holds the type of account for account 2
string account2Type;
//Holds the account number for account 1
string account1;
//Holds the account number for account 2
string account2;
//Holds the balance for account 1
double account1Balance;
//Holds the balance for account 2
double account2Balance;
};

class client {
public:
client(string nameIn, string addressIn, string socialIn, string employerIn, string incomeIn);
client();
//Returns the name of the client
string getName();
//Sets the name of the cient
void setName(string nameIn);
//Sets the address of the client
void setAddress(string addressIn);
//Sets the social security of the client
void setSocial(string socialIn);
//Sets the employer of the client
void setEmployer(string employerIn);
//Sets the annual income of the client
void setAnnualIncome(string incomeIn);
//Outputs the information of the client
void output();
//Creates an account of the client
void createAccount();
//Gets the address of the client
string getAddress();
//Gets the social security of the client
string getSocial();
//Gets employer of the client
string getEmployer();
//Gets the annual income of the client
string getIncome();

Account account;
private:
//Holds the name of the client
string name;
//Holds the address of the client
string address;
//Holds the social security of the client
string socialSec;
//Holds the employer of the client 
string employer;
//Holds the annual income of the client
string annualIncome;
};

struct myOptions {
//Runs the option selected by the employee
int runOption(int optionIn, Employee* employeeIn, vector<Employee>& currentStaffIn, vector<client>& allClientsIn);
//Manages client and account information
void management(vector<client>& allClientsIn);
};

/** 
*Makes sure changing and seeting password works correctly.
*/
void test_checkPassword();
/** 
*Makes sure an administrator can't add an employee with the same user name.
*/
void test_checkForSameEmployee();
/** 
*Makes sure depositing money works correclty. Same strategy used for withdrawing.
*/
void test_Deposit();

/**
Retrieves the information from the clientInformation.txt file.
*/
void getClientInformation(vector<client>& clientIn);
/**
Saves the updated information to the clientInformation.txt file.
*/
void saveClientInformation(vector<client>& clientIn);


int main() {

    cout << "\nTest Results:\n";
	test_checkPassword();
	test_checkForSameEmployee();
	test_Deposit();
	cout << endl;
srand(time(NULL));
int option;
vector<Employee> currentStaff;
vector<client> allClients;
getClientInformation(allClients);
unsigned i;


Employee firstAdmin("admin", "0000", "System Administrator");
currentStaff.push_back(firstAdmin);

myOptions options; 
bool check = false;

//int firstOption = 1;//One to indicate it's the first time logging in. Make sure it 'admin' 
do {

Employee* employee;
cout << "====================================================================\n"
<< "|           Welcome to the Auburn Branch of Tiger Bank!            |\n"
<< "====================================================================\n"
<< "1) Login\n"
<< "2) Quit\n"
<< "\tPlease choose an option: ";

//do-while loop that will continue until user enters valid option.
do {

//std::cin.getline (option, 100);
cin >> option;

if (cin.fail()) {
cout << "\nInvalid option.\n"
<< "\tPlease choose an option: ";
cin.clear();
cin.ignore(256, '\n');
continue;
}


else if (option == 1) {
	cin.clear();
cin.ignore(256, '\n');
break;
}

else if (option == 2) {
cin.clear();
cin.ignore(256, '\n');
exit(1);
}

else if (option != 1 || option != 2) {
cout << "\nInvalid option.\n"
<< "\tPlease choose an option: ";
cin.clear();
cin.ignore(256, '\n');
continue;	
}

}while(true);

cout << endl;
cout << "====================================================================\n"
<< "|           Login to Access the Teller Terminal System             |\n"
<< "====================================================================" << endl;
do {
string userName;
cout << "UserName: ";
//if (firstOption == 1) {   //If it's the first option, you want admin to be the first login
	//cout << "admin";
		//userName = "admin";
		//firstOption = 0;
	//}

//else {
cin >> userName;          //If not the first login, you can login by manually entering a user name.
//}

string password;
cout << "Password: ";
cin >> password;
i = 0;
for (i = 0; i < currentStaff.size(); i++) {
if (!currentStaff[i].getUserName().compare(userName)) {
employee = &currentStaff[i];
break;
}
if ((i + 1) == currentStaff.size() && currentStaff[i].getUserName().compare(userName)) {
check = true;
}

}

if (check == true) {
cout << "The user name or password is incorrect.\n";
check = false;
continue;	
}

if (!employee->getPassword().compare(password)) {   //If the passwords match up
check = false;
break;	
}

else {
	check = false;
cout << "The user name or password is incorrect.\n";
}

}while(true);    //Will continue in loop until valid user name and password is recognized.

do {
employee->menu();
cout << "\tPlease choose an option: ";
cin >> option;

if (cin.fail()) {
cout << "\nInvalid option!\n";
cin.clear();
cin.ignore(256, '\n');
continue;
}

if (options.runOption(option, employee, currentStaff, allClients) == 0){  //Will return 0 if option was to exit
	break;
}
employee = &currentStaff[i];
}while(true);
//employee = NULL;

}while(true); //Loop to make sure you can return to beginning if one wants to exit.



return 0;
}



string Employee::getUserName() {
	return userName;
}


string Employee::getPassword() {
	return password;
}

string Employee::getPosition() {
	return position;
}
/**
void removeEmployee(vector<Employee>& currentStaffIn, int index){
	vector<Employee> holder;
    for (int i = currentStaffIn.size(); i > index; i--){
    	holder.push_back(currentStaffIn.pop_back());
    }
    currentStaffIn.pop_back();

    for (int i = 0; i < holder.size(); i++){
    currentStaffIn.push_back(holder.pop_back());
    }

}
*/

void Employee::menu() {
	cout << endl;
if (!position.compare("System Administrator")) {
cout << "====================================================================\n"
<< "|           Teller Terminal System - System Administration         |\n"
<< "====================================================================\n";
cout << "1) Client and Account Managment\n"
<< "2) Add a branch staff member\n"
<< "3) Delete a branch staff member\n"
<< "4) Display branch staff\n"
<< "5) Change password\n"
<< "6) Exit"
<< endl;
}

else {
cout << "====================================================================\n"
<< "|           Teller Terminal System - Branch Staff                  |\n"
<< "====================================================================\n";
cout << "1) Client and Account Managment\n"
<< "2) Change password\n"
<< "3) Exit"
<< endl;
}

}

void Employee::setName(string nameIn){
	userName.assign(nameIn);
//userName = nameIn;
}
void Employee::setPassword(string passwordIn) {
	password.assign(passwordIn);
//userName = passwordIn;
}

void Employee::setPosition(string positionIn) {
	position.assign(positionIn);
//position = positionIn;
}

void myOptions::management(vector<client>& allClientsIn) {
	int option;
	string account;
	bool stayInLoop = true;
	bool stayInLoop2 = true;
	string name;
	string address;
	string social;
	string employer;
	string income;
	double amount;
	client newClient;
	int secondOption; //To allow the user to either confirm or cancel

do {   //To keep you in loop until someone enters option 6 (Exit)
do {
cout << "============================================================\n"
<< "|  Teller Terminal System - Client and Account Management  |\n"
<< "============================================================\n"
<< "1) Add a client\n"
<< "2) Add an account\n"
<< "3) Edit Client Information\n"
<< "4) Manage an account\n"
<< "5) Save Client And Account Information\n"
<< "6) Exit\n"
<< "\tPlease choose an option: ";
cin >> option;

if (cin.fail() || option < 1 || option > 6) {
cout << "Error - Invalid option!\n";
cin.clear();
cin.ignore(256, '\n');
continue;
}
break;  //Break if you entered a valid option.
}while(true);

switch (option) {
	case 1:     //To add a new client.
	cout << "A new client will be added:\n"
	<< "Client name: ";
	cin >> name;
	cin.clear();
cin.ignore(256, '\n');
	cout << "Address: ";
	cin >> address;
	cin.clear();
cin.ignore(256, '\n');
	cout << "Social security number: ";
	cin >> social;
	cin.clear();
cin.ignore(256, '\n');
	cout << "Employer: ";
	cin >> employer;
	cin.clear();
cin.ignore(256, '\n');
	cout << "Annual income: $";
	cin >> income;
	cin.clear();
cin.ignore(256, '\n');

newClient.setName(name);
newClient.setAddress(address);
newClient.setSocial(social);
newClient.setEmployer(employer);
newClient.setAnnualIncome(income); 

allClientsIn.push_back(newClient);

	cout << "A new client was added!\n";
	cout << "Press any key to continue...";
	cin.ignore().get();
    cout << endl;
    break;
	case 2:  //Add an account

	do {
	cout << "Choose a client: ";
	cin >> name;
	for (unsigned i = 0; i < allClientsIn.size(); i++){

		if (!name.compare(allClientsIn[i].getName())) {
			if (allClientsIn[i].account.getCount() > 1) {
				cout << "\n" << allClientsIn[i].getName() << " already has 2 accounts! You will be brought back to the Menu.\n\n";
				stayInLoop = false;
				break;
			}

				else {
				cout << "A new account will be created for " << allClientsIn[i].getName() << " ...\n";
				allClientsIn[i].createAccount();
				stayInLoop = false;
				break;

				}
		}
		

		else if ((i + 1) == allClientsIn.size() && name.compare(allClientsIn[i].getName())) {
      cout << "Error - The client is not in the system.\n";
      break;
		}
	}
}while(stayInLoop);
stayInLoop = true;

	break;
	case 3:   //Edit client information
	
	do {
	cout << "Choose a client: ";
	cin >> name;
	for (unsigned i = 0; i < allClientsIn.size(); i++){
		if (!name.compare(allClientsIn[i].getName())){
cout << "Display " << allClientsIn[i].getName() << "'s information: \n";
allClientsIn[i].output();
cout << "Client " << allClientsIn[i].getName() << "'s information will be updated ...\n";
	
do {
cout << "1) Confirm\n";
cout << "2) Cancel\n";
cout << "Please enter an option: ";
cin >> secondOption;

if (cin.fail() || secondOption < 1 || secondOption > 2) {
cout << "Error - Invalid option!\n";
cin.clear();
cin.ignore(256, '\n');
continue;
}
break;
}while(true);

if (secondOption == 1){
cin.clear();
cin.ignore(256, '\n');
	cout << "Address: ";
	cin >> address;
	cin.clear();
cin.ignore(256, '\n');
	cout << "Social security number: ";
	cin >> social;
	cin.clear();
cin.ignore(256, '\n');
	cout << "Employer: ";
	cin >> employer;
	cin.clear();
cin.ignore(256, '\n');
	cout << "Annual income: $";
	cin >> income;
	cin.clear();
cin.ignore(256, '\n');

allClientsIn[i].setName(name);
allClientsIn[i].setAddress(address);
allClientsIn[i].setSocial(social);
allClientsIn[i].setEmployer(employer);
allClientsIn[i].setAnnualIncome(income); 
cout << allClientsIn[i].getName() << "'s information was updated!\n";
cout << "Press any key to continue ...";
cin.ignore().get();
    cout << endl;
    stayInLoop = false;
break;
}

else {
	cout << endl;
    stayInLoop = false;
	break;
}


} //End if if statement where it found the corresponding client


} //End of for-loop


if (stayInLoop == true) {
cout << "Error - " << name << " is not in the system.\n";
continue;
}
break;


}while(stayInLoop);
stayInLoop = true;

	break;

	case 4:   //Manage an account
	do {
	cout << "Which account will be managed? ";
	cin >> account;
for (unsigned i = 0; i < allClientsIn.size(); i++){


if (!allClientsIn[i].account.getAccount1().compare(account)){
cout << "Manage account " << allClientsIn[i].account.getAccount1() << " for " << allClientsIn[i].getName() << " ... ";

do {
cout << "\n1) Deposit"
<< "\n2) Withdraw\n"
<< "3) Cancel\n";
cout << "\tPlease choose an option: ";
cin >> option;
if (cin.fail() || option < 1 || option > 3){
	cout << "Invalid input.";
	cin.clear();
cin.ignore(256, '\n');
	continue;
}


if (option == 1){
	do {
	cout << "Deposit Amount: ";
	cin >> amount;
	if (cin.fail()) {
		cout << "Please enter valid amount.\n";
		cin.clear();
cin.ignore(256, '\n');
		continue;
	}
	break;

 }while(true);  //Will keep looping until valid amount entered
cout << "Balance of account " << allClientsIn[i].account.getAccount1() << " is: $" << allClientsIn[i].account.addAccount1Balance(amount); 
}

else if (option == 2){
	do {
	cout << "Withdraw Amount: ";
	cin >> amount;
	if (cin.fail()) {
		cout << "Please enter valid amount.\n";
		cin.clear();
cin.ignore(256, '\n');
		continue;
	}
	break;

 }while(true);  //Will keep looping until valid amount entered
cout << "Balance of account " << allClientsIn[i].account.getAccount1() << " is: $" << allClientsIn[i].account.subAccount1Balance(amount); 
}

else {
	stayInLoop = false;
break;	
}

}while(true);
break;
}
else if (!allClientsIn[i].account.getAccount2().compare(account)){ 
	cout << "Manage account " << allClientsIn[i].account.getAccount2() << " for " << allClientsIn[i].getName() << " ... ";

do {
cout << "\n1) Deposit"
<< "\n2) Withdraw\n"
<< "3) Cancel\n";
cout << "\tPlease choose an option: ";
cin >> option;
if (cin.fail() || option < 1 || option > 3){
	cout << "Invalid input.";
	cin.clear();
cin.ignore(256, '\n');
	continue;
}


if (option == 1){
	do {
	cout << "Deposit Amount: ";
	cin >> amount;
	if (cin.fail()) {
		cout << "Please enter valid amount.\n";
		cin.clear();
cin.ignore(256, '\n');
		continue;
	}
	break;

 }while(true);  //Will keep looping until valid amount entered
cout << "Balance of account " << allClientsIn[i].account.getAccount2() << " is: $" << allClientsIn[i].account.addAccount2Balance(amount); 
}

else if (option == 2){
	do {
	cout << "Withdraw Amount: ";
	cin >> amount;
	if (cin.fail()) {
		cout << "Please enter valid amount.\n";
		cin.clear();
cin.ignore(256, '\n');
		continue;
	}
	break;

 }while(true);  //Will keep looping until valid amount entered
cout << "Balance of account " << allClientsIn[i].account.getAccount2() << " is: $" << allClientsIn[i].account.subAccount2Balance(amount); 
}

else {
	stayInLoop = false;
break;	
}

}while(true);
break;

break;	
}

if ((i + 1) == allClientsIn.size() && allClientsIn[i].account.getAccount1().compare(account) && allClientsIn[i].account.getAccount2().compare(account)) {
cout << "Error - Account " << account << " is not in the system!\n";
do {
cout << "1) Manage an account\n"
<< "2) Cancel\n";
cout << "\tPlease choose an option: ";
cin >> option;

if (cin.fail() || option < 1 || option > 2) {
	cout << "Invalid input\n";
cin.clear();
cin.ignore(256, '\n');
	}

if (option == 1) {
stayInLoop = true;
break;
}

else {
	stayInLoop = false;
	break;
}






}while(true); //Stay in loop until valid input recognized

} //end of if statement thats checks if last and not equal
} // end of for loop 

}while(stayInLoop);
stayInLoop = true;

	break;
	case 5:  //Save Client and Account Information
	saveClientInformation(allClientsIn);
	break;
	case 6:    //Exit
	cout << endl;
    stayInLoop2 = false;

}

}while(stayInLoop2);


}

//Will return 0 if the option was to exit
int myOptions::runOption(int optionIn, Employee* employeeIn, vector<Employee>& currentStaffIn, vector<client>& allClientsIn) {
int returnValue = 1;
int secondOption;
int numberDisplay = 1;//Used when displaying brnach staff memebers. Want to start with '1'.
string newPassword = "";
string newUserName = "";
string role;
bool checkForName = true; // will be set to true if new userName is already in staff

if (!employeeIn->getPosition().compare("System Administrator")) {
switch (optionIn) {
case 1: //Client and Account Management
management(allClientsIn);
break;

case 2: //Add a branch staff member

do {
cout << "User Name: ";
cin >> newUserName;
for (unsigned i = 0; i < currentStaffIn.size(); i++){
if (!currentStaffIn[i].getUserName().compare(newUserName)){
cout << "Employee with that user name is already in the system!\nPlease pick a different user name.\n";
checkForName = true;
cin.clear();
cin.ignore(256, '\n');
}
else {
checkForName = false;
}
}
}while(checkForName);
checkForName = true;

cout << "Password: ";
cin >> newPassword;
do {
cout << "Role  (1 - Administrator; 2 - Branch Staff): ";
cin >> role;

if (!role.compare("1")) {
role.assign("System Administrator");
break;
}

 else if (!role.compare("2")){
 role.assign("Branch Staff");
 }

 else {
cout << "Error - Invalid option!\n";
cin.clear();
cin.ignore(256, '\n');
continue;
}
break;
}while(true);

do {
cout << "1) Confirm\n";
cout << "2) Cancel\n";
cout << "Please choose an option: ";
cin >> secondOption;

if (cin.fail() || secondOption < 1 || secondOption > 2) {
cout << "Error - Invalid option!\n";
cin.clear();
cin.ignore(256, '\n');
continue;
}
break;
}while(true);

if (secondOption == 1) {
Employee newEmployee(newUserName, newPassword, role);
currentStaffIn.push_back(newEmployee);
cout << "A new branch member is added!\n";
cout << "User Name: " << newEmployee.getUserName() << "  Password: " << newEmployee.getPassword();
cout << "\nPress any key to continue...";
cin.ignore().get();
cout << endl;
}
break;

case 3: //Delete a branch staff member
cout << "Delete a user - User Name: ";
cin >> newUserName;
do {
cout << "1) Confirm\n";
cout << "2) Cancel\n";
cout << "Please choose an option: ";
cin >> secondOption;

if (cin.fail() || secondOption < 1 || secondOption > 2) {
cout << "Error - Invalid option!\n";
cin.clear();
cin.ignore(256, '\n');
continue;
}
break;
}while(true);

if (secondOption == 1) {
for (unsigned i = 0; i < currentStaffIn.size(); i++){

	if (!currentStaffIn[i].getUserName().compare(newUserName)){
		string holder;
		holder.assign(currentStaffIn[i].getUserName());
   currentStaffIn.erase(currentStaffIn.begin() + i);
	checkForName = false;
	cout << "User " << holder << " was deleted!" << endl;
	break;

	}
}

if (checkForName == true) {  //If true means no user found.
	cout << "Warning - User " << newUserName << "is not in the system. No user is deleted!" << endl;
}
checkForName = true;

}

break;

case 4: //Display branch staff
cout << "There are " << currentStaffIn.size() << " user(s) in the system.\n";
for (unsigned i = 0; i < currentStaffIn.size(); i++) {
cout << numberDisplay << ". User Name: " << currentStaffIn[i].getUserName()
<< "  Role: " << currentStaffIn[i].getPosition() << endl;
}
cout << "Press any key to continue...";
cin.ignore().get();
cout << endl;
break;

case 5: //change password
do {
cout << "New Password: ";

cin >> newPassword;
if (cin.fail() || !newPassword.compare(employeeIn->getPassword())) {
cout << "Error - Your new password must be different from the old one!\n";
cin.clear();
cin.ignore(256, '\n');
continue;
}

employeeIn->setPassword(newPassword);
cout << "Password was changed!" << endl;

break;
}while(true);
break;

case 6: //Exit
cout << endl;
returnValue = 0;
break;

default:
cout << "\nInvalid option!" << endl;
}

}

//If branch staff member
else {
switch (optionIn) {
case 1: //Client and Account Management
management(allClientsIn);
break;

case 2: //Change Password
do {
cout << "New Password: ";

cin >> newPassword;
if (cin.fail() || !newPassword.compare(employeeIn->getPassword())) {
cout << "Error - Your new password must be different from the old one!\n";
cin.clear();
cin.ignore(256, '\n');
continue;
}

employeeIn->setPassword(newPassword);
cout << "Password was changed!" << endl;

break;
}while(true);
break;

case 3: //Exit
cout << endl;
returnValue = 0;
break;

default:
cout << "\nInvalid option!" << endl;

}
}

return returnValue;
}

void client::createAccount() {
string accountType;
string accountNumber;
double amountIn;

if (account.getCount() == 0) {
cout << "Account Number: ";
cin >> accountNumber;

cout << "Account Type: ";
cin >> accountType;
do {
cout << "Balance: $";
cin >> amountIn;

if (cin.fail()) {
	cin.clear();
cin.ignore(256, '\n');
cout << "Invalid amount! Please make sure you're entering a valid amount.\n";
continue;
}
break;

}while(true); //Wil remain in loop until valid double entered
 
 account.setAccount1(accountNumber);
 account.setAccount1Type(accountType);
 account.setAccountBalance1(amountIn);
 cout << "A new account was created for " << name << "!\n";
 cout << "Press any key to continue ... ";
 cin.ignore().get();
cout << endl;


}

else {
	cout << "Account Number: ";
cin >> accountNumber;

cout << "Account Type: ";
cin >> accountType;
do {
cout << "Balance: $";
cin >> amountIn;

if (cin.fail() ) {
	cin.clear();
cin.ignore(256, '\n');
cout << "Invalid amount! Please make sure you're entering a valid amount.\n";
continue;
}
break;

}while(true); //Wil remain in loop until valid double entered
 
 account.setAccount2(accountNumber);
 account.setAccount2Type(accountType);
 account.setAccountBalance2(amountIn);
 cout << "A new account was created for " << name << "!\n";
 cout << "Press any key to continue ... ";
 cin.ignore().get();
cout << endl;

}
account.incrementCount();


}

client::client(string nameIn, string addressIn, string socialIn, string employerIn, string incomeIn)
       :name(nameIn),address(addressIn),socialSec(socialIn),employer(employerIn),annualIncome(incomeIn)
{}

client::client()
       :name("No name"),address("No address"),socialSec("No social"),employer("No employer"),annualIncome("No income")
{}

void client::output() {
   cout << "Address: "
	<< address
	<< "\nSocial security number: "
	<< socialSec
	<< "\nEmployer: "
	<< employer 
	<< "\nAnnual income: $"
	<< annualIncome << endl;
}

string client::getName() {
	return name;
}

void client::setName(string nameIn) {
name.assign(nameIn);
}

void client::setAddress(string addressIn){
address.assign(addressIn);
}

void client::setSocial(string socialIn){
socialSec.assign(socialIn);
}

void client::setEmployer(string employerIn){
employer.assign(employerIn);
}

void client::setAnnualIncome(string incomeIn){
annualIncome.assign(incomeIn);
}

string client::getAddress() {
return address;
} 

string client::getSocial(){
	return socialSec;
}
string client::getEmployer(){
	return employer;
}
string client::getIncome(){
	return annualIncome;
}

double Account::addAccount1Balance(double amountIn) {
account1Balance += amountIn; 
return account1Balance;
}
double Account::addAccount2Balance(double amountIn) {
account2Balance += amountIn; 
return account2Balance;
}
double Account::subAccount1Balance(double amountIn) {
account1Balance -= amountIn; 
return account1Balance;
}
double Account::subAccount2Balance(double amountIn) {
account2Balance -= amountIn; 
return account2Balance;
}

Account::Account()
	:accountCount(0), account1Type("Not set"), account2Type("Not set"), account1("Not set"), account2("Not set"), account1Balance(0.00), account2Balance(0.00)
{}

void Account::incrementCount() {
accountCount++;
}
string Account::getAccount1() {
return account1;
}
string Account::getAccount2() {
return account2;
}
void Account::setAccount1Type(string accountIn) {
account1Type.assign(accountIn);
}

void Account::setAccount2Type(string accountIn) {
account2Type.assign(accountIn);
}

void Account::setAccount1(string accountIn) {
account1.assign(accountIn);
}

void Account::setAccount2(string accountIn) {
account2.assign(accountIn);
}

void Account::setAccountBalance1(double amountIn) {
account1Balance = amountIn;
}
void Account::setAccountBalance2(double amountIn) {
account2Balance = amountIn;
}

int Account::getCount() {
	return accountCount;
}

void Account::setCount(int countIn){
accountCount = countIn;
}

string Account::getAccount1Type(){
return account1Type;
}
string Account::getAccount2Type(){
return account2Type;
}
double Account::getAccount1Balance(){
return account1Balance;
}
double Account::getAccount2Balance(){
return account2Balance;
}


Employee::Employee(string nameIn, string passwordIn, string positionIn)
:userName(nameIn), password(passwordIn), position(positionIn)
{}

Employee::Employee()
:userName("No name"), password("No password"), position("No position")
{}


/** 
*Makes sure changing and seeting password works correctly.
*/
void test_checkPassword() {
cout << "Testing test_checkPassword()\n";
Employee employee("example", "1234", "System Administrator");
employee.setPassword("5678");
assert(employee.getPassword().compare("5678") == false);
cout << "Test Passed\n";
}

/** 
*Makes sure an administrator can't add an employee with the same user name.
*/
void test_checkForSameEmployee() {
	bool check = false;
vector<Employee> staff;
cout << "Testing test_checkForSameEmployee()\n";
Employee employee("example", "1234", "System Administrator");
staff.push_back(employee);
for (unsigned i = 0; i < staff.size(); i++){
if (!staff[i].getUserName().compare("example")){
check = true;
}
}
assert (check == true);
cout << "Test Passed\n";
}

/** 
*Makes sure depositing money works correclty. Same strategy used for withdrawing.
*/
void test_Deposit() {
	Account account;
 cout << "Testing test_Deposit()\n"; 
 account.setAccountBalance1(45.0);
assert (account.addAccount1Balance(10) == 55.0);
cout << "Test Passed\n";
}


void getClientInformation(vector<client>& clientIn) {

	ifstream getInf;
	string fileName = "clientInformation.txt";
	getInf.open((char*)fileName.c_str());


if (getInf.fail()) {
cout << "File open failed\n";
exit(1);
}

int index = 0;
string information[100];


	while (getline(getInf, information[index])) {
    index++;
    }

getInf.close();
    if (index != 0) {

     for (int i = 0; i < index; i++) {
     	string nameIn;
     	string addressIn;
     	string socialIn;
     	string employerIn;
     	string incomeIn;



     	//nameIn.assign(information[i].substr(0, information[i].length() - 1));
     	nameIn.assign(information[i]);
     	i++;
     	addressIn.assign(information[i]);
     	i++;
     	socialIn.assign(information[i]);
     	i++;
     	employerIn.assign(information[i]);
     	i++;
     	incomeIn.assign(information[i]);
     	i++;
client currentClient(nameIn, addressIn, socialIn, employerIn, incomeIn);
//------------------------------------------------------------------------------------------------------
 int count; 
 string accountNum;
 string accountType;
 double balance;

if (i == (index - 1)) {
count = atoi(information[i].c_str());
currentClient.account.setCount(count);

}

else {
count = atoi(information[i].c_str());
currentClient.account.setCount(count);
i++;


if (count >= 1) {
accountNum.assign(information[i]);
currentClient.account.setAccount1(accountNum);
 i++;
accountType.assign(information[i]);
currentClient.account.setAccount1Type(accountType);
   i++;


balance = atof(information[i].c_str());
currentClient.account.setAccountBalance1(balance);

}

if (count == 2) {
	i++;
accountNum.assign(information[i]);
currentClient.account.setAccount2(accountNum);
 i++;
accountType.assign(information[i]);
currentClient.account.setAccount2Type(accountType);
   i++;

if (i == (index - 1)) {
balance = atof(information[i].c_str());
currentClient.account.setAccountBalance2(balance);

}

}

} //huge else statement
 

clientIn.push_back(currentClient);
 
} //for-loop
}

}
    

void saveClientInformation(vector<client>& clientIn) {
ofstream outputInf;
string fileName = "clientInformation.txt";
 outputInf.open((char*)fileName.c_str());

if (outputInf.fail()) {
cout << "File open failed\n";
exit(1);
}

 for (unsigned i = 0; i < clientIn.size(); i++){
 	outputInf << clientIn[i].getName() << endl;
 	outputInf << clientIn[i].getAddress() << endl;
 	outputInf << clientIn[i].getSocial() << endl;
 	outputInf << clientIn[i].getEmployer() << endl;
 	outputInf << clientIn[i].getIncome() << endl;

   outputInf << clientIn[i].account.getCount() << endl;
   if (clientIn[i].account.getCount() >= 1){
   outputInf << clientIn[i].account.getAccount1() << endl;
   outputInf << clientIn[i].account.getAccount1Type() << endl;
   outputInf << clientIn[i].account.getAccount1Balance() << endl;
   }

   if (clientIn[i].account.getCount() == 2) {
 outputInf << clientIn[i].account.getAccount2() << endl;
   outputInf << clientIn[i].account.getAccount2Type() << endl;
   outputInf << clientIn[i].account.getAccount2Balance() << endl;
   }

}
outputInf.close();
cout << "\nClient information saved in clientInformation.txt file!\n" << endl;

}