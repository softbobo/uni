basenum: basedNumbers.o bn_test.o
	gcc -Wall -g -Wextra -pedantic -lm basedNumbers.o bn_test.o -o basenum 

bn_test.o: bn_test.c
	gcc -c -g -Wall -Wextra -pedantic bn_test.c

basedNumbers.o: basedNumbers.c
	gcc -c -g -Wall -Wextra -lm -pedantic basedNumbers.c
