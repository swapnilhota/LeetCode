/*
Given a string s, return true if s is a good string, or false otherwise.

A string s is good if all the characters that appear in s have the same number of occurrences (i.e., the same frequency).
*/

class Solution {
public:
    bool areOccurrencesEqual(string s) {
        
        map<char, int> mp;
        
        for(char c: s)
        {
            mp[c]++;
        }
        
        int minCnt=INT_MAX;
        int maxCnt=INT_MIN;
        
        for(auto i: mp)
        {
            minCnt = min(minCnt, i.second);
            maxCnt = max(maxCnt, i.second);
        }
        
        if(minCnt==maxCnt)
        {
            return true;
        }
        
        return false;
        
    }
};
