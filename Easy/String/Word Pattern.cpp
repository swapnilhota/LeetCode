/*
Given a pattern and a string s, find if s follows the same pattern.

Here follow means a full match, such that there is a bijection between a letter in pattern and a non-empty word in s.

 

Example 1:

Input: pattern = "abba", s = "dog cat cat dog"
Output: true
Example 2:

Input: pattern = "abba", s = "dog cat cat fish"
Output: false
Example 3:

Input: pattern = "aaaa", s = "dog cat cat dog"
Output: false
Example 4:

Input: pattern = "abba", s = "dog dog dog dog"
Output: false
 

Constraints:

1 <= pattern.length <= 300
pattern contains only lower-case English letters.
1 <= s.length <= 3000
s contains only lower-case English letters and spaces ' '.
s does not contain any leading or trailing spaces.
All the words in s are separated by a single space.
*/

class Solution {
public:
    bool wordPattern(string pattern, string s) {
        
        map<char, string> chr;
        map<string, char> word;
        
        vector<string> words;
        
        string temp="";
        
        for(auto c: s)
        {
            if(c==' ')
            {
                if(temp!="")
                {
                    words.push_back(temp);
                }
                temp="";
            }
            else
            {
                temp += c;
            }
        }
        
        if(temp!="")
        {
            words.push_back(temp);
        }
        
        if(pattern.length()!=words.size())
        {
            return false;
        }
        
        
        
        for(int i=0; i<pattern.length(); i++)
        {
            char ch = pattern[i];
            string curr = words[i];
            
            if(chr.find(ch)==chr.end() && word.find(curr)==word.end())
            {
                chr[pattern[i]] = words[i];
                word[words[i]] = pattern[i];
            }
            else if(chr.find(ch)!=chr.end() && word.find(curr)!=word.end())
            {
                if(chr[ch]!=curr)
                {
                    return false;
                }
            }
            else if(chr.find(ch)!=chr.end())
            {
                if(chr[ch]!=curr)
                {
                    return false;
                }
            }
            else if(word.find(curr)!=word.end())
            {
                if(word[curr]!=ch)
                {
                    return false;
                }
            }
        }
        
        return true;
        
    }
};
