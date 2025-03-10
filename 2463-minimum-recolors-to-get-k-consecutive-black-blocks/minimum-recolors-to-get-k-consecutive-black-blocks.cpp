class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        int white = count(blocks.begin(), blocks.begin() + k, 'W');
        int mini = white;
        for (int i = k; i < blocks.size(); i++) {
            white += blocks[i] == 'W';
            white -= blocks[i - k] == 'W';
            mini = min(mini, white);
        }
        return mini;
    }
};