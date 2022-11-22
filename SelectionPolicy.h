#pragma once
#include "Party.h"
#include <string>

class Simulation;

using std::string;

class SelectionPolicy {
public:
    virtual Party& Select(int PartyId, int coalitionId, Simulation& sim)=0;

    virtual string getType()=0;

    virtual ~SelectionPolicy()=default;
};


class MandatesSelectionPolicy: public SelectionPolicy{ 
    public:
    virtual Party& Select(int PartyId, int coalitionId,Simulation& sim);
    virtual string getType();
};

class EdgeWeightSelectionPolicy: public SelectionPolicy{ 
    public:
    virtual Party& Select(int PartyId, int coalitionId,Simulation& sim);
    virtual string getType();
};
