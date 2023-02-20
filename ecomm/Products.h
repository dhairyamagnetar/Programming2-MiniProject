#ifndef PRODUCTS_H
#define PRODUCTS_H

#include "Globals.h"

class Products {
protected:
    // all of the common data
    string product_id, name;
    Globals::Category category = Globals::Category::Book;
    float price;
    int quantity;
public:
    // all of the common methods
    virtual Globals::Category get_category();
    virtual string get_name();
    virtual string get_product_id();
    virtual float get_price();
    virtual int get_quantity();
    virtual void set_quantity(int amt);
    virtual void set_price(int prc);
};

#endif