//Aaj apun JAVA Karega!

1. https://leetcode.com/problems/detect-capital/description/
Solution : 
class Solution {
    public boolean detectCapitalUse(String word) {
        int n = word.length();
        String first = word.substring(0, 1);
        String shabdha = word.substring(1, n);
        
        if(word == word.toUpperCase()) return true;
        if(word == word.toLowerCase()) return true;
        if(first == first.toUpperCase() && shabdha == shabdha.toLowerCase()) return true;
        return false;
    }
}