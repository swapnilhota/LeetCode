/*
Suppose Andy and Doris want to choose a restaurant for dinner, and they both have a list of favorite restaurants represented by strings.

You need to help them find out their common interest with the least list index sum. If there is a choice tie between answers, output all of them with no order requirement. You could assume there always exists an answer.

 

Example 1:

Input: list1 = ["Shogun","Tapioca Express","Burger King","KFC"], list2 = ["Piatti","The Grill at Torrey Pines","Hungry Hunter Steakhouse","Shogun"]
Output: ["Shogun"]
Explanation: The only restaurant they both like is "Shogun".
Example 2:

Input: list1 = ["Shogun","Tapioca Express","Burger King","KFC"], list2 = ["KFC","Shogun","Burger King"]
Output: ["Shogun"]
Explanation: The restaurant they both like and have the least index sum is "Shogun" with index sum 1 (0+1).
Example 3:

Input: list1 = ["Shogun","Tapioca Express","Burger King","KFC"], list2 = ["KFC","Burger King","Tapioca Express","Shogun"]
Output: ["KFC","Burger King","Tapioca Express","Shogun"]
Example 4:

Input: list1 = ["Shogun","Tapioca Express","Burger King","KFC"], list2 = ["KNN","KFC","Burger King","Tapioca Express","Shogun"]
Output: ["KFC","Burger King","Tapioca Express","Shogun"]
Example 5:

Input: list1 = ["KFC"], list2 = ["KFC"]
Output: ["KFC"]
 

Constraints:

1 <= list1.length, list2.length <= 1000
1 <= list1[i].length, list2[i].length <= 30
list1[i] and list2[i] consist of spaces ' ' and English letters.
All the stings of list1 are unique.
All the stings of list2 are unique.
*/

class Solution {
public:
    vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
        
        unordered_map<string, int> mp;
        for(int i=0; i<list1.size(); i++)
        {
            for(int j=0; j<list2.size(); j++)
            {
                if(list1[i]==list2[j])
                {
                    mp[list1[i]] = (i+1)+(j+1);
                }
            }
        }
        
        vector<string> ans;
        
        int minSum = INT_MAX;
        
        for(auto i: mp)
        {
            minSum = min(minSum, i.second);
        }
        
        for(auto i: mp)
        {
            if(i.second==minSum)
            {
                ans.push_back(i.first);
            }
        }
        
        return ans;
        
    }
};
