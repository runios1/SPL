#include "JoinPolicy.h"

int JoinPolicy::Join(const vector<Agent>& offers,Simulation& s){
    Graph g=s.getGraph();
    Agent bestOffer(offers[offers.size()]);

    // Creates a new agent in the new party in the coalition.
    bestOffer.Duplicate(); //UPDATE ME 
    
    return g.getMandates(bestOffer.getPartyId());
}
