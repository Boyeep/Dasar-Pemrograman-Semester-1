#include <stdio.h>
#include <math.h>
#include <conio.h>
#include <windows.h>

#define PI 3.1415926535
#define HEIGHT 40
#define WIDTH  30

int main() {
    int x, y;
    double angle, sineValue;
    double offset = 0;

    printf("Tekan ENTER untuk berhenti...\n");

    while (1) {
        if (_kbhit()) {
            int c = getch();
            if (c == 13) {
                break;
            }
        }

        system("cls");

        for (y = HEIGHT; y >= 0; y--) {
            angle = ((double)y / HEIGHT * 2 * PI) + offset;
            sineValue = sin(angle);
            x = (int)((sineValue + 1) * (WIDTH / 2));

            int degree = (int)fmod((angle * 180.0 / PI), 360);
            if (degree < 0) degree += 360;
            
            printf("%3d", degree);

            for (int i = 0; i < WIDTH; i++) {
                if (i == x)
                    printf("*");
                else if (i == WIDTH / 2)
                    printf("|");
                else
                    printf(" ");
            }
            printf("\n");
        }

        offset += 0.1;
        Sleep(50);
    }

    printf("\nProgram dihentikan.\n");
    return 0;
}
