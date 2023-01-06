1. https://leetcode.com/problems/minimum-rounds-to-complete-all-tasks/
Solution : 
 * C++ Solution :
    class Solution {
    public:
        int minimumRounds(vector<int>& tasks) {
            map<int, int> f;
            int ans = 0;
            for(auto &i : tasks) f[i]++;
            for(auto &i : f){
                if(i.second < 2) return -1;
                ans += ((i.second + 2) / 3);
            }

            return ans;
        }
    };

 * JAVA Solution : 
    class Solution {
    public int minimumRounds(int[] tasks) {
        HashMap<Integer, Integer> count = new HashMap<>();
        int ans = 0;

        for(int i : tasks) count.put(i, count.getOrDefault(i, 0) + 1);

        for(int freq : count.values()){
            if(freq == 1) return -1;
            ans += ((freq + 2) / 3);
        }

        return ans;
    }
}

---------------------------------------------------------------------------------------------------------------------------------------------

2. https://leetcode.com/problems/largest-odd-number-in-string
Solution : 
1. class Solution {
public:
    string largestOddNumber(string num) {
        string ans = "";
        int capture;
        for(int i = num.size() - 1; i >= 0; i--){
            if(num[i]%2 == 1){
                capture = i;
                break;
            }
        }
        for(int i = 0; i <= capture; i++){
            ans.push_back(num[i]);
        }

        return ans;
    }
};

2. class Solution {
public:
    string largestOddNumber(string num) {
        for(int i = num.size() - 1; i >= 0; i--)
            if(num[i]%2 == 1) return num.substr(0, i + 1);
        return "";
    }
};

---------------------------------------------------------------------------------------------------------------------------------------------

3. https://leetcode.com/problems/minimum-cost-of-buying-candies-with-discount
Solution : 
class Solution {
public:
    int minimumCost(vector<int>& cost) {
        int ans = 0;

        if(cost.size() < 3) return accumulate(cost.begin(), cost.end(), 0);
        sort(cost.begin(), cost.end());
        reverse(cost.begin(), cost.end());
        for(int i = 0; i < cost.size(); i++){
            if((i + 1) % 3 == 0) continue;
            ans += cost[i];
        }

        return ans;
    }
};