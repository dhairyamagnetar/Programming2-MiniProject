#include<bits/stdc++.h>
#include"./demo/DemoPlatform.h"
#include"./ecomm/Seller.h"
#include"./ecomm/Seller016.h"
#include"./ecomm/Seller022.h"
#include"./ecomm/Seller005.h"
#include"./ecomm/Book.h"
#include"./ecomm/Mobile.h"
#include"./ecomm/Products.h"
#include"./ecomm/Globals.h"

#include"./demo/DemoPlatform.cpp"
#include"./ecomm/Seller.cpp"
#include"./ecomm/Seller016.cpp"
#include"./ecomm/Seller022.cpp"
#include"./ecomm/Seller005.cpp"
#include"./ecomm/Book.cpp"
#include"./ecomm/Mobile.cpp"
#include"./ecomm/Products.cpp"
#include"./ecomm/Globals.cpp"


using namespace std;

int main() {
    //instantiating the platform
    Platform* pf = new DemoPlatform();
    
    Seller* seller016 = new Seller016("Seller016");
    Seller* seller022 = new Seller022("Seller022");
    Seller* seller005 = new Seller005("Seller005");
    
    //Associating the platform with sellers
    seller016->add_platform(pf);
    seller022->add_platform(pf);
    seller005->add_platform(pf);

    //user input
    while(1) {
        string s;
        cin >> s;
        if (s == "check") {
            pf->process_requests();
        }
    }

}