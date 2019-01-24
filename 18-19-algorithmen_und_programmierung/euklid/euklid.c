//implementation for training task euklid, specified in pdf
//softbobo 190123

#include<stdio.h>
#include<inttypes.h>

int euclid(int num_1, int num_2);

int main(int argc, char** argv) {
    if(argc < 3 || argc > 3) return -1;
    char* endptr;
    int num_1 = strtoimax(argv[1], &endptr, 10);
    int num_2 = strtoimax(argv[2], &endptr, 10);
    if(num_1 == 0 || num_2 == 0) {
        printf("%c", 'X');
        return 0; }
    int gcd = euclid(num_1, num_2);
    printf("%d\n", gcd);
    return gcd;
}
int euclid(int num_1, int num_2) {
    if(num_1 > num_2) {
        return euclid(num_1 - num_2, num_2);  }
    else if(num_2 > num_1) {
        return euclid(num_2 - num_1, num_1); }
    else
        return num_1;
}