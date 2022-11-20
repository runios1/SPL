#pragma once
#include <vector>
#include "Agent.h"

class Agent;

using std::vector;

class Coalition{
    public:
        Coalition(int mandates,Agent& agent, int id);
        
        void JoinCoalition(Agent& duplicatedAgent,int partyMandates);
        Agent* getAgent();
        Agent* getAgent(int agentId);
        int getMandates();
        int getId();
        int getNumAgents() const;

    private:
        int mMandates;
        vector<Agent> mAgents;
        const int mId;
};
