/*
Count the number of prime numbers less than a non-negative number, n.
*/

class Solution {
public:
    int countPrimes(int n) {
        
        bool* prime = new bool[n]();
        for(int i=2; i*i<=n; i++)
        {
            for(int j=i*i; j<n; j+=i)
            {
                prime[j]=true;
            }
        }
        int cnt=0;
        
        for(int i=2; i<n; i++)
        {
            if(!prime[i])
            {
                cnt++;
            }
        }
        
        return cnt;
    }
};
