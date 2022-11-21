#include "Agent.h"
#include "Simulation.h"
#include "SelectionPolicy.h"


Agent::Agent(int agentId, int partyId, SelectionPolicy *selectionPolicy) : mAgentId(agentId), mPartyId(partyId), mSelectionPolicy(selectionPolicy) ,mCoalitionId(-1)
{
}

Agent::Agent(int agentId, int partyId, SelectionPolicy *selectionPolicy, int CoalitionId) : mAgentId(agentId), mPartyId(partyId), mSelectionPolicy(selectionPolicy),mCoalitionId(CoalitionId)
{
}

// copy constructor
Agent::Agent(const Agent& other): mAgentId(other.mAgentId), mPartyId(other.mPartyId), mSelectionPolicy(other.mSelectionPolicy), mCoalitionId(other.mCoalitionId){

}

// copy assignment 
Agent& Agent :: operator=(const Agent& other){
this->mAgentId = other.mAgentId;
this->mPartyId = other.mPartyId;
this->mSelectionPolicy = other.mSelectionPolicy;
return *this;
}

//destructor
Agent::~Agent(){
    delete mSelectionPolicy;
}

//move constructor
Agent::Agent(Agent&& other) noexcept : mAgentId(other.mAgentId), mPartyId(other.mPartyId), mSelectionPolicy(other.mSelectionPolicy), mCoalitionId(other.mCoalitionId)
{ 
    other.mSelectionPolicy=nullptr;
}

//move assignment
Agent& Agent::operator=(Agent&& other) noexcept
{ 
    mAgentId=other.mAgentId;
    mPartyId=other.mPartyId;
    mSelectionPolicy=other.mSelectionPolicy;
    mSelectionPolicy=other.mSelectionPolicy;
    other.mSelectionPolicy=nullptr;
    return *this;
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

int Agent:: getCoalitionId() const{
    return mCoalitionId;
}

void Agent::setCoalitionId(int coalitionId){
     mCoalitionId = coalitionId;
}
