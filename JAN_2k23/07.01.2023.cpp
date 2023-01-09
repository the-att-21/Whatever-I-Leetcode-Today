1. https://leetcode.com/problems/gas-station/description/
Solution : 
class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int gases = accumulate(gas.begin(), gas.end(), 0);
        int costs = accumulate(cost.begin(), cost.end(), 0);

        if(costs > gases) { return -1; }

        int ans = 0, tank = 0, n = gas.size();

        for(int i = 0; i < n; i++){
            tank += (gas[i] - cost[i]);

            if(tank < 0){
                ans = i + 1;
                tank = 0;
            }
        }

        return ans;
    }
};

-------------------------------------------------------------------------------------------------------------------------------------------

2. https://leetcode.com/problems/maximize-the-topmost-element-after-k-moves/description/
Solution:
class Solution {
public:
    int maximumTop(vector<int>& nums, int k) {
        int n = nums.size(), ans = INT_MIN;
        if(n == 1 and k % 2) { return -1; }
        for(int i = 0; i < k - 1 and i < n; i++)
            ans = max(ans, nums[i]);

        if(k < n)
            ans = max(ans, nums[k]);

        return ans;
    }
};

-------------------------------------------------------------------------------------------------------------------------------------------

3. https://leetcode.com/contest/biweekly-contest-95/problems/categorize-box-according-to-criteria/
Solution:
class Solution {
public:
    string categorizeBox(int length, int width, int height, int mass) {
        long long int vol = (long long)length * (long long)width * (long long)height;
        bool bulky = false, heavy = false;
        
        if(vol >= 1000000000 or length >= 10000 or width >= 10000 or height >= 10000) { bulky = true; }
        if(mass >= 100) { heavy = true; }
        
        if(bulky and heavy) { return "Both"; }
        if(!bulky and !heavy) { return "Neither"; }
        if(bulky) { return "Bulky"; }
        if(heavy) { return "Heavy"; }
        return "Both";
    }
};

-------------------------------------------------------------------------------------------------------------------------------------------

4. https://leetcode.com/problems/find-xor-beauty-of-array/description/
Solution:
class Solution {
public:
    int xorBeauty(vector<int>& nums) {
        int n = nums.size(), ans = 0;
        set<int> s;
        
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                for(int k = 0; k < n; k++){
                    s.insert((nums[i] | nums[j]) & nums[k]);
                }
            }
        }
        
        while(!s.empty()){
            int temp = s.front();
            ans ^= temp;
            s.pop();
        }
        
        return ans;
    }
};
