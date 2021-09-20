# OOP-Hotel-Reservation-Project

Hotel reservation system using C++. 

The program enable the receptionist to handle reservations in the hotel. 
The hotel consists of some floors, which in turn consists of some rooms.

There are three types of rooms: standard, sweet, and conference room.

 Floor contains a floor number, number of rooms, and a list of rooms. 
 1- method to display the available rooms in the floor
 2- method to calculate the profits of the rooms in the floor. 
 
    StandardRoom contains a room number (int), daysOfReservation (int), numberOfBeds (int), bedPrice (double), and isReserved (boolean).
    SweetRoom contains a room number (int), pricePerNight (double), daysOfReservation (int), and isReserved (boolean).
    ConferenceRoom contains a room number (int), daysOfReservation (int), numberOfSeats (int), seatPrice (double), and isReserved (boolean). 
    
    In each class, 
      1- methods to reserve the room,
      2- methods to get the total price of the reservation, 
      3- methods to check if the room is reserved or not,
      4- methods override the toString method to display the details of each room. 
      
      
      A text file contains the configuration of the hotel " HP.txt"
            The system reads the file and sets the hotel configuration based on it in a separate method.
            A menu will be displayed to the receptionist to enable him to make different operations. 
                 The receptionist can :
                    - check out operation (display the price of the stay)
                    - display available rooms in a particular floor
                    - display the total expected profit (based on the current status of the hotel).



