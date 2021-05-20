#include <stdio.h>
#include <stdlib.h>
int N, M;
int numberOfSolutions = 0;
int a[100][100];
void findPaths(int x, int y, int ok)
{
    if(x<1 || y>M)
    {
        return;
    }
    if(x == 1 && y == M && ok == 1)
    {
        //solution is found
        numberOfSolutions ++;
        return;
    }
    if(a[x][y] == 0)
    {
        ok = 1;
        a[x][y]++;
    }
    findPaths(x-1, y, ok); // go north
    findPaths(x-1, y+1 , ok); // go northeast
    findPaths(x, y+1, ok);

}
int main()
{
    scanf("%d%d", &N, &M);
    findPaths(N, 1, 0);
    printf("Number of solutions is: %d", numberOfSolutions);

}
