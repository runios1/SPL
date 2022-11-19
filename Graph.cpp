#include "Graph.h"

Graph::Graph(vector<Party> vertices, vector<vector<int>> edges) : mVertices(vertices), mEdges(edges) 
{
    // You can change the implementation of the constructor, but not the signature!
}

int Graph::getMandates(int partyId) const
{
    return mVertices[partyId].getMandates();
}

int Graph::getEdgeWeight(int v1, int v2) const
{
    return mEdges[v1][v2];
}

int Graph::getNumVertices() const
{
    return mVertices.size();
}

const Party &Graph::getParty(int partyId) const
{
    return mVertices[partyId];
}

Party &Graph::getParty(int partyId)
{
    return mVertices[partyId];
}

const Party& Graph::selectByEdgeWeight(int PartyId, int coalitionId){

int n = getNumVertices()-1;
int maxWeight = -1;
Party* bestselect = &getParty(PartyId);
for(int i=0; i < n; i++){
    int edgeWeight = getEdgeWeight(PartyId,i);
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


const Party& Graph::selectByMandates(int PartyId, int coalitionId){

int n = getNumVertices()-1;
int maxMand = -1;
Party* bestselect = &getParty(PartyId);

for(int i=0; i < n; i++){
    if(getEdgeWeight(PartyId,i)>0){
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
