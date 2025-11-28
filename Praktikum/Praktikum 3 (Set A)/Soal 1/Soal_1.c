#include <stdio.h>
#include <string.h>
#define ll long long

ll count = 0;
ll inNum(long long num, ll count);
ll outNum(ll count);
void seeTable();

ll bookshelf[1001];

int main() {

char input[101];

while(scanf("%s", input) == 1)
{

    if(strcmp(input, "IN") == 0)
    {
      ll x;
      scanf(" %lld", &x);
      if (inNum(x, count) == 1) count++;

    }

    else if (strcmp(input, "OUT") == 0)
    {

    if(outNum(count) == 1) count--;

    }

    else if (strcmp(input, "SEE") == 0)
    {

    seeTable();

    }


}

return 0;
}

ll inNum(ll num, ll count) {

    if(count == 0)
    {
    bookshelf[0] = num;
    }
    
    else if (count >= 1000)
    {
    printf("FULL\n");
    return 0;
    }


for(ll i = count; i > 0; i--) 
{
        bookshelf[i] = bookshelf[i - 1];
}

bookshelf[0] = num; 

printf("OK\n");

return 1;
}
ll outNum(ll count) {

if( count <= 0)
{

    printf("EMPTY\n");
    return 0;

}

printf("REMOVED %lld\n", bookshelf[0]);
for(ll i = 0; i < count - 1; i++)
  {
    bookshelf[i] = bookshelf[i + 1];
  }


return 1;
}
void seeTable() {

if( count <= 0)
{

    printf("EMPTY\n");
    return;

}


for(ll i = count; i > 0; i--)
{

printf("%lld ", bookshelf[i - 1]);

}
printf("\n");

return;

}
