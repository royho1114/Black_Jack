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
using namespace std;

class Hand {
public:
    Hand(string bank, string player, int deck) {
        bank_rate = vector<float>(6, 0.0);
        card = vector<int>(10, 4 * deck);
        card[0] = 16 * deck;
        num_card = 52 * deck - 3;
        
        switch (bank[0]) {
            case 'A':
                bank_val = 1;
                bank_ace = true;
                card[1]--;
                break;
            case 'T':
                bank_val = 10;
                bank_ace = false;
                card[0]--;
                break;
            default:
                bank_val = bank[0] - '0';
                bank_ace = false;
                card[bank[0] - '0']--;
                break;
        }
        
        for (char x: player) {
            player_val = 0;
            player_ace = false;
            switch (x) {
                case 'A':
                    player_val += 1;
                    player_ace = true;
                    card[1]--;
                    break;
                case 'T':
                    player_val += 10;
                    card[0]--;
                    break;
                default:
                    player_val += (bank[0] - '0');
                    card[x - '0']--;
                    break;
            }
        }
        bankCalculator(1.0, bank_val, bank_ace, card, num_card);
        
    }
    void printTable() const {
        float sum = 0.0;
        for (int i = 0; i < 6; i++) {
            sum += bank_rate[i];
            if (i < 5) cout << i + 17 << ": " << bank_rate[i] << endl;
            else cout << "Burst: " << bank_rate[i] << endl;
        }
        cout << "Total: " << sum << endl;
    }
    //    int getHand() const {
    //        if (bust) return 0;
    //        else if (!ace) return val;
    //        else return (val + 10 <= 21)? val + 10: val;
    //    }
private:
    // probability of bank ended at {17, 18, 19, 20, 21, bust};
    vector<float> bank_rate;
    // fixed probability of each card {T, A, 2, ... 9};
    vector<int> card;
    
    int num_card, player_val, bank_val;
    bool player_ace, bank_ace;
//    float hit_w, hit_l, hit_d, hold_w, hold_l, hold_d;
    
    void bankCalculator(float rate, int val, bool ace, vector<int> &card, int n_card) {
        if (ace && val > 7 && val <= 11) {
            bank_rate[val - 7] += rate;
            return;
        }
        else if (val >= 17 && val <= 21) {
            bank_rate[val - 17] += rate;
            return;
        }
        else if (val > 21) {
            bank_rate[5] += rate;
            return;
        }
        else {
            if (card[0] > 0) {
                card[0]--;
                bankCalculator(rate * (float)(card[0] + 1) / n_card,
                               val + 10, ace, card, n_card - 1);
                card[0]++;
            }
            if (card[1] > 0) {
                card[1]--;
                bankCalculator(rate * (float)(card[1] + 1) / n_card,
                               val + 1, true, card, n_card - 1);
                card[1]++;
            }
            for (int i = 2; i <= 9; i++) {
                card[i]--;
                bankCalculator(rate * (float)(card[i] + 1) / n_card,
                               val + i, ace, card, n_card - 1);
                card[i]++;
            }
        }
    }
    
//    void playerCaculator(float rate, int val, bool ace, vector<int> &card, int n_card) {
//        WIN = 0.0, LOSE = 0.0, DRAW = 0.0;
//    }
};

int main(int argc, const char * argv[]) {
    Hand test("A", "22", 1);
    test.printTable();
    // insert code here...
    
    return 0;
}
