class Solution {
public:
    double largestTriangleArea(vector<vector<int>>& points) {
        int n = points.size();
        double res=0.0;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                for(int k=j+1;k<n;k++){
                    auto &a = points[i], &b = points[j], &c = points[k];
                    double area = (double)1/2.0 * ((a[0]*(b[1] - c[1]) + b[0]*(c[1] - a[1]) + c[0]*(a[1]-b[1])));
                    res = max(res, abs(area));
                }
            }
        }
        return res;
    }
};