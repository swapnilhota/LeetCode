/*
You are given a string sentence that consist of words separated by spaces. Each word consists of lowercase and uppercase letters only.

We would like to convert the sentence to "Goat Latin" (a made-up language similar to Pig Latin.) The rules of Goat Latin are as follows:

If a word begins with a vowel ('a', 'e', 'i', 'o', or 'u'), append "ma" to the end of the word.
For example, the word "apple" becomes "applema".
If a word begins with a consonant (i.e., not a vowel), remove the first letter and append it to the end, then add "ma".
For example, the word "goat" becomes "oatgma".
Add one letter 'a' to the end of each word per its word index in the sentence, starting with 1.
For example, the first word gets "a" added to the end, the second word gets "aa" added to the end, and so on.
Return the final sentence representing the conversion from sentence to Goat Latin.

 

Example 1:

Input: sentence = "I speak Goat Latin"
Output: "Imaa peaksmaaa oatGmaaaa atinLmaaaaa"
Example 2:

Input: sentence = "The quick brown fox jumped over the lazy dog"
Output: "heTmaa uickqmaaa rownbmaaaa oxfmaaaaa umpedjmaaaaaa overmaaaaaaa hetmaaaaaaaa azylmaaaaaaaaa ogdmaaaaaaaaaa"
 

Constraints:

1 <= sentence.length <= 150
sentence consists of English letters and spaces.
sentence has no leading or trailing spaces.
All the words in sentence are separated by a single space.
*/

class Solution {
public:
    string toGoatLatin(string sentence) {
        vector<string> words;
        string tmp="";
        for(auto c: sentence)
        {
            if(c==' ')
            {
                if(tmp!="")
                {
                    words.push_back(tmp);
                    tmp="";
                }
            }
            else
            {
                tmp+=c;
            }
        }
        if(tmp!="")
        {
            words.push_back(tmp);
        }
        
        for(int i=0; i<words.size(); i++)
        {
            if(checkVowel(words[i][0]))
            {
                words[i] += "ma";
            }
            else
            {
                words[i] += words[i][0];
                words[i] = words[i].substr(1);
                words[i] += "ma";
            }
        }
        
        for(int i=0; i<words.size(); i++)
        {
            int j=i+1;
            while(j>0)
            {
                words[i] += 'a';
                j--;
            }
        }
        
        string ans="";
        for(int i=0; i<words.size()-1; i++)
        {
            ans += words[i] + " ";
        }
        ans += words[words.size()-1];
        
        return ans;
    }
    
    bool checkVowel(char c)
    {
        c = tolower(c);
        if(c=='a' || c=='e' || c=='i' || c=='o' || c=='u') return true;
        return false;
    }
};
