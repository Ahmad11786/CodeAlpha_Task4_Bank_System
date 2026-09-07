#include<iostream>
#include<windows.h>
#include<string>
#include<ctime>
#include<iomanip>
using namespace std;
const int MAX_CUSTOMERS=50;
const int MAX_ACCOUNTS=100;
const int MAX_TRANSACTIONS=500;
string accountno() {
	string accountNo;
	while(true) {
		getline(cin,accountNo);
		bool valid = true;
		if(accountNo.length() != 13)
			valid = false;
		else {
			for(int i=0; i<13; i++) {
				if(!isdigit(accountNo[i])) {
					valid = false;
					break;
				}
			}
		}
		if(valid)
			return accountNo;
		cout<< "\nEnter valid 13-digit CNIC\n";
	}
}

string Password() {
	string pass, dob, cnic;
	while(true) {
		getline(cin, pass);
		bool alpha=false;
		bool digit=false;
		for(int i=0; i<pass.length(); i++) {
			if(pass[i]>='A' && pass[i]<='Z') {
				alpha=true;
			}
			if(pass[i]>='0' && pass[i]<='9') {
				digit=true;
			}
		}
		if(alpha && digit && pass.length()>=8) {
			return pass;
		} else {

			cout<<"\nWeak Password\n";
			cout<<"Password must contain:\n";
			cout<<"- Minimum 8 characters\n";
			cout<<"- One capital letter\n";
			cout<<"- One digit\n";
		}
	}
}

string names() {
	cin.ignore();
	string name;
	while(true) {
		getline(cin,name);
		bool valid = true;
		if(name.length() < 3) {
			valid = false;
		} else {
			bool spaceFound = false;
			for(int i = 0; i < name.length(); i++) {
				if(name[i] == ' ')
					spaceFound = true;
				if(!isalpha(name[i]) && name[i] != ' ') {
					valid = false;
					break;
				}
			}
			if(!spaceFound)
				valid = false;
		}
		if(valid)
			return name;
		cout<< "Invalid Name! Name must contain only alphabets, and be at least 3 characters long.\n";
	}

}

class Account {
	private:
		long long accountNumber;
		int customerId;
		string accountType;
		double balance;
		string password;
		string mpin;
		bool isBlocked;
	public:
		Account() {
			accountNumber=0;
			customerId=0;
			balance=0;
			isBlocked=false;
		}
		long long getAccountNumber() {
			return accountNumber;
		}
		int getCustomerId() {
			return customerId;
		}
		double getBalance() {
			return balance;
		}
		void createAccount(int id,long long accNo) {
			customerId=id;
			accountNumber=accNo;
			int choice;
			cout<<"\n---------------------- Create Account ----------------------\n";
			cout<<"Customer ID: "<<customerId<<endl;
			do {
				cout<<"Enter Account Type : \n1) Saving\t2)Current): ";
				cin>>choice;
				switch(choice) {
					case 1:
						accountType="saving";
						break;
					case 2:
						accountType="current";
						break;
					default :
						cout << "Invalid choice! Please enter a valid option.";
						break;
				}
			} while (choice != 1 && choice != 2);
			cin.ignore();
			cout<<"Enter Password: ";
			password=Password();
			do {
				cout << "Enter 4-digit MPIN: ";
				cin >> mpin;
				bool valid = (mpin.length() == 4);
				for (char c : mpin) {
					if (!isdigit(c)) {
						valid = false;
						break;
					}
				}
				if (!valid) {
					cout << "Invalid MPIN! MPIN must contain exactly 4 digits.\n";
				}
				if (valid)
					break;
			} while (true);
			while(true) {
				cout<<"Enter Opening Balance: ";
				cin>>balance;
				if(balance<500) {
					cout<<"Insufficiant balance for opening Account \n";
					continue;
				}
				break ;
			}
			isBlocked=false;
		}
		bool login(long long acc,string pass) {
			if(acc==accountNumber&&pass==password) {
				if(isBlocked) {
					cout<<"\nYour account is blocked!\n";
					return false;
				}
				cout<<"\nSuccessful Login!\n";
				return true;
			}
			return false;
		}
		void displayAccount() {
			cout<<"\n-------------------- Account Details --------------------\n";
			cout<<"\nCustomer ID      : "<<customerId;
			cout<<"\nAccount Number   : "<<accountNumber;
			cout<<"\nAccount Type     : "<<accountType;
			cout<<"\nBalance          : Rs. "<<fixed<<setprecision(2)<<balance;
			cout<<"\nPassword         : ********";
			cout<<"\nAccount MPIN     : ****\n";
		}
		bool deposit(double amount) {
			if(amount<=0) {
				cout<<"\nInvalid deposit amount!\n";
				return false;
			}
			balance+=amount;
			cout<<"\nDeposit successful!\n";
			cout<<"Deposited Amount : Rs. "<<amount<<endl;
			cout<<"New Balance      : Rs. "<<balance<<endl;
			return true;
		}
		bool withdraw(double amount,string enteredMpin) {
			if(enteredMpin!=mpin) {
				cout<<"\nInvalid MPIN!\n";
				return false;
			}
			if(amount<=0) {
				cout<<"\nInvalid withdrawal amount!\n";
				return false;
			}
			if(amount>balance) {
				cout<<"\nInsufficient balance!\n";
				return false;
			}
			balance-=amount;
			cout<<"\nWithdrawal successful!\n";
			cout<<"Withdrawn Amount : Rs. "<<amount<<endl;
			cout<<"Remaining Balance: Rs. "<<balance<<endl;
			return true;
		}
		bool transfer(Account &receiver,double amount,string enteredMpin) {
			if(enteredMpin!=mpin) {
				cout<<"\nInvalid MPIN!\n";
				return false;
			}
			if(amount<=0) {
				cout<<"\nInvalid transfer amount!\n";
				return false;
			}
			if(amount>balance) {
				cout<<"\nInsufficient balance!\n";
				return false;
			}
			balance-=amount;
			receiver.balance+=amount;
			cout<<"\nTransfer successful!\n";
			cout<<"Transferred Amount : Rs. "<<amount<<endl;
			cout<<"Remaining Balance  : Rs. "<<balance<<endl;
			return true;
		}
};

Account account[MAX_ACCOUNTS];

class Transaction {
	private:
		long long transactionId;
		long long accountNumber;
		string type;
		double amount;
		double balanceAfter;
		string date;
		string description;
	public:
		void createTransaction(long long id,long long accNo,string transactionType,double transactionAmount,double balance,string transactionDate,string transactionDescription) {
			transactionId=id;
			accountNumber=accNo;
			type=transactionType;
			amount=transactionAmount;
			balanceAfter=balance;
			date=transactionDate;
			description=transactionDescription;
		}
		long long getAccountNumber() {
			return accountNumber;
		}
		void displayTransaction() {
			cout<<"\n---------------- Transaction ----------------\n";
			cout<<"Transaction ID : "<<transactionId<<endl;
			cout<<"Account Number : "<<accountNumber<<endl;
			cout<<"Type           : "<<type<<endl;
			cout<<"Amount         : Rs. "<<fixed<<setprecision(2)<<amount<<endl;
			cout<<"Balance After  : Rs. "<<balanceAfter<<endl;
			cout<<"Date           : "<<date<<endl;
			cout<<"Description    : "<<description<<endl;
		}
};

Transaction trans[MAX_TRANSACTIONS];

class Customer {
	private:
		int customerId;
		string name;
		string dofB;
		string cnic;
		string phone;
		string address;
	public:
		Customer() {
			customerId=0;
		}
		int getCustomerId() {
			return customerId;
		}
		void createCustomer(int id) {
			customerId=id;
			cout<<"\n-------------------- Create New Customer --------------------\n";
			cin.ignore();
			cout<<"\nEnter User Name: ";
			name=names();
			cout<<"Enter Phone No.: ";
			getline(cin,phone);
			cout<<"Enter CNIC No.: ";
			cnic=accountno();
			cout<<"Enter Address: ";
			getline(cin,address);
			cout<<"Enter Date of Birth (mm/dd/yy): ";
			getline(cin,dofB);
		}
		void displayProfile() {
			cout<<"\n---------------- Customer Profile ----------------\n";
			cout<<"Customer ID    : "<<customerId<<endl;
			cout<<"Name           : "<<name<<endl;
			cout<<"Phone          : "<<phone<<endl;
			cout<<"CNIC           : "<<cnic<<endl;
			cout<<"Address        : "<<address<<endl;
			cout<<"Date of Birth  : "<<dofB<<endl;
		}
};

Customer cust[MAX_CUSTOMERS];

int customerCount=0;
int accountCount=0;
int transactionCount=0;

string getCurrentDate() {
	time_t now=time(0);
	tm *localTime=localtime(&now);
	char date[20];
	strftime(date,sizeof(date),"%d/%m/%Y",localTime);
	return string(date);
}

int findCustomer(int customerId) {
	for(int i=0; i<customerCount; i++) {
		if(cust[i].getCustomerId()==customerId)
			return i;
	}
	return -1;
}

int findAccount(long long accountNumber) {
	for(int i=0; i<accountCount; i++) {
		if(account[i].getAccountNumber()==accountNumber)
			return i;
	}
	return -1;
}
void addTransaction(long long accountNumber,string type,double amount,double balance,string description) {
	if(transactionCount>=MAX_TRANSACTIONS) {
		cout<<"\nTransaction storage is full!\n";
		return;
	}
	trans[transactionCount].createTransaction(
	    transactionCount+1,
	    accountNumber,
	    type,
	    amount,
	    balance,
	    getCurrentDate(),
	    description
	);
	transactionCount++;
}
void viewTransactionHistory(long long accountNumber) {
	bool found=false;
	cout<<"\n------------------------ Transaction History ------------------------\n";
	for(int i=0; i<transactionCount; i++) {
		if(trans[i].getAccountNumber()==accountNumber) {
			trans[i].displayTransaction();
			found=true;
		}
	}
	if(!found)
		cout<<"\nNo transactions found for this account.\n";
}
void customerMenu(int loggedInAccountIndex) {
	int choice;
	while(true) {
		cout<<"\n--------------------------- Customer Menu ---------------------------\n";
		cout<<"1) View Profile\n";
		cout<<"2) View Account\n";
		cout<<"3) Deposit Money\n";
		cout<<"4) Withdraw Money\n";
		cout<<"5) Transfer Money\n";
		cout<<"6) View Transaction History\n";
		cout<<"7) Logout\n\n";
		cout<<"Choice: ";
		cin>>choice;
		switch(choice) {
			case 1: {
				int customerId=account[loggedInAccountIndex].getCustomerId();
				int customerIndex=findCustomer(customerId);
				if(customerIndex!=-1)
					cust[customerIndex].displayProfile();
				break;
			}
			case 2:
				account[loggedInAccountIndex].displayAccount();
				break;
			case 3: {
				double amount;
				cout<<"\n-------------------- Deposit Money --------------------\n";
				cout<<"Enter Deposit Amount: Rs. ";
				cin>>amount;
				if(account[loggedInAccountIndex].deposit(amount)) {
					addTransaction(
					    account[loggedInAccountIndex].getAccountNumber(),
					    "Deposit",
					    amount,
					    account[loggedInAccountIndex].getBalance(),
					    "Cash deposit"
					);
				}
				break;
			}
			case 4: {
				double amount;
				string mpin;
				cout<<"\n-------------------- Withdraw Money --------------------\n";
				cout<<"Enter Withdrawal Amount: Rs. ";
				cin>>amount;
				cout<<"Enter MPIN: ";
				cin>>mpin;
				if(account[loggedInAccountIndex].withdraw(amount,mpin)) {
					addTransaction(
					    account[loggedInAccountIndex].getAccountNumber(),
					    "Withdrawal",
					    amount,
					    account[loggedInAccountIndex].getBalance(),
					    "Cash withdrawal"
					);
				}
				break;
			}
			case 5: {
				long long receiverAccountNumber;
				double amount;
				string mpin;
				cout<<"\n-------------------- Transfer Money --------------------\n";
				cout<<"Enter Receiver Account Number: ";
				cin>>receiverAccountNumber;
				int receiverIndex=findAccount(receiverAccountNumber);
				if(receiverIndex==-1) {
					cout<<"\nReceiver account not found!\n";
					break;
				}
				if(receiverIndex==loggedInAccountIndex) {
					cout<<"\nYou cannot transfer money to your own account!\n";
					break;
				}
				cout<<"Enter Transfer Amount: Rs. ";
				cin>>amount;
				cout<<"Enter MPIN: ";
				cin>>mpin;
				if(account[loggedInAccountIndex].transfer(account[receiverIndex],amount,mpin)) {
					addTransaction(
					    account[loggedInAccountIndex].getAccountNumber(),
					    "Transfer",
					    amount,
					    account[loggedInAccountIndex].getBalance(),
					    "Transfer to Account "+to_string(receiverAccountNumber)
					);
					addTransaction(
					    account[receiverIndex].getAccountNumber(),
					    "Received",
					    amount,
					    account[receiverIndex].getBalance(),
					    "Received from Account "+to_string(account[loggedInAccountIndex].getAccountNumber())
					);
				}
				break;
			}
			case 6:
				viewTransactionHistory(account[loggedInAccountIndex].getAccountNumber());
				break;
			case 7:
				cout<<"\nLogging out...\n";
				Sleep(1000);
				return;
			default:
				cout<<"\n======================================================\n";
				cout<<"                  Invalid Choice!\n";
				cout<<"      Please select a valid option from the menu.\n";
				cout<<"======================================================\n";
				break;
		}
	}
}
int main() {
	int choice;
	while(true) {
		cout<<"\n----------------------------- Bank System -----------------------------\n";
		cout<<"1) Login / Sign In\n";
		cout<<"2) Sign Up\n";
		cout<<"3) Exit\n\n";
		cout<<"Choice: ";
		cin>>choice;
		switch(choice) {
			case 1: {
				if(accountCount==0) {
					cout<<"\nNo accounts have been created yet.\n";
					break;
				}
				long long acc;
				string pass;
				cout<<"\n----------- Login / Sign In -----------\n";
				cout<<"Enter Account Number: ";
				cin>>acc;
				cin.ignore();
				cout<<"Enter Password: ";
				getline(cin,pass);
				int accountIndex=findAccount(acc);
				if(accountIndex==-1) {
					cout<<"\nInvalid Account Number or Password!\n";
					break;
				}
				if(account[accountIndex].login(acc,pass))
					customerMenu(accountIndex);
				break;
			}
			case 2: {
				int signupChoice;
				cout<<"\n----------- Sign Up -----------\n";
				cout<<"1) Create Customer\n";
				cout<<"2) Create Account\n";
				cout<<"3) Go Back\n\n";
				cout<<"Choice: ";
				cin>>signupChoice;
				switch(signupChoice) {
					case 1:
						if(customerCount>=MAX_CUSTOMERS) {
							cout<<"\nCustomer storage is full!\n";
							break;
						}
						cust[customerCount].createCustomer(customerCount+1);
						cout<<"\nCustomer created successfully!\n";
						cout<<"Customer ID: "<<customerCount+1<<endl;
						customerCount++;
						break;
					case 2: {
						if(customerCount==0) {
							cout<<"\nPlease create a customer first!\n";
							break;
						}
						if(accountCount>=MAX_ACCOUNTS) {
							cout<<"\nAccount storage is full!\n";
							break;
						}
						int customerId;
						long long accountNumber;
						cout<<"\nEnter Customer ID for this account: ";
						cin>>customerId;
						if(findCustomer(customerId)==-1) {
							cout<<"\nCustomer ID not found!\n";
							break;
						}
						cout<<"Enter Account Number: ";
						cin>>accountNumber;
						if(findAccount(accountNumber)!=-1) {
							cout<<"\nAccount Number already exists!\n";
							break;
						}
						account[accountCount].createAccount(customerId,accountNumber);
						accountCount++;
						cout<<"\nAccount created successfully!\n";
						break;
					}
					case 3:
						cout<<"\nReturning to Main Menu...\n";
						Sleep(1000);
						break;
					default:
						cout<<"\n=================================================\n";
						cout<<"              Invalid Choice!\n";
						cout<<"   Please select a valid option from the menu.\n";
						cout<<"=================================================\n";
						break;
				}
				break;
			}
			case 3:
				cout<<"\n==============================================\n";
				cout<<"        Thank You for Banking With Us!\n";
				cout<<"        Your security is our priority.\n";
				cout<<"        Have a safe and wonderful day!\n";
				cout<<"==============================================\n";
				Sleep(1000);
				return 0;
			default:
				cout<<"\n=================================================\n";
				cout<<"              Invalid Choice!\n";
				cout<<"   Please select a valid option from the menu.\n";
				cout<<"=================================================\n";
				break;
		}
	}
	return 0;
}