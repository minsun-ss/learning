# SOLVED

# You run an e-commerce website and want to record the last N order ids in a log. Implement a data structure to
# accomplish this, with the following API:

#    record(order_id): adds the order_id to the log
#    get_last(i): gets the ith last element from the log. i is guaranteed to be smaller than or equal to N.

# You should be as efficient with time and space as possible.

# N = number of orders
N = 10
order_list = []
start_position = 0
end_position = 0

def list_len(list):
    return end_position - start_position + 1

def record(order_id):
    global start_position
    global end_position
    if list_len(order_list) < N:
        order_list.append(order_id)
        end_position += 1
    else:
        order_list.append(order_id)
        start_position += 1
        end_position += 1

def get_last(i):
    position = end_position - i
    return order_list[position]

record(1)
record(2)
record(3)
record(4)
record(5)
record(6)
record(7)
record(8)
record(9)
record(10)
record(11)

print(order_list)
print(get_last(2))