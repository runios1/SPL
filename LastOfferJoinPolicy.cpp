#include "JoinPolicy.h"

//virtual
void LastOfferJoinPolicy::Join(const vector<Coalition>& offers, int partyMandates, int partyid, int newAgentid){
    Coalition bestOffer(offers[offers.size()]);

    // Creates a new agent in the new party in the coalition.
    Agent a=*bestOffer.getAgent();
    Agent b=a.Cloning(partyid,newAgentid,a.getCoalitionId()); 
    bestOffer.JoinCoalition(b,partyMandates);
} 
string LastOfferJoinPolicy::getType(){
    return "L";
}
