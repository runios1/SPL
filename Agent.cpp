#include "Agent.h"

Agent::Agent(int agentId, int partyId, SelectionPolicy *selectionPolicy) : mAgentId(agentId), mPartyId(partyId), mSelectionPolicy(selectionPolicy)
{
    mCoalitionId = -1;

}

Agent::Agent(int agentId, int partyId, SelectionPolicy *selectionPolicy, int CoalitionId) : mAgentId(agentId), mPartyId(partyId), mSelectionPolicy(selectionPolicy),mCoalitionId(CoalitionId)
{
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
    Party temp = mSelectionPolicy-> Select(mPartyId, mCoalitionId,sim);
    temp.addToOffers(sim.getCoalition(mCoalitionId));
}

Agent* Agent::Cloning(int pratyid, int newAgentId, int CoalitionId){
    return new Agent(newAgentId,pratyid,mSelectionPolicy, CoalitionId);
}
// we need to decide if  to call the constructor with fields or geters functions of the class(Memory management preferences).
// pay attention that the func returns pointer - so we need to decide where it will be deleted or change the implement

int Agent:: getCoalitionId() const{
    return mCoalitionId;
}

void Agent::setCoalitionId(int coalitionId){
     mCoalitionId = coalitionId;
}
