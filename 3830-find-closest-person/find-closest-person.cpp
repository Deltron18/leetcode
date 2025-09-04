class Solution {
public:
    int findClosest(int x, int y, int z) {
        int dx = abs(x - z);
        int dy = abs(y - z);
        
        if (dx == dy) return 0;
        if (dx < dy) return 1;
        return 2;
    }
};
