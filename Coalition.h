#pragma once
#include <vector>
#include "Agent.h"

using std::vector;

class Coalition{
    public:
        Coalition(int mandates,Agent& agent, int id);
        
        void JoinCoalition(Agent& duplicatedAgent,int partyMandates);
        Agent* getAgent();
        const Agent* getAgent(int agentId) const;
        int getMandates();
        int getId();
        int getNumAgents() const;

    private:
        int mMandates;
        vector<Agent> mAgents;
        int mId;
};
