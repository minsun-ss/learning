A = [0, 1, 3, -2, 0, 1, 0, -3, 2, 3]


min_num = min(A)
max_num = max(A)
depths = []

for i in range(len(A)-1):
    for j in range(1,len(A)-1):
        for k in range(2, len(A)-1):
            if i >= j:
                pass
            else:
                apoint = A[i:j+1]
                asortedpoint = sorted(apoint,reverse=True)
                if apoint != asortedpoint:
                    pass
                else:
                    if j >= k:
                        pass
                    else:
                        apoint = A[j:k+1]
                        asortedpoint = sorted(apoint)
                        #print(apoint)
                        #print(asortedpoint)
                        if apoint == asortedpoint:
                            #print(str(i) + "," + str(j) + "," + str(k))
                            #print(A[i],A[j],A[k])
                            depth = min(A[i]-A[j],A[k]-A[j])
                            #print(depth)
                            depths.append(depth)
if not depths:
    return -1
return(max(depths))