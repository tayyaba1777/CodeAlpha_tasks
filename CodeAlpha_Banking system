#include <iostream>
#include <fstream>
#include <string>
#include <ctime>
#include <cstdlib>
#include <cstdio>

using namespace std;

// Function declarations
void createAccount();
void loginAccount();
void depositMoney();
void withdrawMoney();
void showAllAccounts();
void closeAccount();
void miniStatement();

// ===================== MAIN =====================
int main() {
    int choice;

    do {
        cout << "\n====================================\n";
        cout << "        SIMPLE BANKING SYSTEM       \n";
        cout << "====================================\n";
        cout << "1. Create Account\n";
        cout << "2. Login & View Account\n";
        cout << "3. Deposit Money\n";
        cout << "4. Withdraw Money\n";
        cout << "5. Show All Accounts\n";
        cout << "6. Close Account\n";
        cout << "7. Mini Statement\n";
        cout << "8. Exit\n";
        cout << "Enter Choice: ";
        cin >> choice;

        switch (choice) {
            case 1: createAccount(); break;
            case 2: loginAccount(); break;
            case 3: depositMoney(); break;
            case 4: withdrawMoney(); break;
            case 5: showAllAccounts(); break;
            case 6: closeAccount(); break;
            case 7: miniStatement(); break;
            case 8: cout << "Thank you for using Banking System!\n"; break;
            default: cout << "Invalid choice!\n";
        }

    } while (choice != 8);

    return 0;
}

// ===================== CREATE ACCOUNT =====================
void createAccount() {
    int accNo;
    string name, password;
    float balance;

    cout << "\nEnter Account Number: ";
    cin >> accNo;
    cin.ignore();

    cout << "Enter Name: ";
    getline(cin, name);

    cout << "Set Password: ";
    getline(cin, password);

    cout << "Enter Initial Deposit: ";
    cin >> balance;

    ofstream file("accounts.txt", ios::app);
    file << accNo << "\n" << name << "\n" << password << "\n" << balance << "\n";
    file.close();

    cout << "Account Created Successfully!\n";
}

// ===================== LOGIN =====================
void loginAccount() {
    int accNo;
    string line, name, pass, inputPass;
    float balance;
    bool found = false;

    cout << "Enter Account Number: ";
    cin >> accNo;
    cin.ignore();

    ifstream file("accounts.txt");

    while (getline(file, line)) {
        int fileAccNo = atoi(line.c_str());
        getline(file, name);
        getline(file, pass);
        getline(file, line);
        balance = atof(line.c_str());

        if (fileAccNo == accNo) {
            found = true;
            cout << "Enter Password: ";
            getline(cin, inputPass);

            if (inputPass == pass) {
                cout << "\nAccount Number: " << fileAccNo << endl;
                cout << "Name: " << name << endl;
                cout << "Balance: " << balance << endl;
            } else {
                cout << "Incorrect Password!\n";
            }
            break;
        }
    }

    if (!found)
        cout << "Account Not Found!\n";

    file.close();
}

// ===================== DEPOSIT =====================
void depositMoney() {
    int accNo;
    string line, name, pass, inputPass;
    float balance, amount;
    bool found = false;

    cout << "Enter Account Number: ";
    cin >> accNo;
    cin.ignore();

    ifstream file("accounts.txt");
    ofstream temp("temp.txt");

    while (getline(file, line)) {
        int fileAccNo = atoi(line.c_str());
        getline(file, name);
        getline(file, pass);
        getline(file, line);
        balance = atof(line.c_str());

        if (fileAccNo == accNo) {
            found = true;
            cout << "Enter Password: ";
            getline(cin, inputPass);

            if (inputPass == pass) {
                cout << "Enter Amount to Deposit: ";
                cin >> amount;
                balance += amount;
                cout << "Amount Deposited Successfully!\n";

                ofstream t("transactions.txt", ios::app);
                time_t now = time(0);
                t << "Account: " << accNo << " | Deposit | "
                  << amount << " | " << ctime(&now);
                t.close();
            } else {
                cout << "Incorrect Password!\n";
            }
        }

        temp << fileAccNo << "\n" << name << "\n" << pass << "\n" << balance << "\n";
    }

    file.close();
    temp.close();
    remove("accounts.txt");
    rename("temp.txt", "accounts.txt");

    if (!found)
        cout << "Account Not Found!\n";
}

// ===================== WITHDRAW =====================
void withdrawMoney() {
    int accNo;
    string line, name, pass, inputPass;
    float balance, amount;
    bool found = false;

    cout << "Enter Account Number: ";
    cin >> accNo;
    cin.ignore();

    ifstream file("accounts.txt");
    ofstream temp("temp.txt");

    while (getline(file, line)) {
        int fileAccNo = atoi(line.c_str());
        getline(file, name);
        getline(file, pass);
        getline(file, line);
        balance = atof(line.c_str());

        if (fileAccNo == accNo) {
            found = true;
            cout << "Enter Password: ";
            getline(cin, inputPass);

            if (inputPass == pass) {
                cout << "Enter Amount to Withdraw: ";
                cin >> amount;

                if (amount > balance) {
                    cout << "Insufficient Balance!\n";
                } else {
                    balance -= amount;
                    cout << "Amount Withdrawn Successfully!\n";

                    ofstream t("transactions.txt", ios::app);
                    time_t now = time(0);
                    t << "Account: " << accNo << " | Withdraw | "
                      << amount << " | " << ctime(&now);
                    t.close();
                }
            } else {
                cout << "Incorrect Password!\n";
            }
        }

        temp << fileAccNo << "\n" << name << "\n" << pass << "\n" << balance << "\n";
    }

    file.close();
    temp.close();
    remove("accounts.txt");
    rename("temp.txt", "accounts.txt");

    if (!found)
        cout << "Account Not Found!\n";
}

// ===================== SHOW ALL =====================
void showAllAccounts() {
    ifstream file("accounts.txt");
    string line, name, pass;
    float balance;

    cout << "\n===== ALL ACCOUNTS =====\n";

    while (getline(file, line)) {
        int accNo = atoi(line.c_str());
        getline(file, name);
        getline(file, pass);
        getline(file, line);
        balance = atof(line.c_str());

        cout << "Account No: " << accNo << endl;
        cout << "Name: " << name << endl;
        cout << "Balance: " << balance << endl;
        cout << "-----------------------\n";
    }

    file.close();
}

// ===================== CLOSE ACCOUNT =====================
void closeAccount() {
    int accNo;
    cout << "Enter Account Number to Close: ";
    cin >> accNo;

    ifstream file("accounts.txt");
    ofstream temp("temp.txt");
    string line, name, pass;
    float balance;
    bool found = false;

    while (getline(file, line)) {
        int fileAccNo = atoi(line.c_str());
        getline(file, name);
        getline(file, pass);
        getline(file, line);
        balance = atof(line.c_str());

        if (fileAccNo != accNo) {
            temp << fileAccNo << "\n" << name << "\n" << pass << "\n" << balance << "\n";
        } else {
            found = true;
        }
    }

    file.close();
    temp.close();
    remove("accounts.txt");
    rename("temp.txt", "accounts.txt");

    if (found)
        cout << "Account Closed Successfully!\n";
    else
        cout << "Account Not Found!\n";
}

// ===================== MINI STATEMENT =====================
void miniStatement() {
    int accNo;
    cout << "Enter Account Number: ";
    cin >> accNo;

    ifstream file("transactions.txt");
    string line;
    char accStr[20];
    sprintf(accStr, "%d", accNo);

    cout << "\n===== MINI STATEMENT =====\n";

    while (getline(file, line)) {
        if (line.find(accStr) != string::npos)
            cout << line << endl;
    }

    file.close();
}
