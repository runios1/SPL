#include "JoinPolicy.h"

//virtual
void MandatesJoinPolicy::Join(const vector<Coalition>& offers,int partyMandates, int partyid, int newAgentid){
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
    Agent *b=a.Cloning(partyid,newAgentid,a.getCoalitionId()); 
    bestOffer.JoinCoalition(*b,partyMandates);
    //pay attention that b is a pointer to Agent varible on heap, make sure to find the right place to delete varible from heap
    //we need to check what happens to '*b' at the end of scope of Join
}

string MandatesJoinPolicy::getType(){
    return "M";
}
