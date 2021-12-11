/*
A positive integer is magical if it is divisible by either a or b.

Given the three integers n, a, and b, return the nth magical number. Since the answer may be very large, return it modulo 109 + 7.

 
*/

class Solution {
public:
    int nthMagicalNumber(long long n, long long a, long long b) {
        long long low = min(a, b);
        long long high = n*min(a, b);
        long long mod = 1e9+7;
        long long ans=0;
        
        while(low<=high)
        {
            long long mid = (high-low)/2LL + low;
            int cnt = magicLessThanOrEqual(mid, a, b);
            if(cnt<n)
            {
                low=mid+1;
            }
            else
            {
                high=mid-1;
                ans=mid;
            }
        }
        
        return ans%mod;
    }
    
    int magicLessThanOrEqual(long long mid, long long a, long long b)
    {
        long long lcm = (a*b)/__gcd(a, b);
        
        return mid/a+mid/b-mid/lcm;
    }
};
