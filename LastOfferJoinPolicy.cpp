#include "JoinPolicy.h"

void JoinPolicy::Join(const vector<Coalition>& offers, int partyMandates){
    Coalition bestOffer(offers[offers.size()]);

    // Creates a new agent in the new party in the coalition.
    Agent a=*bestOffer.getAgent();
    Agent b=a.Duplicate(); //UPDATE ME 
    bestOffer.JoinCoalition(b,partyMandates);
}
