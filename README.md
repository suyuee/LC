# LC
My leetcode sulotions
### 7.Reverse Integer
1. When implementing %d in vprintf, we do the job in the same way. It works like two stacks : push every element poped out from the original stack into a new stack, but without extra data structures.
2. Notice how to check overflow : check before pushing elements into the new stack.
### 13.Roman to Integer
1. One rule to decide when a roman charactor should be added to or subtracted from the sum : when it denotes a smaller number than the next one, it should be subtracted; otherwise added.
### 36.Valid Sudoku
1. The general idea is to keep three "check lists" : rows, columns and 3*3 boxes. Actually, this is how human beings would check if the sudoku is valid.
2. The takeaway : ponder on how humans would do the job.
3. Bug : Index out of bounds. The array's max index is 8 instead of nine. Do not use the numbers in the sudoku as indexes of the array. 
### 70.Climbint Staairs
0. Very basic dynamic programming problem, 
1. First question to think about : is the question of a smaller scale and that of a bigger scale *essentially*the same. If they are, we would call the one of a smaller scale 'the subproblem'; then we have more questions to ask based on the principles of DP:
2. How, *in the given context*, would the subproblem help to solve the problem; or how would the solution to the problem benefits from those to the subproblems. These two questions matter because they indicate how the solution builds up or how the problem breaks down. In this problem, the following builds the connection we need: if we want to reach the Nth step, we have exactly two situations before that result, on the N-1th step or on the N-2th step. That is what the
description tells us : 1 or 2 steps a time.
3. We need a handy data structure to store the number of solutions to the  solved subproblems. And we would need to look it up later. In this case, we only need constant storage for this purpose actually, since one subprolem only contributes to exactly two problems in all and it would become useless after 2 consequtive iterations.
### 88. Merge Sorted Array
1. Fill the array from the back of nums1. Very interesting operations on the array.
### 125.Valid Palindrome
1. Good helpers with strings : isalpha, isalnum and tolower.
2. "Ignoring cases" means "a==A", rather than "there are no upper case letters".
### 191.Number of 1 Bits
1. Given n, if we let n & n - 1, then we have exactly one less 1 bit in n. If we keep doing it until n is zero, we have the number of 1 bits.
2. It is rather to prove that. Just use the basic conditions.
### 237.Delete Node in a Linked List
1. The idea of this "wield" solution is to make THIS node become its NEXT node. Normally, the annoying part of removing a node from a linked list is that the predecessor has to be found and the predecessor should point to another node. But in this solution, we can ignore the predecessor.
### 242.Valid Anagram 
1. The concept of the anagram is having same numbers of all the letters, and that is how the work is done.
2. An alternative is to sort both of the strings and use operator == to check if they are the same.

### 268.Missing Number
1. Very simple solution : if we know a series of consecutive integers starting from 0 and its length, then we know the sum of them; after taking one of them away, the sum changes and we know which one.
2. We can use this solution because the condition given is very special : starting from 0, consequtive integers.
### 384.Shuffle an Array
1. As for the data members, we should always keep the original version as it is required by reset();
2. To generate a random permutation of a array, we have Fisher-Yates algorithms here : swap every element with a random element before it (or with itself);
3. When srand() is called to initialize the pseudo random number generator, the sequence of random numbers has been decided. 
### 387.First unique character in a string
1. We cannot tell if a character is unique unless we have checked it against the whole string; and we also need to find the first unique one. So in the first round, we can record the occurence of every charactor; and in the second round, we find the first unique one.
### 461. Hamming Distance
1. The exclusive-or of two numbers can indicate on which bits they differ. Then the number of 1 bits is the hamming distance of the two numbers (using question 191).
