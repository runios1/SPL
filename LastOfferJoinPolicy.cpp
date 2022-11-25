#include "JoinPolicy.h"
#include "Simulation.h"

//virtual
void LastOfferJoinPolicy::Join(Simulation sim,vector<int>& offers, int partyMandates, int partyid, int newAgentid){
    sim.joinByLastOffer(offers, partyMandates, partyid, newAgentid);
} 
string LastOfferJoinPolicy::getType(){
    return "L";
}
