#include "include/Coalition.h"

Coalition:: Coalition(int mandates,Agent& agent, int id) : mMandates(mandates), mId(id){
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

int Coalition::getId(){
    return mId;
}
