#include<bits/stdc++.h>
#include "Products.h"
#include "Globals.h"

using namespace std;


// all of the common functions
Globals::Category  Products::get_category() {
    return category;
}
string Products::get_name() {
    return name;
};
string Products::get_product_id() {
    return product_id;
};
float Products::get_price() {
    return price;
};
int Products::get_quantity() {
    return quantity;
};
void Products::set_quantity(int amt) {
    quantity = amt;
}
void Products::set_price(int prc) {
    price = prc;
}
