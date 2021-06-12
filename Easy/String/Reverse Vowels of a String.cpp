/*
Given a string s, reverse only all the vowels in the string and return it.

The vowels are 'a', 'e', 'i', 'o', and 'u', and they can appear in both cases.
*/

class Solution {
public:
    string reverseVowels(string s) {
        
        vector<int> indices;
        
        for(int i=0; i<s.length(); i++)
        {
            if(check(s[i]))
            {
                indices.push_back(i);
            }
        }
        
        int i=0;
        int j=indices.size()-1;
        
        while(i<j)
        {
            swap(s[indices[i]], s[indices[j]]);
            i++;
            j--;
        }
        
        return s;
        
    }
    
    bool check(char c)
    {
        c = tolower(c);
        if(c=='a' || c=='e' || c=='i' || c=='o' || c=='u')
        {
            return true;
        }
        
        return false;
    }
};
