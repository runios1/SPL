#include "Agent.h"

Agent::Agent(int agentId, int partyId, SelectionPolicy *selectionPolicy) : mAgentId(agentId), mPartyId(partyId), mSelectionPolicy(selectionPolicy)
{
    // You can change the implementation of the constructor, but not the signature!
}

int Agent::getId() const
{
    return mAgentId;
}

int Agent::getPartyId() const
{
    return mPartyId;
}

void Agent::step(Simulation &sim)
{
    // TODO: implement this method
}

Agent* Agent::Cloning(int pratyid, int newAgentId){
    return new Agent(newAgentId,pratyid,mSelectionPolicy);
}
// we need to decide if  to call the constructor with fields or geters functions of the class(Memory management preferences).
// pay attention that the func returns pointer - so we need to decide where it will be deleted or change the implement
