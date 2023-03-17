# Transaction_Information_Project
This C++ program reads in lines of input using cin, file redirection, processes the data, and then outputs the results using cout. This code reads in and displays a header, customer name, employee name, amount withdrawing or depositing, and the balance remaining.

Author: kkgui05

Features:

The program reads in data from a file or user input via cin.
The program displays a header with the title and information such as the customer's name, employee's name, amount withdrawing or depositing, and balance remaining.
The program uses two structures, Employee and Customer, to store information about the employees and customers respectively.
The program allows the user to specify the type of transaction, either a withdrawal or a deposit.
The program tracks the account balance of each customer and updates it based on the transaction.
The program outputs the customer's name, employee's name, the amount of the transaction, and the new account balance with proper formatting.

How to Use: 

Clone or download the repository.
Compile the main.cpp file using a C++ compiler.
Run the compiled file on your machine.
If you want to provide input from a file, use the file redirection method. Otherwise, provide input using cin.
The program will read the input and output the results to the console.

Example Input:

e 1 John

c 1 Jane 1000

t 1 1 w 500

Example Output:

**************** Transaction Information ****************
    
    Customer         Employee         Amount      Balance
_________________________________________________________
           Jane             John     -$ 500.00 $  500.00

