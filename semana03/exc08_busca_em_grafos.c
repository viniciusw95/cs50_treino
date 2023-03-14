#include <stdio.h>

const int MAX = 5;

int locked[5][5];

int is_there_any_path(int source, int dest);

int main(void)
{
    
    for (int i = 0; i < MAX; i++)
    {
        for (int j = 0; i < MAX; i++)
        {
            locked[i][j] = 0;
        }
        
    }
    locked[0][1] = 1;
    locked[0][4] = 1;
    locked[4][2] = 1;
    locked[2][3] = 1;
    printf("%d\n", is_there_any_path(4, 2));
}

int is_there_any_path(int source, int dest)
{
    if (locked[source][dest])
    {
        return 1;
    }
    // Edges: Number os edges leaving source.
    int edges = 0;
    int paths[MAX];
    /* Checking what (and how many) edges the source element has, so that we can use
    these informations later to search for alternative paths that arrive to dest. */
    int i = 0;
    while (i < MAX)
    {
        if (locked[source][i])
        {
            paths[edges] = i;
            edges++;
        }
        i++;
    }
    /* If there is 1 (or more) edge(s) leaving source, so maybe exist an alternative path
    to dest. */
    for (int j = 0; j < edges; j++)
    {
        // Recursively search for alternative paths.
        int exists = is_there_any_path(paths[j], dest);
        if (exists)
        {
            return 1;
        }
    }
    /* If there this no edge leaving a particular source, it is guaranteed to say that
    there is no path from source to dest. */
    return 0;

}