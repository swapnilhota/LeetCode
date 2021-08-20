/*
You are keeping score for a baseball game with strange rules. The game consists of several rounds, where the scores of past rounds may affect future rounds' scores.

At the beginning of the game, you start with an empty record. You are given a list of strings ops, where ops[i] is the ith operation you must apply to the record and is one of the following:

An integer x - Record a new score of x.
"+" - Record a new score that is the sum of the previous two scores. It is guaranteed there will always be two previous scores.
"D" - Record a new score that is double the previous score. It is guaranteed there will always be a previous score.
"C" - Invalidate the previous score, removing it from the record. It is guaranteed there will always be a previous score.
Return the sum of all the scores on the record.
*/

class Solution {
public:
    int calPoints(vector<string>& ops) {
        stack<int> pts;
        int i=0;
        for(auto s: ops)
        {
            if(s=="+")
            {
                int x = pts.top(); pts.pop();
                int y = pts.top(); pts.pop();
                pts.push(y);
                pts.push(x);
                pts.push(x+y);
            }
            else if(s=="D")
            {
                int x = pts.top();
                pts.push(2*x);
            }
            else if(s=="C")
            {
                pts.pop();
            }
            else
            {
                pts.push(stoi(s));
            }
        }
        
        int sum=0;
        while(!pts.empty())
        {
            sum += pts.top(); pts.pop();
        }
        
        return sum;
    }
};
