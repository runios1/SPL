#pragma once

#include <vector>
#include "Graph.h"
#include "SelectionPolicy.h"


class SelectionPolicy;

class Agent
{
public:
    Agent(int agentId, int partyId, SelectionPolicy *selectionPolicy);
    Agent(int agentId, int partyId, SelectionPolicy *selectionPolicy, int CoalitionId);
    
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
