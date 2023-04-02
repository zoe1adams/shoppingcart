#include <iostream>
#include <iomanip>

using namespace std;

// Customer information
struct Customer {
    string username;
    string password;
    int accountNumber;
    string memberLevel;
    double storeCredit;
    string address;
} customer = {"jsmith", "blue123", 123456789, "Gold", 3000.00, "100 W New Haven Ave, Melbourne, FL 32901"};

// Product information
struct Product {
    string sku;
    string name;
    int itemsInUnit;
    double pricePerUnit;
    int quantityOnHand;
} products[3] = {{"HF-342", "½ in Bolt", 50, 20.00, 200},
                 {"LK-322", "¼ in Nail", 25, 5.75, 76},
                 {"KF-231", "Hammer", 1, 15.23, 100}};

// Discount rate based on membership level
double getDiscountRate(string memberLevel) {
    if (memberLevel == "Diamond") {
        return 0.12;
    } else if (memberLevel == "Gold") {
        return 0.085;
    } else {
        return 0.06;
    }
}

// Required spend based on membership level
double getRequiredSpend(string memberLevel) {
    if (memberLevel == "Diamond") {
        return 700.00;
    } else if (memberLevel == "Gold") {
        return 300.00;
    } else {
        return 100.00;
    }
}

// Function to update account information
void updateAccount() {
    string newAddress;
    cout << "Enter new address: ";
    getline(cin, newAddress);
    customer.address = newAddress;
    cout << "Account updated successfully." << endl;
}

// Function to display all available products
void displayProducts() {
    cout << "Available products:" << endl;
    cout << setw(10) << left << "SKU" << setw(20) << left << "Name" << setw(20) << left << "Price per unit" << setw(20) << left << "Quantity on hand" << endl;
    for (int i = 0; i < 3; i++) {
        cout << setw(10) << left << products[i].sku << setw(20) << left << products[i].name << setw(20) << left << products[i].pricePerUnit << setw(20) << left << products[i].quantityOnHand << endl;
    }
}

// Function to calculate cost of purchase
double calculateCost(string sku, int quantity) {
    double pricePerUnit;
    int quantityOnHand;
    for (int i = 0; i < 3; i++) {
        if (products[i].sku == sku) {
            pricePerUnit = products[i].pricePerUnit;
            quantityOnHand = products[i].quantityOnHand;
            break;
        }
    }
    if (quantity > quantityOnHand) {
        return -1;
    } else {
        double subTotal = pricePerUnit * quantity;
        double discountRate = getDiscountRate(customer.memberLevel);
        double requiredSpend = getRequiredSpend(customer.memberLevel);
        double discount = 0;
        if (subTotal >= requiredSpend) {
            discount = subTotal * discountRate;
        }
        double tax = 0.06 * subTotal;
        double total = subTotal - discount + tax;
        if (total > customer.storeCredit) {
            return -2;
        } else {
            return total;
        }
    }
}