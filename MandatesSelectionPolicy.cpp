#include "SelectionPolicy.h"
#include "Simulation.h"

Party& MandatesSelectionPolicy:: Select(int PartyId, int coalitionId,Simulation& sim){
    Party& output = sim.selectByMandates(PartyId,coalitionId);
    return output;
}
