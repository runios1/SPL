#include "SelectionPolicy.h"


Party& SelectionPolicy:: Select(int partyID, int coalitionId,Simulation& sim){
    Party temp = sim.getGraph().selectByEdgeWeight(partyID,coalitionId);
}
