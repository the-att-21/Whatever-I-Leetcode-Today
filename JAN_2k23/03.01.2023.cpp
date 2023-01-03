1. https://leetcode.com/problems/delete-columns-to-make-sorted
Solution :
 * C++ Solution :
    class Solution {
    public:
        int minDeletionSize(vector<string>& strs) {
            int rows = strs.size();
            int cols = strs[0].size();
            int ans = 0;
        
            for(int j = 0; j < cols; j++){
                for(int i = 0; i < rows - 1; i++){
                    if(strs[i][j] > strs[i+1][j]){
                        ans++;
                        break;
                    }
                }
            }

            return ans;
        }
    };


 * JAVA Solution : 
    class Solution {
        public int minDeletionSize(String[] strs) {
            int rows = strs.length;
            int cols = strs[0].length();
            int ans = 0;

            for(int j = 0; j < cols; j++){
                for(int i = 0; i < rows - 1; i++){
                    if(strs[i].charAt(j) > strs[i+1].charAt(j)){
                        ans++;
                        break;
                    }
                }
            }

            return ans;
        }
    }