//
//  Card.cpp
//  Black_Jack_CPP
//
//  Created by CCHo on 2017/3/15.
//  Copyright © 2017年 UCD. All rights reserved.
//

#include "Card.hpp"

Card::Card(int point, int suit) {
    switch (point) {
        case 1:
            this -> point = 'A';
            break;
            
        case 10:
            this -> point = 'T';
            break;
            
        case 11:
            this -> point = 'J';
            break;
            
        case 12:
            this -> point = 'Q';
            break;
            
        case 13:
            this -> point = 'K';
            break;
            
        default:
            this -> point = '0' + point;
            break;
    }
    
    switch (suit) {
        case 1:
            this -> suit = 'S';
            break;
            
        case 2:
            this -> suit = 'H';
            break;
            
        case 3:
            this -> suit = 'D';
            break;
            
        default:
            this -> suit = 'P';
            break;
    }
}

char Card::getPoint() const{
    return point;
}

char Card::getSuit() const{
    return suit;
}
