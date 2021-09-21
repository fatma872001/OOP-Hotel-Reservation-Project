#include"SweetRoom.h"

// to store the Price per night of the sweet room in each floor at hotel
void SweetRoom:: setPricepernight(double pricepernight) {
    this->pricepernight = pricepernight;
}

//override function set room per night price for every sweet room
void SweetRoom:: RPrice(double pricepernight) {
    this->pricepernight = pricepernight;
}

//override function get room per night price for every sweet room
double SweetRoom:: Price() {
    return pricepernight;
}

//override  to reserve room
void SweetRoom:: ReserveRoom()  {
    isReserved = true;
}

//override  to check if the room is reserved or not
bool SweetRoom:: CheckReservation()  {
    return isReserved;
}

//override to calculate the total price of reservation
double SweetRoom:: TotalPrice()  {
    return Price() * getDayOfReservation();
}

//override to display the details of each room.
void SweetRoom:: toString() {
    std::cout << "Room Type : Sweet  ,  " << " Room number :" << getRoomnumber() << " ,  Price per night :" << Price() << " ,  is reservation : " << CheckReservation() << std::endl;
}

void numofbedorseat(int) {}