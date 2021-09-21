#include"ConferanceRoom.h"

// to store the number of seats of the conference room in each floor at hotel
void ConferanceRoom:: setNumofseats(int numofseats) {
    this->numofseats = numofseats;
}

// override function to store the numbers of beds for every standard room and number of seat of very conference room in each floor at hotel
void ConferanceRoom:: numofbedorseat(int numofseats) {
    this->numofseats = numofseats;
}

// to return the number of seats of the conference room in each floor at hotel
int ConferanceRoom:: getNumofseats() {
    return numofseats;
}

// to store the Price of seats of the conference room in each floor at hotel
void ConferanceRoom:: setSeatprice(double seatprice) {
    this->seatprice = seatprice;
}

//override function set seats price for every conference room
void ConferanceRoom:: RPrice(double seatprice) {
    this->seatprice = seatprice;
}

//override function get seats price for every conference room
double ConferanceRoom:: Price() {
    return seatprice;
}

//override  to reserve room
void ConferanceRoom:: ReserveRoom()  {
    isReserved = true;
}

//override  to check if the room is reserved or not
bool ConferanceRoom:: CheckReservation()  {
    return isReserved;
}

// override to calculate the total price of reservation
double ConferanceRoom:: TotalPrice()  {
    return Price() * getNumofseats() * getDayOfReservation();
}

// override to display the details of each room.
void ConferanceRoom:: toString() {
    std::cout << "Room Type : Conference  ,  " << " Room number : " << getRoomnumber() << "  ,  the Number of Seats : " << getNumofseats() << "   ,  Seat price : " << Price() << "  ,  is reservation :" << CheckReservation() << std::endl;

}