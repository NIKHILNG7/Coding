class Solution:
    def dfs(self, node, adjacency, visited, inStack):
        # If the node is already in the stack, we have a cycle.
        if inStack[node]:
            return True
        if visited[node]:
            return False
        # Mark the current node as visited and part of current recursion stack.
        visited[node] = True
        inStack[node] = True
        for neighbor in adjacency[node]:
            if self.dfs(neighbor, adjacency, visited, inStack):
                return True
        # Remove the node from the stack.
        inStack[node] = False
        return False

    def eventualSafeNodes(self, graph: List[List[int]]) -> List[int]:
        numNodes = len(graph)
        adjacency = [[] for _ in range(numNodes)]

        for i in range(numNodes):
            for node in graph[i]:
                adjacency[i].append(node)

        visited = [False] * numNodes
        inStack = [False] * numNodes

        for i in range(numNodes):
            self.dfs(i, adjacency, visited, inStack)

        safeNodes = []
        for i in range(numNodes):
            if not inStack[i]:
                safeNodes.append(i)

        return safeNodes