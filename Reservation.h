// reservation.h
#ifndef RESERVATION_H
#define RESERVATION_H

#include <string>
#include <vector>

class Reservation {
public:
    Reservation(const std::string& catName, const std::string& ownerName, int duration);
    std::string getCatName() const;
    std::string getOwnerName() const;
    int getDuration() const;

private:
    std::string catName;
    std::string ownerName;
    int duration; // Duration in days
};

class ReservationSystem { 
public:
    void addReservation(const Reservation& reservation);
    void displayReservations() const;

private:
    std::vector<Reservation> reservations;
};

#endif // BOOKING_H

