from collections import deque,defaultdict

n = 4 
dominoes = [(1,2), (1,3),(2,3), (3,4)]

answer = 0

for mask in range(1, 1 << n):  # from 1 to 2^n-1
    # Build this subset's graph
    degree = defaultdict(int)
    adjacency = defaultdict(list)
    used_numbers = set()
    
    for i in range(n):
        if (mask >> i) & 1:
            x, y = dominoes[i]
            degree[x] += 1
            degree[y] += 1
            adjacency[x].append(y)
            adjacency[y].append(x)
            used_numbers.add(x)
            used_numbers.add(y)
    
    # Connectivity check (BFS)
    start = next(iter(used_numbers))
    queue = deque([start])
    visited = set([start])
    while queue:
        node = queue.popleft()
        for neighbor in adjacency[node]:
            if neighbor not in visited:
                visited.add(neighbor)
                queue.append(neighbor)
    if visited != used_numbers:  # Not all nodes reachable
        continue

    # Degree check
    odd_count = 0
    for num in used_numbers:
        if degree[num] % 2 == 1:
            odd_count += 1

    if odd_count == 0 or odd_count == 2:
        answer += 1

print(answer)