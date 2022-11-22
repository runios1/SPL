#include "JoinPolicy.h"

//virtual
void MandatesJoinPolicy::Join(const vector<Coalition>& offers,int partyMandates, int partyid, int newAgentid){
    int maxMend(-1);
    Coalition bestOffer=offers[0];

    for(Coalition c : offers){
        int mandates(c.getMandates());
        if(mandates>maxMend){
            maxMend=mandates;
            bestOffer=c;
        }
    }
    // Creates a new agent in the new party in the coalition.
    Agent a=*bestOffer.getAgent();
    Agent* b=a.Cloning(partyid,newAgentid,a.getCoalitionId()); 
    bestOffer.JoinCoalition(*b,partyMandates);
    delete b;
}

string MandatesJoinPolicy::getType(){
    return "L";
}
