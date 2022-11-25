#pragma once

#include <vector>
#include <string>
#include "Agent.h"
#include "Graph.h"

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
    int getCurrentId();
    Party* selectByEdgeWeight(int PartyId, int coalitionId);
    Party* selectByMandates(int PartyId, int coalitionId);
    void joinByMandates(vector<int>& offers,int partyMandates, int partyid, int newAgentid);
    void joinByLastOffer(vector<int>& offers,int partyMandates, int partyid, int newAgentid);

private:
    Graph mGraph;
    vector<Agent> mAgents;
    vector<Coalition> coalitions;
};
