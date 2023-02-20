#include <iostream>

#include "Seller.h"
#include "Seller022.h"

#include "Products.h"

#include <random>
#include <time.h>

#define pb push_back

Seller022::Seller022(string id):Seller(id){
    //to initialize the list of books and mobiles, we randomly generate the names and every other detail from some hardcoded datasets
    
    vector<string> firstnames = {"Aaron", "Bismuth", "Cadabra", "Devon"};
    vector<string> lastnames = {"Erorgorn","Fateem", "Ganesh", "Hugovitch"};
    vector<string> adjectives = {"Bloody", "Horrific", "Blissful", "Trippy"};
    vector<string> nouns = {"Sunday", "Sunrise", "Funeral", "Blasphemy"};

    srand(time(NULL));  // seed for random values
    for(int id=100;id<110;id++){
        products[Globals::Category(2)][to_string(id)] = new Book( 
            adjectives[rand()%4] + " " + nouns[rand()%4] + " by " + firstnames[rand()%4] + " " + lastnames[rand()%4],
            to_string(id),
            300 + (rand()%1000)/10, 
            10 + rand()%13
        );
    }

    // generating mobile objects
    vector<string> companies = {"Bigoby", "TinyChip", "Amsmung", "Orange"};
    srand(time(NULL));
    for(int id=200;id<210;id++){
        products[Globals::Category(1)][to_string(id)] = new Mobile(
            companies[rand()%4] + " " + char(65 + rand()%20) + to_string(1 + rand()%10),
            to_string(id),
            8000 + (rand()%100000000)/100,
            50 + rand()%200
        );
    }
};

void Seller022::add_platform(Platform* the_platform) {
    the_platform->add_seller(this);
}

void Seller022::add_product(Products* prod,Globals::Category category) {
    products[category][prod->get_product_id()] = prod;
};

vector<Products*> Seller022::find_products(Globals::Category which_one) {
    vector<Products*> ret;
    for (auto prod : products[which_one]) {
        ret.pb(prod.second);
    }
    return ret;
}

bool Seller022::buy_product(string product_id, int quantity) {
    Products *prod;
    bool found = false;
    for(auto categories : products){
        if(categories.second.find(product_id)!=categories.second.end()){
            prod = categories.second[product_id];
            found = true;
            break;
        }
    }

    if (!found || prod->get_quantity() < quantity) {
        return false;
    }
    prod->set_quantity(prod->get_quantity() - quantity);
    //we increase the prices by a small exponential factor as the quantity decreases
    prod->set_price(prod->get_price()*1.0005*quantity);
    return true;
}