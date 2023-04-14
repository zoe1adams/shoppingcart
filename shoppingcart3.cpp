#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

int main()
{
// constants to store the customer details
const string CUSTOMERNAME = "Jane Smith", USERNAME = "jsmith", PASSWORD = "blue123",
ACCOUNTNUMBER = "123456789", MEMBERLEVEL = "Gold", ADDRESS = "100 W New Haven Ave, Melbourne, FL, 32901";

const string CUSTOMERNAME2 = "Ellen Sue Doe", USERNAME2 = "edoe", PASSWORD2 = "pink234",
ACCOUNTNUMBER2 = "234567890", MEMBERLEVEL2 = "Blue", ADDRESS2 = "235 South Street, Bronx, NY, 21110";

const string CUSTOMERNAME3 = "Michael Black", USERNAME3 = "mblack", PASSWORD3 = "brown124",
ACCOUNTNUMBER3 = "235765437", MEMBERLEVEL3 = "None", ADDRESS3 = "56 N Pathway Rd, Phoenix, AZ, 56565";

const string CUSTOMERNAME4 = "John Carter", USERNAME4 = "jcarter", PASSWORD4 = "green289",
ACCOUNTNUMBER4 = "987654251", MEMBERLEVEL4 = "Diamond", ADDRESS4 = "1060 W Addison St, Chicago, IL 60613";

double storeCredit = 3000.00; // available store credit
const int ITEMS = 3; // number of items
const double SALES_TAX = 6; // sales tax percent

// arrays to store the details of items available for purchase
string sku[] = {"HF-342", "LK-322", "KF-231"};
string name[] = {"1/2 in Bolt", "1/4 in Nail", "Hammer"};
int itemsInUnit[] = {50, 25, 1};
double pricePerUnit[] = {20.00, 5.75, 15.23};
int quantityOnHand[] = {200, 76, 100};

// variables for input
string input_username, input_password, input_sku;
int input_qty;
int itemIndex;
double amount, salesTax, totalDue;

// login to the system, input the username and password
cout << right << setw(20) << " LOGIN" << endl;
cout << "Username: ";
cin >> input_username;
cout << "Password: ";
cin >> input_password;

// validate login was successful
if (input_username == USERNAME && input_password == PASSWORD) {
    // code to execute if input is correct
}
else if (input_username == USERNAME2 && input_password == PASSWORD2) {
    // code to execute if input is correct
}
else if (input_username == USERNAME3 && input_password == PASSWORD3) {
    // code to execute if input is correct
}
else if (input_username == USERNAME4 && input_password == PASSWORD4) {
    // code to execute if input is correct
}
else { cout << "ERROR: Invalid USERNAME and/or PASSWORD. Terminating the program..." << endl;
    // code to execute if none of the input is correct
}

{
// display the details of the items available
cout << endl << right << setw(30) << "ITEMS" << endl;
cout << left << setw(10) << "SKU" << left << setw(20) << "Name" << right << setw(15) << "Items in unit"
<< right << setw(20) << "Price per unit" << right << setw(20) << "Quantity on hand" << endl;

cout << fixed << setprecision(2);

for(int i=0;i<ITEMS;i++)
{
cout << left << setw(10) << sku[i] << left << setw(20) << name[i] << right << setw(10) << itemsInUnit[i]
<< right << setw(20) << pricePerUnit[i] << right << setw(20) << quantityOnHand[i] << endl;
}

// input the sku of the item to purchase
cout << endl << "Enter the SKU of the item to purchase: ";
cin >> input_sku;

itemIndex = -1;

// loop to get the index of the item user wants to purchase
for(int i=0;i<ITEMS;i++)
{
if(sku[i] == input_sku)
{
itemIndex = i;
break;
}
}

if(itemIndex == -1) // invalid sku, display error and exit
cout << "ERROR: Invalid SKU!!!! Terminating the program..." << endl;
else
{
// input the quantity to purchase
cout << "Enter the quantity to purchase: ";
cin >> input_qty;

// validate quantity is valid, else display error message and exit
if(input_qty < 1 || input_qty > quantityOnHand[itemIndex])
cout << "ERROR: Insufficient quantity. Quantity must be between [1, " << quantityOnHand[itemIndex] << "]. Terminating the program..." << endl;
else
{
// compute the total amount due
amount = input_qty * pricePerUnit[itemIndex]; // amount before taxes
salesTax = (amount * SALES_TAX)/100; // sales tax
totalDue = amount + salesTax; // total amount

// validate user has enough store credit, if not display error message and exit
if(totalDue > storeCredit)
cout << "ERROR: Insufficient store credit!!! Terminating the program..." << endl;
else
{
// deduct the store credit
storeCredit -= totalDue;
//display receipt
cout << endl << "*********************** RECEIPT **************************" << endl;
cout << left << setw(20) << "Customer Name" << ": " << CUSTOMERNAME << endl;
cout << left << setw(20) << "Account Number" << ": " << ACCOUNTNUMBER << endl;
cout << left << setw(20) << "Member Level" << ": " << MEMBERLEVEL << endl;
cout << left << setw(20) << "Address" << ": " << ADDRESS << endl;
cout << "=========================================================================" << endl;
cout << left << setw(20) << "Item SKU" << ": " << input_sku << endl;
cout << left << setw(20) << "Item Name" << ": " << name[itemIndex] << endl;
cout << left << setw(20) << "Items in unit" << ": " << right << setw(10) << itemsInUnit[itemIndex] << endl;
cout << left << setw(20) << "Price per unit" << ": $" << right << setw(8) << pricePerUnit[itemIndex] << endl;
cout << left << setw(20) << "Quantity" << ":" << right << setw(10) << input_qty << endl;
cout << left << setw(20) << "Gross Amount" << ": $" << right << setw(8) << amount << endl;
cout << left << setw(20) << "Sales Tax" << ": $" << right << setw(8) << salesTax << endl;
cout << left << setw(20) << "Total Amount" << ": $" << right << setw(8) << totalDue << endl;
cout << left << setw(20) << "Store Credit" << ": $" << right << setw(8) << storeCredit << endl;
cout << endl << "**** Thank you for your purchase. Have a nice day!!! ****" << endl;
}

}
}
}

return 0;
}

// end of program
