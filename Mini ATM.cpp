#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define MAX_ACCOUNTS 10

// Structure to represent an account
struct Account {
    int accountNumber;
    char pin[6];
    float balance;
};

struct Account accounts[MAX_ACCOUNTS];
int accountCount = 0;

// Function to create a new account
void createAccount(int accountNumber, char pin[], float initialBalance) {
    if (accountCount < MAX_ACCOUNTS) {
        accounts[accountCount].accountNumber = accountNumber;
        strcpy(accounts[accountCount].pin, pin);
        accounts[accountCount].balance = initialBalance;
        accountCount++;
        printf("Account created successfully!\n");
    } else {
        printf("Cannot create more accounts. Limit reached.\n");
    }
}

// Function to find an account by account number
int findAccount(int accountNumber) {
    for (int i = 0; i < accountCount; ++i) {
        if (accounts[i].accountNumber == accountNumber) {
            return i; // Return the index of the account if found
        }
    }
    return -1; // Return -1 if account not found
}

// Function to simulate a withdrawal
void withdraw(int accountIndex, float amount) {
    if (accounts[accountIndex].balance >= amount) {
        accounts[accountIndex].balance -= amount;
        printf("Withdrawal successful. Remaining balance: Rs%.2f\n", accounts[accountIndex].balance);
    } else {
        printf("Insufficient funds!\n");
    }
}

// Function to simulate a deposit
void deposit(int accountIndex, float amount) {
    accounts[accountIndex].balance += amount;
    printf("Deposit successful. New balance: RS%.2f\n", accounts[accountIndex].balance);
}

// Function to display account balance
void displayBalance(int accountIndex) {
    printf("Account Number: %d\n", accounts[accountIndex].accountNumber);
    printf("Current Balance: Rs%.2f\n", accounts[accountIndex].balance);
}

int main() {
    // Creating sample accounts
    int acc_no;
    float init_balance;
    char acc_pin[20];
    printf("Enter Account Number:\t");
    scanf("%d", &acc_no);
    printf("Enter Account Pin:\t");
    scanf("%s", &acc_pin);
    printf("Enter Account Starting Balance:\t");
    scanf("%f", &init_balance);
    createAccount(acc_no, acc_pin, init_balance);

    int choice, accountNumber, accountIndex;
    char pin[6];
    float amount;

    do {
        printf("\nWelcome to Mini ATM\n");
        printf("1. Login\n");
        printf("2. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter account number: ");
                scanf("%d", &accountNumber);
                printf("Enter PIN: ");
                scanf("%s", pin);

                accountIndex = findAccount(accountNumber);
                if (accountIndex != -1 && strcmp(accounts[accountIndex].pin, pin) == 0) {
                    int option;
                    do {
                        printf("\n1. Withdraw\n");
                        printf("2. Deposit\n");
                        printf("3. Check Balance\n");
                        printf("4. Logout\n");
                        printf("Enter option: ");
                        scanf("%d", &option);

                        switch (option) {
                            case 1:
                                printf("Enter amount to withdraw: ");
                                scanf("%f", &amount);
                                withdraw(accountIndex, amount);
                                break;
                            case 2:
                                printf("Enter amount to deposit: ");
                                scanf("%f", &amount);
                                deposit(accountIndex, amount);
                                break;
                            case 3:
                                displayBalance(accountIndex);
                                break;
                            case 4:
                                printf("Logged out.\n");
                                break;
                            default:
                                printf("Invalid option\n");
                        }
                    } while (option != 4);
                } else {
                    printf("Invalid account number or PIN\n");
                }
                break;
            case 2:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice\n");
        }
    } while (choice != 2);

    return 0;
}
