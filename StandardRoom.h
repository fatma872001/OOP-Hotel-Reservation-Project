#pragma once

#include"Room.h"
#include<string>
#include<iostream>

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
    StandardRoom() {
        int numofbed = 0;
        double bedprice = 0;
    }
    // to store the numbers of beds for every standard room in each floor at hotel
    void setNumofbed(int numofbed);

    // override function to store the numbers of beds for every standard room and number of seat of very conference room in each floor at hotel
    void numofbedorseat(int numofbed);

    //to return/get the numbers of beds for every standard room
    int getNumofbed();

    //to set beds price for every standard room
    void setBedprice(double bedprice);

    //override function set beds price for every standard room
    void RPrice(double bedprice);

    //override function return beds price for every standard
    double Price();

    //override  function to reserve room
    void ReserveRoom() override;

    //override  to check if the room is reserved or not
    bool CheckReservation() override;

    //override  to calculate the total price of reservation
    double TotalPrice() override;

    //override to display the details of each room.
    void toString();

};
