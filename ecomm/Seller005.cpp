#include <bits/stdc++.h>
#include "Seller.h"
#include "Seller005.h"
#include "Products.h"
#include "Mobile.h"

Seller005::Seller005(string id) : Seller(id)
{
    Products *mobile = new Mobile("mobile1", "005mob", 10, 125);
    Products *mobile1 = new Mobile("mobile2", "025mob", 51.12, 564);
    Products *mobile2 = new Mobile("mobile3", "125mob", 545, 589);
    Products *mobile3 = new Mobile("mobile4", "625mob", 12.2356, 254);
    Products *mobile4 = new Mobile("mobile5", "125mob", 78.25, 256);
    Products *mobile5 = new Mobile("mobile6", "15625mob", 123.5, 124);

    category_to_list_map[Globals::Category::Mobile].push_back(mobile);
    category_to_list_map[Globals::Category::Mobile].push_back(mobile1);
    category_to_list_map[Globals::Category::Mobile].push_back(mobile2);
    category_to_list_map[Globals::Category::Mobile].push_back(mobile3);
    category_to_list_map[Globals::Category::Mobile].push_back(mobile4);
    category_to_list_map[Globals::Category::Mobile].push_back(mobile5);
}

void Seller005::add_platform(Platform *thePlatform)
{
    thePlatform->add_seller(this);
}

void Seller005::add_product(Products *prod, Globals::Category category)
{
    category_to_list_map[category].push_back(prod);
}

vector<Products *> Seller005::find_products(Globals::Category categoryName)
{
    return category_to_list_map[categoryName];
}

bool Seller005::buy_product(string productId, int qty)
{
    int remaining = 0;
    bool found = false;

    for (auto key_value : category_to_list_map)
    {
        for (auto prod : key_value.second)
        {
            if (prod->get_product_id() == productId)
            {
                if (prod->get_quantity() < qty)
                {
                    return false;
                }
                remaining = prod->get_quantity() - qty;
                found = true;
            }
        }
    }

    if (!found)
    {
        return false;
    }

    for (auto &key_value : category_to_list_map)
    {
        vector<Products *> newList;
        for (auto prod : key_value.second)
        {
            if (prod->get_product_id() == productId)
            {
                prod->set_quantity(remaining);
                newList.push_back(prod);
            }
            else
            {
                newList.push_back(prod);
            }
        }
        key_value.second = newList;
    }
    return true;
}
