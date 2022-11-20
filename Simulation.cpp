#include "Simulation.h"
#include "Coalition.h"
#include "Party.h"

Simulation::Simulation(Graph graph, vector<Agent> agents) : mGraph(graph), mAgents(agents), coalitions()
{
    int i = 0;
    for( Agent& a : agents){
        a.setCoalitionId(i);
        coalitions.push_back(Coalition(mGraph.getMandates(a.getPartyId()), a, i));
        i++;
    }
    // You can change the implementation of the constructor, but not the signature!
    // we need to run on the vector of agents - for each agent create a coalition and push it to the vector of coalitions
    // after the creation of the coalition - we need to update coalitionId of the agent
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
    for(Coalition c:coalitions){
        vector<int> partyIds;
        for(int i=0;c.getNumAgents()-1;i++){
            partyIds.push_back(c.getAgent(i)->getPartyId());
        }
        output.push_back(partyIds);
        //NOTICE HERE! IT GOES BY VALUE SO IT'S OK FOR ME TO CLEAR IT RIGHT?
        partyIds.clear();
    }
    return output;
}

int Simulation::getCurrentId(){
    return mAgents.size();
}

Coalition& Simulation::getCoalition(int coalitionId){
    return coalitions[coalitionId];
}

//check:
Party& Simulation::selectByEdgeWeight(int PartyId, int coalitionId){
    int n = mGraph.getNumVertices()-1;
int maxWeight = -1;
Party* bestselect = &(mGraph.getParty(PartyId));
for(int i=0; i < n; i++){
    int edgeWeight = mGraph.getEdgeWeight(PartyId,i);
    if(edgeWeight>0){
        Party temp = getParty(i);
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
return (*bestselect);
}

Party& Simulation::selectByMandates(int PartyId, int coalitionId){

int n =  mGraph.getNumVertices()-1;
int maxMand = -1;
Party* bestselect = &(mGraph.getParty(PartyId));

for(int i=0; i < n; i++){
    if(mGraph.getEdgeWeight(PartyId,i)>0){
        Party temp = getParty(i);
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
return (*bestselect);

}
