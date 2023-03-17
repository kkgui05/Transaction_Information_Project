/* 
 * Description: This C++ program reads in lines of input using cin, file redirection, processes the data, and then outputs the results using cout. This code reads in and displays a header, customer name, employee name, amount withdrawing or depositing, and the balance remaining.
*/

#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

//structure named Employee
struct Employee
{
	//declaring variables
	int employee_ID;
	string employee_name;
};

//structure named Customer
struct Customer
{
	//declaring variables
	string customer_name;
	float account_balance;
};

//function of void type named printHeader
void printHeader()
{
	//displays header with title and info, including customer's name, employee's name, amount withdrawing or depositing, and balance remaining
	cout << "**************** Transaction Information ****************" << endl;
	cout << '\t' << "Customer" << '\t' << "Employee" << '\t' << "Amount" << '\t' << "  " << "Balance" << endl;
	cout << "_________________________________________________________" << endl; 

}

//main function
int main()
{
	//array of 50 customers
	Customer customer[50];
	//array of 50 employees
	string employee[50];

	//declaring variables
	string name;
	int cur_cus_idx;
        int cur_emp_idx;
        bool showHeader = true;

	char person_type;//variable of char type to store either 'c' or 'e'
	char transfer_type;//variable of char type to store the transfer type
	int  employee_count=0;//int variable counter to keep track of the employee count
	int customer_count=0;//int variable counter to keep track of the customer count
	double transaction_amt;//variable of double type that stores the transaction amount
	int id;//variable of int type that stores the ID read in from the file
	float accountBalance;//variable of float type that stores the account balance read from the file

	//while loop that reads information from the file and stores in either employee or customer structure
	while (cin >> person_type)
	{
		//checks if line begins with e and if so, stores employee information
		if (person_type == 'e')
		{
			cin >> id;
			cin >> name;
			employee[id-1] = name;
		}
		
		//checks if line begins with c and if so, stores customer information
		if(person_type == 'c')
		{
			cin >> id;
			cin >> name;
			cin >> accountBalance;
			customer[id-1].customer_name = name;
			customer[id-1].account_balance = accountBalance;
		}
		
		//checks if line begins with t and if so, displays header and stores transaction information
		if(person_type == 't')
		{
			if(showHeader) 
			{
			printHeader();
			showHeader = false;
			}
			cin >> cur_cus_idx;
			cur_cus_idx -= 1;
			cin >> cur_emp_idx;
			cur_emp_idx -= 1;
			cin >> transfer_type;
			//checks if line begins with w which stores withdrawal information
			if (transfer_type == 'w') 
			{
				cin >> transaction_amt;
				customer[cur_cus_idx].account_balance = customer[cur_cus_idx].account_balance-transaction_amt;
				
				//displays customer name, employee name, amount withdrawing, and balance remaining with proper formatting
				cout << setw(15) << right << customer[cur_cus_idx].customer_name << setw(16) << right << employee[cur_emp_idx] << setw(8) << right << "-$ " << transaction_amt << fixed << showpoint << setprecision(2) << " " << "$" << " " << right << customer[cur_cus_idx].account_balance << fixed << showpoint << setprecision(2) << endl;

			//checks if line begins with d which stores deposit information
			}else
			{
				cin >> transaction_amt;
				customer[cur_cus_idx].account_balance = customer[cur_cus_idx].account_balance + transaction_amt;

				//displays customer name, employee name, amount depositing, and balance remaining with proper formatting
				cout << setw(15) << right << customer[cur_cus_idx].customer_name << setw(16) << right << employee[cur_emp_idx] << setw(8) << right << "+$ " << transaction_amt << fixed << showpoint << setprecision(2) << " " << "$" << " " << right << customer[cur_cus_idx].account_balance << fixed << showpoint << setprecision(2) << endl;
			}
		}
	}
	
	return 0;
}
