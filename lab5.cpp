#include <iostream>

using namespace std;

class BankAccount
{
protected:
	double balance;
	double charge = 0.0;
public:
	BankAccount() { balance = 0.0; };

	virtual void deposit(double amt)
	{
		balance += amt;
		cout << "Your account balance is now : $ " << balance << endl;
	}
	virtual int withdraw(double amt)
	{
		balance -= amt;
		balance -= charge;
		cout << "Your account balance is now : $ " << balance << endl;
		return balance;
	}
	void servicecharge();
};

class checkingAcct : public BankAccount{
public:
	checkingAcct(double amt) : BankAccount() { balance = amt; }
	void statement()
	{
		cout << "Your balance now is : " << balance << endl;
	}
	virtual int withdraw(double amt)
	{
		if (balance - amt < 25)
			return -1;
		else
			BankAccount::withdraw(amt);
	}
	void monthlyProc(int withdraw_check)
	{
		charge = 5 + 0.1 * withdraw_check;
		cout << charge;
	}
};

class SavingAcct : public BankAccount{

public:
	SavingAcct(double amt) : BankAccount() { balance = amt; } //class constructor
	void statement()
	{
		cout << "Your balance now is : " << balance << endl;
	}
	virtual int withdraw(double amt)
	{
		if (balance - amt < 25)
		{
			return -1;
		}
		else
		{
			withdraw_save++;
			save.monthlyProc(withdraw_save);
			BankAccount::withdraw(amt);

		}

	}
	void monthlyProc(int withdraw_save)
	{
		if (withdraw_save > 4)
		{
			charge++;
		}
	}
};

int main()
{
	checkingAcct check;
	double Balance_check = 0.0;
	double Balance_save = 0.0;
	int choice;

	cout << "What's your balance in checking account?" << endl;
	cout << "$ ";
	cin >> Balance_check;
	checkingAcct check (Balance_check);
	cout << "What's your balance in saving account?" << endl;
	cout << "$ ";
	cin >> Balance_save;
	SavingAcct save (Balance_save);

	do{
		int amt = 0;
		cout << " ----------------------------" << endl;
		cout << "| 1. Deposit on checking     |" << endl;
		cout << "| 2. Deposit on savings      |" << endl;
		cout << "| 3. Withdraw from checking  |" << endl;
		cout << "| 4. Withdraw from savings   |" << endl;
		cout << "| 5. Statement               |" << endl;
		cout << "| 6. Quit                    |" << endl;
		cout << " ----------------------------" << endl;
		cout << "Your choice is : ";
		cin >> choice;

		switch (choice)
		{
		case 1:
			cout << "How much money do you want to deposit?" << endl;
			cout << "$";
			cin >> amt;
			check.deposit(amt);
			break;
		case 2:
			cout << "How much money do you want to deposit?" << endl;
			cout << "$";
			cin >> amt;
			save.deposit(amt);
			break;
		case 3:
			cout << "How much money do you want to withdraw?" << endl;
			cout << "$";
			cin >> amt;
			//check.withdraw(amt);
			withdraw_check++;
			break;
		case 4:
			cout << "How much money do you want to withdraw?" << endl;
			cout << "$";
			cin >> amt;
			if (save.withdraw(amt) == -1)
			{
				cout << "Not enough balance" << endl;
			}
			else
			{

				save.withdraw(amt);
			}
			break;
		case 5:
			cout << "Your statement is : $";
			break;
		case 6:
			break;
		default:
			cout << endl << "You entered an invalid option!" << endl << endl;
			break;
		}
	} while (choice != 6);



	return 0;
}
