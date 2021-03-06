#include <stdlib.h>
#include <stdio.h>


//  THIS IS A SOLUTION TO PROBLEM A OF THE 2014 ICPC WORLD FINALS
//  The goal is to rearrange a sequence of n-many "BA"s into
//  n "A"s followed by n "B"s by only moving two adjacent characters
//  at a time, in as few moves as possible.

//  There are 2n-many empty cells to the left of the string to be used
//  for storage, represented by "."

//  Each cell in the string is numbered from 1 to 2n, and each cell to
//  the left of the string is numbered from 0 to -2n + 1.

//  For example, if n = 4, then the initial configuration is
//  |.|.|.|.|.|.|.|.|B|A|B|A|B|A|B|A|
//  -7-6-5-4-3-2-1 0 1 2 3 4 5 6 7 8

//  The program outputs a shortest sequence of moves to rearrange
//  the string.

//  And the final arrangement would be
//  |.|.|.|.|.|.|A|A|A|A|B|B|B|B|.|.|
//  -7-6-5-4-3-2-1 0 1 2 3 4 5 6 7 8

//  The solution is a recursive algorithm.
//  The base cases are n = 4, 5, 6, or 7. n = 3 is a unique case.
//  For n greater than 7, the solution is as follows:

//  ..BABA((BA)^n-4))BABA
//  ABBABA((BA)^n-4))B..A
//  ABBA..((BA)^n-4))BBAA
//  Then you recursively do the same thing for the middle section.
//  ABBA((A^n-4)(B^n-4))..BBAA
//  A..A((A^n-4)(B^n-4))BBBBAA
//  AAAA((A^n-4)(B^n-4))BBBB..

// ============== CODE STARTS HERE ==============

/*
   solve3: void -> void
   Since 3 is a unique case that doesn't fit the recursion model,
   it's easier to simply test at the start if n == 3 and solve it right away.
   If it's not 3, then we can discount that possibility forever.
*/
void solve3() {
   printf("2 to -1\n5 to 2\n3 to -3\n");
   return;
}

/*
   solution: int -> void
   Takes the integer corresponding to the desired solution, and outputs the solution
   as a side-effect. Since loops are preferred over recursion in C, we utilize a
   while-loop for the pre- and post recursion, and a switch for the base case.
*/
void solution(int n) {
   int tmp = n;
   int offset = 0;
   // Do the pre-base set up.
   while(tmp > 7) {
      printf("%d to %d\n", 2*tmp - 2 + offset, -1 + offset);
      printf("%d to %d\n", 3 + offset, 2*tmp - 2 + offset);
      tmp -= 4;
      offset += 4;
   }
   // Print the solution to the proper base case.
   switch(tmp) {
      case 4:
         printf("%d to %d\n", 6 + offset, -1 + offset);
         printf("%d to %d\n", 3 + offset, 6 + offset);
         printf("%d to %d\n", 0 + offset, 3 + offset);
         printf("%d to %d\n", 7 + offset, 0 + offset);
         break;
      case 5:
         printf("%d to %d\n", 8 + offset, -1 + offset);
         printf("%d to %d\n", 3 + offset, 8 + offset);
         printf("%d to %d\n", 6 + offset, 3 + offset);
         printf("%d to %d\n", 0 + offset, 6 + offset);
         printf("%d to %d\n", 9 + offset, 0 + offset);
         break;
      case 6:
         printf("%d to %d\n", 10 + offset, -1 + offset);
         printf("%d to %d\n",  7 + offset, 10 + offset);
         printf("%d to %d\n",  2 + offset, 7 + offset);
         printf("%d to %d\n",  6 + offset, 2 + offset);
         printf("%d to %d\n",  0 + offset, 6 + offset);
         printf("%d to %d\n", 11 + offset, 0 + offset);
         break;
      case 7:
         printf("%d to %d\n", 12 + offset, -1 + offset);
         printf("%d to %d\n",  5 + offset, 12 + offset);
         printf("%d to %d\n",  8 + offset, 5 + offset);
         printf("%d to %d\n",  3 + offset, 8 + offset);
         printf("%d to %d\n",  9 + offset, 3 + offset);
         printf("%d to %d\n",  0 + offset, 9 + offset);
         printf("%d to %d\n", 13 + offset, 0 + offset);
         break;
      default:
         printf("You shouldn't even be here!\n");
         exit(-1);
   }
   // Do the post-solution recursion.
   while(tmp < n) {
      tmp += 4;
      offset -= 4;
      printf("%d to %d\n", 0 + offset, 2*tmp - 5 + offset);
      printf("%d to %d\n", 2*tmp - 1 + offset, 0 + offset);
   }
   return;
}

int main() {
   // Get the n to be used. In a real-world setting, I would test that the input
   // is a valid int, but I will simply assume that the input is of the format that
   // the problem specification says it will be.
   int n, depth = 0;
   printf("Give me a number between 3 and 100: ");
   scanf("%d", &n);
   // If n == 3, just run the unique 3 case and be done with it.
   if(n == 3) {
      solve3();
      return 0;
   }
   solution(n);
   return 0;
}
