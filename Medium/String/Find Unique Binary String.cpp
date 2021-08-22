/*
Given an array of strings nums containing n unique binary strings each of length n, return a binary string of length n that does not appear in nums. If there are multiple answers, you may return any of them.

 

Example 1:

Input: nums = ["01","10"]
Output: "11"
Explanation: "11" does not appear in nums. "00" would also be correct.
Example 2:

Input: nums = ["00","01"]
Output: "11"
Explanation: "11" does not appear in nums. "10" would also be correct.
Example 3:

Input: nums = ["111","011","001"]
Output: "101"
Explanation: "101" does not appear in nums. "000", "010", "100", and "110" would also be correct.
 

Constraints:

n == nums.length
1 <= n <= 16
nums[i].length == n
nums[i] is either '0' or '1'.
*/

class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums) {
        vector<int> v;
        for(auto s: nums)
        {
            v.push_back(convert(s));
        }
        map<int, int> mp;
        for(auto i: v)
        {
            cout<<i<<endl;
            mp[i]++;
        }
        int n = nums.size();
        int ans = -1;
        for(int i=0; i<(1<<n); i++)
        {
            if(mp.find(i)==mp.end())
            {
                ans = i;
            }
        }
        string res = convertToString(ans, n);
        return res;
    }
    string convertToString(int ans, int n)
    {
        cout<<ans<<endl;
        string res="";
        for(int i=0; i<32; i++)
        {
            if((1<<i)>ans)
            {
                break;
            }
            int b = (1<<i)&ans;
            if(b!=0)
            {
                res = '1' + res;
            }
            else
            {
                res = '0' + res;
            }
        }
        
        int len = res.size();
        while(len<n)
        {
            res = '0' + res;
            len++;
        }
        return res;
    }
    int convert(string s)
    {
        int n = s.length()-1;
        int res=0;
        for(int i=n; i>=0; i--)
        {
            if(s[i]=='1')
            {
                res += (1<<(n-i));
            }
        }
        return res;
    }
};
