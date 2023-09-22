#include <iostream>
#include <conio.h>
#include <windows.h>

using namespace std;

string usernames[15] = {"masterwebedu", "master"};
string passwords[15] = {"4566897", "30"};
string roles[15] = {"Admin", "Manager"};
string stockAccessoryItems[10] = {"handfree", "Charger", "Datacable (Normal)", "Adapter", "C-Type Datacable"};
int stockAccessroyPrices[10] = {300, 500, 150, 350, 200};
int stockAccessroyActualPrices[10] = {150, 200, 75, 125, 100};
int noOfStockAccessory[10] = {30, 30, 30, 30, 30, 30};
string TouchRepairing[6] = {"Sumsung Panel", "Oppo Panel", "Vivo Panel", "Jeck", "Mic", "Speaker"};
int TouchRepairingPrices[6] = {3500, 3000, 2500, 400, 300, 350};
int TouchRepairingActualPrices[6] = {2500, 2000, 1500, 100, 100, 150};
int noOfTouchRepairingItems[6] = {5, 5, 5, 5, 5, 5};
string notepadRepairing[3] = {"Jeck", "Mic", "Speaker"};
int notepadRepairingPrices[3] = {200, 200, 200};
int notepadRepairingActualPrices[3] = {50, 50, 50};
int noOfNotepadRepairingItems[3] = {5, 5, 5};
string customerName[100];
string customerItems[100];
int actualPrices[100];
int customerPrices[100];
int noOfItems[100];
string managerCity[14] = {"lahore"};
string managerCONTACT[14] = {"03354566897"};
string managerCNIC[14] = {"3540129181657"};

int userCounter = 2;
int accessoryCounter = 5;
int customerCounter = 0;
int managerCounter = 1;

void gotoxy(int x, int y);
void startingLogo();
void copyrightText();
void header();
void clearScreen();
void subMenuBeforeMainMenu(string);
void subMenu(string);
int loginScreen();
bool signUp(string, string, string);
string signIn(string, string);
void adminInterface();
int adminMenu();
void managerInterface();
int managerMenu();
void customerInterface();
int customerMenu();
void buyAccessory();
void viewStock();
bool addStock();
void changePrice();
void itemsAndPrices();
void customerDetail();
bool searchCustomer();
void accessoryInterface();
int accessoryMenu();
void profit();
void sales();
void managerSignup();
void touchRepairingInterface();
int touchRepairingMenu();
void notepadRepairingInterface();
int notepadRepairingMenu();
void bill();

main()
{
    int loginOption = 0;

    system("cls");
    startingLogo();
    gotoxy(12, 13);
    copyrightText();
    Sleep(1000);
    system("cls");

    while (loginOption != 3)
    {
        header();
        subMenuBeforeMainMenu("Login");
        loginOption = loginScreen();
        if (loginOption == 1)
        {
            system("cls");

            string name;
            string password;
            string role;
            header();
            subMenuBeforeMainMenu("SignIn");
            cout << "Enter your Name: " << endl;
            cin >> name;
            cout << "Enter your Password: " << endl;
            cin >> password;
            role = signIn(name, password);

            if (role == "Admin")
            {
                clearScreen();
                adminInterface();
            }
            else if (role == "Manager")
            {
                clearScreen();
                managerInterface();
            }
            else if (role == "Customer")
            {
                clearScreen();
                customerInterface();
            }
            else if (role == "undefined")
            {
                cout << "You Entered wrong Credentials" << endl;
                clearScreen();
            }
            system("cls");
        }
        else if (loginOption == 2)
        {
            system("cls");
            string name;
            string password;
            string role;
            header();
            subMenuBeforeMainMenu("SignUp");
            cout << "Enter your Name: " << endl;
            cin >> name;
            cout << "Enter your Password: " << endl;
            cin >> password;
            role = "Customer";
            bool condition = signUp(name, password, role);
            if (condition)
            {
                cout << "SignedUp Successfully" << endl;
            }
            if (!condition)
            {
                cout << "Users in the System have exceeded the Capacity" << endl;
            }
            clearScreen();
        }
    }
}

void gotoxy(int x, int y)
{
    COORD coordinates;
    coordinates.X = x;
    coordinates.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coordinates);
}

void startingLogo()
{
    cout << " ::::::::         :::::::::::::::::::::::::::::::::::::::::::::::::::: " << endl;
    cout << " ::   :::         :::                                               :: " << endl;
    cout << " ::   :::         :::          :     :           ::::::::::::::::   :: " << endl;
    cout << " ::   :::         :::         :::   :::          ::::::::::::::::   :: " << endl;
    cout << " ::   :::::::::::::::        ::::: :::::         :::                :: " << endl;
    cout << " ::   :::::::::::::::       ::: ::::: :::        :::                :: " << endl;
    cout << " ::   :::         :::      :::   :::   :::       :::   Center       :: " << endl;
    cout << " ::   ::: Huzaifa :::     :::     :     :::      :::                :: " << endl;
    cout << " ::   :::         :::    :::             :::     ::::::::::::::::   :: " << endl;
    cout << " ::   :::         :::   :::     Mobile    :::    ::::::::::::::::   :: " << endl;
    cout << " ::                                        :::                      :: " << endl;
    cout << " ::::::::::::::::::::::::::::::::::::::::   :::::::::::::::::::::::::: " << endl;
}

void copyrightText()
{
    string text = "Huzaifa Mobile Center : All rights are reserved.";
    int idx = 0;
    while (text[idx] != '\0')
    {
        cout << text[idx];
        Sleep(50);
        idx++;
    }
    gotoxy(32, 14);
    cout << "@ master";
    cout << endl
         << endl;
}

void header()
{
    cout << "************************************************************" << endl;
    cout << "*         Huzaifa Mobile Center & Repairing Lab            *" << endl;
    cout << "************************************************************" << endl;
    cout << endl;
}

int loginScreen()
{
    int choose;
    cout << "1. Login" << endl;
    cout << "2. Signup" << endl;
    cout << "3. Exit";
    cout << endl
         << "Your Choice (1-3): ";
    cin >> choose;
    return choose;
}

void subMenuBeforeMainMenu(string submenu)
{
    string message = submenu + " Menu";
    int idx = 1;
    int xPosition;
    while (message[idx] != '\0')
    {
        idx++;
    }
    xPosition = (60 - idx) / 2;
    gotoxy((xPosition), 4);
    cout << message << endl;
    gotoxy((xPosition), 5);
    int i = 1;
    while (i != idx)
    {
        cout << "*";
        i++;
    }
    cout << endl;
}

void subMenu(string submenu)
{
    string message = "Main Menu > " + submenu;
    cout << message << endl;
    cout << "---------------------" << endl;
}

bool signUp(string name, string password, string role)
{
    if (userCounter < 15)
    {
        usernames[userCounter] = name;
        passwords[userCounter] = password;
        roles[userCounter] = role;
        userCounter++;
        return true;
    }
    else
    {
        return false;
    }
}

void clearScreen()
{
    cout << "Press Any Key to Continue.." << endl;
    getch();
    system("cls");
}

int adminMenu()
{
    int choose;
    cout << "Select one of the following options number..." << endl;
    cout << "1. View Profit" << endl;
    cout << "2. View Sales" << endl;
    cout << "3. View Managers Detail" << endl;
    cout << "4. Add Manager" << endl;
    cout << "5. View All created  Accounts" << endl;
    cout << "6. Exit" << endl;
    cout << "Your Option..";
    cin >> choose;
    return choose;
}

void adminInterface()
{
    int adminOption = 0;
    while (adminOption != 6)
    {
        header();
        subMenuBeforeMainMenu("Admin");
        subMenu("admin");
        adminOption = adminMenu();
        if (adminOption == 1)
        {
            system("cls");
            header();
            subMenuBeforeMainMenu("Admin");
            subMenu("View Profit");
            profit();
            clearScreen();
        }
        else if (adminOption == 2)
        {
            system("cls");
            header();
            subMenuBeforeMainMenu("Admin");
            subMenu("View Sales");
            sales();
            clearScreen();
        }
        else if (adminOption == 3)
        {
            system("cls");
            header();
            subMenuBeforeMainMenu("Admin");
            subMenu("View Manager Details");
            int c = 0;
            for (int idx = 0; idx < 15; idx++)
            {
                if (roles[idx] == "Manager")
                {
                    cout << "Name: " << usernames[idx] << endl;
                    cout << "Contact No: " << managerCONTACT[c] << endl;
                    cout << "CNIC No: " << managerCNIC[c] << endl;
                    cout << "City: " << managerCity[c] << endl;
                    cout << "--------------------------------" << endl;

                    c++;
                }
            }
            clearScreen();
        }
        else if (adminOption == 4)
        {
            system("cls");
            header();
            subMenuBeforeMainMenu("Admin");
            subMenu("Add Manager");
            managerSignup();
            clearScreen();
        }
        else if (adminOption == 5)
        {
            system("cls");
            header();
            subMenuBeforeMainMenu("Admin");
            subMenu("All Accounts");
            for (int idx = 0; idx < userCounter; idx++)
            {
                cout << usernames[idx] << " : " << roles[idx] << endl;
            }
            clearScreen();
        }
        system("cls");
    }
}

int managerMenu()
{
    int choose;
    cout << "Select one of the following options number..." << endl;
    cout << "1. View Stock" << endl;
    cout << "2. Add Stock" << endl;
    cout << "3. View Items and their Prices" << endl;
    cout << "4. Change Price" << endl;
    cout << "5. Total Customers" << endl;
    cout << "6. Exit" << endl;
    cout << "Your Option..";
    cin >> choose;
    return choose;
}

void managerInterface()
{
    int managerOption = 0;
    while (managerOption != 6)
    {
        header();
        subMenuBeforeMainMenu("manager");
        subMenu("manager");
        managerOption = managerMenu();
        if (managerOption == 1)
        {
            system("cls");
            header();
            subMenuBeforeMainMenu("manager");
            subMenu("View Stock");
            viewStock();
            clearScreen();
        }
        else if (managerOption == 2)
        {
            bool flag;
            system("cls");
            header();
            subMenuBeforeMainMenu("manager");
            subMenu("Add Stock");
            flag = addStock();
            if (flag)
            {
                cout << "Enter the name of Item: ";
                cin >> stockAccessoryItems[accessoryCounter];
                cout << "Enter the price of Item: ";
                cin >> stockAccessroyPrices[accessoryCounter];
                cout << "Enter the Actual Price of Item: ";
                cin >> stockAccessroyActualPrices[accessoryCounter];
                cout << "Enter no of Items: ";
                cin >> noOfStockAccessory[accessoryCounter];
                accessoryCounter++;
                cout << "You've successfully added a Item to Stock." << endl;
            }
            else if (!flag)
            {
                cout << "Limit of addition is exceeded." << endl;
            }
            clearScreen();
        }
        else if (managerOption == 3)
        {
            system("cls");
            header();
            subMenuBeforeMainMenu("manager");
            subMenu("Item Prices");
            itemsAndPrices();
            clearScreen();
        }

        else if (managerOption == 4)
        {
            changePrice();
            clearScreen();
        }
        else if (managerOption == 5)
        {
            system("cls");
            header();
            subMenuBeforeMainMenu("manager");
            subMenu("Total Customers");
            customerDetail();
            clearScreen();
        }
        system("cls");
    }
}

int customerMenu()
{
    int choose;
    cout << "Select one of the following options number..." << endl;
    cout << "1. Buy Accessory" << endl;
    cout << "2. Touch Mobile Repairing" << endl;
    cout << "3. Keypad Mobile Repairing" << endl;
    cout << "4. View Bill" << endl;
    cout << "5. Exit" << endl;
    cout << "Your Option..";
    cin >> choose;
    return choose;
}

void customerInterface()
{
    int customerOption = 0;
    while (customerOption != 5)
    {
        header();
        subMenuBeforeMainMenu("customer");
        subMenu("customer");
        customerOption = customerMenu();
        system("cls");
        if (customerOption == 1)
        {
            accessoryInterface();
        }
        else if (customerOption == 2)
        {
            touchRepairingInterface();
        }
        else if (customerOption == 3)
        {
            notepadRepairingInterface();
        }
        else if (customerOption == 4)
        {
            system("cls");
            header();
            subMenuBeforeMainMenu("customer");
            subMenu("View Bill");
            bill();
            clearScreen();
        }
    }
}

void accessoryInterface()
{
    int choice;

    while (choice != (accessoryCounter + 1))
    {
        header();
        subMenuBeforeMainMenu("customer");
        subMenu("Accessories");
        choice = accessoryMenu();
        if (choice != (accessoryCounter + 1))
        {
            system("cls");
            header();
            subMenuBeforeMainMenu("customer");
            subMenu(stockAccessoryItems[choice - 1]);
            cout << "Iten Name: " << stockAccessoryItems[choice - 1] << endl;
            cout << "Item Price: " << stockAccessroyPrices[choice - 1] << endl;
            cout << "Available Stock of this Items: " << noOfStockAccessory[choice - 1] << endl;
            string decision = "no";
            cout << "Do you want to buy it (yes/no)? ";
            cin >> decision;
            if (decision == "yes")
            {
                cout << "Please enter you first name (And remember it, it'll help you to check your bill in future): ";
                cin >> customerName[customerCounter];
                cout << "Total number of items that you want to buy: ";
                cin >> noOfItems[customerCounter];
                cout << "Thank You! for having our product." << endl;
                actualPrices[customerCounter] = stockAccessroyActualPrices[choice - 1];
                noOfStockAccessory[choice - 1] = noOfStockAccessory[choice - 1] - noOfItems[customerCounter];
                customerItems[customerCounter] = stockAccessoryItems[choice - 1];
                customerPrices[customerCounter] = stockAccessroyPrices[choice - 1];
                customerCounter++;
                clearScreen();
            }
            else
            {
                clearScreen();
            }
        }

        system("cls");
    }
}

int accessoryMenu()
{
    int idx = 0;
    int choose;
    cout << "Select one of the following options" << endl;
    for (idx = 0; idx < accessoryCounter; idx++)
    {
        cout << idx + 1 << ". " << stockAccessoryItems[idx] << endl;
    }
    cout << idx + 1 << ". Back" << endl;
    cout << "Your Option..";
    cin >> choose;
    return choose;
}

string signIn(string name, string password)
{
    for (int index = 0; index < userCounter; index++)
    {
        if (usernames[index] == name && passwords[index] == password)
        {
            return roles[index];
        }
    }
    return "undefined";
}

void viewStock()
{
    cout << endl
         << "Accessory Items" << endl
         << endl;
    for (int idx = 0; idx < accessoryCounter; idx++)
    {
        cout << stockAccessoryItems[idx] << " : " << noOfStockAccessory[idx] << endl;
    }
    cout << endl
         << "---------------------------" << endl
         << endl;
    cout << "Touch Repairing Items" << endl
         << endl;
    for (int idx = 0; idx < 6; idx++)
    {
        cout << TouchRepairing[idx] << " : " << noOfTouchRepairingItems[idx] << endl;
    }
    cout << endl
         << "---------------------------" << endl
         << endl;
    cout << "Notepad Repairing Items" << endl
         << endl;
    for (int idx = 0; idx < 3; idx++)
    {
        cout << notepadRepairing[idx] << " : " << noOfNotepadRepairingItems[idx] << endl;
    }
    cout << endl
         << "---------------------------" << endl
         << endl;
}

bool addStock()
{
    if (accessoryCounter < 10)
    {
        return true;
    }
    else
    {
        return false;
    }
}
void changePrice()
{
    int option = 0;

    while (option != 4)
    {
        system("cls");
        header();
        subMenuBeforeMainMenu("manager");
        subMenu("Update Price");
        cout << "Please Select the type of Item." << endl;
        cout << "1. Accessory Item" << endl;
        cout << "2. Touch Repairing Item" << endl;
        cout << "3. Notepad Repairing Item" << endl;
        cout << "4. Back" << endl;
        cout << "Choose Option..";
        cin >> option;

        if (option == 1)
        {

            system("cls");
            header();
            subMenuBeforeMainMenu("Update Price");
            char name[50];
            bool flag = false;
            int idx = 0;
            cout << "Total Accessory Items are as follows." << endl;
            for (int index =0; index <accessoryCounter; index ++)
            {
                cout << (index + 1) << " : " << stockAccessoryItems[index] << endl;
            }
            cout << "Enter the name of Item: ";
            cin.clear();
            cin.ignore();
            cin.get(name, 50);
            for (idx = 0; idx < accessoryCounter; idx++)
            {
                if (name == stockAccessoryItems[idx])
                {
                    flag = true;
                    break;
                }
            }
            if (flag)
            {
                cout << "Price of the Selected item is: " << stockAccessroyPrices[idx] << endl;
                cout << "Enter the price to update the system: ";
                cin >> stockAccessroyPrices[idx];
                cout << "Your New Price is: " << stockAccessroyPrices[idx] << endl;
            }
            else
            {
                cout << "Entered Item does not exist in the system." << endl;
            }
            clearScreen();
        }
        else if (option == 2)
        {
            system("cls");
            header();
            subMenuBeforeMainMenu("Update Price");
            char name[50];
            bool flag = false;
            int idx = 0;
            cout << "Total Repairing Items are as follows." << endl;
            for (int index =0; index <6; index ++)
            {
                cout << (index + 1) << " : " << TouchRepairing[index] << endl;
            }
            cout << "Enter the name of Item: ";
            cin.clear();
            cin.ignore();
            cin.get(name, 50);
            for (idx = 0; idx < 6; idx++)
            {
                if (name == TouchRepairing[idx])
                {
                    flag = true;
                    break;
                }
            }
            if (flag)
            {
                cout << "Price of the Selected item is: " << TouchRepairingPrices[idx] << endl;
                cout << "Enter the price to update the system: ";
                cin >> TouchRepairingPrices[idx];
                cout << "Your New Price is: " << TouchRepairingPrices[idx] << endl;
            }
            else
            {
                cout << "Entered Item does not exist in the system." << endl;
            }
            clearScreen();
        }
        else if (option == 3)
        {
            system("cls");
            header();
            subMenuBeforeMainMenu("Update Price");
            char name[50];
            bool flag = false;
            int idx = 0;
            cout << "Total keypad Items are as follows." << endl;
            for (int index =0; index < 3; index ++)
            {
                cout << (index + 1) << " : " << notepadRepairing[index] << endl;
            }
            cout << "Enter the name of Item: ";
            cin.clear();
            cin.ignore();
            cin.get(name, 50);
            for (idx = 0; idx < 3; idx++)
            {
                if (name == notepadRepairing[idx])
                {
                    flag = true;
                    break;
                }
            }
            if (flag)
            {
                cout << "Price of the Selected item is: " << notepadRepairingPrices[idx] << endl;
                cout << "Enter the price to update the system: ";
                cin >> notepadRepairingPrices[idx];
                cout << "Your New Price is: " << notepadRepairingPrices[idx] << endl;
            }
            else
            {
                cout << "Entered Item does not exist in the system." << endl;
            }
            clearScreen();
        }
    }
}

void itemsAndPrices()
{
    cout << endl
         << "Accessory Items" << endl
         << endl;
    for (int idx = 0; idx < accessoryCounter; idx++)
    {
        cout << stockAccessoryItems[idx] << " : " << stockAccessroyPrices[idx] << endl;
    }
    cout << endl
         << "---------------------------" << endl
         << endl;
    cout << "Touch Repairing Items" << endl
         << endl;
    for (int idx = 0; idx < 6; idx++)
    {
        cout << TouchRepairing[idx] << " : " << TouchRepairingPrices[idx] << endl;
    }
    cout << endl
         << "---------------------------" << endl
         << endl;
    cout << "Notepad Repairing Items" << endl
         << endl;
    for (int idx = 0; idx < 3; idx++)
    {
        cout << notepadRepairing[idx] << " : " << notepadRepairingPrices[idx] << endl;
    }
    cout << endl
         << "---------------------------" << endl
         << endl;
}

void customerDetail()
{
    int c = 0;
    for (int idx = 0; idx < 15; idx++)
    {
        if (roles[idx] == "Customer")
        {
            cout << usernames[idx] << endl;
            c++;
        }
    }
    if (c == 0)
    {
        cout << "There's no any data to show here." << endl;
    }
}

void sales()
{
    int sale = 0;
    int help = 0;
    for (int idx = 0; idx < customerCounter; idx++)
    {
        cout << customerItems[idx] << " : " << noOfItems[idx] << " : " << customerPrices[idx] << endl;
    }
    for (int idx = 0; idx < customerCounter; idx++)
    {
        sale = (customerPrices[idx] * noOfItems[idx]) + help;
        help = sale;
    }
    cout << "Total Sale is: " << sale << endl;
}

void profit()
{
    int profit = 0;
    int help = 0;
    for (int idx = 0; idx < customerCounter; idx++)

    {
        profit = ((customerPrices[idx] - actualPrices[idx]) * noOfItems[idx]) + help;
        help = profit;
    }
    cout << "Total profit is: " << profit << endl;
}

void managerSignup()
{
    if (userCounter < 15)
    {
        cout << "Enter username: ";
        cin >> usernames[userCounter];
        cout << "Enter Password: ";
        cin >> passwords[userCounter];
        roles[userCounter] = "Manager";
        cout << "Enter Contact Number: ";
        cin >> managerCONTACT[managerCounter];
        cout << "Enter CNIC Number: ";
        cin >> managerCNIC[managerCounter];
        cout << "Enter City: ";
        cin >> managerCity[managerCounter];
        cout << endl
             << "You've Successfully Created a manager account" << endl;
        managerCounter++;
        userCounter++;
    }
}

void touchRepairingInterface()
{
    int choice;

    while (choice != 7)
    {
        header();
        subMenuBeforeMainMenu("customer");
        subMenu("Touch Mobile Repairing");
        choice = touchRepairingMenu();
        if (choice != (7))
        {
            system("cls");
            header();
            subMenuBeforeMainMenu("customer");
            subMenu(TouchRepairing[choice - 1]);
            cout << "Iten Name: " << TouchRepairing[choice - 1] << endl;
            cout << "Item Price: " << TouchRepairingPrices[choice - 1] << endl;
            cout << "Available Stock of this Items: " << noOfTouchRepairingItems[choice - 1] << endl;
            string decision = "no";
            cout << "Do you want to buy it (yes/no)? ";
            cin >> decision;
            if (decision == "yes")
            {
                cout << "Please enter you first name (And remember it, it'll help you to check your bill in future): ";
                cin >> customerName[customerCounter];
                cout << "Total number of items that you want to buy: ";
                cin >> noOfItems[customerCounter];
                cout << "Thank You! for having our product." << endl;
                actualPrices[customerCounter] = TouchRepairingActualPrices[choice - 1];
                noOfTouchRepairingItems[choice - 1] = noOfTouchRepairingItems[choice - 1] - noOfItems[customerCounter];
                customerItems[customerCounter] = TouchRepairing[choice - 1];
                customerPrices[customerCounter] = TouchRepairingPrices[choice - 1];
                customerCounter++;
                clearScreen();
            }
            else
            {
                clearScreen();
            }
        }

        system("cls");
    }
}

int touchRepairingMenu()
{
    int idx = 0;
    int choose;
    cout << "Select one of the following options" << endl;
    for (idx = 0; idx < 6; idx++)
    {
        cout << idx + 1 << ". " << TouchRepairing[idx] << endl;
    }
    cout << idx + 1 << ". Back" << endl;
    cout << "Your Option..";
    cin >> choose;
    return choose;
}

void notepadRepairingInterface()
{
    int choice;

    while (choice != 4)
    {
        header();
        subMenuBeforeMainMenu("customer");
        subMenu("Keypad Mobile Repairing");
        choice = notepadRepairingMenu();
        if (choice != (4))
        {
            system("cls");
            header();
            subMenuBeforeMainMenu("customer");
            subMenu(notepadRepairing[choice - 1]);
            cout << "Iten Name: " << notepadRepairing[choice - 1] << endl;
            cout << "Item Price: " << notepadRepairingPrices[choice - 1] << endl;
            cout << "Available Stock of this Items: " << noOfNotepadRepairingItems[choice - 1] << endl;
            string decision = "no";
            cout << "Do you want to buy it (yes/no)? ";
            cin >> decision;
            if (decision == "yes")
            {
                cout << "Please enter you first name (And remember it, it'll help you to check your bill in future): ";
                cin >> customerName[customerCounter];
                cout << "Total number of items that you want to buy: ";
                cin >> noOfItems[customerCounter];
                cout << "Thank You! for having our product." << endl;
                actualPrices[customerCounter] = notepadRepairingActualPrices[choice - 1];
                noOfNotepadRepairingItems[choice - 1] = noOfNotepadRepairingItems[choice - 1] - noOfItems[customerCounter];
                customerItems[customerCounter] = notepadRepairing[choice - 1];
                customerPrices[customerCounter] = notepadRepairingPrices[choice - 1];
                customerCounter++;
                clearScreen();
            }
            else
            {
                clearScreen();
            }
        }

        system("cls");
    }
}

int notepadRepairingMenu()
{
    int idx = 0;
    int choose;
    cout << "Select one of the following options" << endl;
    for (idx = 0; idx < 3; idx++)
    {
        cout << idx + 1 << ". " << notepadRepairing[idx] << endl;
    }
    cout << idx + 1 << ". Back" << endl;
    cout << "Your Option..";
    cin >> choose;
    return choose;
}

void bill()
{
    int sum = 0;
    int help;
    string name;
    cout << "Enter Your first name: ";
    cin >> name;
    for (int idx = 0; idx < customerCounter; idx++)
    {
        if (name == customerName[idx])
        {
            cout << customerItems[idx] << " : " << noOfItems[idx] << " : " << customerPrices[idx] << endl;
        }
    }
    for (int idx = 0; idx < customerCounter; idx++)
    {
        if (name == customerName[idx])
        {
            help = noOfItems[idx] * customerPrices[idx];
            sum = sum + help;
        }
    }
    cout << "Your Total is: " << sum << endl;
}