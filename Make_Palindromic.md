## Minimum Characters required to make a String Palindromic

Given an string A. The only operation allowed is to insert  characters in the beginning of the string.

Find how many minimum characters are needed to be inserted to make the string a palindrome string.



## Code:
  
  ~~~~~~
  

/*
    Time complexity: O(N)
    Space complexity: O(N)
    
    Where N is length of the string.    
*/

vector<int> calculateLPSArray(string str)
{
    int m = str.length();
    vector<int> lps(m);

    int len = 0;

    // As, lps[0] is always 0
    lps[0] = 0;

    // The loop calculates lps[i] for i = 1 to M-1.
    int i = 1;
    while (i < m)
    {
        // We get new prefix and new suffix, so increase length of  current lps by 1 and go to next iteration.
        if (str[i] == str[len])
        {
            len++;
            lps[i] = len;
            i++;
        }
        else
        {
            // Don't increment i here
            if (len != 0)
            {
                len = lps[len - 1];
            }
            else
            {
                // There isn't any lps ends with pat[i], so set lps[i] = 0 and go to next iteration.
                lps[i] = 0;
                i++;
            }
        }
    }

    return lps;
}

// Function for reverse a string
string reverse(string s)
{

    int n = s.length();

    for (int i = 0; i < n / 2; i++)
    {
        char temp = s[i];
        s[i] = s[n - i - 1];
        s[n - i - 1] = temp;
    }

    return s;
}

int Solution::solve(string str) {

    string revStr = reverse(str);

    // Concatenate string with $ symbol and reverse string.
    string concat = str + "$" + revStr;

    // Get LPS array of this concatenated string
    vector<int> lps = calculateLPSArray(concat);

    return (str.length() - lps[lps.size() - 1]);
}
  ~~~~~~
  
  
  ## Reference:
  
  -[Codestudio](https://www.codingninjas.com/codestudio/problems/893000?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website&leftPanelTab=2)
