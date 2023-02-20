#include <bits/stdc++.h>
#include "Globals.h"
using namespace std;

// file name variable
string Globals::to_platfrom = "PortalToPlatform.txt";
string Globals::from_platform = "PlatformToPortal.txt";

// initializing string_to_category map
map<string, Globals::Category> Globals::string_to_category_map = {
	{"Mobile", static_cast<Category>(Category(1))},
	{"Book", static_cast<Category>(Category(2))},
};


string Globals::get_category_name(Category c)
{
	switch (c)
	{
	case Mobile:
		return "Mobile";
	case Book:
		return "Book";
	default:
		return "Error";
	}
}

Globals::Category Globals::get_category_enum(string s)
{
	Globals global;

	return string_to_category_map[s];
}