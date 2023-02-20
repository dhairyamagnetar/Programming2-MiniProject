#ifndef BOOK_H
#define BOOK_H

#include<bits/stdc++.h>
#include"Products.h"
#include"Globals.h"

using namespace std;

class Book: public Products {
    
public:
    Book(string prod_id, string nam, float prc, int qnty);
};

#endif