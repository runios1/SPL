#pragma once
#include "Simulation.h"
#include "Coalition.h"

class JoinPolicy {
    public:
        void Join(const vector<Coalition>& offers,int partyMandates);
};

class MandatesJoinPolicy : public JoinPolicy {};

class LastOfferJoinPolicy : public JoinPolicy {};
