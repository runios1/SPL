#include "Party.h"
#include "Agent.h"
#include "Simulation.h"

Party::Party(int id, string name, int mandates, JoinPolicy *jp) : mId(id), mName(name), mMandates(mandates), mJoinPolicy(jp), mState(Waiting) ,timer(0),offers()
{
}

//copy constructor
Party::Party(const Party& other): mId(other.mId), mName(other.mName), mMandates(other.mMandates),mJoinPolicy(nullptr), mState(other.mState), timer(other.timer), offers(){
    if(other.mJoinPolicy->getType()=="M")
        mJoinPolicy=new MandatesJoinPolicy;
    else
        mJoinPolicy=new LastOfferJoinPolicy;

    for(Coalition c:other.offers){
        offers.push_back(c);
    }
}

// copy assignment 
Party& Party :: operator=(const Party& other){
this->mId = other.mId;
this->mName = other.mName;
this->mMandates = other.mMandates;
//this->mJoinPolicy = other.mJoinPolicy;

if(other.mJoinPolicy->getType()=="M")
        mJoinPolicy=new MandatesJoinPolicy;
    else
        mJoinPolicy=new LastOfferJoinPolicy;

this->mState = other.mState;
this->timer = other.timer;

for(Coalition c:other.offers){
   offers.push_back(c);
}

return *this;
}

//destructor
Party::~Party(){
    delete mJoinPolicy;
}


//move constructor
Party::Party(Party&& other) noexcept : mId(other.mId), mName(other.mName), mMandates(other.mMandates),mJoinPolicy(other.mJoinPolicy), mState(other.mState), timer(other.timer), offers(other.offers)
{ 
    other.mJoinPolicy=nullptr;
}

//move assignment
Party& Party::operator=(Party&& other) noexcept
{ 
    mId=other.mId;
    mName=other.mName;
    mJoinPolicy=other.mJoinPolicy;
    other.mJoinPolicy=nullptr;
    
    return *this;
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

