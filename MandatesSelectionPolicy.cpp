#include "SelectionPolicy.h"

Party& SelectionPolicy:: Select(int PartyId, int coalitionId,Simulation& sim){
    Party temp = sim.selectByMandates(PartyId,coalitionId);
}
