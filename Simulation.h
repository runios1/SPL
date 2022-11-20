#pragma once

#include <vector>
#include "Agent.h"
#include "Graph.h"

class Agent;
class Party;
class Coalition;

using std::string;
using std::vector;

class Simulation
{
public:
    Simulation(Graph g, vector<Agent> agents);

    void step();
    bool shouldTerminate() const;

    const Graph &getGraph() const;
    const vector<Agent> &getAgents() const;
    const Party &getParty(int partyId) const;
    const vector<vector<int>> getPartiesByCoalitions() const;
    vector<Party> getAdjParties(int AgentId);
    int getCurrentId();
    Coalition& getCoalition(int coalitionId);
    Party& selectByEdgeWeight(int PartyId, int coalitionId);
    Party& selectByMandates(int PartyId, int coalitionId);

private:
    Graph mGraph;
    vector<Agent> mAgents;
    vector<Coalition> coalitions;
};
