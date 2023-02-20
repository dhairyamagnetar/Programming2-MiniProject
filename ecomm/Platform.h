#ifndef PLATFROM_H
#define PLATFROM_H

#include<bits/stdc++.h>

class Seller;

using namespace std;

class Platform {
protected:
	vector<Seller*> sellers;  // list of all the sellers
	map<pair<string, string>,int> done_req;  // keeps track of the request that was done in form <PortalId, RequestId>

public:
	virtual bool add_seller(Seller* seller){};
	virtual void process_requests(){};
};

#endif