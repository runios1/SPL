#include "JoinPolicy.h"
#include "Simulation.h"

//virtual
void MandatesJoinPolicy::Join(Simulation sim,vector<int>& offers,int partyMandates, int partyid, int newAgentid){
    sim.joinByMandates(offers,partyMandates, partyid, newAgentid);
}

string MandatesJoinPolicy::getType(){
    return "M";
}
