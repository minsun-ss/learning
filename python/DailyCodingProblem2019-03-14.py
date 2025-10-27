# COMPLETE

# Given an integer k and a string s, find the length of the longest substring that contains at most k
# distinct characters.

# For example, given s = "abcba" and k = 2, the longest substring with k distinct characters is "bcb".

from collections import Counter

s = "abcba"
k = 2

def indexes(str, start=0):
    return (i for i, _ in enumerate(str,start=start))

def get_all_substrings(s,min_length):
    return list(s[i:j] for i in range(len(s)) for j in indexes(s[i+min_length-1:],i+min_length))

def get_longest_substring(str_list,min):
    longest_string = ""
    for i in str_list:
        c = Counter(i)
        if len(c.most_common()) == min:
            if len(i) > len(longest_string):
                longest_string = i
    return longest_string

a = get_all_substrings(s,k)
print(get_longest_substring(a, k))