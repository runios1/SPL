#include "SelectionPolicy.h"
#include "Simulation.h"

Party* EdgeWeightSelectionPolicy:: Select(int partyID, int coalitionId ,Simulation& sim){
    return sim.selectByEdgeWeight(partyID,coalitionId);
}
string EdgeWeightSelectionPolicy::getType(){
    return "E";
}
