#pragma once

class SelectionPolicy {
public:
    virtual Party& Select(int PartyId, int coalitionId, Simulation& sim);

};


class MandatesSelectionPolicy: public SelectionPolicy{ 
    public:
    virtual Party& Select(int PartyId, int coalitionId,Simulation& sim);

};

class EdgeWeightSelectionPolicy: public SelectionPolicy{ 
    public:
    virtual Party& Select(int PartyId, int coalitionId,Simulation& sim);

};
