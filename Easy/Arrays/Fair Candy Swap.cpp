/*
Alice and Bob have a different total number of candies. You are given two integer arrays aliceSizes and bobSizes where aliceSizes[i] is the number of candies of the ith box of candy that Alice has and bobSizes[j] is the number of candies of the jth box of candy that Bob has.

Since they are friends, they would like to exchange one candy box each so that after the exchange, they both have the same total amount of candy. The total amount of candy a person has is the sum of the number of candies in each box they have.

Return an integer array answer where answer[0] is the number of candies in the box that Alice must exchange, and answer[1] is the number of candies in the box that Bob must exchange. If there are multiple answers, you may return any one of them. It is guaranteed that at least one answer exists.

 

Example 1:

Input: aliceSizes = [1,1], bobSizes = [2,2]
Output: [1,2]
Example 2:

Input: aliceSizes = [1,2], bobSizes = [2,3]
Output: [1,2]
Example 3:

Input: aliceSizes = [2], bobSizes = [1,3]
Output: [2,3]
Example 4:

Input: aliceSizes = [1,2,5], bobSizes = [2,4]
Output: [5,4]
 

Constraints:

1 <= aliceSizes.length, bobSizes.length <= 104
1 <= aliceSizes[i], bobSizes[j] <= 105
Alice and Bob have a different total number of candies.
There will be at least one valid answer for the given input.
*/

class Solution {
public:
    vector<int> fairCandySwap(vector<int>& aliceSizes, vector<int>& bobSizes) {
        sort(aliceSizes.begin(), aliceSizes.end());
        sort(bobSizes.begin(), bobSizes.end());
        int aliceSum=0, bobSum=0;
        for(auto c: aliceSizes)
        {
            aliceSum += c;
        }
        for(auto c: bobSizes)
        {
            bobSum += c;
        }
        vector<int> ans;
        int target = (aliceSum+bobSum)/2;
        if(aliceSum>bobSum)
        {
            for(auto c: bobSizes)
            {
                int req = c+(target-bobSum);
                auto itr = lower_bound(aliceSizes.begin(), aliceSizes.end(), req);
                if(itr!=aliceSizes.end())
                {
                    if(*itr == req)
                    {
                        ans.push_back(*itr);
                        ans.push_back(c);
                        return ans;
                    }
                }
            }
        }
        else
        {
            for(auto c: aliceSizes)
            {
                int req = c+(target-aliceSum);
                auto itr = lower_bound(bobSizes.begin(), bobSizes.end(), req);
                if(itr!=bobSizes.end())
                {
                    if(*itr == req)
                    {
                        ans.push_back(c);
                        ans.push_back(*itr);
                        return ans;
                    }
                }
            }
        }
        return ans;
    }
};
