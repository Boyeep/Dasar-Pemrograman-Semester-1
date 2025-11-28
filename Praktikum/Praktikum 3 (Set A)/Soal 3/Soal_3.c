#include <stdio.h>

long long solusi = 0;
void Permutations(long long arr[], long long data[], long long start, long long end, long long index, long long target)
{

if((int)target % 2 != 0)
{
return;
}

if( index == target && target % 2 == 0)
    {
        printf("{ ");

        for(long long i = 0; i < target; i++)
        {

            printf("%lld ", data[i]);

        }
        printf("}\n");
        solusi++;
        return;
    }

    for(long long j = start; j <= end && end - j + 1 >= target - index ; j++)
    {

        data[index] = arr[j];
        Permutations(arr, data, j + 1, end, index + 1, target);

    }

}


void Permutations_Helper(long long arr[], long long n, long long target)
{

  if( target <= 0)
  {
    solusi++;
    printf("{ }\n");
    printf("\n");
    printf("Ada %lld total kombinasi pita genap yang dimiliki oleh Kitty\n", solusi);
    return;


  }

   long long data[target];
  Permutations(arr, data, 0, n, 0, target);

  Permutations_Helper(arr, n, target - 1);

}

int main () {

long long n;
scanf("%lld", &n);
long long arr[n];
for( long long i = 0; i < n; i++)
{

    scanf("%lld", &arr[i]);

}

Permutations_Helper(arr, n - 1, n);

return 0;
  }
