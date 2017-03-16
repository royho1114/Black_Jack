//
//  main.cpp
//  Black_Jack_CPP
//
//  Created by CCHo on 2017/1/28.
//  Copyright © 2017年 UCD. All rights reserved.
//

#include <iostream>
#include <vector>
#include <string>
#include "Deck.hpp"
using namespace std;

int main(int argc, const char * argv[]) {
    Deck d = Deck();
    for (int i = 0; i < 5; i++) {
        Card c = d.pickCard('T', 'S');
        cout << c.getSuit() << ": " << c.getPoint() << endl;
    }
    for (int i = 0; i < 104; i++) {
        Card c = d.getCard();
        cout << c.getSuit() << ": " << c.getPoint() << endl;
    }
    return 0;
}
