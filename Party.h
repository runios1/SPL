#pragma once
#include <string>
#include "JoinPolicy.h"
#include "Coalition.h"
#include "Simulation.h"

using std::string;

class Simulation;

enum State
{
    Waiting,
    CollectingOffers,
    Joined
};

class Party
{
public:
    Party(int id, string name, int mandates, JoinPolicy *); 

    State getState() const;
    void setState(State state);
    int getMandates() const;
    void step(Simulation &s);
    const string &getName() const;
    
    int getIdOfParty() const;
    void addToOffers(Coalition& coalition);
    bool isInOffers(int coalitionId);
    
private:
    int mId;
    string mName;
    int mMandates;
    JoinPolicy *mJoinPolicy;
    State mState;

    int timer;
    vector<Coalition> offers;
};
