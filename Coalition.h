#pragma once
#include "vector"
#include "Agent.h"

class Coalition{
    public:
        Coalition(int mandates,Agent& agent){};
        
        void JoinCoalition(Agent& duplicatedAgent,int partyMandates){};
        Agent* getAgent(){};
        int getMandates(){};

    private:
        int mMandates;
        vector<Agent> mAgents;
};
