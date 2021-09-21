#pragma once

#include"Room.h"
#include<string>
#include<iostream>

class ConferanceRoom : public Room {
protected:

    //Data members the room form conference type "contains"
    int numofseats = 0;
    double seatprice = 0;
public:

    // default constructor for room from conference type
    ConferanceRoom() {
        int numofseats = 0;
        double seatprice = 0;
    }

    // to store the number of seats of the conference room in each floor at hotel
    void setNumofseats(int numofseats);

    // override function to store the numbers of beds for every standard room and number of seat of very conference room in each floor at hotel
    void numofbedorseat(int numofseats);

    // to return the number of seats of the conference room in each floor at hotel
    int getNumofseats();

    // to store the Price of seats of the conference room in each floor at hotel
    void setSeatprice(double seatprice);

    //override function set seats price for every conference room
    void RPrice(double seatprice);

    //override function get seats price for every conference room
    double Price();

    //override  to reserve room
    void ReserveRoom() override;

    //override  to check if the room is reserved or not
    bool CheckReservation() override;

    // override to calculate the total price of reservation
    double TotalPrice() override;

    // override to display the details of each room.
    void toString();

};