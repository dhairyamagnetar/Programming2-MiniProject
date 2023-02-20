#ifndef SELLER005_H
#define SELLER005_H

#include <bits/stdc++.h>
#include "Seller.h"
#include "Platform.h"
#include "Globals.h"
#include "Products.h"

using namespace std;

class Seller005 : public Seller
{
private:
    map<Globals::Category, vector<Products *>> category_to_list_map;

public:
    Seller005(string id);
    void add_platform(Platform *the_platform) override;
    void add_product(Products *prod, Globals::Category category) override;
    vector<Products *> find_products(Globals::Category which_one) override;
    bool buy_product(string product_id, int quantity) override;
};

#endif