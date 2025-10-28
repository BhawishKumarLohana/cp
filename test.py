from collections import deque, defaultdict

def main():
    T = int(input())
    for f in range(T):
        N = int(input())
        dominoes = []
        for d in range(N):
            a, b = map(int, input().split())
            dominoes.append((a, b))
        
        answer = 0
        #print(dominoes)
        for m in range(1, 1 << N):
            deg = defaultdict(int)
            adj = defaultdict(list)
            used = set()
            # Graph
            for i in range(N):
                if (m >> i) & 1:
                    x, y = dominoes[i]
                    deg[x] += 1
                    deg[y] += 1
                    adj[x].append(y)
                    adj[y].append(x)
                    used.add(x)
                    used.add(y)
            # BFS
            start = next(iter(used))
            queue = deque([start])
            visited = set([start])
            while queue:
                node = queue.popleft()
                for neighbor in adj[node]:
                    if neighbor not in visited:
                        visited.add(neighbor)
                        queue.append(neighbor)
                        #print(queue)
            if visited != used:
                continue
            #  odd degree
            odd_counter = 0
            for num in used:
                if deg[num] % 2 == 1:
                    odd_counter += 1
            if odd_counter == 0 or odd_counter == 2:
                answer += 1
        print(answer)

main()