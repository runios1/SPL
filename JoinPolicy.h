#pragma once
#include "Coalition.h"
#include <string>

using std::string;

class JoinPolicy {
    public:
    virtual void Join(Simulation sim,vector <int> & offers,int partyMandates, int partyid, int newAgentid)=0;
    
    virtual string getType()=0;

    virtual ~JoinPolicy()=default;
};

class MandatesJoinPolicy : public JoinPolicy {
public:
    virtual void Join(Simulation sim,vector <int> & offers,int partyMandates, int partyid,int newAgentid);
    virtual string getType();
};

class LastOfferJoinPolicy : public JoinPolicy {
public:
    virtual void Join(Simulation sim,vector <int> & offers,int partyMandates, int partyid,int newAgentid);
    virtual string getType();
};
