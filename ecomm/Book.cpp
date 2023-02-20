#include<bits/stdc++.h>
#include "Book.h"
#include "Globals.h"

using namespace std;

// settin all the data of the Book
Book::Book(string nam, string prod_id, float prc, int qnty) {
    product_id = prod_id;
    name = nam;
    price = prc;
    quantity = qnty;
}

