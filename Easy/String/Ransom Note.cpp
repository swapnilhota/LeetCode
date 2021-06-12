/*
Given two stings ransomNote and magazine, return true if ransomNote can be constructed from magazine and false otherwise.

Each letter in magazine can only be used once in ransomNote.
*/

class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        
        if(ransomNote.length()>magazine.length())
        {
            return false;
        }
        
        map<char, int> ran;
        map<char, int> mag;
        
        for(char c: ransomNote)
        {
            ran[c]++;
        }
        
        for(char c: magazine)
        {
            mag[c]++;
        }
        
        for(auto i : ran)
        {
            if(i.second > mag[i.first])
            {
                return false;
            }
        }
        
        return true;
        
    }
};
