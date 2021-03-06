/*
A teacher is writing a test with n true/false questions, with 'T' denoting true and 'F' denoting false. He wants to confuse the students by maximizing the number of consecutive questions with the same answer (multiple trues or multiple falses in a row).

You are given a string answerKey, where answerKey[i] is the original answer to the ith question. In addition, you are given an integer k, the maximum number of times you may perform the following operation:

Change the answer key for any question to 'T' or 'F' (i.e., set answerKey[i] to 'T' or 'F').
Return the maximum number of consecutive 'T's or 'F's in the answer key after performing the operation at most k times.
*/

class Solution {
public:
    int maxConsecutiveAnswers(string answerKey, int k) {
        int n = answerKey.length();
        int i=0;
        int j=0;
        int cntT=0;
        int cntF=0;
        int ans=0;
        while(i<n && j<n)
        {
            if(answerKey[j]=='T')
            {
                cntT++;
            }
            else
            {
                cntF++;
            }
            if(cntT>k && cntF>k)
            {
                while(cntT>k && cntF>k)
                {
                    if(answerKey[i]=='T')
                    {
                        cntT--;
                    }
                    else
                    {
                        cntF--;
                    }
                    i++;
                }
                ans=max(ans, j-i+1);
                j++;
            }
            else
            {
                ans = max(ans, j-i+1);
                j++;
            }
        }
        ans=max(ans, j-i);
        return ans;
    }
};
