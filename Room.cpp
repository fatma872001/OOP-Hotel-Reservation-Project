#include"Room.h"


void Room :: setRoomnumber(int roomnumber) {  // to store the room numbers for every room in each floor at hotel
    this->roomnumber = roomnumber;
}
int Room :: getRoomnumber() {                // to show or return the room numbers for every room in each floor at hotel
    return roomnumber;
}
void Room :: setDayOfReservation(int daysOfReservation) {  // to store the number of Day Of Reservation for every room in each floor at hotel
    this->daysOfReservation = daysOfReservation;
}
int Room :: getDayOfReservation() {          //to show or return  the number of Day Of Reservation for every room in each floor at hotel
    return daysOfReservation;
}
void Room :: setIsReserved(bool isReserved) {   // to store the value of boolean variable for reservation for every room in each floor at hotel
    this->isReserved = isReserved;
}
bool Room :: getIsReserved() {     // to show or return the value of boolean variable for reservation for every room in each floor at hotel
    return isReserved;
}