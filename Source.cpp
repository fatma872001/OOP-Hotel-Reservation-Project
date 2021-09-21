#include"Room.h"
#include"Floor.h"
#include"StandardRoom.h"
#include"SweetRoom.h"
#include"ConferanceRoom.h"
#include <iostream>
#include <fstream>
#include <string>
#include<vector>
#include<cstdlib>

using namespace std;


int num;
int numr[30] = { 0 };
Floor* arr;

// function to show all the operations The receptionist can do
void menu() {
    cout << '\n' << "         1 - For Show statues in hotel" << endl;
    cout << "         2 - For Make reservation" << endl;
    cout << "         3 - For Cancel reservation" << endl;
    cout << "         4 - For Display available rooms in the floor you want to choose" << endl;
    cout << "         5 - For Display the total profits of current statues in hotel" << endl;
    cout << "         6 - For Exit" << endl;
    cout << "----------------------------------------------------------------------------" << endl;
}

// function to display message to tell The receptionist that the choice he entered is not one of showing ones means "not valid"
void NotValid() {
    cout << "invalid number, please choose from the menu";
}

// function to display/Show statues in hotel
void Displayhotel() {
    for (int i = 0; i < num; i++) {
        arr[i].display();
    }
}

// function that display the free rooms in each floor and its numbers and Make reservation by entering the number of the room he want
void ReserveAthotel() {

    for (int i = 0; i < num; i++) {
        cout << "\n  Floor" << i + 1 << endl;
        arr[i].displayavailable();
    }
    int numro;
    cout << "\n choose number of free room : ";
    cin >> numro;
    for (int i = 0; i < num; i++) {
        arr[i].ReserveFromFloor(numro);
    }
}

//function to Cancel the reservation by entering the number of this room
void CancelReservation() {
    int numro;
    cout << "Enter number of room you want to cancel it`s Reservation";
    cin >> numro;
    for (int i = 0; i < num; i++) {
        arr[i].CancelReservationFromFloor(numro);
    }
}

// function to display the available rooms in the floor you want to choose
void DisplayaVailableRoomsOnFloor() {
    int numflo;
    cout << "choose number of the floor you want to reserve in";
    cin >> numflo;
    arr[numflo - 1].displayavailable();
}

// function to display the total profits of current statues in hotel
void CurrentStatusProfit() {
    int profit = 0;
    for (int i = 0; i < num; i++) {
        arr[i].priceStatus();
        cout << "Floor " << i + 1 << " Profit " << arr[i].priceStatus() << endl;
        profit += arr[i].priceStatus();
    }
    cout << "Total price of current status = " << profit << endl;
}




int main() {
    int numch = 0;
    //call function menu that show all the operations The receptionist can do

    menu();
    bool k = true;
    while (k)
    {
        // opening the configuration file and read the hotel details from it
        ifstream newfile;
        newfile.open("HP.txt");
        string Total_Floors;
        newfile >> Total_Floors;
        newfile >> num; // variable to store number of floor
        arr = new Floor[num]; // dynamic array to create floors in hotel by the number of it configuration file
        string type[50][50];
        string numroom[50][50];
        int numroomi[30][30] = { 0 }; // array to store number of rooms in each floor
        string numbed[50][50];
        int numbedi[30][30] = { 0 };  // array to store number of bed in each room
        string price[50][50];
        int pricei[30][30] = { 0 };   //array to store price of elements in each room
        string nf[50];
        string room[50];
        Room* h ; // pointer to create rooms in each floor in the hotel

// 2D array to store information of all rooms in all floors of the hotel
        //first for loop loops on the number of floor
        for (int i = 0; i < num; i++) {
            newfile >> nf[i];
            newfile >> room[i];
            newfile >> numr[i];
            //store the number of rooms in each floor
            (arr + i)->setNumberofrooms(numr[i]);
            // for loop loops on the number of rooms
            for (int j = 0; j < numr[i]; j++) {
                // store the type of each room in floor
                newfile >> type[i][j];
                // condition check types and add room of this type
                   // sweet type
                if (type[i][j] == "Sweet,") {
                    h = new SweetRoom();
                    // arr[i].AddRoom(*h);
                    arr[i].AddRoom(h);
                    newfile >> numroom[i][j];
                    // handle the read information and transfer it to usable ones "from string with some additions to another without or to integers that up to the needed "
                    numroom[i][j].pop_back();
                    numroomi[i][j] = stoi(numroom[i][j]);
                    h->setRoomnumber(numroomi[i][j]);
                    newfile >> price[i][j];
                    price[i][j].pop_back();
                    pricei[i][j] = stoi(price[i][j]);
                    h->RPrice(pricei[i][j]);
                }
                //standard type
                else if (type[i][j] == "Standard,") {

                    h = new StandardRoom();
                    // arr[i].AddRoom(*h);
                    arr[i].AddRoom(h);
                    newfile >> numroom[i][j];
                    numroom[i][j].pop_back();
                    numroomi[i][j] = stoi(numroom[i][j]);
                    h->setRoomnumber(numroomi[i][j]);
                    newfile >> numbed[i][j];
                    numbed[i][j].pop_back();// bed `or seat
                    numbedi[i][j] = stoi(numbed[i][j]);
                    h->numofbedorseat(numbedi[i][j]);
                    newfile >> price[i][j];
                    price[i][j].pop_back();
                    pricei[i][j] = stoi(price[i][j]);
                    h->RPrice(pricei[i][j]);

                }
                else
                {
                    //standard type
                    h = new ConferanceRoom();
                    // arr[i].AddRoom(*h);
                    arr[i].AddRoom(h);
                    newfile >> numroom[i][j];
                    numroom[i][j].pop_back();
                    numroomi[i][j] = stoi(numroom[i][j]);
                    h->setRoomnumber(numroomi[i][j]);
                    newfile >> numbed[i][j];
                    numbed[i][j].pop_back();// bed or seat
                    numbedi[i][j] = stoi(numbed[i][j]);
                    h->numofbedorseat(numbedi[i][j]);
                    newfile >> price[i][j];
                    price[i][j].pop_back();
                    pricei[i][j] = stoi(price[i][j]);
                    h->RPrice(pricei[i][j]);
                }
            }
        }
        // close the file after reading all information
        newfile.close();
        // display functions in menu depend on the choice choosed
        int flag = 1;
        while (flag == 1)
        {
            cout << "                          ";
            cin >> numch;
            if (numch == 6) {
                flag = 0;
            }
            if (numch > 6 || numch < 1) {

                // call function to display message to tell The receptionist that the choice he entered is not one of showing ones means "not valid"
                NotValid();
            }
            else
            {
                system("cls");
                if (numch == 1) {

                    // call function to display/Show statues in hotel
                    cout << endl;
                    Displayhotel();
                    cout << endl<<" To Back to Main Menu ";
                    system("pause");
                    system("cls");
                    menu();
                }
                if (numch == 2) {

                    // call function that display the free rooms in each floor and its numbers and Make reservation by entering the number of the room he want
                    cout << endl;
                    ReserveAthotel();
                    cout << endl << " To Back to Main Menu ";
                    system("pause");
                    system("cls");
                    menu();
                }

                else if (numch == 3) {

                    // call function to Cancel the reservation by entering the number of this room
                    cout << endl;
                    CancelReservation();
                    cout << endl << " To Back to Main Menu ";
                    system("pause");
                    system("cls");
                    menu();
                }
                if (numch == 4) {

                    // call function to display the available rooms in the floor you want to choose
                    cout << endl;
                    DisplayaVailableRoomsOnFloor(); 
                    cout << endl << " To Back to Main Menu ";
                    system("pause");
                    system("cls");
                    menu();
                }

                if (numch == 5) {

                    // call function to display the total profits of current statues in hotel
                    cout << endl;
                    CurrentStatusProfit();
                    cout << endl << " To Back to Main Menu ";
                    system("pause");
                    system("cls");
                    menu();
                }
                if (numch == 6) {
                    //to close the program
                    k = false;
                }
            }
        }
    }

    cout << "         The Program is closed  \n";
    system("exit");


    return 0;
}


