# SOLVED - wow that was slow of me

# Suppose we represent our file system by a string in the following manner:

# The string "dir\n\tsubdir1\n\tsubdir2\n\t\tfile.ext" represents:

# dir
#     subdir1
#     subdir2
#         file.ext

# The directory dir contains an empty sub-directory subdir1 and a sub-directory subdir2 containing a file file.ext.

# The string "dir\n\tsubdir1\n\t\tfile1.ext\n\t\tsubsubdir1\n\tsubdir2\n\t\tsubsubdir2\n\t\t\tfile2.ext" represents:

# dir
#    subdir1
#        file1.ext
#        subsubdir1
#    subdir2
#        subsubdir2
#            file2.ext

# The directory dir contains two sub-directories subdir1 and subdir2. subdir1 contains a file file1.ext and an empty
# second-level sub-directory subsubdir1. subdir2 contains a second-level sub-directory subsubdir2 containing a file
# file2.ext.

# We are interested in finding the longest (number of characters) absolute path to a file within our file system.
# For example, in the second example above, the longest absolute path is "dir/subdir2/subsubdir2/file2.ext", and its
# length is 32 (not including the double quotes).

# Given a string representing the file system in the above format, return the length of the longest absolute path to
# a file in the abstracted file system. If there is no file in the system, return 0.

# Note:

# The name of a file contains at least a period and an extension.
# The name of a directory or sub-directory will not contain a period.

# We will be sending the solution tomorrow, along with tomorrow's question. As always, feel free to shoot us an email
# if there's anything we can help with.

url = "dir\n\tsubdir1\n\t\tfile1.ext\n\t\tsubsubdir1\n\tsubdir2\n\t\tsubsubdir2\n\t\t\tfile2.ext"

def parse_string(str):
    set = str.split('\n')
    fileset = []
    for i in set:
        set2 = i.split('\t')
        fileset.insert(0,set2)
    return fileset

def fill_fileset(set):
    files = []
    for i in range(len(set)):
        if "." in set[i][-1]:
            for j in reversed(range(len(set[i])-1)):
                for k in range(i+1, len(set)):
                    if len(set[k])-1 == j:
                        set[i][j] = set[k][-1]
                        break
            #files.append(set[i])
            files.append('\\'.join(str(e) for e in set[i]))
    return files

def find_max(files):
    print(max(files, key=len))






set = parse_string(url)
print(set)
find_max(fill_fileset(set))
