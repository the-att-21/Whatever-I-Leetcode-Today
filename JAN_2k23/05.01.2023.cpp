1. https://leetcode.com/problems/minimum-number-of-arrows-to-burst-balloons
Solution : 
class Solution {
public:
    static bool cmp(vector<int> &a, vector<int> &b){
        return a[1] < b[1];
    }
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(), points.end(), cmp);
        int curr = points[0][1];
        int ans = 1;

        for(int i = 0; i < points.size(); i++){
            if(curr < points[i][0]){
                ans++;
                curr = points[i][1];
            }
        }

        return ans;
    }
};