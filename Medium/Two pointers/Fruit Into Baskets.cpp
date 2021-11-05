/*
You are visiting a farm that has a single row of fruit trees arranged from left to right. The trees are represented by an integer array fruits where fruits[i] is the type of fruit the ith tree produces.

You want to collect as much fruit as possible. However, the owner has some strict rules that you must follow:

You only have two baskets, and each basket can only hold a single type of fruit. There is no limit on the amount of fruit each basket can hold.
Starting from any tree of your choice, you must pick exactly one fruit from every tree (including the start tree) while moving to the right. The picked fruits must fit in one of your baskets.
Once you reach a tree with fruit that cannot fit in your baskets, you must stop.
Given the integer array fruits, return the maximum number of fruits you can pick.
*/

class Solution {
public:
    int totalFruit(vector<int>& nums) {
        int ans = 0;
        int a=-1;
        int b=-1;
        int cnt_a=0;
        int cnt_b=0;
        int i=0;
        int j=0;
        int n = nums.size();
        while(j<n)
        {
            if(a==-1)
            {
                if(nums[j]!=b)
                {
                    a=nums[j];
                    cnt_a++;
                }
                else
                {
                    cnt_b++;
                }
            }
            else if(b==-1)
            {
                if(nums[j]!=a)
                {
                    b=nums[j];
                    cnt_b++;
                }
                else
                {
                    cnt_a++;
                }
            }
            else
            {
                if(nums[j]==a)
                {
                    cnt_a++;
                }
                else if(nums[j]==b)
                {
                    cnt_b++;
                }
                else
                {
                    ans = max(ans, cnt_a+cnt_b);
                    while(i<j && cnt_a>0 && cnt_b>0)
                    {
                        if(nums[i]==a)
                        {
                            cnt_a--;
                        }
                        if(nums[i]==b)
                        {
                            cnt_b--;
                        }
                        i++;
                    }
                    if(cnt_a==0)
                    {
                        swap(a, b);
                        swap(cnt_a, cnt_b);
                    }                    
                    b=nums[j];
                    cnt_b++;
                }
            }
            j++;
        }
        
        ans = max(ans, cnt_a+cnt_b);
        
        return ans;
    }
};
