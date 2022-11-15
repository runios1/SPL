#pragma once
#include "Simulation.h"

class JoinPolicy {
    public:
        int Join(const vector<Agent>& offers,Simulation &s);
};

class MandatesJoinPolicy : public JoinPolicy {};

class LastOfferJoinPolicy : public JoinPolicy {};
