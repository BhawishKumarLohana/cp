from collections import Counter

def can_reduce(arr):
    if len(arr) == 1:
        return True
    # Count occurrences of each value
    freq = Counter(arr)
    # Find a value with at least two occurrences
    for x in freq:
        if freq[x] >= 2:
            next_arr = arr[:]
            count = 0
            # Remove two x
            i = 0
            while count < 2 and i < len(next_arr):
                if next_arr[i] == x:
                    next_arr.pop(i)
                    count += 1
                    i -= 1  # because we popped
                i += 1
            # Add x+1
            next_arr.append(x + 1)
            return can_reduce(next_arr)
    return False

# Example usage:
print(can_reduce([1, 1, 1, 2]))   # False
print(can_reduce([2, 2, 2, 2]))   # True
print(can_reduce([0, 3, 1, 3, 4, 1, 4][5:6]))  # For input example: [1]