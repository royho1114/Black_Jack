//
//  Deck.hpp
//  Black_Jack_CPP
//
//  Created by CCHo on 2017/3/15.
//  Copyright © 2017年 UCD. All rights reserved.
//

#ifndef Deck_hpp
#define Deck_hpp

#include <stdio.h>
#include <vector>
#include "Card.hpp"

using namespace::std;

class Deck {
public:
    Deck(int n = 1);
    void reset();
    Card getCard();
    Card pickCard(char p, char s);
private:
    vector<Card> cardDeck;
    int numDecks;
};

#endif /* Deck_hpp */
