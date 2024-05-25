#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include <conio.h>
#include<unistd.h>


//Function
void admin();
void login();
void menu();
void transaction();
int option();
void menuexit();
void chkblnc();
void deposit();
void withdrawl();
void search();
void view();
void add_account();
void edit();
void del();
void about();
void adminmenu();
int find_node_no(int id);
void loadFromFile();
void saveToFile();
void del();


int total_user=0;

COORD coord = {0, 0};
void gotoxy(int a, int b)
{
    coord.X = a;
    coord.Y = b;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}



// Structure for customer account
struct add
{
    char name[30];
    int id;
    char address[30];
    int phone;
    char userid[30];
    char pass[30];
    double deposit;
    struct add *next;
};


struct add *head=NULL,*temp=NULL,*usetemp=NULL;

char dummy;


int main()
{
    system("color f4");
    system("CLS");
    loadFromFile();
    gotoxy(50,10);
    printf(" WELCOME TO DIU BANKING SYSTEM \n");
    gotoxy(53,12);
    printf("1. Admin");

    gotoxy(53,13);
    printf("2. User ");
    gotoxy(53,15);
    printf("Enter Your Choice .... ");

    int choose;
    scanf("%d", &choose);
    if (choose != 1 && choose != 2)
    {
        system("cls");
        gotoxy(50,10);
        printf("Wrong Option");
        sleep(1);
        main();
    }

    if (choose == 1)
    {
        char username[20] = "sayem";
        char pass[20] = "sayem";
        gotoxy(50,17);
        printf("Enter The Username : ");
        char tempname[20];
        scanf(" %[^\n]", tempname);
        gotoxy(50,18);
        printf("Enter The Password : ");
        char temppass[20];
        scanf(" %[^\n]", temppass);

        if (strcmp(username, tempname) == 0 && strcmp(pass, temppass) == 0)
        {
            system("cls");
            gotoxy(50,10);
            printf("LOGIN SUCESSFULL");
            sleep(1);
            adminmenu();
        }
        else
        {
            system("cls");
            gotoxy(50,10);
            printf("Wrong UserName And Password");
            sleep(2);
            main();
        }
    }
    //user option
    else if (choose==2)
    {
        transaction();
    }

    return 0;
}

int option()
{
    int i;
    scanf("%d", &i);
    system("CLS");
    switch (i)
    {
    case 1:
        view();
        break;
    case 2:
        add_account();
        break;
    case 3:
        edit();
        break;
    case 4:
        del();
        break;
    case 5:
        search();
        break;
    case 6:
        menuexit();
        break;
    case 7:
        about();
        break;
    default:
        adminmenu();
    }
}

void adminmenu()
{
    system("CLS");
    gotoxy(54,9);
    printf("WELCOME TO MAIN MENU\n");
    gotoxy(50,11);
    printf("[1] . View Customer Accounts\n\n");
    gotoxy(50,12);
    printf("[2] . Customer Account Registration\n\n");
    gotoxy(50,13);
    printf("[3] . Edit Customer Account\n\n");
    gotoxy(50,14);
    printf("[4] . Delete Customer Account\n\n");
    gotoxy(50,15);
    printf("[5] . Search Customer Account\n\n");
    gotoxy(50,16);
    printf("[6] . Log Out !!! \n\n");
    gotoxy(50,17);
    printf("[7] . About US \n\n");
    gotoxy(50,18);
    printf("Please Enter Your Choice [1-8] : ");
    option();
}

void add_account()
{
    struct add *new_user = (struct add *)malloc(sizeof(struct add));
    system("CLS");
    gotoxy(54,8);
    printf("CUSTOMER ACCOUNT REGISTRATION\n");
    gotoxy(50,10);
    printf("Please Enter Your Name              : ");
     dummy = getchar();
    scanf("%[^\n]", new_user->name);
    gotoxy(50,11);
    printf("Please Enter Your Unique Student ID : ");
    scanf("%d", &new_user->id);
    gotoxy(50,12);
    printf("Please Enter Your Address           : ");

    scanf("%s", new_user->address);
    gotoxy(50,13);
    printf("Please Enter Your Phone Number      : ");
    scanf("%d", &new_user->phone);
    gotoxy(50,14);
    printf("Please Enter Your User ID           : ");

    scanf("%s", new_user->userid);
    gotoxy(50,15);

    printf("Please Enter Your Password          : ");
    scanf("%s", new_user->pass);
    gotoxy(50,16);
    printf("Please Enter Your Deposit Balance   : ");
    scanf("%lf",&new_user->deposit);
    new_user->next = NULL;

    if (head == NULL)
    {
        total_user++;
        head = temp = new_user;
    }
    else
    {
        total_user++;
        temp = head;
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = new_user;
    }
    gotoxy(50,18);
    printf("New user regintration Successfull\n");
    gotoxy(50,20);
    //save
    saveToFile();
    printf("Press any key to return back to Admin menu. \n");
    char z = getch();
    if (z == 13)
    {
        adminmenu();
    }


    adminmenu();

}

void view()
{
    struct add *temptemp = head;
    int i=8;
    gotoxy(20,5);
    printf("Name");
    gotoxy(40,5);
    printf("A/C NO");
    gotoxy(60,5);
    printf("Address");
    gotoxy(80,5);
    printf("Phone Number");
    gotoxy(100,5);
    printf("Balance");
    while (temptemp != NULL)
    {
        gotoxy(20,i);
        printf("%s",temptemp->name);
        gotoxy(40,i);
        printf("%d",temptemp->id);
        gotoxy(60,i);
        printf("%s",temptemp->address);
        gotoxy(80,i);
        printf("%d",temptemp->phone);
        gotoxy(100,i);
        printf("%.2lf",temptemp->deposit);

        temptemp = temptemp->next;
        i++;
    }
    gotoxy(50,i+5);
    printf("Press any key to return back to Admin menu. \n");
    char z = getch();
    if (z == 13)
    {
        adminmenu();
    }


}

void search()
{
    struct add *temptemp = head;
    gotoxy(50,2);
    printf("Enter Student ID  : ");
    int id;
    scanf("%d", &id);
    int flag=0;
    while (temptemp != NULL)
    {
        if (temptemp->id == id)
        {
            flag=1;
            gotoxy(20,8);
            printf("Name");
            gotoxy(40,8);
            printf("A/C NO");
            gotoxy(60,8);
            printf("Address");
            gotoxy(80,8);
            printf("Phone Number");
            gotoxy(100,8);
            printf("Balance");

            //****************************************************
            gotoxy(50,4);
            printf("ID %d is found\n\n",id);
            gotoxy(20,11);
            printf("%s",temptemp->name);
            gotoxy(40,11);
            printf("%d",temptemp->id);
            gotoxy(60,11);
            printf("%s",temptemp->address);
            gotoxy(80,11);
            printf("%d",temptemp->phone);
            gotoxy(100,11);
            printf("%.2lf",temptemp->deposit);
        }
        temptemp = temptemp->next;
    }
    if (flag==0)
    {
        gotoxy(50,4);
        printf("ID %d Not Found",id);
    }
    gotoxy(50,15);
    printf("Press any key to return back to Admin menu. \n");
    char z = getch();
    if (z == 13)
    {
        adminmenu();
    }
}

void about()
{
    gotoxy(65,10);
    printf("!!!ABOUT US!!!\n");
    gotoxy(50,12);
    printf("This project has been created by Athaher Sayem.");
    gotoxy(50,13);
    printf("It is a Simple Bank Management System Project ");
    gotoxy(50,14);
    printf("For My 2nd Semester based on C programming language.");
    gotoxy(50,18);
    printf("Press any key to return back to Admin menu.");
    char z = getch();
    if (z == 13)
    {
        adminmenu();
    }
}

void del()
{
    system("cls");
    if (head == NULL)
    {
        gotoxy(50,10);
        printf("List is empty.\n");
        return;
    }
    gotoxy(50,10);
    printf("Enter user id : ");
    int id ;

    scanf("%d",&id);
    int x=find_node_no(id);

    usetemp=head;

    if (id==usetemp->id)
    {
        head=head->next;
        free(usetemp);
        gotoxy(50,11);
        printf("User Id Deleted Sucessfully\n");
        sleep(2);
    }
    //last
    else if (id==temp->id)
    {
        struct add *prenode;
        while (usetemp->next != 0)
        {
            prenode=usetemp;
            usetemp=usetemp->next;

        }
        temp=prenode;
        prenode->next=NULL;
         printf("User Id Deleted Sucessfully\n");
         sleep(2);

    }
    //middle

    else if (x==0)
    {
        gotoxy(50,11);
        printf("Student ID : %d Not Found\n",id);
        gotoxy(50,15);
        printf("Press any key to return back to Admin menu. \n");
        char z = getch();
        if (z == 13)
        {
            adminmenu();
        }
    }

    else if (x)
    {
        int pos=x,i=1;
        struct add *nextnode;
        usetemp=head;

        while (i<pos-1)
        {
            usetemp=usetemp->next;
            i++;

        }
        nextnode=usetemp->next;
        usetemp->next=nextnode->next;
        gotoxy(50,11);
        printf("User Id Deleted Sucessfully\n");
        sleep(2);

    }


    saveToFile();
    loadFromFile();

    gotoxy(50,15);
    printf("Press any key to return back to Admin menu. \n");
    char z = getch();
    if (z == 13)
    {
        adminmenu();
    }

}

void edit()
{
    if (head == NULL) // If list is empty
    {
        system("cls");
        gotoxy(50,10);
        printf("List is empty.\n");
        return;
    }
    gotoxy(50,8);
    printf("Enter Student ID to edit: ");
    int id;
    scanf("%d", &id);

    struct add *current = head;

    // find
    while (current != NULL && current->id != id)
    {
        current = current->next;
    }

    if (current != NULL)
    {
        gotoxy(50,10);

        printf("Enter Your New Details");
        gotoxy(50,11);
        printf("Enter new name          : ");

        scanf("%s", current->name);
        gotoxy(50,12);
        printf("Enter new address       : ");
        scanf("%s", current->address);
        gotoxy(50,13);
        printf("Enter new phone number  : ");
        scanf("%lf", &current->phone);
        gotoxy(50,14);
        printf("Enter new user ID       : ");
        scanf("%s", current->userid);
        gotoxy(50,15);
        printf("Enter new password      : ");
        scanf("%s", current->pass);
        gotoxy(50,20);
        printf("Account data updated successfully.\n");
    }
    else
    {
        gotoxy(50,10);
        printf("Student ID %d not found.", id);
    }
    gotoxy(50,25);
    printf("Press any key to return back to Admin menu. \n");
    char z = getch();
    if (z == 13)
    {
        saveToFile();
        loadFromFile();
        adminmenu();
    }

}

void menuexit()
{
    system("cls");
    gotoxy(50,10);
    printf("!!! THANK YOU !!!\n");
    gotoxy(50,11);
    printf("USER :: Athaher Sayem \n");
    system("cls");
    gotoxy(50,12);
    printf("Log Out successfull\n\n");
    sleep(1);
    main();

}

int find_node_no(int x)
{
    int counter =0,flag=0,id=x;

    usetemp = head;
    while(usetemp != NULL)
    {
        counter++;
        if(id==usetemp->id)
        {
            flag=1;
            return counter;
        }
        usetemp = usetemp->next;
    }
    if (flag==0)
    {
        return 0;
    }

}

// USER Function ******************************************************************
//***********************************************************************************

void transaction()
{
    system("CLS");
    gotoxy(50,10);
    printf("TRANSACTION MENU");
    gotoxy(50,12);
    printf("[1] . Balance Inquiry");
    gotoxy(50,14);
    printf("[2] . Cash Deposit");
    gotoxy(50,16);
    printf("[3] . Cash Withdrawal");
    gotoxy(50,18);
    printf("[4] . Main Menu");


    gotoxy(50,20);
    printf("Please Enter Your Choice [1-4] : ");
    int a;
    scanf("%d", &a);
    switch (a)
    {
    case 1:
        system("cls");
        chkblnc();
        break;
    case 2:
        system("cls");
        deposit();
        break;
    case 3:
        system("cls");
        withdrawl();
        break;
    case 4:
        system("cls");
        main();
        break;

    default:
        transaction();
    }
}




void chkblnc()
{

    int id,flag=0;
    gotoxy(50,10);
    printf("BALANCE INQUIRY");
    gotoxy(50,12);
    printf("Enter Your Account Number : ");
    scanf("%d", &id);

    usetemp=head;

    while (usetemp!=NULL)
    {
        if (usetemp->id==id)
        {
            flag=1;
            gotoxy(50,14);
            printf("Account is found");
            gotoxy(50,15);
            printf("Your balance Is : %.2lf",usetemp->deposit);
            gotoxy(50,18);
            printf("Press any key to return back to main menu. ");
            getch();
            transaction();
        }
        usetemp=usetemp->next;

    }

    if (flag==0)
    {
        gotoxy(50,14);
        printf("Account Doesn't Exit");
        gotoxy(50,18);
        printf("Press any key to return back to main menu. ");
        getch();
        transaction();
    }


}





void deposit()
{
    int id,flag=0;
    double money;

    system("cls");
    gotoxy(50,10);
    printf("CASH DEPOSIT");
    gotoxy(50,12);
    printf("Enter Your Account Number : ");
    scanf("%d", &id);


    usetemp=head;

    while (usetemp!=NULL)
    {
        if (usetemp->id==id)
        {
            flag=1;
            gotoxy(50,14);
            printf("Account Found");
            gotoxy(50,15);
            printf("Enter The Amount To Deposit : $ ");
            scanf("%lf", &money);
            usetemp->deposit += money;
            gotoxy(50,16);
            printf("CASH DEPOSIT SUCCESSFULL\n\n");
            saveToFile();
            loadFromFile();
            gotoxy(50,20);
            printf("Press any key to return back...");
            getch();
            transaction();


        }
        usetemp=usetemp->next;
    }

    if (flag==0)
    {
        gotoxy(50,14);
        printf("Account Doesn't Exist.");
        gotoxy(50,20);
        printf("Press any key to return back...");
        getch();
        transaction();
    }


}






void withdrawl()
{
    int id, flag = 0, wrongpass = 0;
    double money;
    system("CLS");
    gotoxy(50,10);
    printf("CASH WITHDRAWAL");
    gotoxy(50,12);
    printf("Enter Your Account Number : ");
    scanf("%d", &id);

    struct add *temptemp = head;

    while (temptemp != NULL)
    {
        if (temptemp->id == id)
        {
            flag = 1;
            gotoxy(50,14);
            printf("Account Found");

            while (wrongpass < 3)
            {
                gotoxy(50,15);
                printf("Enter Your username : ");
                char tempname[20];
                scanf(" %[^\n]", tempname);
                gotoxy(50,16);
                printf("Enter Your Password : ");
                char temppass[20];
               dummy = getchar();
                scanf(" %[^\n]", temppass);

                if (strcmp(temptemp->userid, tempname) == 0 && strcmp(temptemp->pass, temppass) == 0)
                {
                    system("cls");
                    gotoxy(50,10);
                    printf("LOGIN SUCCESSFUL");
                    sleep(1);
                    gotoxy(50,12);
                    printf("Enter The Amount To Withdraw : $ ");
                    scanf("%lf", &money);

                    if (temptemp->deposit >= money)
                    {
                        temptemp->deposit -= money;
                        gotoxy(50,14);
                        printf("CASH WITHDRAWAL SUCCESSFUL");
                        saveToFile();
                        loadFromFile();
                        gotoxy(50,18);
                        printf("Press Any Key To Continue ....   ");
                        getch();
                        transaction();
                    }
                    else
                    {
                        gotoxy(50,14);
                        printf("Entered amount exceeds current balance");
                        gotoxy(50,16);
                        printf("Current Balance is $%.2lf", temptemp->deposit);
                        gotoxy(50,18);
                        printf("Press any key to return back...");
                        getch();
                        transaction();
                    }
                }
                else
                {
                    system("cls");
                    gotoxy(50,10);
                    printf("Wrong Password\n");
                    wrongpass++;
                    if (wrongpass == 3)
                    {
                        gotoxy(50,14);
                        printf("Press any key to return back...");
                        getch();
                        transaction();
                    }
                    sleep(2);
                }
            }
        }

        temptemp = temptemp->next;
    }

    if (flag == 0)
    {
        gotoxy(50,14);
        printf("Account Doesn't Exist");
        gotoxy(50,18);
        printf("Press any key to return back...");
        getch();
        transaction();
    }
}

//**********************************************************************************************
//**********************************************************************************************
////Load file

void loadFromFile()
{
    FILE *fp = fopen("Record.txt", "r");
    if (fp == NULL)
    {
        printf("File may not exist yet\n");
        return;
    }

    head = NULL;

    // Skip first line
    char dummy[500];
    fgets(dummy, sizeof(dummy), fp);


    struct add *current = head;
    while (!feof(fp))
    {
        struct add *newnode = (struct add*)malloc(sizeof(struct add));
        if (newnode == NULL)
        {
            printf("Memory allocation failed.\n");
            exit(1);
        }
        if (fscanf(fp, "%s %d %s %d %s %s %lf", newnode->name, &newnode->id, newnode->address, &newnode->phone,newnode->userid,newnode->pass, &newnode->deposit) != 7)
        {
            total_user++;
            free(newnode);
            break;
        }
        newnode->next = NULL;

        if (head == NULL)
            head = newnode;
        else
            current->next = newnode;

        current = newnode;
    }
    fclose(fp);
}

void saveToFile()
{
    FILE *fp = fopen("Record.txt", "w");
    if (fp == NULL)
    {
        printf("Error opening file for writing.\n");
        return;
    }

    // header
    fprintf(fp, "Name\t\tID\t\tAddress\tPhone\t\tUserID\t\tPassword\t\tBalance\n\n");

    struct add *current = head;
    while (current != NULL)
    {
        fprintf(fp, "%s\t%d\t%s\t%d\t%s\t%s\t\t%.2lf\n", current->name, current->id, current->address, current->phone, current->userid, current->pass, current->deposit);
        current = current->next;
    }

    fclose(fp);
}
