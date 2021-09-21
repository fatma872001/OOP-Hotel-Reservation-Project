#include"StandardRoom.h"

// to store the numbers of beds for every standard room in each floor at hotel
void StandardRoom:: setNumofbed(int numofbed) {

    this->numofbed = numofbed;
}
// override function to store the numbers of beds for every standard room and number of seat of very conference room in each floor at hotel
void StandardRoom::numofbedorseat(int numofbed) {
    this->numofbed = numofbed;
}
//to return/get the numbers of beds for every standard room
int StandardRoom::getNumofbed() {
    return numofbed;
}
//to set beds price for every standard room
void StandardRoom::setBedprice(double bedprice) {
    this->bedprice = bedprice;
}
//override function set beds price for every standard room
void StandardRoom::RPrice(double bedprice) {
    this->bedprice = bedprice;
}
//override function return beds price for every standard
double StandardRoom::Price() {
    return bedprice;
}
//override  function to reserve room
void StandardRoom::ReserveRoom()   {
    isReserved = true;
}
//override  to check if the room is reserved or not
bool StandardRoom::CheckReservation()  {
    return isReserved;
}
//override  to calculate the total price of reservation
double StandardRoom::TotalPrice()  {  
    return getNumofbed() * Price() * getDayOfReservation();
}
//override to display the details of each room.
void StandardRoom::toString() {
    std::cout << "Room Type : Standard  ,  " << "Room number : " << getRoomnumber() << " ,  Number of beds : " << getNumofbed() << " ,  Bed +price :" << Price() << " ,  is reservation :" << CheckReservation() << std::endl;

}