#include <stdio.h>
#include <windows.h>

int main() {
    int h, m, s;
    int delay = 1000;

    printf("Set time (hh:mm:ss): ");
    scanf("%d:%d:%d", &h, &m, &s);

    while (1) {
        if (h > 24) h = 0;
        if (m > 60) h += 1; m = 0;
        if (s > 60) m += 1; s = 0;
        s += 1;
        Sleep(delay);
    };
}