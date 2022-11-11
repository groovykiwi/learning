#include <stdio.h>
#include <windows.h>

int main() {
    int h, m, s;
    int delay = 1000;

    printf("Set time:\n");
    scanf("%d%d%d", &h, &m, &s);

    while (1) {
        if (h > 23) h = 0;
        if (m > 59) {
            h++;
            m = 0;
        }
        if (s > 59) {
            m++;
            s = 0;
        }
        s += 1;
        printf("Clock: %02d:%02d:%02d", h,m,s);
        Sleep(delay);
        system("cls");
    };
}