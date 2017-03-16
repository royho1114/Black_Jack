//
//  Deck.cpp
//  Black_Jack_CPP
//
//  Created by CCHo on 2017/3/15.
//  Copyright © 2017年 UCD. All rights reserved.
//

#include "Deck.hpp"
#include <cstdlib>
#include <ctime>

Deck::Deck(int n) {
    numDecks = n;
    reset();
}

void Deck::reset() {
    for (int i = 0; i < numDecks; i++) {
        for (int s = 1; s <= 4; s++) {
            for (int p = 1; p <= 13; p++) {
                Card card = Card(p, s);
                cardDeck.push_back(card);
            }
        }
    }
}

Card Deck::getCard() {
    Card card = Card(0, 0); // initialize as an invalid card with point: P0
    if (cardDeck.empty()) return card;
    else {
        srand((unsigned int)time(0));
        int index = rand() % cardDeck.size();
        card = cardDeck[index];
        cardDeck.erase(cardDeck.begin() + index);
        return card;
    }
}

Card Deck::pickCard(char p, char s) {
    Card card = Card(0, 0); // initialize as an invalid card with point: P0
    for (int i = 0; i < cardDeck.size(); i++) {
        if (cardDeck[i].getPoint() == p && cardDeck[i].getSuit() == s) {
            card = cardDeck[i];
            cardDeck.erase(cardDeck.begin() + i);
            return card;
        }
    }
    return card;
}
