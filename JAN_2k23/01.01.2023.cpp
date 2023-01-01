//Happy New Year
//First Time 4/4✅
1. https://leetcode.com/contest/weekly-contest-326/problems/count-the-digits-that-divide-a-number/
Solution :
class Solution {
public:
    int countDigits(int num) {
        vector<int> digits;
        int n = num, r;
        while(num > 0){
            r = num % 10;
            digits.push_back(r);
            num /= 10;
        }
        int ans = digits.size();
        for(auto &i : digits){
            if(n % i != 0) ans--;
        }
        return ans;
    }
};

---------------------------------------------------------------------------------------------------------------------------------

2. https://leetcode.com/contest/weekly-contest-326/problems/distinct-prime-factors-of-product-of-array/
Solution :
class Solution {
public:
    set<int> ans;
    void findPrimeF(int n)
    {
        while(n % 2 == 0){
            ans.insert(2);
            n /= 2;
        }
        
        for(int i = 3; i <= sqrt(n); i = i + 2)
        {
            while(n % i == 0){
                ans.insert(i);
                n /= i;
            }
        }
        
        if(n > 2) ans.insert(n);
    }
    int distinctPrimeFactors(vector<int>& nums) {
        for(auto &i : nums){
            findPrimeF(i);
        }
        return ans.size();
    }
};

---------------------------------------------------------------------------------------------------------------------------------

3. https://leetcode.com/contest/weekly-contest-326/problems/partition-string-into-substrings-with-values-at-most-k/
Solution :
class Solution {
public:
    int minimumPartition(string s, int k) {
        int n = s.size();
        string sub = "";
        int ans = 0;
        
        for(int i = 0; i < n; i++){
            string t;
            t.push_back(s[i]);
            long long flag = stol(t);
            if(flag > k) return -1;
            
            sub.push_back(s[i]);
            long long temp = stol(sub);
            if(temp > k)
            {
                ans++; i--;
                sub = "";
            }
        }
        return ans + 1;
    }
};

---------------------------------------------------------------------------------------------------------------------------------

4. https://leetcode.com/contest/weekly-contest-326/problems/closest-prime-numbers-in-range/
Solution : 
class Solution {
public:
    vector<int> primes;
    void helpMe(vector<int>& prime, int high)
    {
        bool ck[high + 1];
        memset(ck, true, sizeof(ck));
        ck[1] = false;
        ck[0] = false;
        for (int i = 2; (i * i) <= high; i++) {
            if (ck[i] == true) {
                for (int j = i * i; j <= sqrt(high); j = j + i) {
                    ck[j] = false;
                }
            }
        }
        for (int i = 2; i * i <= high; i++) {
            if (ck[i] == true) {
                prime.push_back(i);
            }
        }
    }
    
    void findPrimes(int low, int high)
    {
        if (low<2 and high>=2){
            low = 2;
        }
        bool prime[high - low + 1];
        memset(prime, true, sizeof(prime));
 
        vector<int> chprime;
        helpMe(chprime, high);
        for (int i : chprime) {
            int lower = (low / i);
            if (lower <= 1) {
                lower = i + i;
            }
            else if (low % i) {
                lower = (lower * i) + i;
            }
            else {
                lower = (lower * i);
            }
            for (int j = lower; j <= high; j = j + i) {
                prime[j - low] = false;
            }
        }
   
        for (int i = low; i <= high; i++) {
            if (prime[i - low] == true) {
                primes.push_back(i);
            }
        }
    }
    vector<int> closestPrimes(int left, int right) {
        findPrimes(left, right);
        int n = primes.size();
        vector<int> res;
        
        if(n < 2){
            res.push_back(-1);
            res.push_back(-1);
            return res;
        }
        int mini = INT_MAX, c1, c2;
        
        for(int i = 0; i < n - 1; i++){
            int temp = primes[i + 1] - primes[i];
            if(mini > temp){
                mini = temp;
                c1 = i;
                c2 = i + 1;
            }
        }
        
        res.push_back(primes[c1]);
        res.push_back(primes[c2]);
        return res;
    }
};

---------------------------------------------------------------------------------------------------------------------------------

5. https://leetcode.com/problems/word-pattern/description/
Solution : 
class Solution {
public:
    bool wordPattern(string pattern, string s) {
        int n=pattern.size();
        stringstream str(s);
        string word;
        vector<string> words;
        while(str>>word){
            words.push_back(word);
        }
        if(pattern.size()!=words.size()){
            return false;
        }
        map<char,string> charToString;
        map<string,char> stringToChar;
        for(int i=0;i<n;i++){
        if(charToString.find(pattern[i])==charToString.end()&&
            stringToChar.find(words[i])==stringToChar.end()){
                charToString[pattern[i]]=words[i];
                stringToChar[words[i]]=pattern[i];
            }
            else if(charToString[pattern[i]]!=words[i]){
                return false;
            }
        }
        return true;
    }
};