class Solution {
public:
    struct SparseTable {
        int n, LOG;
        vector<int> lg;
        vector<vector<int>> stMax, stMin;

        SparseTable(const vector<int>& a) {
            n = (int)a.size();
            lg.assign(n + 1, 0);
            for (int i = 2; i <= n; ++i)
                lg[i] = lg[i >> 1] + 1;
            LOG = lg[n];

            stMax.assign(LOG + 1, vector<int>(n));
            stMin.assign(LOG + 1, vector<int>(n));
            for (int i = 0; i < n; ++i) {
                stMax[0][i] = a[i];
                stMin[0][i] = a[i];
            }
            for (int k = 1; k <= LOG; ++k) {
                int len = 1 << k, half = 1 << (k - 1);
                for (int i = 0; i + len <= n; ++i) {
                    stMax[k][i] = max(stMax[k - 1][i], stMax[k - 1][i + half]);
                    stMin[k][i] = min(stMin[k - 1][i], stMin[k - 1][i + half]);
                }
            }
        }

        inline int rangeMax(int l, int r) const {
            int k = lg[r - l + 1];
            return max(stMax[k][l], stMax[k][r - (1 << k) + 1]);
        }
        inline int rangeMin(int l, int r) const {
            int k = lg[r - l + 1];
            return min(stMin[k][l], stMin[k][r - (1 << k) + 1]);
        }
        inline long long spread(int l, int r) const {
            return (long long)rangeMax(l, r) - (long long)rangeMin(l, r);
        }
    };

    struct Node {
        long long val;
        int l, r;
        bool operator<(const Node& other) const {
            return val < other.val;
        }
    };

    long long maxTotalValue(const vector<int>& nums, long long k) {
        int n = (int)nums.size();
        SparseTable st(nums);

        priority_queue<Node> pq;
        pq = priority_queue<Node>();

        for (int l = 0; l < n; ++l) {
            long long v = st.spread(l, n - 1);
            pq.push({v, l, n - 1});
        }

        long long ans = 0;
        for (long long picked = 0; picked < k; ++picked) {
            Node cur = pq.top();
            pq.pop();
            ans += cur.val;
            if (cur.r > cur.l) {
                int nl = cur.l, nr = cur.r - 1;
                long long nv = st.spread(nl, nr);
                pq.push({nv, nl, nr});
            }
        }
        return ans;
    }
};