#include "Simulation.h"
#include "Coalition.h"
#include "Party.h"

Simulation::Simulation(Graph graph, vector<Agent> agents) : mGraph(graph), mAgents(agents), coalitions()
{
    int i = 0;
    for( Agent& a : mAgents){
        a.setCoalitionId(i);
        coalitions.push_back(Coalition(mGraph.getMandates(a.getPartyId()), a, i));
        i++;
    }
}

void Simulation::step()
{
    for(int i=0;i<mGraph.getNumVertices();i++)
        mGraph.getParty(i).step(*this);
    for(Agent a:mAgents)
        a.step(*this);
}

bool Simulation::shouldTerminate() const
{
    bool allPartiesJoined=true;
    for(int i=0;i<mGraph.getNumVertices();i++){
        if(mGraph.getParty(i).getMandates()>=61)
            return true;
        if(mGraph.getParty(i).getState()!=State::Joined)
            allPartiesJoined=false;
    }
    return allPartiesJoined;    
}

const Graph &Simulation::getGraph() const
{
    return mGraph;
}

const vector<Agent> &Simulation::getAgents() const
{
    return mAgents;
}

const Party &Simulation::getParty(int partyId) const
{
    return mGraph.getParty(partyId);
}

/// This method returns a "coalition" vector, where each element is a vector of party IDs in the coalition.
/// At the simulation initialization - the result will be [[agent0.partyId], [agent1.partyId], ...]
const vector<vector<int>> Simulation::getPartiesByCoalitions() const
{
    vector<vector<int>> output;
    for(unsigned int j=0;j<coalitions.size();j++){
        vector<int> partyIds;
        for(int i=0;i<coalitions[j].getNumAgents();i++){
            partyIds.push_back(coalitions[j].getAgent(i)->getPartyId());
        }
        output.push_back(partyIds);
        partyIds.clear();
    }
    return output;
}

int Simulation::getCurrentId(){
    return mAgents.size();
}

//check:
Party* Simulation::selectByEdgeWeight(int PartyId, int coalitionId){
    int n = mGraph.getNumVertices()-1;
int maxWeight = -1;
Party* bestselect = &(mGraph.getParty(PartyId));
for(int i=0; i < n; i++){
    int edgeWeight = mGraph.getEdgeWeight(PartyId,i);
    if(edgeWeight>0){
        Party& temp = mGraph.getParty(i);
        if(temp.getState()!=State::Joined){
            if(edgeWeight > maxWeight){
                if(temp.getState()==State::CollectingOffers){
                    if(!temp.isInOffers(coalitionId)){
                    maxWeight = edgeWeight;
                    bestselect = &temp;
                    }
                }
                else{
                    //state Waiting
                    maxWeight = edgeWeight;
                    bestselect = &temp;
                }
            }
        }
    }
}
return (bestselect);
}

Party* Simulation::selectByMandates(int PartyId, int coalitionId){

int n =  mGraph.getNumVertices()-1;
int maxMand = -1;
Party* bestselect = &(mGraph.getParty(PartyId));

for(int i=0; i < n; i++){
    if(mGraph.getEdgeWeight(PartyId,i)>0){
        Party& temp = mGraph.getParty(i);
        if(temp.getState()!=State::Joined){
            if(temp.getMandates() > maxMand){
                if(temp.getState()==State::CollectingOffers){
                    if(!temp.isInOffers(coalitionId)){
                    maxMand = temp.getMandates();
                    bestselect = &temp;
                    }
                }
                else{
                    //state Waiting
                    maxMand = temp.getMandates();
                    bestselect = &temp;
                }
            }
        }
    }
}
return (bestselect);

}

void Simulation::joinByMandates(vector<int>& offers,int partyMandates, int partyid, int newAgentid){
    int maxMend(-1);
    int maxIndex(0);
    unsigned int i(0);

    while(i<offers.size()){
        if(coalitions[offers[i]].getMandates()>maxMend){
            maxMend=coalitions[offers[i]].getMandates();
            maxIndex=i;
        }
        i++;
    }
    // Creates a new agent in the new party in the coalition.
    Agent* a=coalitions[offers[maxIndex]].getAgent();
    Agent b=std::move(a->Cloning(partyid,newAgentid,a->getCoalitionId()));
    mAgents.push_back(b);
    coalitions[offers[maxIndex]].JoinCoalition(b,partyMandates);
    a=nullptr;
}
void Simulation::joinByLastOffer(vector<int>& offers, int partyMandates, int partyid, int newAgentid){
    Agent* a=coalitions[offers[offers.size()-1]].getAgent();
    Agent b=std::move(a->Cloning(partyid,newAgentid,a->getCoalitionId()));
    mAgents.push_back(b);
    coalitions[offers[offers.size()-1]].JoinCoalition(b,partyMandates);
    a=nullptr;
}
