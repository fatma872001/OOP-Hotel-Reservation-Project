#pragma once

#include"Room.h"
#include<string>
#include<iostream>

class SweetRoom : public Room {
protected:

    //Data members the room form sweet type "contains"
    double pricepernight = 0;
public:

    // default constructor for room from sweet type
    SweetRoom() {
        double pricepernight = 0;
    }

    // to store the Price per night of the sweet room in each floor at hotel
    void setPricepernight(double pricepernight);

    //override function set room per night price for every sweet room
    void RPrice(double pricepernight);

    //override function get room per night price for every sweet room
    double Price();

    //override  to reserve room
    void ReserveRoom() override;

    //override  to check if the room is reserved or not
    bool CheckReservation() override;

    //override to calculate the total price of reservation
    double TotalPrice() override;

    //override to display the details of each room.
    void toString();


    void numofbedorseat(int);
};
