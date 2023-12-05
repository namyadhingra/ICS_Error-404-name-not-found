#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int my_index = 0;
int line_count = 1;

void check_lines() {
    FILE *fptr;
    char ch;

    fptr = fopen("data", "r");

    if (fptr == NULL) {
        printf("Could not open the file.\n");
        return;
    }

    while ((ch = fgetc(fptr)) != EOF) {
        if (ch == '\n') {
            line_count++;
        }
    }

    fclose(fptr);
}

void welcome(); 

void register_acc() {
    FILE *fptr;
    int arr[line_count];
    int acc_no;
    int pin;
    int balance;

    fptr = fopen("data", "r");

    printf("Enter your account number : ");
    scanf("%d", &acc_no);

    for (int i = 0; i < line_count; i++) {
        fscanf(fptr, "%d", &arr[i]);
    }

    for (int i = 0; i < line_count; i += 3) {
        if (acc_no == arr[i]) {
            printf("Account already exists..\nChoose another account number\n\n\n\n");
            register_acc();
        }
    }

    printf("Enter your pin : ");
    scanf("%d", &pin);

    balance = rand() % 100000000;
    printf("Your account balance is %d\n", balance);
    line_count += 3;

    fptr = fopen("data", "a");
    fprintf(fptr, "\n%d", acc_no);
    fprintf(fptr, "\n%d", pin);
    fprintf(fptr, "\n%d", balance);
    fclose(fptr);

    printf("Account created successfully..\n\n\n\n");
    welcome();
}

void sign_in();

void options();

void check_balance() {
    FILE *fptr;
    int arr[line_count];

    fptr = fopen("data", "r");

    for (int i = 0; i < line_count; i++) {
        fscanf(fptr, "%d", &arr[i]);
    }

    printf("Your balance is: %d\n\n\n\n", arr[my_index + 2]);
    options();

    fclose(fptr);
}

void with_mon() {
    FILE *fptr;
    fptr = fopen("data", "r");
    int arr[line_count];
    int amt_with;

    printf("Enter the amount you want to withdraw: \n");
    scanf("%d", &amt_with);

    for (int i = 0; i < line_count; i++) {
        fscanf(fptr, "%d", &arr[i]);
    }

    if (amt_with <= arr[my_index + 2]) {
        arr[my_index + 2] -= amt_with;
        fclose(fptr);

        FILE *fptr2;
        fptr2 = fopen("data", "w");

        for (int i = 0; i < line_count; i++) {
            fprintf(fptr2, "%d", arr[i]);
            fprintf(fptr2, "\n");
        }

        fclose(fptr2);

        printf("Amount withdrawn successfully :)\nYour current balance is: %d\n\n", arr[my_index + 2]);
        options();
    } else {
        printf("Not enough balance ;)\n");
        options();
    }
}

void depo_mon() {
    FILE *fptr;
    fptr = fopen("data", "r");
    int arr[line_count];
    int amt_depo;

    printf("Enter the amount you want to deposit: ");
    scanf("%d", &amt_depo);

    for (int i = 0; i < line_count; i++) {
        fscanf(fptr, "%d", &arr[i]);
    }

    arr[my_index + 2] += amt_depo;
    fclose(fptr);

    FILE *fptr2;
    fptr2 = fopen("data", "w");

    for (int i = 0; i < line_count; i++) {
        fprintf(fptr2, "%d", arr[i]);
        fprintf(fptr2, "\n");
    }

    fclose(fptr2);

    printf("Amount deposited successfully.\n");
    options();
}

int pin_cha() {
    FILE *fptr;
    int curr_pin;
    int new_pin;
    int re_new_pin;
    int arr[line_count];

    fptr = fopen("data", "r");

    for (int i = 0; i < line_count; i++) {
        fscanf(fptr, "%d", &arr[i]);
    }

    printf("Enter your current pin..");
    scanf("%d", &curr_pin);

    if (curr_pin == arr[my_index + 1]) {
        printf("Enter new pin: ");
        scanf("%d", &new_pin);
        printf("Confirm new pin: ");
        scanf("%d", &re_new_pin);

        if (re_new_pin == new_pin) {
            arr[my_index + 1] = new_pin;
            printf("Pin successfully changed.\n");
        } else {
            printf("Pin do not match..\nRenter your old pin to change it again.");
            pin_cha();
        }
    } else {
        printf("Wrong current pin entered.. Try Again :(\n");
        pin_cha();
    }

    FILE *fptr2;
    fptr2 = fopen("data", "w");

    for (int i = 0; i < line_count; i++) {
        fprintf(fptr2, "%d", arr[i]);
        fprintf(fptr2, "\n");
    }

    fclose(fptr2);
    options();
}

void options() {
    int option;
    printf("Choose one of the following functions:\n");
    printf("1. Check Balance\n2. Withdraw money\n3. Deposit Money\n4. Pin Change\n5. Log out\n");
    printf("Your input : ");
    scanf("%d", &option);

    switch (option) {
        case 1:
            check_balance();
            break;
        case 2:
            with_mon();
            break;
        case 3:
            depo_mon();
            break;
        case 4:
            pin_cha();
            break;
        case 5:
            printf("Logged out successfully..\nThank you for using our ATM services.");
            exit(0);
        default:
            printf("Wrong input entered..\n");
            options();
    }
}

void sign_in() {
    int arnav = 0;
    FILE *fptr;
    int arr[line_count];

    printf("Enter your account number: ");
    scanf("%d", &arr[my_index]);
    printf("Enter your pin: ");
    scanf("%d", &arr[my_index + 1]);

    fptr = fopen("data", "r");

    for (int i = 0; i < line_count; i++) {
        fscanf(fptr, "%d", &arr[i]);
    }

    for (int i = 0; i < line_count; i += 3) {
        if (arr[i] == arr[my_index] && arr[i + 1] == arr[my_index + 1]) {
            printf("Account signed in successfully.\n");
            my_index = i;
            arnav = 1;
            fclose(fptr);
            options();
            break;
        }
    }

    if (arnav == 0) {
        printf("Sign in info did not match:(\n");
        sign_in();
    }

    fclose(fptr);
}

void welcome() {
    printf("Do you want to:\n(1) Register\n(2) Sign in\n\n");
    int welcome;
    scanf("%d", &welcome);

    switch (welcome) {
        case 1:
            register_acc();
            break;
        case 2:
            sign_in();
            break;
        default:
            printf("Wrong input entered.. Please try again..\n\n");
    }
}

int main() {

    check_lines();
    printf("Hello.......Welcome to the ATM :)\n");
    welcome();

    return 0;
}

