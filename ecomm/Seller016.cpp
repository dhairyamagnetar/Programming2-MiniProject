#include<bits/stdc++.h>
#include"Seller.h"
#include"Seller016.h"
#include"Products.h"
#include"Book.h"
#include"Mobile.h"

Seller016::Seller016(string id):Seller(id){
    // hardcoding products in the seller product list 
    category_to_list_map[Globals::Category::Book].push_back(
        new Book("book1", "book016", 69.69, 69)
    );
    category_to_list_map[Globals::Category::Book].push_back(
       new Book("book2", "book017", 69.699, 690)
    );
    category_to_list_map[Globals::Category::Book].push_back(
        new Book("book3", "book018", 69.6999, 691)
    );
    category_to_list_map[Globals::Category::Book].push_back(
        new Book("book4", "book019", 69.70, 693)
    );
    category_to_list_map[Globals::Category::Book].push_back(
        new Book("book5", "book020", 69.6969, 6969)
    );

    category_to_list_map[Globals::Category::Mobile].push_back(
        new Mobile("Mobile1", "Mobile020", 8000, 61)
    );
    category_to_list_map[Globals::Category::Mobile].push_back(
        new Mobile("Mobile2", "Mobile021", 12398, 96)
    );
    category_to_list_map[Globals::Category::Mobile].push_back(
        new Mobile("Mobile3", "Mobile022", 43534, 9)
    );
};

bool Seller016::buy_product(string product_id, int quantity) {
    int available = 0;
    // search through all of the list in the map
    for (auto key_value : category_to_list_map) {
        // iterating the vector 
        for (auto prod : key_value.second) {
            if (prod->get_product_id() == product_id) {
                available = prod->get_quantity();
            }
        }
    }

    // if not enough product is available, return false
    if (available < quantity) return false;
    
    // again iterate the map for updating the list
    for (auto &key_value : category_to_list_map) {
        vector<Products*> new_list;
        for (auto prod : key_value.second) {
            if (prod->get_product_id() == product_id) {
                prod->set_quantity(available - quantity);
                prod->set_price(prod->get_price() + 30*(available - quantity));
                new_list.push_back(prod);
            }
            else {
                new_list.push_back(prod);
            }
        }
        key_value.second = new_list;
        
    }
    return true;
}

void Seller016::add_platform(Platform* the_platform) {
    the_platform->add_seller(this);
}

void Seller016::add_product(Products* prod, Globals::Category category) {
    category_to_list_map[category].push_back(prod);
};

vector<Products*> Seller016::find_products(Globals::Category which_one) {
    return category_to_list_map[which_one];
}