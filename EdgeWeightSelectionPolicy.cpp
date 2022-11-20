#include "SelectionPolicy.h"
#include "Simulation.h"

Party& EdgeWeightSelectionPolicy:: Select(int partyID, int coalitionId ,Simulation& sim){
    Party& output = sim.selectByEdgeWeight(partyID,coalitionId);
    return output;
}
