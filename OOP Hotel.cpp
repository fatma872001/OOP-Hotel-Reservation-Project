#include <iostream>
#include <fstream>
#include <string>
#include<vector>
#include<cstdlib>
using namespace std;


class Room {
public:
    //Data members the room class "contains"
    int roomnumber = 0;
    int daysOfReservation = 0;
    bool isReserved = false;
    double price = 0;
public:
    // default constructor for room from type
    Room() {
        int roomnumber = 0;
        int daysOfReservation = 0;
        bool isReserved = false;
    }

    virtual void ReserveRoom() = 0; // to reserve room in hotel

    virtual void numofbedorseat(int) = 0;//to set number of beds in standard or seats in conference

    virtual void RPrice(double) = 0; //to set price

    virtual double Price() = 0; // to get price

    virtual double TotalPrice() = 0; // to calculate the total price of reservation

    virtual bool CheckReservation() = 0; // to check if the room is reserved or not

    virtual void toString() = 0;  //to display the details of each room.


    void setRoomnumber(int roomnumber){  // to store the room numbers for every room in each floor at hotel
        this->roomnumber = roomnumber;
    }
    int getRoomnumber(){                // to show or return the room numbers for every room in each floor at hotel
        return roomnumber;
    }
    void setDayOfReservation(int daysOfReservation){  // to store the number of Day Of Reservation for every room in each floor at hotel
        this->daysOfReservation = daysOfReservation;
    }
    int getDayOfReservation(){          //to show or return  the number of Day Of Reservation for every room in each floor at hotel
        return daysOfReservation;
    }
    void setIsReserved(bool isReserved){   // to store the value of boolean variable for reservation for every room in each floor at hotel
        this->isReserved = isReserved;
    }
    bool getIsReserved(){     // to show / return the value of boolean variable for reservation for every room in each floor at hotel
        return isReserved;
    }

};

class StandardRoom : public Room {
protected:

     //Data members the standard room "contains"
    int numofbed = 0;
    double bedprice = 0;
public:
    // constructor with parameter for room from standard type
    StandardRoom(int roomnumber, int daysOfReservation, bool isReserved, int numofbed, int bedprice) {
       this->bedprice = bedprice;
        this->numofbed = numofbed;
      }
    // defualt constructor for room from standard type
    StandardRoom(){
        int numofbed = 0;
        double bedprice = 0;
    }
    // to store the numbers of beds for every standard room in each floor at hotel
    void setNumofbed(int numofbed){

        this->numofbed = numofbed;
    }
    // override function to store the numbers of beds for every standard room and number of seat of very conference room in each floor at hotel
    void numofbedorseat(int numofbed){
        this->numofbed = numofbed;
    }
    //to return/get the numbers of beds for every standard room
    int getNumofbed() {
        return numofbed;
    }
    //to set beds price for every standard room
    void setBedprice(double bedprice){
        this->bedprice = bedprice;
    }
    //override function set beds price for every standard room
    void RPrice(double bedprice ) {
        this->bedprice = bedprice;
    }
    //override function return beds price for every standard
    double Price() {
        return bedprice;
    }
     //override  function to reserve room
    void ReserveRoom() override {
        isReserved = true;
    }
    //override  to check if the room is reserved or not
    bool CheckReservation() override {
        return isReserved;
    }
    //override  to calculate the total price of reservation
    double TotalPrice() override {
        return getNumofbed() * Price() * getDayOfReservation();
    }
    //override to display the details of each room.
    void toString() {
        cout << "Room Type : Standard and " << "Room number : " << getRoomnumber() << " and Number of beds : " << getNumofbed() << " and Bed +price :" << Price() << " and is reservation :" << CheckReservation()<<endl;

    }

};

class SweetRoom : public Room {
protected:

    //Data members the room form sweet type "contains"
    double pricepernight = 0;
public:

    // default constructor for room from sweet type
    SweetRoom(){
        double pricepernight = 0;
    }

    // to store the Price per night of the sweet room in each floor at hotel
    void setPricepernight(double pricepernight){
        this->pricepernight = pricepernight;
    }

    //override function set room per night price for every sweet room
    void RPrice(double pricepernight){
        this->pricepernight = pricepernight;
    }

    //override function get room per night price for every sweet room
    double Price(){
        return pricepernight;
    }

    //override  to reserve room
    void ReserveRoom() override{
        isReserved = true;
    }

    //override  to check if the room is reserved or not
    bool CheckReservation() override{
        return isReserved;
    }

    //override to calculate the total price of reservation
    double TotalPrice() override{
        return Price() * getDayOfReservation();
    }

    //override to display the details of each room.
    void toString() {
        cout << "Room Type : Sweet and " << " Room number :" << getRoomnumber() << " and Price per night :" << Price() << " and is reservation : " << CheckReservation() << endl;
    }

    void numofbedorseat(int ){}
};

class ConferanceRoom : public Room {
protected:

    //Data members the room form conference type "contains"
    int numofseats = 0;
    double seatprice = 0;
public:

    // default constructor for room from conference type
    ConferanceRoom(){
        int numofseats = 0;
        double seatprice = 0;
    }

    // to store the number of seats of the conference room in each floor at hotel
    void setNumofseats(int numofseats){
        this->numofseats = numofseats;
    }

    // override function to store the numbers of beds for every standard room and number of seat of very conference room in each floor at hotel
    void numofbedorseat(int numofseats){
        this->numofseats = numofseats;
    }

    // to return the number of seats of the conference room in each floor at hotel
    int getNumofseats(){
        return numofseats;
    }

    // to store the Price of seats of the conference room in each floor at hotel
    void setSeatprice(double seatprice){
        this->seatprice = seatprice;
    }

    //override function set seats price for every conference room
    void RPrice(double seatprice){
        this->seatprice = seatprice;
    }

    //override function get seats price for every conference room
    double Price(){
        return seatprice;
    }

    //override  to reserve room
    void ReserveRoom() override {
        isReserved = true;
    }

    //override  to check if the room is reserved or not
    bool CheckReservation() override {
        return isReserved;
    }

    // override to calculate the total price of reservation
    double TotalPrice() override {
        return Price() * getNumofseats() * getDayOfReservation();
    }

    // override to display the details of each room.
    void toString() {
        cout << "Room Type : Conference and " << " Room number : " << getRoomnumber() << "  and the Number of Seats : " << getNumofseats() << "   and Seat price : " << Price() << "  and is reservation :" << CheckReservation() << endl;

    }

};

class Floor
{
protected:

    //Data members the floor "contains"
    int floornumber=0;
    int numberofrooms=0;
    vector<Room*> ids = vector<Room*>();

public:

    // default constructor for floor
    Floor(){
     int floornumber=0;
    int numberofrooms=0;
    vector<Room*> ids = vector<Room*>();
    }

    // constructor with parameter for floor
    Floor(int floornumber, int numberofrooms) {
        this->floornumber = floornumber;
        this->numberofrooms = numberofrooms;
    }

   /* void AddRoom(Room & r)
    {
        ids.push_back(&r);
    }*/


    // function to store rooms from different types to it`s floor in hotel
    void AddRoom(Room * r){
        ids.push_back(r);
    }

    //function to store the floor number
    void setFloornumber(int floornumber) {
        this->floornumber = floornumber;
    }

    //function to return the floor number
    int getFloornumber(){
        return floornumber;
    }

    /*void setIds(vector<Room>& ids)
    {
        this->ids = ids;
    }*/

    // function to get rooms from different types from it`s floor in hotel
    vector<Room*> getIds(){
        return ids;
    }

    //function to store the number of rooms in each floor at hotel
    void setNumberofrooms(int numberofrooms){
        this->numberofrooms = numberofrooms;
    }

    //function to return the number of rooms in each floor at hotel
    int getNumberofrooms(){
        return getIds().size();
    }

    // function to show the free rooms in each floor "non reserved ones"
    void displayavailable(){
        for (int i = 0; i < ids.size(); i++)
        {
            if (ids[i]->isReserved == false)
            {
                cout << "the Room " << getIds()[i]->roomnumber << " : " << " is free" << endl;
            }

        }
    }

    // function to reserve room from specific floor
    void ReserveFromFloor(int nro){
       for (int i = 0; i < ids.size(); i++)
        {
            if (ids[i]->roomnumber == nro)
            {
                 if (ids[i]->isReserved == false){
                cout << "the Room " << getIds()[i]->roomnumber << " : " << " has been reserved" << endl;
                ids[i]->ReserveRoom();
                   int DOR = 0;
                    cout << "\n         Days Of Reservation :";
                    cin >> DOR;
                    ids[i]->setDayOfReservation(DOR);
                }
                 else{
                     cout << "the Room " << getIds()[i]->roomnumber << " : " << " it`s already reserved before" << endl;
                 }
            }

        }
    }

    // function to cancel reservation of a specific room
    void CancelReservationFromFloor(int nro){
       for (int i = 0; i < ids.size(); i++)
        {
            if (ids[i]->roomnumber == nro)
            {
                 if (ids[i]->isReserved == false){
                 cout << "the Room " << getIds()[i]->roomnumber << " : " << " it`s already free" << endl;
                 }
                 else{
                     cout << "the Room " << getIds()[i]->roomnumber << " : " << " it has been cancelled" << endl;
                     ids[i]->setIsReserved(false);
                 }
            }

        }
        }

    // function to display the details of each room in the floor
    void display(){
        for (int i = 0; i < ids.size(); i++){
            ids[i]->toString();
        }
    }

    // function to display the total profits for each floor
    string profits(){
        double total = 0;
        for (int i = 0; i < ids.size(); i++)
        {
            total += ids[i]->TotalPrice();
        }
        return "the Total profit is :" + to_string(total);

    }

    // function to return the total profits for only the reserved rooms in the floor
    double priceStatus(){
        double total = 0;
        for (int i = 0; i < ids.size(); i++){
            if (ids[i]->isReserved == true){
                 total += ids[i]->TotalPrice();
            }
        }
        return total;
    }
};



int num;
int numr[30] = { 0 };
Floor* arr;

// function to show all the operations The receptionist can do
void menu(){
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
        cout<<"Floor"<<i+1 <<endl;
        arr[i].displayavailable();
    }
    int numro;
    cout << "choose number of free room";
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
    arr[numflo-1].displayavailable();
 }

// function to display the total profits of current statues in hotel
void CurrentStatusProfit(){
  int profit=0;
  for (int i = 0; i < num; i++) {
      arr[i].priceStatus();
      cout<<"Floor "<<i+1 << " Profit "<<arr[i].priceStatus()<<endl;
       profit+=arr[i].priceStatus();
    }
   cout<<"Total price of current status = "<<profit<<endl;
}




int main() {
    int numch = 0;
    //call function menu that show all the operations The receptionist can do

    menu();
    cout << "                          ";
    bool k = true;
    while (k)
 {
         // opening the configuration file and read the hotel details from it
            ifstream newfile;
            newfile.open("tpoint.txt");
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
            Room* h=nullptr; // pointer to create rooms in each floor in the hotel

    // 2D array to store information of all rooms in all floors of the hotel
            //first for loop loops on the number of floor
            for (int i = 0; i < num; i++){
                newfile >> nf[i];
                newfile >> room[i];
                newfile >> numr[i];
                //store the number of rooms in each floor
                (arr + i)->setNumberofrooms(numr[i]);
                // for loop loops on the number of rooms
                for (int j = 0; j < numr[i]; j++){
                        // store the type of each room in floor
                    newfile >> type[i][j];
                    // condition check types and add room of this type
                       // sweet type
                    if (type[i][j] == "Sweet,"){
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
                    else if (type[i][j] == "Standard,"){

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
              int flag =1;
            while(flag==1)
            {
                 cin >> numch;
                 if(numch==6){
                    flag=0;
                 }
            if (numch > 6 || numch < 1) {

                // call function to display message to tell The receptionist that the choice he entered is not one of showing ones means "not valid"
                NotValid();
            }
            else
               {
                if (numch == 1){

                    // call function to display/Show statues in hotel
                    Displayhotel();
                }
               if (numch == 2){

                   // call function that display the free rooms in each floor and its numbers and Make reservation by entering the number of the room he want
                   ReserveAthotel();
                }

               else if (numch == 3){

                  // call function to Cancel the reservation by entering the number of this room
                   CancelReservation();
                }
                if (numch == 4){

                    // call function to display the available rooms in the floor you want to choose
                    DisplayaVailableRoomsOnFloor();
                }

               if (numch == 5){

                   // call function to display the total profits of current statues in hotel
                   CurrentStatusProfit();
                }
                if (numch==6){
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
