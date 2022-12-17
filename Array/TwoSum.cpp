/*

1st Approach:  [1,4,2,9,5] target: 11

Traverse through the array by taking start element and check the adjacent one is equal
to target or not.

Step1: In one scan we will take 1 and check with each element that it is equal to target or not,
then if not found move i and j and check again . T.C will be O(n*n)

2nd Approach:

(2 pointer approach)
First sort the array with their corresponding indices in pair and store it in hashmap

so the item willl be: {(1,0),(2,2),(4,1),(5,4),(9,3)}

then take the i form start and j from the last, and check 

step1: 1+9 != target,since the array is sorted and target is greater than the actual sum
    so we have to maximize the next element so will move i and fix the j as it is
    the 2+9 == 11 so now retuen the indices (2,3)

    T.C = O(nlogn) + O(n) + O(n) = O(nlogn)
        sorting the array+ storing the array in hashmap + traversing the array once


3rd Approach: 

    create hashmap assuming it is taking constant time

    take 1st element and perform target - the element and check if it is present in hashmap
    if present then return the indices of element and that hashmap element indices

    else store the value in hashmap

*/


class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> new_map;

        for(int i=0;i<nums.size();++i){
            if(new_map.count(target-nums[i])){
                return {i,new_map[target-nums[i]]};
            }
            new_map[nums[i]] = i;
        }
        return {};
    }
};