class Solution {
public:
    long long solve(string& s, int encCost, int flatCost, int start, int end) {
        int l = end - start + 1;
        int count = 0;
        for (int i = start; i <= end; i++) {
            if (s[i] == '1')
                count++;
        }

        long long cost = 0;
        if (count)
            cost = 1LL * encCost * l * count;
        else
            cost = 1LL * flatCost;

        int mid = (start + end) / 2;
        if (l % 2 == 0) {
            long long cost1 = solve(s, encCost, flatCost, start, mid);
            long long cost2 = solve(s, encCost, flatCost, mid + 1, end);
            cost = min(cost, (cost1 + cost2));
        }

        return cost;
    }

    long long minCost(string s, int encCost, int flatCost) {
        return solve(s, encCost, flatCost, 0, s.size() - 1);
    }
};