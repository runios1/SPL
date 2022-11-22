#pragma once
#include <string>

class SelectionPolicy;
class Simulation;

using std::string;


class Agent
{
public:
    Agent(int agentId, int partyId, SelectionPolicy *selectionPolicy);
    Agent(int agentId, int partyId, SelectionPolicy *selectionPolicy, int CoalitionId);

    //The Rule of 5:
    Agent(const Agent& other); // copy constructor
    Agent& operator = (const Agent& other); // copy assignment
    virtual ~Agent(); // destructor
    Agent(Agent&& other) noexcept; // move constuctor
    Agent& operator = (Agent&& other) noexcept; // move assignment

    int getPartyId() const;
    int getId() const;
    void step(Simulation & sim);
    Agent* Cloning(int partyid, int newAgentId, int CoalitionId);
    int getCoalitionId() const;
    void setCoalitionId(int coalitionId);
    SelectionPolicy* setSelectionType() const;

private:
    int mAgentId;
    int mPartyId;
    SelectionPolicy *mSelectionPolicy;
    int mCoalitionId;
};
