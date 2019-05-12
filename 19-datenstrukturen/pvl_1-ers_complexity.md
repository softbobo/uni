<!-- Time complexity write-down for first lab assignment for data structures
    to be converted to pdf later
    Robert Schulze 1 May 2019-->

Robert Schulze
Matrikelnummer: 555625

## Zeitkomplexität meiner Implementierung des Sieb des Eratosthenes

### Ermittlung der Anzahl der Primzahlen P in Abhängigkeit von N


```c++
    for(unsigned i = 0; i <= max; i++) {
        if(sieve[i] == true) { output[1]++; }
    }
```

### Ermittlung der Anzahl der Streichungen in Abhängigkeit von N
```c++
    for(unsigned i = 2; (i*i <= max); i++) {
        if(sieve[i] == true) {
            for(unsigned j = i*i; j <= max; j += i) {
                sieve[j] = false;
                output[2]++;
            }
        }
    }
```

### Gesamtkomplexität