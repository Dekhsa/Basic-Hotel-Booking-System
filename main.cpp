// main.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
using namespace std;

// Room
int Room[3][10] = {
        {101,102,103,104,105,106,107,108,109,110},
        {201,202,203,204,205,206,207,208,209,210},
        {301,302,303,304,305,306,307,308,309,310}
};
bool Room_Status[3][10] = {};

// Food and Beverage
string FnB[20] = { 
    "Garlic Bread", "Chicken Pop", "Fried Rice", "Cheese Cake", "Grilled Wagyu", "Salad", "Sop Buntut", "Mushroom Soup", "Lasagna", "Beef Burger", "Blue Ocean", "Milkshake", "Mineral Water", "Americano", "v60", "Soda", "Ginger Tea", "Lemon Tea", "Orange Squash", "Cincau" 
};
int FnBPrice[20] = { 
    15000, 40000, 20000, 15000, 75000, 38000, 60000, 18000, 35000, 25000, 15000, 18000, 10000, 40000, 40000, 15000, 12000, 8000, 10000, 5000 
};
int FnBSize = size(FnB);
int MenuSize = 5;

// Service
string Service[5] = { "Laundry /KG", "Laundry /ITEM", "Fitness Gym /DAY", "Massage /HOUR", "Shuttle /KM" };
int ServicePrice[5] = { 15000, 5000, 30000, 50000, 5000 };

// Cart
string CartId[10];
int CartItemTotal[10];
int TotalItemPrice[10];
int CartSize = size(CartId);
int CartVal = 0;
int TotalPrice = 0;

int MenuChoice;


    // ============================================== Functions ==================================================

// Print Menu Bar Function (Void Type)
void mbar(int b)
{
    if (b == 1)
    {
        cout << "=================================================" << endl;
    }
    else if (b == 2)
    {
        cout << "|                                               |" << endl;
    }
    else if (b == 3)
    {
        cout << "|             HOTEL BOOKING SYSTEM              |" << endl;
    }
    else if (b == 4)
    {
        cout << "=================================================" << endl;
        cout << "|             HOTEL BOOKING SYSTEM              |" << endl;
        cout << "=================================================" << endl;
    }
};

// Cart Default Value Adding Function (Void Type)
void DefaultCart() {
    for (int i = 0; i < CartSize; i++) {
        CartId[i] = "Empty";
    }
}
    
// Room Search Function (Returning Boolean Value)
bool RoomSearch(int room) 
{
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 10; j++) {
            if (room == Room[i][j]) {
                return true;
            }
        }
    }
    return false;
};

// Room Status Search Function (Returning Boolean Value)
bool RoomStatSearch(int room) 
{
    int RFloor = 0, RRoom = 0;
    if (room > 100 && room <= 110) {
        RFloor = 0;
        RRoom = room - 101;
    }
    else if (room > 200 && room <= 210) {
        RFloor = 1;
        RRoom = room - 201;
    }
    else if (room > 300 && room <= 310) {
        RFloor = 2;
        RRoom = room - 301;
    }

    if (Room_Status[RFloor][RRoom] == true) {
        return true;
    }
    else {
        return false;
    }
};
   
// Print Menu Function (Void Type)
void PrintMenu() {
    system("cls");
    mbar(1); 
    cout << "|                   MAIN MENU                   |" << endl; 
    mbar(1);
    cout << "|  1.) FOODS AND BEVERAGES                      |" << endl;
    cout << "|  2.) HOTEL SERVICES                           |" << endl;
    cout << "|  3.) REPORT                                   |" << endl;
    cout << "|  4.) EXIT                                     |" << endl;
    mbar(1);
}

// Print Food Menu Function (Void Type)
void PrintMenuFnB(int PageNow) {
    system("cls");
    mbar(1);
    cout << "|              FOOD AND BEVERAGES               |" << endl;
    mbar(1);
    for (int i = PageNow * MenuSize; i < (PageNow + 1) * MenuSize; i++)
    {
        cout << "  " <<  i + 1 << ".) " << FnB[i] << " - " << FnBPrice[i] << endl;
    }
    mbar(1);
    cout << "|  1.) ORDER                                    |" << endl;
    cout << "|  2.) BACK                                     |" << endl;
    cout << "|  3.) FINISH                                   |" << endl;
    cout << "|  4.) PREVIOUS PAGE                            |" << endl;
    cout << "|  5.) NEXT PAGE                                |" << endl;
    mbar(1);
}

// Print Service Menu Function (Void Type)
void PrintMenuServices() {
    system("cls");
    mbar(1);
    cout << "|                HOTEL SERVICES                 |" << endl;
    mbar(1);
    for (int i = 0; i < size(ServicePrice); i++) {
        cout << "  " << i + 1 << ".) " << Service[i] << " - " << ServicePrice[i] << endl;
    }
    mbar(1);
    cout << "|  1.) ORDER                                    |" << endl;
    cout << "|  2.) BACK                                     |" << endl;
    cout << "|  3.) FINISH                                   |" << endl;
    mbar(1);
}

// Print Report Menu Function (Void Type)
void PrintMenuReport() {
    system("cls");
    mbar(1);
    cout << "|                    REPORT                     |" << endl;
    cout << "|  1.) INPUT REPORT                             |" << endl;
    cout << "|  2.) BACK                                     |" << endl;
    mbar(1);
}

// Cart Add Fuction (Void Type)
void CartAdd(int pilih) {
    CartVal = 0;            
    for (int i = 0; i < 10; i++) {
        if (FnB[pilih-1] == CartId[i] || Service[pilih-1] == CartId[i]) {
            string choose;
        Update:
            cout << "\n   MENU HAS BEEN ALREADY ON CART, DO YOU WANT" << endl;
            cout << "   TO UPDATE?(Y/N) "; cin >> choose;
            if (choose == "y" || choose == "Y") {
                cout << "\n   HOW  MANY(TOTAL AMOUNT)  DO  YOU  WANT  TO" << endl;
                cout << "   UPDATE : ";cin >> CartItemTotal[i];
                if (MenuChoice == 1) {
                    TotalItemPrice[i] = FnBPrice[i] * CartItemTotal[i];
                }else if (MenuChoice == 2) {
                    TotalItemPrice[i] = ServicePrice[i] * CartItemTotal[i];
                }
                cout << "\n   CART WAS UPDATED!" << endl;
                CartVal = 1;
                i = 11;
            }
            else if (choose == "n" || choose == "N") {
                CartVal = 1;
                i = 11;
            }
            else {
                cout << "   ONLY INPUT(Y/N)" << endl;
                goto Update;
            }
        }
        else if(CartId[i] == "Empty") {
            cout << "   HOW MANY ITEMS DO YOU WANT : ";cin >> CartItemTotal[i];
            if (MenuChoice == 1){
                CartId[i] = FnB[pilih - 1];
                TotalItemPrice[i] = FnBPrice[i] * CartItemTotal[i];
            }
            else if (MenuChoice == 2) {
                CartId[i] = Service[pilih - 1];
                TotalItemPrice[i] = ServicePrice[i] * CartItemTotal[i];
            }
            cout << "   CART WAS UPDATED!" << endl;
            CartVal = 1;
            i = 11;
        }
    }
}

// Print Receipt Function (Void Type)
void CartReceipt() {
    system("cls");
    string ReceiptChoice;
    CartVal = 0;
    mbar(1);
    cout << "|                    RECEIPT                    |" << endl;
    mbar(1);
    for (int i = 0; i < CartSize; i++) {
        cout << "  " << i + 1 << ".)  " << CartId[i] << " - " << CartItemTotal[i] << " - Rp." << TotalItemPrice[i] << ",-" << endl;
        TotalPrice += TotalItemPrice[i];
    }
    cout << "\n=================== Total Price : " << " - Rp." << TotalPrice << ",-" << endl;
    cout << "\n   ARE YOU SURE TO ORDER?(Y/N):"; cin >> ReceiptChoice;
    if (ReceiptChoice == "y" || ReceiptChoice == "Y") {
        cout << "\n   THANK YOU FOR ORDERING, THE WAITER WILL COME" << endl;
        cout << "                       SOON!" << endl;
        CartVal = 2;
    }
    else if (ReceiptChoice == "n" || ReceiptChoice == "N") {
        system("cls");
        TotalPrice = 0;
        CartVal = 1;
    }

}


    //  ======================================= Main Function =====================================================
int main()
{
    // Adding Default Value to Cart
    DefaultCart();
    //  == Room Status Example ====
    Room_Status[0][0]= true;
    //  ===========================
    Input_Room:
    int Room_Choice;
    mbar(4); cout << endl;
    cout << "   R00M : "; cin >> Room_Choice;
    if (RoomSearch(Room_Choice) && RoomStatSearch(Room_Choice) == true) {
        system("cls");
        goto Menu;
    }
    else {
        mbar(1);
        cout << "|  ROOM NOT FOUND OR ROOM HASN'T ORDERED YET!   |" << endl;
        mbar(1);
        goto Input_Room;
    }
    // Print Menu ==========
    Menu:
    PrintMenu();
    cout << "\n   ENTER YOUR CHOICE : "; cin >> MenuChoice;
    if (MenuChoice == 1) 
    {
        // Print Menu Food and Beverage ==========
        int FnBChoice,PageNow = 0;
    PrintMenuFnB:
        PrintMenuFnB(PageNow);
        cout << "   ENTER YOUR CHOICE : "; cin >> FnBChoice;
        switch (FnBChoice) {
        case 1:
            int pilih;
            cout << "   ENTER MENU NUMBER : "; cin >> pilih;
            CartAdd(pilih);
            if (CartVal == 1) {
                goto PrintMenuFnB;
            }
            break;
        case 2:
            goto Menu;
            break;
        case 3:
            goto PrintCart;
            break;
        case 4:
            if (PageNow == 0) {
                goto PrintMenuFnB;
            }
            else {
                PageNow--;
                goto PrintMenuFnB;
            }
            break;
        case 5:
            if (PageNow == (FnBSize / MenuSize) - 1) {
                goto PrintMenuFnB;
            }
            else {
                PageNow++;
                goto PrintMenuFnB;
            }
            break;
        default:
            goto PrintMenuFnB;
            break;
        }
    } else if (MenuChoice == 2) {
        // Print Menu Services ==========
        int ServiceChoice,MenuServiceChoice;
     PrintMenuServices:
        PrintMenuServices();
        cout << "   ENTER YOUR CHOICE : "; cin >> MenuServiceChoice;
        if (MenuServiceChoice == 1) {
            cout << "   ENTER MENU NUMBER : "; cin >> ServiceChoice;
            CartAdd(ServiceChoice);
            if (CartVal == 1) {
                goto PrintMenuServices;
            }
        }
        else if (MenuServiceChoice == 2) {
            goto Menu;
        }
        else if (MenuServiceChoice == 3) {
            goto PrintCart;
        }
        else {
            goto PrintMenuServices;
        }
    }
    else if (MenuChoice == 3) {
        // Print Menu Report ==========
     PrintMenuReport:
        PrintMenuReport();
        int MenuReportChoice;
        cout << "   ENTER YOUR CHOICE : "; cin >> MenuReportChoice;
        if (MenuReportChoice == 1) {
            string input,SubmitReport;
            cout << "   REPORT : ";cin >> input;
            getline(cin,input);
            mbar(1);
            cout << "|                 REPORT REVIEW                 |" << endl;
            mbar(1);
            cout << input << endl;
            mbar(1);
            cout << "|*disclaimer: if you submits  the  report, your |" << endl;
            cout << "| cart    will  be   deleted  and  you  will be |" << endl;
            cout << "| redirected to exit the program.               |" << endl;
            mbar(1);
            SubmitReport:
            cout << "   SUBMIT REPORT(Y/N) : "; cin >> SubmitReport;
            if (SubmitReport == "y" || SubmitReport == "Y") {
                system("cls");
                cout << "   THANK YOU FOR YOUR REPORT!" << endl;
                return 0;
            }
            else if (SubmitReport == "n" || SubmitReport == "N") {
                goto Menu;
            }
            else {
                cout << "   ONLY INPUT(Y/N)"; cin.ignore();
                goto SubmitReport;
            }
        }
        else if (MenuReportChoice == 2) {
            goto Menu;
        }
        else {
            goto PrintMenuReport;
        }

    }
    else if (MenuChoice == 4) {
        // Print Menu Exit ==========
        string ExitChoice;
        ExitChoice:
        cout << " ARE YOU SURE YOU WANT TO EXIT THE PROGRAM(Y/N)"; cin >> ExitChoice;
        if (ExitChoice == "y" || ExitChoice == "Y") {
            system("cls");
            return 0;
        }
        else if (ExitChoice == "n" || ExitChoice == "N") {
            goto Menu;
        }
        else {
            cout << "   ONLY INPUT(Y/N)"; cin.ignore();
            goto ExitChoice;
        }
    } else {
        system("cls");
        goto Menu;
    }
    // Print Cart (Finished) ==========
    PrintCart:
    CartReceipt();
    if (CartVal == 1) {
        goto Menu;
    }
    else if (CartVal == 2) {
        return 0;
    }
    else {
        system("cls");
        goto PrintCart;
    }
};
//  ==============================================================================================================

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
