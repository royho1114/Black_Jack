//
//  Card.cpp
//  Black_Jack_CPP
//
//  Created by CCHo on 2017/3/15.
//  Copyright © 2017年 UCD. All rights reserved.
//

#include "Card.hpp"

Card::Card(int p, int s) {
    switch (p) {
        case 1:
            point = 'A';
            break;
            
        case 10:
            point = 'T';
            break;
            
        case 11:
            point = 'J';
            break;
            
        case 12:
            point = 'Q';
            break;
            
        case 13:
            point = 'K';
            break;
            
        default:
            point = ('0' + p);
            break;
    }
    
    switch (s) {
        case 1:
            suit = 'S';
            break;
            
        case 2:
            suit = 'H';
            break;
            
        case 3:
            suit = 'D';
            break;
            
        default:
            suit = 'P';
            break;
    }
}

char Card::getPoint() const{
    return point;
}

char Card::getSuit() const{
    return suit;
}
