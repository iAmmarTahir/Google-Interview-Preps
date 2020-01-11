import queue
import math


class Graph:
    graph = {}

    def addEdge(self, node, child):
        if node not in self.graph:
            self.graph[node] = [child]
        else:
            self.graph[node].append(child)

    def printGraph(self):
        for node, child in self.graph.items():
            print(node, '->', child)

    def BFS(self, s):
        visited = {}
        for i in self.graph:
            visited[i] = False
        queue = []
        queue.append(s)
        visited[s] = True
        while len(queue) != 0:
            s = queue.pop(0)
            for node in self.graph[s]:
                if visited[node] != True:
                    visited[node] = True
                    queue.append(node)
            print(s, "-> ", end="")


def takeSteps(n):
    if n == 1 or n == 0:
        return 1
    elif n == 2:
        return 2
    else:
        return takeSteps(n-1)+takeSteps(n-2)+takeSteps(n-3)


def dpTakeSteps(n):
    x = 1
    y = 1
    z = 2
    i = 3
    result = 0
    while i <= n:
        result += x + y + z
        x = y
        y = z
        z = result
        i += 1
    return result


#         2
#      /    \
#     3      4
#   /  \    / \
#  5    8

def levelOrder(arr):
    size = math.ceil(math.log2(len(arr)))
    count = 0
    j = 0
    for i in range(size):
        while j < pow(2, i):
            print(arr[j], " ")
            count += 1
            j += 1


def main():
    levelOrder([2, 3, 4, 5, 8])


if __name__ == "__main__":
    main()
