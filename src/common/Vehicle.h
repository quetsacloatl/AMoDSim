/*
########################################################
##           __  __       _____   _____ _             ##
##     /\   |  \/  |     |  __ \ / ____(_)            ##
##    /  \  | \  / | ___ | |  | | (___  _ _ __ ___    ##
##   / /\ \ | |\/| |/ _ \| |  | |\___ \| | '_ ` _ \   ##
##  / ____ \| |  | | (_) | |__| |____) | | | | | | |  ##
## /_/    \_\_|  |_|\___/|_____/|_____/|_|_| |_| |_|  ##
##                                                    ##
## Author:                                            ##
##    Andrea Di Maria                                 ##
##    <andrea.dimaria90@gmail.com>                    ##
########################################################
*/

#ifndef VEHICLE_H_
#define VEHICLE_H_

#include <Packet_m.h>

class Vehicle: public Packet {
    protected:
        static int nextID;
        int id;
        int seats;
        int traveledDistance;
        bool busyState;
        int specialVehicle; //veicolo di emergenza -1 0 civile 1 ambulanza (TODO: enum)
        int trafficWeight;  // influence of single vehicle in traffic channel. It increases the travel times of other vehicles.

        int chosenGate; // Choose the gate for leaving the node

        double speed;  // Avg. speed of vehicle in channel
        
        double currentTraveledTime;
        double optimalEstimatedTravelTime;

    public:
        Vehicle();
        Vehicle(int specialVehicle, double speed, int trafficWeight);
        virtual ~Vehicle();
        virtual int getID() const;
        virtual double getTraveledDistance() const;
        virtual void setTraveledDistance(double distance);
        virtual int getSeats() const;
        virtual void setSeats(int seats);

        virtual int getSpecialVehicle() const;
//        virtual void setSpecialVehicle(int specialVehicle);
        virtual int getChosenGate();
        virtual void setChosenGate(int gate);
        virtual double getSpeed() const;
        virtual void setSpeed(double speed);
        virtual bool isBusyState() const;
        virtual void setBusyState(bool busyState);
        virtual int getTrafficWeight() const;
        virtual double getCurrentTraveledTime() const;
        virtual void setCurrentTraveledTime(double currentTraveledTime);
        virtual double getOptimalEstimatedTravelTime() const;
        virtual void setOptimalEstimatedTravelTime(double optimalEstimatedTravelTime);
};

#endif /* VEHICLE_H_ */
