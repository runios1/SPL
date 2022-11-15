#include "Party.h"
#include "Agent.h"

Party::Party(int id, string name, int mandates, JoinPolicy *jp) : mId(id), mName(name), mMandates(mandates), mJoinPolicy(jp), mState(Waiting) 
{
    int timer(0);
    vector<Agent> offers;
}

State Party::getState() const
{
    return mState;
}

void Party::setState(State state)
{
    mState = state;
}

int Party::getMandates() const
{
    return mMandates;
}

const string & Party::getName() const
{
    return mName;
}

void Party::step(Simulation &s)
{
    if(mState==State::CollectingOffers){
        timer++;
        if(timer==3){
        mMandates=mJoinPolicy->Join(offers,s);
        setState(State::Joined);
    }
}


