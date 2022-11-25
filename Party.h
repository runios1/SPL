#pragma once
#include <string>
#include "JoinPolicy.h"

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

    //The Rule Of 5:
    Party(const Party& other); // copy constructor
    Party& operator = (const Party& other); // copy assignment
    virtual ~Party(); // destructor
    Party(Party&& other) noexcept; // move constuctor
    Party& operator = (Party&& other) noexcept; // move assignment



    State getState() const;
    void setState(State state);
    int getMandates() const;
    void step(Simulation &s);
    const string &getName() const;
    int getIdOfParty() const;
    void addToOffers(int coalitionId);
    bool isInOffers(int coalitionId) const;

private:
    int mId;
    string mName;
    int mMandates;
    JoinPolicy *mJoinPolicy;
    State mState;
    int timer;
    vector <int> offers; //stores all the coalitions that offered to the party by id.
};
