## Problem Statement:

You’re given a stack consisting of 'N' integers. Your task is to sort this stack in descending order using recursion.
We can only use the following functions on this stack S.


## Code:

~~~~~

/*
    Time Complexity: O(N^2)
    Space Complexity: O(N),

    where N is the number of elements in the stack.
*/

void sortedInsert(stack<int> &stack, int current)
{
	if (stack.empty() || current > stack.top())
	{
		stack.push(current);
		return;
	}

	// Remove the top element
	int top = stack.top();
	stack.pop();
	// Recursion for the remaining elements in the stack
	sortedInsert(stack, current);
	// Insert the popped element back in the stack
	stack.push(top);
}

// Recursive method to sort a stack
void sortStack(stack<int> &stack)
{
	// Base case: stack is empty
	if (stack.empty())
	{
		return;
	}

	// Remove the top element
	int top = stack.top();
	stack.pop();
	// Recursion for the remaining elements in the stack
	sortStack(stack);
	// Insert the popped element back in the sorted stack
	sortedInsert(stack, top);
}

~~~~~

## Reference:
- [Codestudio](https://www.codingninjas.com/codestudio/problems/sort-a-stack_985275?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website&leftPanelTab=2)
