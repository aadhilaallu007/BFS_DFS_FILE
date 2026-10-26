
#include <stdio.h>

int graph[10][10], visited[10], n;

void BFS(int start)
{
    int queue[10], front = 0, rear = 0, i, v;

    for (i = 0; i < n; i++)
        visited[i] = 0;

    queue[rear++] = start;
    visited[start] = 1;

    printf("BFS Traversal: ");

    while (front < rear)
    {
        v = queue[front++];
        printf("%c ", 'A' + v);

        for (i = 0; i < n; i++)
        {
            if (graph[v][i] == 1 && !visited[i])
            {
                queue[rear++] = i;
                visited[i] = 1;
            }
        }
    }
    printf("\n");
}

void DFS(int v)
{
    int i;

    visited[v] = 1;
    printf("%c ", 'A' + v);

    for (i = 0; i < n; i++)
    {
        if (graph[v][i] == 1 && !visited[i])
            DFS(i);
    }
}

int main()
{
    int i, j, start, target;

    printf("Enter number of folders (max 10): ");
    scanf("%d", &n);

    if (n < 1 || n > 10)
    {
        printf("Invalid number of folders.\n");
        return 0;
    }

    printf("Enter adjacency matrix:\n");

    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            scanf("%d", &graph[i][j]);

    printf("Enter starting folder (A=0, B=1, etc.): ");
    scanf("%d", &start);

    printf("Enter target folder (A=0, B=1, etc.): ");
    scanf("%d", &target);

    if (start < 0 || start >= n ||
        target < 0 || target >= n)
    {
        printf("Invalid folder number.\n");
        return 0;
    }

    BFS(start);

    for (i = 0; i < n; i++)
        visited[i] = 0;

    printf("DFS Traversal: ");
    DFS(start);
    printf("\n");

    for (i = 0; i < n; i++)
        visited[i] = 0;

    BFS(start);

    if (visited[target])
        printf("Target folder %c is reachable.\n",
               'A' + target);
    else
        printf("Target folder %c is not reachable.\n",
               'A' + target);

    return 0;
}
