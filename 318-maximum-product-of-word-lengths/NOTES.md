why value[i] |= 1 << (tmp.charAt(j) - 'a');
Let's take some examples,
​
// a 1->1
// b 2->10
// c 4->100
// ab 3->11
// ac 5->101
// abc 7->111
// az 33554433->10000000000000000000000001
Example, "abcd" and "aabbccdd" will both return 0000 ***0 1111
​
you should know, we don't care how many times of a character occurs in one word, we just want to record what letters occurs in one word, so that we can use AND operation to compare if two words has the same letter afterwards.
​
for prior case, 0000 ***0 1111 & 0000 ***0 1111 equals to **** 1111 which means has same letter.
​
another case would be "abcd" and "efgh",
​
0000 **** 0000 1111 & 0000 **** 1111 0000 equals to 0000 **** 0000, which means these two words don't have same letters