#include "Party.h"
#include "Agent.h"
#include "Simulation.h"

Party::Party(int id, string name, int mandates, JoinPolicy *jp) : mId(id), mName(name), mMandates(mandates), mJoinPolicy(jp), mState(Waiting) ,timer(0),offers()
{
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
        mJoinPolicy->Join(offers,mMandates,mId,s.getCurrentId());
        setState(State::Joined);
        }
    }
}

void Party::addToOffers(Coalition& coalition){
    offers.push_back(coalition);
}

bool Party::isInOffers(int coalitionId){
    for(Coalition a : offers){
        if( coalitionId == a.getId()){
            return true;
        }
    }
    return false;
}

