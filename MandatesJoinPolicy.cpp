#include "include/JoinPolicy.h"

void JoinPolicy::Join(const vector<Coalition>& offers,int partyMandates){
    int maxMend(-1);
    Coalition bestOffer=offers[0];

    for(Coalition a : offers){
        int mandates(a.getMandates());
        if(mandates>maxMend){
            maxMend=mandates;
            bestOffer=a;
        }
    }
    // Creates a new agent in the new party in the coalition.
    Agent a=*bestOffer.getAgent();
    Agent b=a.Duplicate(); //UPDATE ME 
    bestOffer.JoinCoalition(b,partyMandates);
}
