#pragma once
#include "vector"
#include "Agent.h"

class Coalition{
    public:
        Coalition(int mandates,Agent& agent, int id);
        
        void JoinCoalition(Agent& duplicatedAgent,int partyMandates);
        Agent* getAgent();
        int getMandates();
        int getId();

    private:
        int mMandates;
        vector<Agent> mAgents;
        const int mId;
};
