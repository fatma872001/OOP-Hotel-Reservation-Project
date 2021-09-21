#include"Floor.h"

// function to store rooms from different types to it`s floor in hotel
void Floor:: AddRoom(Room* r) {
    ids.push_back(r);
}

//function to store the floor number
void Floor:: setFloornumber(int floornumber) {
    this->floornumber = floornumber;
}

//function to return the floor number
int Floor:: getFloornumber() {
    return floornumber;
}

/*void setIds(vector<Room>& ids)
{
    this->ids = ids;
}*/

// function to get rooms from different types from it`s floor in hotel
std::vector<Room*> Floor:: getIds() {
    return ids;
}

//function to store the number of rooms in each floor at hotel
void Floor:: setNumberofrooms(int numberofrooms) {
    this->numberofrooms = numberofrooms;
}

//function to return the number of rooms in each floor at hotel
int Floor::getNumberofrooms() {
    return getIds().size();
}

// function to show the free rooms in each floor "non reserved ones"
void Floor:: displayavailable() {
    for (int i = 0; i < ids.size(); i++)
    {
        if (ids[i]->isReserved == false)
        {
            std::cout << "   the Room " << getIds()[i]->roomnumber << " : " << " is free" << std::endl;
        }

    }
}

// function to reserve room from specific floor
void Floor:: ReserveFromFloor(int nro) {
    for (int i = 0; i < ids.size(); i++)
    {
        if (ids[i]->roomnumber == nro)
        {
            if (ids[i]->isReserved == false) {
                std::cout << "the Room " << getIds()[i]->roomnumber << " : " << " has been reserved" << std::endl;
                ids[i]->ReserveRoom();
                int DOR = 0;
                std::cout << "\n         Days Of Reservation : ";
                std::cin >> DOR;
                ids[i]->setDayOfReservation(DOR);
            }
            else {
                std::cout << "the Room " << getIds()[i]->roomnumber << " : " << " it`s already reserved before" << std::endl;
            }
        }

    }
}

// function to cancel reservation of a specific room
void Floor:: CancelReservationFromFloor(int nro) {
    for (int i = 0; i < ids.size(); i++)
    {
        if (ids[i]->roomnumber == nro)
        {
            if (ids[i]->isReserved == false) {
                std::cout << "the Room " << getIds()[i]->roomnumber << " : " << " it`s already free" << std::endl;
            }
            else {
                std::cout << "the Room " << getIds()[i]->roomnumber << " : " << " it has been cancelled" << std::endl;
                ids[i]->setIsReserved(false);
            }
        }

    }
}

// function to display the details of each room in the floor
void Floor:: display() {
    for (int i = 0; i < ids.size(); i++) {
        ids[i]->toString();
        std::cout << std::endl;
    }
}

// function to display the total profits for each floor
std::string Floor:: profits() {
    double total = 0;
    for (int i = 0; i < ids.size(); i++)
    {
        total += ids[i]->TotalPrice();
    }
    return "the Total profit is :" + std::to_string(total);

}

// function to return the total profits for only the reserved rooms in the floor
double Floor:: priceStatus() {
    double total = 0;
    for (int i = 0; i < ids.size(); i++) {
        if (ids[i]->isReserved == true) {
            total += ids[i]->TotalPrice();
        }
    }
    return total;
}