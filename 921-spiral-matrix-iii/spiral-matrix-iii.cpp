class Solution
{
public:
    vector<vector<int>> spiralMatrixIII(int rows, int cols, int rStart, int cStart)
    {
        vector<vector<int>> res;
        int moves = 1;
        int all = rows * cols;
        while (res.size() < all)
        {
            // move right
            for (int i = 0; i < moves; i++)
            {
                if (cStart >= 0 && cStart < cols && rStart >= 0 && rStart < rows)
                {
                    res.push_back({rStart, cStart});
                    if (res.size() == all)
                        return res;
                }
                cStart++;
            }
            // move down
            for (int i = 0; i < moves; i++)
            {
                if (cStart >= 0 && cStart < cols && rStart >= 0 && rStart < rows)
                {
                    res.push_back({rStart, cStart});
                    if (res.size() == all)
                        return res;
                }
                rStart++;
            }
            moves++;
            // move left
            for (int i = 0; i < moves; i++)
            {
                if (cStart >= 0 && cStart < cols && rStart >= 0 && rStart < rows)
                {
                    res.push_back({rStart, cStart});
                    if (res.size() == all)
                        return res;
                }
                cStart--;
            }
            // move up
            for (int i = 0; i < moves; i++)
            {
                if (cStart >= 0 && cStart < cols && rStart >= 0 && rStart < rows)
                {
                    res.push_back({rStart, cStart});
                    if (res.size() == all)
                        return res;
                }
                rStart--;
            }
            moves++;
        }
        return res;
    }
};