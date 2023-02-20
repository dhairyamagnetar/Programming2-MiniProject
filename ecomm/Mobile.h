#ifndef MOBILE_H
#define MOBILE_H

#include<bits/stdc++.h>
#include"Products.h"

using namespace std;

class Mobile : public Products {

public:
    Mobile(string prod_id, string nam, float prc, int qnty);
};


#endif