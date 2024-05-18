Bank Management System

Overview

This project is a simple Bank Management System developed for a 2nd semester course using the C programming language. The system allows the bank's admin to manage customer accounts, including adding, viewing, editing, and deleting accounts. Users can perform transactions such as balance inquiries, deposits, and withdrawals.
Features

    Admin Functions:
        View customer accounts
        Register new customer accounts
        Edit existing customer accounts
        Delete customer accounts
        Search for a customer account
        View about section

    User Functions:
        Balance inquiry
        Cash deposit
        Cash withdrawal

How to Use
Running the Program

    Ensure that the necessary C development environment is set up on your machine.
    Compile the source code using a C compiler (e.g., gcc).
    Run the compiled executable.

Main Menu

Upon starting the program, the main menu offers two options:

    Admin Login
    User Transaction

Admin Login

    Default Username: sayem
    Default Password: sayem
    If the login is successful, the admin is taken to the admin menu.

Admin Menu Options

    View Customer Accounts: Displays a list of all registered customer accounts.
    Customer Account Registration: Allows the admin to add new customer accounts.
    Edit Customer Account: Enables the admin to modify details of an existing customer account.
    Delete Customer Account: Allows the admin to delete a customer account based on the user ID.
    Search Customer Account: Enables the admin to search for a customer account by user ID.
    Log Out: Logs out the admin and returns to the main menu.
    About Us: Displays information about the project and the author.

User Transactions

    Balance Inquiry: Users can check their account balance by entering their account number.
    Cash Deposit: Users can deposit money into their account.
    Cash Withdrawal: Users can withdraw money from their account.

Data Storage

    The system saves all customer account details in a file named Record.txt.
    Upon loading the program, the data from the file is read into memory.
    All modifications to accounts (additions, edits, deletions) are saved back to the file.

Code Structure
Functions

    admin(): Handles admin functionalities.
    login(): Manages the login process for admin.
    menu(): Displays the main menu.
    transaction(): Handles user transactions.
    option(): Processes admin menu options.
    menuexit(): Handles exit process.
    chkblnc(): Checks the balance for a user account.
    deposit(): Manages the cash deposit process.
    withdrawl(): Manages the cash withdrawal process.
    search(): Searches for a specific user account.
    view(): Displays all user accounts.
    add_account(): Registers a new user account.
    edit(): Edits an existing user account.
    del(): Deletes a user account.
    about(): Displays the about section.
    adminmenu(): Displays the admin menu.
    find_node_no(int id): Finds the position of a node in the linked list.
    loadFromFile(): Loads data from the file into memory.
    saveToFile(): Saves data from memory to the file.

Data Structures

    struct add: Represents a customer account with fields for name, ID, address, phone number, user ID, password, deposit balance, and a pointer to the next account.
    
Future Improvements

    Implement encryption for user passwords for enhanced security.
    Add a graphical user interface (GUI) for better user interaction.
    Include more detailed error handling and input validation.
    Develop additional features such as transaction history and account statements.

About the Author

This project was created by Athaher Sayem and my teammate ,as a part of a 2nd semester coursework. It demonstrates fundamental concepts in C programming and basic file handling operations.
Contact

For any queries or suggestions, please contact Athaher Sayem at athahersayem@yahoo.com
