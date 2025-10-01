class Solution {
public:
    int numWaterBottles(int n, int k) {
        int total = n;         // You drink all starting bottles
        int empty = n;         // After drinking, all are empty

        while (empty >= k) {
            int newBottles = empty / k;   // How many new full bottles you can get
            total += newBottles;          // Drink them
            empty = newBottles + (empty % k); // New empties + leftover empties
        }

        return total;
    }
};
