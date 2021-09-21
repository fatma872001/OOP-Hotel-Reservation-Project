#pragma once

#include<string>

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


    void setRoomnumber(int roomnumber);    // to store the room numbers for every room in each floor at hotel
    
    int getRoomnumber();                  // to show or return the room numbers for every room in each floor at hotel

    void setDayOfReservation(int daysOfReservation); // to store the number of Day Of Reservation for every room in each floor at hotel

    int getDayOfReservation();         //to show or return  the number of Day Of Reservation for every room in each floor at hotel

    void setIsReserved(bool isReserved); // to store the value of boolean variable for reservation for every room in each floor at hotel

    bool getIsReserved();           // to show or return the value of boolean variable for reservation for every room in each floor at hotel

};