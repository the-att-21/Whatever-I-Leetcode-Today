1. https://leetcode.com/contest/weekly-contest-327/problems/maximum-count-of-positive-integer-and-negative-integer/
Solution :
class Solution {
public:
    int maximumCount(vector<int>& nums) {
        int neg = 0, pos = 0;
        
        for(auto &i : nums){
            if(i < 0) { neg++; }
            if(i > 0) { pos++; }
        }
        
        return max(neg, pos);
    }
};

-------------------------------------------------------------------------------------------------------------------------------------------

2. https://leetcode.com/contest/weekly-contest-327/problems/maximal-score-after-applying-k-operations/
Solution :
class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
        priority_queue<int> pq;
        long long ans = 0;
        
        for(auto &i : nums){
            pq.push(i);
        }

        for(int i = 0; i < k; i++){
            long long temp = pq.top();
            ans += temp;
            temp = ceil(temp / 3.0000000000);
            pq.pop();
            pq.push(temp);
        }
        
        return ans;
    }
};

-------------------------------------------------------------------------------------------------------------------------------------------

3. https://leetcode.com/problems/max-points-on-a-line/description/
Solution : 
class point {
public:
    double x, y;
    point(double a, double b){
        this -> x = a;
        this -> y = b;
    }
};

class Solution {
public:
    bool isCollinear(point a, point b, point c){
        double m1 = (a.y - b.y)/(a.x - b.x);
        double m2 = (a.y - c.y)/(a.x - c.x);

        return m1 == m2;
    }
    
    int maxPoints(vector<vector<int>>& p) {
        int n = p.size(), ans = 0;
        if(n <= 2) { return n; }

        vector<point> coords;
        for(int i = 0; i < p.size(); i++){
            point m = point((double)p[i][0], (double)p[i][1]);
            coords.push_back(m);
        }

        for(int i = 0; i < coords.size(); i++){
            for(int j = 0; j < coords.size(); j++){
                int cnt = 0;
                for(int k = 0; k < coords.size(); k++){
                    if(i!=j  and j!=k and k!=i){
                        if(isCollinear(coords[i], coords[j], coords[k])) { cnt++; }
                    }
                }
                ans = max(cnt + 2, ans);
            }
        }

        return ans;
    }
};

-------------------------------------------------------------------------------------------------------------------------------------------

4. https://leetcode.com/problems/minimum-lines-to-represent-a-line-chart/description/
Solution : 
class Solution {
public:
    int minimumLines(vector<vector<int>>& sp) {
        sort(sp.begin(), sp.end());
        int n = sp.size(), ans = 1;
        if(n == 1) { return 0; }
        for(int i = 0; i < n - 2; i++){
            long dy = (long)sp[i][1] - (long)sp[i + 1][1];
            long dx = (long)sp[i][0] - (long)sp[i + 1][0];

            long dy_ = (long)sp[i + 1][1] - (long)sp[i + 2][1];
            long dx_ = (long)sp[i + 1][0] - (long)sp[i + 2][0];

            if(dy * dx_ != dy_ * dx) { ans++; }
        }

        return ans;
    }
};