#include <stdio.h>
#include <sys/time.h>
#include <math.h>
#include <random>


#define profile_size 1000
#define repeat_times 10000
#define rand_range   1000000
#define seeds        42

double getTime() {
    struct timeval cur;

    gettimeofday(&cur, NULL);
    return (cur.tv_sec + cur.tv_usec / 1000000.0);
}

int *initDatabase(int s) {
    int *db = new int[s];

    std::minstd_rand simple_rand;
    simple_rand.seed(seeds);

    for (int i = 0; i < s; i++)
        db[i] = simple_rand() % rand_range + 1;

    return db;
}

void profile_times(int *db, int size, double *profile_time) {
    *profile_time = getTime();

    for (int i = 0; i < size; i++)
        db[i] * db[i];

    *profile_time = getTime() - *profile_time;
}

void profile_pow(int *db, int size, double *profile_time) {
    *profile_time = getTime();

    for (int i = 0; i < size; i++)
        std::pow(db[i], 2);

    *profile_time = getTime() - *profile_time;
}


int main() {
    int *db = initDatabase(profile_size);

    double tim_time = 0.0;
    double pow_time = 0.0;
    double profile;

    for (int i = 0; i < repeat_times; i++) {
        profile_times(db, profile_size, &profile);
        tim_time += profile;

        profile_pow(db, profile_size, &profile);
        pow_time += profile;
    }

    printf("profile:\n");
    printf("times runtime: %.6f\n", tim_time);
    printf("pow   runtime: %.6f\n", pow_time);
    printf("runtime difference\n\tpow : times = %.1f\n", pow_time/tim_time);

    return 0;
}