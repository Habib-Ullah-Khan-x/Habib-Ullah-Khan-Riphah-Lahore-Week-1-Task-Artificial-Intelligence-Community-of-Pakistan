#include<iostream>
using namespace std;
#include<string>
#include<vector>

// Struct to represent computer components
struct Component {
    string itemCode;
    string description;
    double price;
};

// list of available components
void displayComponents(const vector<Component>& components) {
    cout << "Available Components:\n";
    cout << "Item Code\tDescription\t\tPrice ($)\n";
    for (const Component& component : components) {
        cout << component.itemCode << "\t\t" << component.description << "\t\t" << component.price << endl;
    }
    cout << endl;
}

int main() {
    vector<Component> components = {
        {"A1", "Compact Case", 75.00},
        {"A2", "Tower Case", 150.00},
        {"B1", "8 GB RAM", 79.99},
        {"B2", "16 GB RAM", 149.99},
        {"C1", "1 TB HDD", 49.99},
        {"C2", "2 TB HDD", 89.99},
        {"D1", "240 GB SSD", 59.99},
        {"D2", "480 GB SSD", 119.99},
        {"E1", "1 TB HDD", 49.99},
        {"E2", "2 TB HDD", 89.99},
        {"F1", "DVD/Blu-Ray Player", 50.00},
        {"F2", "DVD/Blu-Ray Re-writer", 100.00},
        {"G1", "Standard OS", 100.00},
        {"G2", "Professional OS", 175.00}
    };

      cout<<"------------------------------------------"<<endl;
    cout << "Welcome to the Online Computer Shop!" << endl;
    cout<<"------------------------------------------"<<endl;

    // Task 1 - Choose one case, one RAM, and one Main Hard Disk Drive
    string chosenCase, chosenRAM, chosenHDD;
    displayComponents(components);
  cout<<"------------------------------------------"<<endl;
    cout << "Please choose one case (A1/A2): ";
    cin >> chosenCase;
    cout << "Please choose one RAM (B1/B2): ";
    cin >> chosenRAM;
    cout << "Please choose one Main Hard Disk Drive (C1/C2): ";
    cin >> chosenHDD;

    // Task 2 - Calculate the price of the computer with the chosen items and basic components
    double totalPrice = 200.00; // Basic components cost
    bool isValidChoice = false;

    for (const Component& component : components) {
        if (component.itemCode == chosenCase || component.itemCode == chosenRAM || component.itemCode == chosenHDD) {
            totalPrice += component.price;
            isValidChoice = true;
        }
    }

    if (!isValidChoice) {
        cout << "Invalid choice of components. Exiting..." << endl;
        return 1;
    }

    // Task 3 - Offering discounts based on the number of additional items
    int additionalItems = 0;

    for (int i = 0; i < 3; i++) {
        string additionalItem;
        displayComponents(components);
        cout << "Please choose an additional item (or 'done' to finish): ";
        cin >> additionalItem;

        if (additionalItem == "done") {
            break;
        }

        for (const Component& component : components) {
            if (component.itemCode == additionalItem) {
                totalPrice += component.price;
                additionalItems++;
            }
        }
    }

    double discount = 0.0;
    if (additionalItems == 1) {
        discount = 0.05; // 5% discount
    } else if (additionalItems >= 2) {
        discount = 0.10; // 10% discount
    }

    double discountedPrice=totalPrice-(totalPrice*discount);

    cout<<"Chosen Components:\n";
    cout<<"Case: "<<chosenCase<<endl;
    cout<<"RAM: "<<chosenRAM<<endl;
    cout<<"Main HDD: "<<chosenHDD<<endl;
    cout<<"Additional Items: "<<additionalItems<<endl;
    cout<<"Total Price ($): "<<totalPrice<<endl;
    cout<<"Discount Applied: "<<(discount * 100)<<"%"<<endl;
    cout<<"New Price After Discount ($): "<<discountedPrice<<endl;

    return 0;
}
