# THIS IS A SOLUTION TO PROBLEM A OF THE 2014 ICPC WORLD FINALS
# The goal is to rearrange a sequence of n-many "BA"s into
# n "A"s followed by n "B"s by only moving two adjacent characters
# at a time, in as few moves as possible.

# There are 2n-many empty cells to the left of the string to be used
# for storage, represented by "."

# Each cell in the string is numbered from 1 to 2n, and each cell to
# the left of the string is numbered from 0 to -2n + 1.

# For example, if n = 4, then the initial configuration is
# |.|.|.|.|.|.|.|.|B|A|B|A|B|A|B|A|
# -7-6-5-4-3-2-1 0 1 2 3 4 5 6 7 8

# The program outputs a shortest sequence of moves to rearrange
# the string.

# And the final arrangement would be
# |.|.|.|.|.|.|A|A|A|A|B|B|B|B|.|.|
# -7-6-5-4-3-2-1 0 1 2 3 4 5 6 7 8

# The solution is a recursive algorithm.
# The base cases are n = 4, 5, 6, or 7. n = 3 is a unique case.
# For n greater than 7, the solution is as follows:

# ..BABA((BA)^n-4))BABA
# ABBABA((BA)^n-4))B..A
# ABBA..((BA)^n-4))BBAA
# Then you recursively do the same thing for the middle section.
# ABBA((A^n-4)(B^n-4))..BBAA
# A..A((A^n-4)(B^n-4))BBBBAA
# AAAA((A^n-4)(B^n-4))BBBB..

# =============== CODE STARTS HERE ====================

'''
  n represents the number of BA pairs to be rearranged.
  Since the function is called recursively, and each level
  of recursion shifts the movements by 2, we need to track the
  depth for use as a modifier.
'''
def solution(n, depth):
    # n = 3 is a special case. It doesn't take into account depth.
    modifier = 4 * depth
    if n==3:
        print "2 to -1"
        print "5 to 2"
        print "3 to -3"
    elif n==4:
        print "%d to %d" %(6 + modifier, -1 + modifier)
        print "%d to %d" %(3 + modifier, 6 + modifier)
        print "%d to %d" %(0 + modifier, 3 + modifier)
        print "%d to %d" %(7 + modifier, 0 + modifier)                                                                       
    elif n==5:
        print "%d to %d" %(8 + modifier, -1 + modifier)
        print "%d to %d" %(3 + modifier, 8 + modifier)
        print "%d to %d" %(6 + modifier, 3 + modifier)
        print "%d to %d" %(0 + modifier, 6 + modifier)
        print "%d to %d" %(9 + modifier, 0 + modifier)
    elif n==6:
        print "%d to %d" %(10 + modifier, -1 + modifier)
        print "%d to %d" %(7 + modifier, 10 + modifier)
        print "%d to %d" %(2 + modifier, 7 + modifier)
        print "%d to %d" %(6 + modifier, 2 + modifier)
        print "%d to %d" %(0 + modifier, 6 + modifier)
        print "%d to %d" %(11 + modifier, 0 + modifier)
    elif n==7:
        print "%d to %d" %(12 + modifier, -1 + modifier)
        print "%d to %d" %(5 + modifier, 12 + modifier)
        print "%d to %d" %(8 + modifier, 5 + modifier)
        print "%d to %d" %(3 + modifier, 8 + modifier)
        print "%d to %d" %(9 + modifier, 3 + modifier)
        print "%d to %d" %(0 + modifier, 9 + modifier)
        print "%d to %d" %(13 + modifier, 0 + modifier)
    else:
        print "%d to %d" %(2*n - 2 + modifier, -1 + modifier)
        print "%d to %d" %(3 + modifier, 2*n - 2 + modifier)
        solution(n - 4, depth + 1)
        print "%d to %d" %(0 + modifier, 2*n - 5 + modifier)
        print "%d to %d" %(2*n - 1 + modifier, 0 + modifier)



# Main Loop of the function is here
n = int(raw_input("Give me a number between 3 and 100: "))
solution(n, 0)
