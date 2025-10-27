# SOLVED but not efficient - use trie
# Implement an autocomplete system. That is, given a query string s and a set of all possible
# query strings, return all strings in the set that have s as a prefix.

# For example, given the query string de and the set of strings [dog, deer, deal], return
# [deer, deal].

# Hint: Try preprocessing the dictionary into a more efficient data structure to speed up queries.

from collections import defaultdict

A = ['dog', 'deer', 'deal']
query = 'de'

def process_dictionary(alist):
    # let's preprocess this dictionary
    dict = defaultdict(list)
    for i in alist:
        for j in range(len(i)):
            #print(i[:j+1], i)
            dict[i[:j+1]].append(i)
            #print(j)
    return dict

def process_query(dict, str):
    return dict[str]

new_dict = process_dictionary(A)

print(process_query(new_dict,'de'))
