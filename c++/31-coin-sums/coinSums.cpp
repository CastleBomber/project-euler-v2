#include "coinSums.h"

/**
 * Calculates the number of combinations possible with the alloted coins
 * from the smallest up to the target coin
 * 
 * @param target largest coin and our main search
 * @return ways[target] number of cominations possible 
 */
int coinSums(int target) {
    vector<int> coins = {1, 2, 5, 10, 20, 50, 100, 200};
    vector<int> ways(target); // [0, 0, ..., 0, 0]
    ways[0] = 1; // Base case, one way to make 0p (no coins)

    for (auto coin : coins) {
        for (int i = coin; i < target+1; i++) {
            ways[i] += ways[i-coin];
        }
    }

    return ways[target];
}
