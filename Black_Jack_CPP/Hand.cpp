//
//  Hand.cpp
//  Black_Jack_CPP
//
//  Created by CCHo on 2017/3/15.
//  Copyright © 2017年 UCD. All rights reserved.
//

#include "Hand.hpp"

Hand::Hand() {
    ace = false;
    point = 0;
}

Hand::Hand(vector<Card> cs) {
    ace = false;
    point = 0;
    cards = cs;
    for (Card c: cards) addCard(c);
}

void Hand::addCard(Card c) {
    cards.push_back(c);
    char p = c.getPoint();
    if (p == 'A') {
        if (point + 11 > 21) point += 1;
        else {
            point += 11;
            ace = true;
        }
    }
    else {
        if (p >= '2' && p <= '9') point += (p - '0');
        else point += 10;
        if (point > 21 && ace) {
            point -= 10;
            ace = false;
        }
    }
}

void Hand::removeLast() {
    cards.pop_back();
    ace = false;
    point = 0;
    for (Card c: cards) addCard(c);
}

int Hand::getPoint() {
    return point;
}

//Hand::Hand(int card) {
//    point = card;
//    if (card == 0 || card == 1) point += 10;
//    ace = (card == 1);
//    cards.push_back(card);
//}
//
//Hand::Hand(vector<int> cards) {
//    setHand(cards);
//}
//
//void Hand::getCard(int card) {
//    if (card == 1) ace = true;
//    point += card;
//    if (card == 0 || card == 1) point += 10;
//    if (ace && point > 21) point -= 10;
//    cards.push_back(card);
//}
//
//void Hand::removeCard() {
////    int card = cards.back();
//    cards.pop_back();
//    
//}

//Hand::Hand(string bank, string player, int deck) {
//    cout << "In the case:" << endl;
//    cout << "Bank: " << bank << endl;
//    cout << "Player: " << player << endl;
//    cout << endl;
//    bank_rate = vector<float>(6, 0.0);
//    card = vector<int>(10, 4 * deck);
//    card[0] = 16 * deck;
//    num_card = 52 * deck - 3;
//    
//    switch (bank[0]) {
//        case 'A':
//            bank_val = 1;
//            bank_ace = true;
//            card[1]--;
//            break;
//        case 'T':
//            bank_val = 10;
//            bank_ace = false;
//            card[0]--;
//            break;
//        default:
//            bank_val = bank[0] - '0';
//            bank_ace = false;
//            card[bank[0] - '0']--;
//            break;
//    }
//    
//    player_val = 0;
//    player_ace = false;
//    for (char x: player) {
//        switch (x) {
//            case 'A':
//                player_val += 1;
//                player_ace = true;
//                card[1]--;
//                break;
//            case 'T':
//                player_val += 10;
//                card[0]--;
//                break;
//            default:
//                player_val += (x - '0');
//                card[x - '0']--;
//                break;
//        }
//    }
//    bankCalculator(1.0, bank_val, bank_ace, card, num_card);
//    
//    vector<float> tmp = playerCaculator(player_val, player_ace);
//    hold_w = tmp[0];
//    hold_l = tmp[1];
//    hold_d = tmp[2];
//    
//    hit_w = 0.0, hit_l = 0.0, hit_d = 0.0;
//    for (int i = 0; i < 10; i++) {
//        vector<float> tmp2;
//        if (i == 0) {
//            tmp2 = playerCaculator(player_val + 10, player_ace);
//            hit_w += tmp2[0] * (float) card[0] / num_card;
//            hit_l += tmp2[1] * (float) card[0] / num_card;
//            hit_d += tmp2[2] * (float) card[0] / num_card;
//        }
//        else if (i == 1) {
//            tmp2 = playerCaculator(player_val + 1, true);
//            hit_w += tmp2[0] * (float) card[1] / num_card;
//            hit_l += tmp2[1] * (float) card[1] / num_card;
//            hit_d += tmp2[2] * (float) card[1] / num_card;
//        }
//        else {
//            tmp2 = playerCaculator(player_val + i, player_ace);
//            hit_w += tmp2[0] * (float) card[i] / num_card;
//            hit_l += tmp2[1] * (float) card[i] / num_card;
//            hit_d += tmp2[2] * (float) card[i] / num_card;
//        }
//        cout << "";
//    }
//}
