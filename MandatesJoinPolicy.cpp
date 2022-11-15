#include "include/JoinPolicy.h"

int JoinPolicy::Join(const vector<Agent>& offers,Simulation& s){
    Graph g=s.getGraph();
    int maxMend(-1);
    Agent bestOffer=offers[1];

    for(Agent a : offers){
        int mandates(g.getMandates(a.getPartyId()));
        if(mandates>maxMend){
            maxMend=mandates;
            bestOffer=a;
        }
    }
    // Creates a new agent in the new party in the coalition.
    bestOffer.Duplicate(); //UPDATE ME 
    
    return maxMend;
}