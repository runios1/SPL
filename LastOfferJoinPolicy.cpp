#include "JoinPolicy.h"

//virtual
void LastOfferJoinPolicy::Join(const vector<Coalition>& offers, int partyMandates, int partyid, int newAgentid){
    Coalition bestOffer(offers[offers.size()]);

    // Creates a new agent in the new party in the coalition.
    Agent a=*bestOffer.getAgent();
    Agent *b=a.Cloning(partyid,newAgentid); 
    bestOffer.JoinCoalition(*b,partyMandates);
    //pay attention that b is a pointer to Agent varible on heap, make sure to find the right place to delete varible from heap
    //we need to check what happens to '*b' at the end of scope of Join
} 
