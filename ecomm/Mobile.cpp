#include<bits/stdc++.h>
#include "Mobile.h"
#include "Globals.h"

using namespace std;

// setting all the values
Mobile::Mobile(string nam, string prod_id, float prc, int qnty) {
    product_id = prod_id;
    name = nam;
    price = prc;
    quantity = qnty;
}
