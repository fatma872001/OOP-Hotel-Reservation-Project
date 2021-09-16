#include <iostream>
#include <fstream>
#include <string>
#include<vector>
#include<cstdlib>
using namespace std;


class Room {
  protected:
     int roomnumber = 0;
     int daysOfReservation = 0;
      bool isReserved = false;

  public:
     Room(){}
      Room(int roomnumber, int daysOfReservation, bool isReserved) {
        this->daysOfReservation=daysOfReservation;
        this->isReserved=isReserved;
        this->roomnumber=roomnumber;
    }
    virtual void ReverseRoom() = 0;

    virtual double TotalPrice() = 0;

    virtual bool CheckReservation() = 0;

    virtual string toString() = 0;


    void setRoomnumber(int roomnumber)
    {
        this->roomnumber = roomnumber;
    }
    int getRoomnumber()
    {
        return roomnumber;
    }
    void setDayOfReversation(int daysOfReservation)
    {
        this->daysOfReservation = daysOfReservation;
    }
    int getDayOfReversation()
    {
        return daysOfReservation;
    }
    void setIsReserved(bool isReserved)
    {
        this->isReserved = isReserved;
    }
    bool getIsReserved()
    {
        return isReserved;
    }
    
};

class StandardRoom : public Room {
private:
    int numofbed = 0;
    double bedprice = 0;
public:
	
    StandardRoom(int roomnumber, int daysOfReservation, bool isReserved, int numofbed, int bedprice) {
        this->bedprice = bedprice;
        this->numofbed = numofbed;
    }
    StandardRoom()
    {
        int numofbed = 0;
        double bedprice = 0;
    }
    void setNumofbed(int numofbed)
    {
        this->numofbed = numofbed;
    }
    int getNumofbed()
    {
        return numofbed;
    }
    void setBedprice(double bedprice)
    {
        this->bedprice = bedprice;
    }
    double getBedprice()
    {
        return bedprice;
    }
    void ReverseRoom() override
    {
        isReserved = true;
    }
    bool CheckReservation() override
    {
        return isReserved;
    }
    double TotalPrice() override
    {
        return getNumofbed() * getBedprice() * getDayOfReversation();
    }
      virtual string toString() {
        cout<<"Room Type : Standard and " << "Room number : " << roomnumber << " and Number of beds : " << numofbed << " and Bed price :" << bedprice<< " and is reservation :" << isReserved;

    }

};

class SweetRoom : public Room {
private:
    double pricepernight = 0;
 
public:
    SweetRoom() 
    {
        double pricepernight = 0;
    }
    void setPricepernight(double pricepernight)
    {
        this->pricepernight = pricepernight;
    }
    double getPricepernight()
    {
        return pricepernight;
    }
    void ReverseRoom() override
    {
        isReserved = true;
    }
    bool CheckReservation() override
    {
        return isReserved;
    }
    double TotalPrice() override
    {
        return getPricepernight() * getDayOfReversation();
    }
      virtual string toString() {
        cout<< "Room Type : Sweet and " << " Room number :" << roomnumber << " and Price per night :" << pricepernight << " and is reservation : " <<isReserved;

};

class ConferanceRoom : public Room {
private:
    int numofseats = 0;
    double seatprice = 0;

public:
    ConferanceRoom() 
    {
        int numofseats = 0;
        double seatprice = 0;
    }
    void setNumofseats(int numofseats)
    {
        this->numofseats = numofseats;
    }
    int getNumofseats()
    {
        return numofseats;
    }
    void setSeatprice(double seatprice)
    {
        this->seatprice = seatprice;
    }
    double getSeatprice()
    {
        return seatprice;
    }
    void ReverseRoom() override
    {
        isReserved = true;

    }
    bool CheckReservation() override
    {
        return isReserved;
    }
    double TotalPrice() override
    {
        return getSeatprice() * getNumofseats() * getDayOfReversation();
    }
      virtual string toString() {
        cout<< "Room Type : Conference and " << " Room number : " << roomnumber << " and the Number of Seats : " << numofseats <<"and Seat price : " << seatprice << "  and is reservation :" <<isReserved;

    }

};

class Floor
{
protected:
    int floornumber;
    int numberofrooms;
    //int List_of_Rooms[];
    vector<Room*> ids = vector<Room*>();
    
public:
    Floor(){}
    Floor(int floornumber, int numberofrooms) {
        this->floornumber = floornumber;
        this->numberofrooms = numberofrooms;
    }
    void setFloornumber(int floornumber) {
        this->floornumber = floornumber;
    }
    int getFloornumber()
    {
        return floornumber;
    }
    void setIds(vector<Room*>& ids)
    {
        this->ids = ids;
    }
    vector<Room*> getIds()
    {
        return ids;
    }
    void setNumberofrooms(int numberofrooms)
    {
        this->numberofrooms = numberofrooms;
    }
    int getNumberofrooms()
    {
        return getIds().size();
    }
    /*void set_List_of_Rooms(Room list_rooms[]) {
        List_of_Rooms[];
    }*/

    void displayavailable()
    {
        for (int i = 0; i < ids.size(); i++)
        {
            if (ids[i]->isReserved == false)
            {
                cout << "the Room " << getIds()[i]->roomnumber << " : " << " is free" << endl;
            }

        }
    }
    string profits()
    {
        double total = 0;
        for (int i = 0; i < ids.size(); i++)
        {
            total += ids[i]->TotalPrice();
        }
        return "the Total profit is :" + to_string(total);

    }
};


void menu()
{ //function for view the menu and choices
    cout << '\n' << "         1 - For Show statues in hotel" << endl;
    cout << "         2 - For Make reservation" << endl;
    cout << "         3 - For Cancel reservation" << endl;
    cout << "         4 - For Display available rooms in the floor you want to choose" << endl;
    cout << "         5 - For Display the total profits of current statues in hotel" << endl;
    cout << "         6 - For Exit" << endl;
    cout << "**************************" << endl;
}

void choice(int nc);




int num;
int numr[30] = { 0 };
Floor* arr = new Floor[num];


int main() {
    int numch = 0;
    menu();
    cout << "                          ";
    cin >> numch;
    if (numch == 6)
    {
        system("exit");
    }
    else
    {
        system("cls");
        if (numch == 1)
        {

        }
        
        
        else if (numch == 4)
        {

        }
        else if (numch == 5)
        {

        }

        ifstream newfile;
        newfile.open("HP.txt");
        string Total_Floors;
        newfile >> Total_Floors;
        newfile >> num;
        /*cout << Total_Floors <<" ";
        cout << num << "\n";*/
        string type[50][50];
        string numroom[50][50];
        int numroomi[30][30] = { 0 };
        string numbed[50][50];
        int numbedi[30][30] = { 0 };
        string price[50][50];
        int pricei[30][30] = { 0 };
        string nf[50];
        string room[50];
        for (int i = 0; i < num; i++)
        {
            newfile >> nf[i];
            newfile >> room[i];
            newfile >> numr[i];
            (arr + i)->setNumberofrooms(numr[i]);
            for (int j = 0; j < numr[i]; j++)
            {

                newfile >> type[i][j];
                if (type[i][j] == "Sweet,")
                {
                    SweetRoom* r_arr = new SweetRoom();
                    newfile >> numroom[i][j];
                    numroom[i][j].pop_back();
                    numroomi[i][j] = stoi(numroom[i][j]);
                    r_arr->setRoomnumber(numroomi[i][j]);
                    newfile >> price[i][j];
                    price[i][j].pop_back();
                    pricei[i][j] = stoi(price[i][j]);
                    r_arr->setPricepernight(pricei[i][j]);
                   if (numch == 2)
                   {
                       r_arr->ReverseRoom();
                       cout << "\n      Sweet Room is reserved"<<'\n';
                       r_arr->setIsReserved(true);

                   }
                   else if (numch == 3)
                   {
                       r_arr->setIsReserved(false);
                       cout << "\n      Sweet Room is canceled Reservation" << '\n';
                   }
                    

                }
                else if (type[i][j] == "Standard,")
                {
                    StandardRoom* r_arr = new StandardRoom();
                    newfile >> numroom[i][j];
                    numroom[i][j].pop_back();
                    numroomi[i][j] = stoi(numroom[i][j]);
                    r_arr->setRoomnumber(numroomi[i][j]);
                    newfile >> numbed[i][j];
                    numbed[i][j].pop_back();// bed or seat
                    numbedi[i][j] = stoi(numbed[i][j]);
                    r_arr->setNumofbed(numbedi[i][j]);
                    newfile >> price[i][j];
                    price[i][j].pop_back();
                    pricei[i][j] = stoi(price[i][j]);
                    r_arr->setBedprice(pricei[i][j]);
                    if (numch == 2)
                    {
                        r_arr->ReverseRoom();
                        cout << "\n      Standard Room is reserved" << '\n';
                        r_arr->setIsReserved(true);
                    }
                    else if (numch == 3)
                    {
                        r_arr->setIsReserved(false);
                        cout << "\n      Standard Room is canceled Reservation" << '\n';
                    }
                }
                else
                {
                    ConferanceRoom* r_arr = new ConferanceRoom();
                    newfile >> numroom[i][j];
                    numroom[i][j].pop_back();
                    numroomi[i][j] = stoi(numroom[i][j]);
                    r_arr->setRoomnumber(numroomi[i][j]);
                    newfile >> numbed[i][j];
                    numbed[i][j].pop_back();// bed or seat
                    numbedi[i][j] = stoi(numbed[i][j]);
                    r_arr->setNumofseats(numbedi[i][j]);
                    newfile >> price[i][j];
                    price[i][j].pop_back();
                    pricei[i][j] = stoi(price[i][j]);
                    r_arr->setSeatprice(pricei[i][j]);
                    if (numch == 2)
                    {
                        r_arr->ReverseRoom();
                        cout << "\n      Conferance Room is reserved" << '\n';
                        r_arr->setIsReserved(true);
                    }
                    else if (numch == 3)
                    {
                        r_arr->setIsReserved(false);
                        cout << "\n      Conferance Room is canceled Reservation" << '\n';
                    }
                }

            }
        }


            // loop for be sure about file 
      /* for (int i = 0; i < num; i++) {
            //cout << nf[i] << "  " << room[i] << " " << numr[i] << "\n";
            /Floor* array = new Floor * [num];
            for (int j = 0; j< numr[i]; ++i){
                array[j] = new Floor[numr[i]];
                //cout << type[i][j] << "  " << numroomi[i][j] << "  " << numbedi[i][j] << "  " << pricei[i][j] << "\n";

        } */
        

        newfile.close();

    }


    

    
    
   
    return 0;
    
}
