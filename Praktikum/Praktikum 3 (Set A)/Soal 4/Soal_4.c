#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>

char map[101][101];
bool visited[101][101] = {false};
int teleportation_x1[19];
int teleportation_y1[19];
int teleportation_x2[19];
int teleportation_y2[19];
bool teleportation_checker[10] = {false};


int rows, column;


int DFS(int r, int c)
{

if( r >= rows || c >= column || r < 0 || c < 0)
{

return 0;

}

if(visited[r][c])
{
return 0;
}
visited[r][c] = true;

if(map[r][c] == '#')
{

return 0;

}

if(map[r][c] == 'x')
{
return 1;
}

int solusi = 0;

solusi += DFS(r + 1, c);
solusi += DFS(r - 1, c);
solusi += DFS(r, c + 1);
solusi += DFS(r, c - 1);

if(isdigit(map[r][c]))
{
int n_r, n_c;
int where = map[r][c] - '0';

if( r == teleportation_x1[where] && c == teleportation_y1[where])
    {
        n_r = teleportation_x2[where];
        n_c = teleportation_y2[where];
    }

else 
{

n_r = teleportation_x1[where];
n_c = teleportation_y1[where];

}

solusi += DFS(n_r, n_c);

}

return solusi;

}

int main () {
bool harta_karun = false;
scanf("%d %d", &rows, &column);
char input[100];

for (int i = 0; i < rows; i++)
{

    for( int j = 0; j < column; j++)
    {
          
      scanf(" %c", &map[i][j]);
      if( map[i][j] == 'x')
      {
          harta_karun = true;
      }
      if(isdigit(map[i][j]))
      {
            int pos = map[i][j] - '0';
            
            if(teleportation_checker[pos] == false)
            {
                teleportation_x1[pos] = i;
                teleportation_y1[pos] = j;
                teleportation_checker[pos] = true;
            }   
      

            else
              {
                  int pos = map[i][j] - '0';
                  teleportation_x2[pos] = i;
                  teleportation_y2[pos] = j;

              }
      }
  }

}


int solusi = DFS(0, 0);
if (solusi >= 1)
{

printf("YES");

}

else if( harta_karun == false || solusi == 0)
{
printf("NO");
}

return 0;

}


