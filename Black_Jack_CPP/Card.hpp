//
//  Card.hpp
//  Black_Jack_CPP
//
//  Created by CCHo on 2017/3/15.
//  Copyright © 2017年 UCD. All rights reserved.
//

#ifndef Card_hpp
#define Card_hpp

#include <stdio.h>
#include <string>

using namespace::std;

class Card {
public:
    Card(int p, int s);
    char getPoint() const;
    char getSuit() const;
private:
    char point, suit;
    // point: Ace: A, 2, 3, 4, 5, 6, 7, 8, 9, 10: T, J: 11, Q: 12, K: 13
    // suit: 1.spade: S, 2.heart: H, 3.diamond: D, 4.plum: P
};

#endif /* Card_hpp */
