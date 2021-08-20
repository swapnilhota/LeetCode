/*
You have a data structure of employee information, which includes the employee's unique id, their importance value, and their direct subordinates' id.

You are given an array of employees employees where:

employees[i].id is the ID of the ith employee.
employees[i].importance is the importance value of the ith employee.
employees[i].subordinates is a list of the IDs of the subordinates of the ith employee.
Given an integer id that represents the ID of an employee, return the total importance value of this employee and all their subordinates.

 

Example 1:


Input: employees = [[1,5,[2,3]],[2,3,[]],[3,3,[]]], id = 1
Output: 11
Explanation: Employee 1 has importance value 5, and he has two direct subordinates: employee 2 and employee 3.
They both have importance value 3.
So the total importance value of employee 1 is 5 + 3 + 3 = 11.
Example 2:


Input: employees = [[1,2,[5]],[5,-3,[]]], id = 5
Output: -3
 

Constraints:

1 <= employees.length <= 2000
1 <= employees[i].id <= 2000
All employees[i].id are unique.
-100 <= employees[i].importance <= 100
One employee has at most one direct leader and may have several subordinates.
id is guaranteed to be a valid employee id.
*/

/*
// Definition for Employee.
class Employee {
public:
    int id;
    int importance;
    vector<int> subordinates;
};
*/

class Solution {
public:
    int getImportance(vector<Employee*> employees, int id) {
        int ans=0;
        unordered_map<int, int> mp;
        unordered_map<int, vector<int>> mpSub;
        for(auto e: employees)
        {
            mp[e->id] = e->importance;
            mpSub[e->id] = e->subordinates;
        }
        
        queue<int> q;
        
        for(auto e: employees)
        {
            if(e->id==id)
            {
                q.push(e->id);
                break;
            }
        }
        
        while(!q.empty())
        {
            int curr_id = q.front();
            q.pop();
            ans += mp[curr_id];
            for(auto i: mpSub[curr_id])
            {
                q.push(i);
            }
        }
        
        return ans;
    }
};
