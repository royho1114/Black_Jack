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
#include "Hand.hpp"
#include "Deck.hpp"
using namespace std;

int main(int argc, const char * argv[]) {
    Deck d = Deck();
    Card c1 = d.getCard(), c2 = d.getCard();
    cout << "The first two cards are: " << c1.getSuit() << c1.getPoint() << " and " << c2.getSuit() << c2.getPoint() << endl;
    Hand player1 = Hand({c1, c2});
    int p = player1.getPoint();
    cout << "The current point is: " << p << endl;
    
    char hit;
    while (true) {
        cout << "Deal? (y/n): ";
        cin >> hit;
        if (hit == 'y') {
            cout << "The final point is: " << player1.getPoint() << endl;
            break;
        }
        else {
            Card c = d.getCard();
            cout << "The next card is: " << c.getSuit() << c.getPoint() << endl;
            player1.addCard(c);
            p = player1.getPoint();
            if (p > 21) {
                cout << "Busted with " << p << "!!" << endl;
                break;
            }
            else cout << "The current point is: " << p << endl;
        }
    }
    return 0;
}
