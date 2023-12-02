#include <stdio.h>
#include <string.h>
#include <math.h>

int *acc_no;
int *pin;
int line_count = 1;
int index = 0;

int pin_cha(){
    FILE *fptr;
    int curr_pin;
    int new_pin;
    int re_new_pin;
    int arr[line_count];

    fptr = fopen("HelloAnuj", "r");

    for(int i=0;i<line_count;i++)
    {
        fscanf(fptr,"%d",&arr[i]);
    }
    
    printf("Enter your current pin..");
    scanf("%d", &curr_pin);
    if(curr_pin == arr[index+1]){
        printf("Enter new pin: ");
        scanf("%d", &new_pin);
        printf("Confirm new pin: ");
        scanf("%d", &re_new_pin);
        if(re_new_pin == new_pin){
            arr[index +1] = new_pin;
            printf("Pin successfully changed.\n");
        }
        else{
            printf("Pin do not match.. \nRenter your old pin to change it again.");
            pin_cha();
        }
    }
    else{
        printf("Wrong current pin entered.. Try Again :( ");
        pin_cha();
    }
    FILE *fptr2;
    fptr2 = fopen("HelloAnuj", "w");
    for(int i=0;i<line_count;i++){
        fprintf(fptr2, "%d", arr[i]);
        fprintf(fptr2, "\n");
    }
    fclose(fptr2);
    options();


}
int check_balance(){
    FILE *fptr;
    
    int arr[line_count];

    fptr = fopen("HelloAnuj", "r");

    for(int i=0;i<line_count;i++)
    {
        fscanf(fptr,"%d",&arr[i]);
    }

    printf("Your balance is: %d\n\n\n\n", arr[index+2]);
    options();

}
int options(){
    int option;
    printf("Choose one of the following function:\n");
    printf("1. Check Balance\n2. Withdraw money\n3. Deposit Money\n4. Pin Change\n5. Log out\n");
    printf("Your input : ");
    scanf("%d", &option);
    switch(option){
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
        case 5:
            printf("Logged out succesfully.. \n Thankyou for using our ATM services.");
            return 0;
        default:
            printf("Wrong input entered.. \n");
            options();

    }
    
}
int clear()
{
    for (int i = 0; i < 20; i++)
    {
        printf("\n");
    }
}
int check_lines()
{
    FILE *fptr;

    char ch;

    // Open the file in read mode
    fptr = fopen("HelloAnuj", "r");

    // Check if the file is opened successfully
    if (fptr == NULL)
    {
        printf("Could not open the file.\n");
        return 1;
    }

    // Read the file character by character
    while ((ch = fgetc(fptr)) != EOF)
    {
        if (ch == '\n')
        {
            line_count++;
        }
    }

    // Close the file
    fclose(fptr);

//     // Print the number of lines
//     printf("The file has %d lines.\n", line_count);
}
int with_mon(){
    FILE *fptr;
    fptr = fopen("HelloAnuj", "r");
    int arr[line_count];
    int amt_with;
    printf("Enter the amount you want to withdraw: \n");
    scanf("%d", &amt_with);
    for(int i=0;i<line_count;i++)
    {
        fscanf(fptr,"%d",&arr[i]);
    }
    if(amt_with <= arr[index+2]){
        arr[index +2] -= amt_with;
        fclose(fptr);
        FILE *fptr2;
        fptr2 = fopen("HelloAnuj", "w");
        for(int i=0;i<line_count;i++){
            fprintf(fptr2, "%d", arr[i]);
            fprintf(fptr2, "\n");
        }
        fclose(fptr2);
        printf("Amount withdrawn successfully :)\nYour current balance is: %d\n\n", arr[index+2]);
        options();
    
    }
    else{
        printf("Not enough balance ;)");
        options();
        return 0;
    }

}
int depo_mon(){
    FILE *fptr;
    fptr = fopen("HelloAnuj", "r");
    int arr[line_count];
    int amt_depo;
    printf("Enter the amount you want to deposit: ");
    scanf("%d", &amt_depo);
    for(int i=0;i<line_count;i++)
    {
        fscanf(fptr,"%d",&arr[i]);
    }
   
    arr[index +2] += amt_depo;
    fclose(fptr);
    FILE *fptr2;
    fptr2 = fopen("HelloAnuj", "w");
    for(int i=0;i<line_count;i++){
        fprintf(fptr2, "%d", arr[i]);
        fprintf(fptr2, "\n");
    }
    fclose(fptr2);
    printf("Amount deposited succesfully.");
    options();

}
int register_acc()
{
    FILE *fptr;
    int arr[line_count];
    int acc_no;
    int pin;
    int balance;
    fptr = fopen("HelloAnuj", "r");
    printf("Enter your account number : ");
    scanf("%d", &acc_no); 
    for(int i=0;i<line_count;i++)
    {
        fscanf(fptr,"%d",&arr[i]);
    }
    // for(int i=0;i<line_count;i++)
    // {
    //     printf("%d ", arr[i]);
    // }
    for(int i = 0; i<line_count; i+=3){
        if(acc_no == arr[i]){
            printf("Account already exists..\nChoose another account number\n\n\n\n");
            register_acc();
        }
    }
    printf("Enter your pin : ");
    scanf("%d", &pin);
    // printf("Enter your balance : ");
    // scanf("%d", &balance);1
    
    balance = srand() % 100000000;
    printf("Your account balance is %d\n", balance);
    line_count+= 3;

    fptr = fopen("HelloAnuj", "a");
    fprintf(fptr, "\n%d", acc_no );
    fprintf(fptr, "\n%d", pin );
    fprintf(fptr, "\n%d", balance);
    fclose(fptr);
    printf("Account created successfully..\n\n\n\n");

    welcome();
    return 0;
}

int sign_in()
{
        int arnav = 0;
        FILE *fptr;

        int *arr[line_count];
        

        printf("Enter your account number: ");
        scanf("%d", &acc_no);
        printf("Enter your pin: ");
        scanf("%d", &pin);

        fptr = fopen("HelloAnuj", "r");
        

        for (int i = 0; i < (line_count); i++)
        {
            fscanf(fptr, "%d", &arr[i]);
        }
        for (int i = 0; i < line_count; i += 3)
        {
            if (arr[i] == acc_no && arr[i + 1] == pin)
            {
                printf("Account signed in successfully \n\n\n\n");
                index = i;
                arnav = 1;
                fclose(fptr);
                options();
                break;
                
            }
            
        }
        if(arnav == 0){
            
            printf("Sign in info did not match:(");
            sign_in();
        }
        fclose(fptr);
        return 0;
    
}
int welcome()
{
    printf("Do you want to: \n(1)Register\n(2)Sign in\n\n");
    int welcome;
    scanf("%d", &welcome);
    switch (welcome)
    {
        case 1:
            register_acc();
            return 1;
        case 2:
            sign_in();
            return 2;
        default:
            printf("Wrong input entered.. Please try again..\n\n");
            return 3;
    }
}

int main()
{
    
    FILE *fptr;
    clear();
    check_lines();
    printf("Hello.......Welcome to the ATM :)\n");

    welcome();
    
}
