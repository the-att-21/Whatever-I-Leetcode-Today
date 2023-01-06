1. https://leetcode.com/problems/maximum-ice-cream-bars
Solution : 
class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        sort(costs.begin(), costs.end());
        int ans = 0;
        for(auto &i : costs){
            if(i > coins){return ans;}
            ans++;
            coins -= i;
        }

        return ans;
    }
};