#include <stdio.h>
#include <math.h>

/**
 * drawMenger - Entry point
 *
 * @size: Arguments vector
 * @level: Arguments vector
 *
 */

void drawMenger(int size, int level) {
    if (level < 0) {
        return;
    }

    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            int x = i, y = j;
            char c = '#';

            while (x > 0 || y > 0) {
                if (x % 3 == 1 && y % 3 == 1) {
                    c = ' ';
                    break;
                }
                x /= 3;
                y /= 3;
            }

            printf("%c", c);
        }
        printf("\n");
    }
}

/**
 * menger - Entry point
 *
 * @level: Arguments vector
 *
 */
void menger(int level) {
    if (level < 0) {
        return;
    }

    int spongeSize = (int)pow(3, level);
    drawMenger(spongeSize, level);

    for (int i = 0; i < spongeSize; i++) {
        for (int j = 0; j < spongeSize; j++) {
            printf("#");
        }
        printf("\n");
    }
}
