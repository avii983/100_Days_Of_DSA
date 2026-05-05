// Problem: Given a target distance and cars’ positions & speeds, compute the number of car fleets reaching the destination.
// Sort cars by position in descending order and calculate time to reach target.
#include <stdio.h>
#include <stdlib.h>

struct Car {
    int pos;
    double time;
};

int compare(const void* a, const void* b) {
    return ((struct Car*)b)->pos - ((struct Car*)a)->pos;
}

int main() {
    int n, target;
    scanf("%d %d", &n, &target);

    int position[n], speed[n];

    for (int i = 0; i < n; i++)
        scanf("%d", &position[i]);

    for (int i = 0; i < n; i++)
        scanf("%d", &speed[i]);

    struct Car cars[n];

    for (int i = 0; i < n; i++) {
        cars[i].pos = position[i];
        cars[i].time = (double)(target - position[i]) / speed[i];
    }

    qsort(cars, n, sizeof(struct Car), compare);

    int fleets = 0;
    double prevTime = 0;

    for (int i = 0; i < n; i++) {
        if (cars[i].time > prevTime) {
            fleets++;
            prevTime = cars[i].time;
        }
    }

    printf("%d", fleets);

    return 0;
}