## Problem Statement:

There are ‘N’ people at a party. Each person has been assigned a unique id between 0 to 'N' - 1(both inclusive). A celebrity is a person who is known to everyone but does not know anyone at the party.
Given a helper function ‘knows(A, B)’, It will returns "true" if the person having id ‘A’ know the person having id ‘B’ in the party, "false" otherwise. Your task is to find out the celebrity at the party. Print the id of the celebrity, if there is no celebrity at the party then print -1.
Note:
- The helper function ‘knows’ is already implemented for you.
- ‘knows(A, B)’ returns "false", if A doesn't know B.
- You should not implement helper function ‘knows’, or speculate about its implementation.
- You should minimize the number of calls to function ‘knows(A, B)’.
- There are at least 2 people at the party.
- At most one celebrity will exist.

## Code:

~~~~~~

/*
    Time complexity: O(N)
    Space complexity: O(N)
    
    Where 'N' is the number of people at the party.
*/

#include <stack>

int findCelebrity(int n) {

    // Create a stack and push all ids in it.
    stack<int> ids;
    for(int i = 0; i < n; i++) {
        ids.push(i);
    }

    // Finding celebrity.
    while(ids.size() > 1) {
        int id1 = ids.top();
        ids.pop();
        int id2 = ids.top();
        ids.pop();
        
        if(knows(id1, id2)) {
            // Because person with id1 can not be celebrity. 
            ids.push(id2); 
        }
        else {
            // Because person with id2 can not be celebrity.
            ids.push(id1); 
        }
    }

    int celebrity = ids.top();
    bool knowAny = false, knownToAll = true;

    // Verify whether the celebrity knows any other person.
    for(int i = 0; i < n; i++) {
        if(i != celebrity && knows(celebrity, i)) {
            knowAny = true;
            break;
        }
    }

    // Verify whether the celebrity is known to all the other person.
    for(int i = 0; i < n; i++) {
        if(i != celebrity and !knows(i, celebrity)) {
            knownToAll = false;
            break;
        }
    }

    if(knowAny or !knownToAll) {
        // If verificatin failed, then it means there is no celebrity at the party.
        celebrity = -1;
    }

    return celebrity;
}
~~~~~~ 
## Reference:
- [Codestudio](https://www.codingninjas.com/codestudio/problems/the-celebrity-problem_982769?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website&leftPanelTab=0)


