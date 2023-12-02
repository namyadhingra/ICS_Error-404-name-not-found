## ICS_Error-404-name-not-found


# Overview
This repository contains a simple ATM (Automated Teller Machine) program written in C. The program allows users to perform basic banking operations such as checking balance, withdrawing money, depositing money, and changing their PIN.

File Structure
- **ATM.c**: This file contains the main source code for the ATM program.
- **HelloAnuj**: This file serves as the data storage for account information, including account numbers, PINs, and balances.

# How to Use
1. **Compilation**: Compile the `B23CS1040_B23EE1074_B23CH1006_B23CI1006.c` file using a C compiler.
  
2. **Run the Program**: Execute the compiled program.
   
3. **Account Registration**: When prompted, choose to register a new account. Enter the account number and set the PIN. An initial balance will be assigned automatically.

4. **Account Sign-In**: Choose to sign in and enter your account number and PIN. If the provided credentials match an existing account, you will be signed in.

5. **Main Menu Options**:
    - **1. Check Balance**: View the current account balance.
    - **2. Withdraw Money**: Withdraw a specified amount from the account balance.
    - **3. Deposit Money**: Deposit a specified amount into the account.
    - **4. Change PIN**: Change the PIN associated with the account.
    - **5. Log Out**: Log out of the current account.

# Important Notes
- The account information (account number, PIN, and balance) is stored in the `HelloAnuj` file. Do not modify this file manually.
- The program utilizes simple file Input-Output operations to read and write account information.
- This is a basic implementation for educational purposes and may not include advanced security features.
