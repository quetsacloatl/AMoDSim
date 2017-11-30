#ifndef VEHICLE_H_
#define VEHICLE_H_

#include <Packet_m.h>

class Vehicle: public Packet {
    protected:
        static int nextID;
        int id;
        int seats;
        int traveledDistance;

    public:
        Vehicle();
        virtual ~Vehicle();
        virtual int getID() const;
        virtual int getTraveledDistance() const;
        virtual void setTraveledDistance(int distance);
        virtual int getSeats() const;
        virtual void setSeats(int seats);
};

#endif /* VEHICLE_H_ */
