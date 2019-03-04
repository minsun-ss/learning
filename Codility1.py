# if I remember rightly, this  pip problem is
# minimum number of turns until all pips are the same
# pips on opposite faces cost 2 turns while the rest cost 1

A = [1, 2, 2, 3, 4, 5, 5, 6, 6]

min_turns = []
for i in range(1,7):
    opposite_pip_face = 7 - i
    turns = 0
    for j in range(len(A)):
        if A[j] == i:
            pass  # do nothing because it's the same pip face
        elif A[j] == opposite_pip_face:
            turns = turns + 2  # takes 2 turns to turn this pip face
        else:
            turns = turns + 1  # takes 1 turn to turn this pip face
    min_turns.append(turns)
print(min_turns)
absolute_min_turns = min(min_turns)
absolute_min_turns_pipface = min_turns.index(absolute_min_turns) + 1

print("Minimum number of turns:", absolute_min_turns)
print("Pip face that uses minimum number of turns:", absolute_min_turns_pipface)