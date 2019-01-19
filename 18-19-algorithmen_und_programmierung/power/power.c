//task 010 for uni, specified in .pdf
//softbobo 190116

int power(int x, unsigned n) {
//this -obviously- has O(n) time complexity.
//O(log(n)) can be achieved using an addition chain, i have to review that 
    for(int i = 0; i < n; i++)
        x *= x;
    return x;
}

int poly1(int x, unsigned n) {
    return n;
}