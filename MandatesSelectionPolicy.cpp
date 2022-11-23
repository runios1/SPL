#include "SelectionPolicy.h"
#include "Simulation.h"

Party* MandatesSelectionPolicy:: Select(int PartyId, int coalitionId,Simulation& sim){
    return sim.selectByMandates(PartyId,coalitionId);
}
string MandatesSelectionPolicy::getType(){
    return "M";
}
