#include "Simulation.h"

Simulation::Simulation(Graph graph, vector<Agent> agents) : mGraph(graph), mAgents(agents) 
{
    // You can change the implementation of the constructor, but not the signature!
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
    // TODO: you MUST implement this method for getting proper output, read the documentation above.
    return vector<vector<int>>();
}
