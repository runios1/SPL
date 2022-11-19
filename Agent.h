#pragma once

#include <vector>
#include "Graph.h"
#include "Party.h"
#include "SelectionPolicy.h"


class SelectionPolicy;

class Agent
{
public:
    Agent(int agentId, int partyId, SelectionPolicy *selectionPolicy);
    Agent(int agentId, int partyId, SelectionPolicy *selectionPolicy, int CoalitionId);

    //The Rule of 5:
    Agent(const Agent& other); // copy constructor
    Agent& operator = (const Agent& other); // copy assignment
    virtual ~Agent(); // destructor
    Agent(Agent&& other); // move constuctor
    Agent& operator = (Agent&& other); // move assignment

    int getPartyId() const;
    int getId() const;
    void step(Simulation &);
    Agent* Cloning(int partyid, int newAgentId, int CoalitionId);
    int getCoalitionId() const;
    void setCoalitionId(int coalitionId);

private:
    int mAgentId;
    int mPartyId;
    SelectionPolicy *mSelectionPolicy;
    int mCoalitionId;
};
