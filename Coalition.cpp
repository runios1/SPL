#include "include/Coalition.h"

Coalition:: Coalition(int mandates,Agent& agent) : mMandates(mandates){
    mAgents.push_back(agent);
}

void Coalition::JoinCoalition(Agent& duplicatedAgent,int partyMandates){
    mAgents.push_back(duplicatedAgent);
    mMandates+=partyMandates;
}

Agent* Coalition::getAgent(){
    return &mAgents[0];
}

int Coalition::getMandates(){
    return mMandates;
}
