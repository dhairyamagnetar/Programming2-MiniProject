#include <bits/stdc++.h>
#include "Globals.h"
#include "Seller.h"


using namespace std;

// setting id during initialization
Seller::Seller(string id) {
	my_id = id;
}

// getter
string Seller::get_id() {
	return my_id;
}