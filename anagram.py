#!/bin/python3

import math
import os
import random
import re
import sys
def anagram(s):
    n=len(s)
    if n%2==0:
        a=int(n/2)
        l=list(s)
        l1=l[:a]
        l2=l[a:]
        for x in l1:
            if x in l2:
                l2.remove(x)
        return len(l2)
    else:
        return -1
if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    q = int(input())

    for q_itr in range(q):
        s = input()

        result = anagram(s)

        fptr.write(str(result) + '\n')

    fptr.close()
