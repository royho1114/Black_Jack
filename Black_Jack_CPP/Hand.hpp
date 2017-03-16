//
//  Hand.hpp
//  Black_Jack_CPP
//
//  Created by CCHo on 2017/3/15.
//  Copyright © 2017年 UCD. All rights reserved.
//

#ifndef Hand_hpp
#define Hand_hpp

#include <stdio.h>
#include <vector>
#include "Card.hpp"

using namespace::std;

class Hand {
public:
    Hand(Card);
    Hand(vector<Card>);
    void addCard(Card);
    void removeCard();

private:
    bool ace;
    int point;
    vector<Card> cards;
};

//    void printTable() const {
//        float sum = 0.0;
//        for (int i = 0; i < 6; i++) {
//            sum += bank_rate[i];
//            if (i < 5) cout << i + 17 << ": " << bank_rate[i] << endl;
//            else cout << "Burst: " << bank_rate[i] << endl;
//        }
//        cout << endl;
//
//        float sum1 = 0.0 , sum2 = 0.0;
//        sum1 = hold_d + hold_l + hold_w;
//        sum2 = hit_d + hit_l + hit_w;
//        cout << "Hold:" << endl;
//        cout << "Win: " << hold_w << endl;
//        cout << "Lose: " << hold_l << endl;
//        cout << "Draw: " << hold_d << endl;
//        cout << endl;
//        cout << "After one hit:" << endl;
//        cout << "Win: " << hit_w << endl;
//        cout << "Lose: " << hit_l << endl;
//        cout << "Draw: " << hit_d << endl;
//
//        cout << "Total: " << sum << ", " << sum1 << ", " << sum2 << endl;
//    }
//    //    int getHand() const {
//    //        if (bust) return 0;
//    //        else if (!ace) return val;
//    //        else return (val + 10 <= 21)? val + 10: val;
//    //    }


////////////////////



//    // probability of bank ended at {17, 18, 19, 20, 21, bust};
//    vector<float> bank_rate;
//    // fixed probability of each card {T, A, 2, ... 9};
//    vector<int> card;
//
//    int num_card, player_val, bank_val;
//    bool player_ace, bank_ace;
//    float hit_w, hit_l, hit_d, hold_w, hold_l, hold_d;
//
//    void bankCalculator(float rate, int val, bool ace, vector<int> &card, int n_card) {
//        if (ace && val > 7 && val <= 11) {
//            bank_rate[val - 7] += rate;
//            return;
//        }
//        else if (val >= 17 && val <= 21) {
//            bank_rate[val - 17] += rate;
//            return;
//        }
//        else if (val > 21) {
//            bank_rate[5] += rate;
//            return;
//        }
//        else {
//            if (card[0] > 0) {
//                card[0]--;
//                bankCalculator(rate * (float)(card[0] + 1) / n_card,
//                               val + 10, ace, card, n_card - 1);
//                card[0]++;
//            }
//            if (card[1] > 0) {
//                card[1]--;
//                bankCalculator(rate * (float)(card[1] + 1) / n_card,
//                               val + 1, true, card, n_card - 1);
//                card[1]++;
//            }
//            for (int i = 2; i <= 9; i++) {
//                card[i]--;
//                bankCalculator(rate * (float)(card[i] + 1) / n_card,
//                               val + i, ace, card, n_card - 1);
//                card[i]++;
//            }
//        }
//    }
//
//    vector<float> playerCaculator(int val, bool ace) {
//        float win = bank_rate[5], lose = 0.0, draw = 0.0;
//
//        int p_val = val;
//        if (ace && val + 10 <= 21) p_val += 10;
//
//        if (p_val > 21) {
//            win = 0.0;
//            lose = 1.0;
//            draw = 0.0;
//        }
//        else {
//            for (int i = 0; i < 5; i++) {
//                if (p_val - 17 == i) draw = bank_rate[i];
//                else if (p_val - 17 > i) win += bank_rate[i];
//                else lose += bank_rate[i];
//            }
//        }
//
//        return {win, lose, draw};
//    }

#endif /* Hand_hpp */
