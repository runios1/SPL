#pragma once
#include "Party.h"

class Simulation;

class SelectionPolicy {
public:
    virtual Party& Select(int PartyId, int coalitionId, Simulation& sim);

    virtual ~SelectionPolicy()=default;
};


class MandatesSelectionPolicy: public SelectionPolicy{ 
    public:
    virtual Party& Select(int PartyId, int coalitionId,Simulation& sim);

};

class EdgeWeightSelectionPolicy: public SelectionPolicy{ 
    public:
    virtual Party& Select(int PartyId, int coalitionId,Simulation& sim);

};
