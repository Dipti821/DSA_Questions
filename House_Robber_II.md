## Problem Statement:

Mr. X is a professional robber planning to rob houses along a street. Each house has a certain amount of money hidden. All houses along this street are arranged in a
circle. That means the first house is the neighbor of the last one. Meanwhile, adjacent houses have a security system connected, and it will automatically contact the
police if two adjacent houses were broken into on the same night.
You are given an array/list of non-negative integers 'ARR' representing the amount of money of each house. Your task is to return the maximum amount of money Mr. X can
rob tonight without alerting the police.


## Code:

~~~~~
/*
    Time Complexity: O(N)
    Space complexity: O(N)
    
    where 'N' is the length of array.
*/

long long int houseRobberUtil(vector<int> valueInHouse, int start, int end)
{

    long long int valueAtIthHouse[valueInHouse.size()];

    // Check if the thief may steal the first house or not.
    if (start == 0)
    {
        valueAtIthHouse[0] = valueInHouse[0];
        valueAtIthHouse[1] = max(valueInHouse[0], valueInHouse[1]);
    }

    else
    {
        valueAtIthHouse[0] = 0;
        valueAtIthHouse[1] = valueInHouse[1];
    }

    for (int i = 2; i < end; i++)
    {
        valueAtIthHouse[i] = max(valueAtIthHouse[i - 2] + valueInHouse[i], valueAtIthHouse[i - 1]);
    }

    return valueAtIthHouse[end - 1];
}

long long int houseRobber(vector<int>& valueInHouse)
{

    if (valueInHouse.size() == 0)
    {
        return 0;
    }

    if (valueInHouse.size() == 1)
    {
        return valueInHouse[0];
    }

    return max(houseRobberUtil(valueInHouse, 0, valueInHouse.size() - 1), houseRobberUtil(valueInHouse, 1, valueInHouse.size()));
}

~~~~~

## Note: 
You can do further space optimisation.
