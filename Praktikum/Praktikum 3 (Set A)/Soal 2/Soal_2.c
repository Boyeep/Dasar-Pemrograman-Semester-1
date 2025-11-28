#include <stdio.h>

void pola(long long n, long long ori);



int main () {

long long input;
scanf("%lld", &input);


pola(input, input);

return 0;


}

void pola(long long n, long long ori)
{

  char toprint;

if(n == 1 && ori == 1)
    {

        printf("o");
        return;
    }


if( n <= 1)
{

printf("a\n");
return;

}

pola(n - 1, ori);

if( n % 2 == 0)
{

toprint = 'e';


}

else {

toprint = 'a';


}

for( int i = 0; i < n; i++)
{

 


  if(n == ori)
    {

        printf("o");

    }

  else {
    printf("%c", toprint);
  }

}
printf("\n");

pola(n - 1, ori);


}
