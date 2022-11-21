#pragma once
#include "Coalition.h"

class JoinPolicy {
    public:
    virtual void Join(const vector <Coalition> & offers,int partyMandates, int partyid, int newAgentid)=0;

    virtual ~JoinPolicy()=default;
};

class MandatesJoinPolicy : public JoinPolicy {
public:
    virtual void Join(const vector <Coalition> & offers,int partyMandates, int partyid,int newAgentid);
};

class LastOfferJoinPolicy : public JoinPolicy {
public:
    virtual void Join(const vector <Coalition> & offers,int partyMandates, int partyid,int newAgentid);
};
