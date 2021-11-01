/*
Given an integer array arr. You have to sort the integers in the array in ascending order by the number of 1's in their binary representation and in case of two or more integers have the same number of 1's you have to sort them in ascending order.

Return the sorted array.
*/

class Solution {
public:
    
    struct Num
    {
        int x;
        int ones=0;
    };
    
    vector<int> sortByBits(vector<int>& arr) {
        int n = arr.size();
        Num nums[n];
        for(int i=0; i<n; i++)
        {
            int curr = arr[i];
            int cnt=0;
            for(int j=0; j<32; j++)
            {
                int b = (1<<j)&curr;
                if(b!=0)
                {
                    cnt++;
                }
            }
            Num tmp;
            tmp.x = curr;
            tmp.ones = cnt;
            nums[i] = tmp;
        }
        
        sort(nums, nums+n, comp);
        
        for(int i=0; i<n; i++)
        {
            arr[i] = nums[i].x;
        }
        
        return arr;
    }
    
    static bool comp(Num a, Num b)
    {
        if(a.ones<b.ones)
        {
            return true;
        }
        else if(a.ones==b.ones)
        {
            return a.x < b.x;
        }
        else
        {
            return false;
        }
    }
};
