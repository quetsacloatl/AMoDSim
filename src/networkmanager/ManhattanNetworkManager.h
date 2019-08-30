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

#ifndef __AMOD_SIMULATOR_MANHATTANNETWORKMANAGER_H_
#define __AMOD_SIMULATOR_MANHATTANNETWORKMANAGER_H_

#include <omnetpp.h>
#include <AbstractNetworkManager.h>
#include <set>

class ManhattanNetworkManager : public AbstractNetworkManager
{
private:
    int rows;
    int columns;
    int numberOfEmergencyVehicles;

    double xChannelLength;
    double yChannelLength;
    double xTravelTime;
    double yTravelTime;

    simsignal_t newCivilVehicle;



    std::set<int> setOfDestroyedNodes;          //nodes without connections
    std::set<int> setOfNodesInRedZone;          //good neighbours of destroyed nodes
    std::set<int> setOfBorderNodes;             //nodes in the border of the grid

protected:
    virtual void initialize() override;
    virtual void handleMessage(cMessage *msg) override;
    virtual std::set<int> propagateEarthquakeBetweenNodes(int epicenterAddress, std::set<int> auxSet) override;
	void buildSetOfNodesInRedZone();
	void buildsetOfBorderNodes();
	std::set<int> buildSetOfDestroyedNodes();
	void buildSetOfNodesInRedZone(std::set<int> auxSet);
	void buildSetOfBorderNodes();
	void buildTruckStartNode();

  public:
    virtual double getTimeDistance(int srcAddr, int dstAddr) override;
    virtual double getSpaceDistance(int srcAddr, int dstAddr) override;
    virtual double getChannelLength(int nodeAddr, int gateIndex) override;
    virtual int getOutputGate(int srcAddr, int destAddr) override;
    virtual int getVehiclesPerNode(int nodeAddr) override;
    virtual bool isValidAddress(int nodeAddr) override;
    virtual bool checkDisconnectedNode(int addr) override;

	const std::set<int>& getSetOfBorderNodes() const {
		return setOfBorderNodes;
	}
};

#endif
