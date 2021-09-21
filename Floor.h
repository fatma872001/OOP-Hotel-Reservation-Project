#pragma once

#include "Room.h"
#include <string>
#include <vector>
#include <iostream>

class Floor
{
protected:

    //Data members the floor "contains"
    int floornumber = 0;
    int numberofrooms = 0;
    std::vector<Room*> ids = std::vector<Room*>();

public:

    // default constructor for floor
    Floor() {
        int floornumber = 0;
        int numberofrooms = 0;
       std:: vector<Room*> ids = std::vector<Room*>();
    }

    // constructor with parameter for floor
    Floor(int floornumber, int numberofrooms) {
        this->floornumber = floornumber;
        this->numberofrooms = numberofrooms;
    }


     // function to store rooms from different types to it`s floor in hotel
    void AddRoom(Room* r);

    //function to store the floor number
    void setFloornumber(int floornumber);

    //function to return the floor number
    int getFloornumber();

    

    // function to get rooms from different types from it`s floor in hotel
    std::vector<Room*> getIds();

    //function to store the number of rooms in each floor at hotel
    void setNumberofrooms(int numberofrooms);

    //function to return the number of rooms in each floor at hotel
    int getNumberofrooms();

    // function to show the free rooms in each floor "non reserved ones"
    void displayavailable();

    // function to reserve room from specific floor
    void ReserveFromFloor(int nro);

    // function to cancel reservation of a specific room
    void CancelReservationFromFloor(int nro);

    // function to display the details of each room in the floor
    void display();

    // function to display the total profits for each floor
    std::string profits();

    // function to return the total profits for only the reserved rooms in the floor
    double priceStatus();

};
