//Robert Schulze
//Matrikelnummer 555625

#include<iostream>
#include<fstream>

using namespace std;

/* takes one of the read-in filenames as parameter and returns array with 
the vals for the matrices */
int* pvl4_read_in(char* fname) {

    fstream file;
    file.open(fname);

    /* need to find out array length and copy all data to arr */

}

int main(int argc, char** argv) {

    if(argc != 3) {
        cout << "Es müssen exakt zwei Dateinamen übergeben werden."
        << "Bitte Programm erneut starten";
        return 1;
    }

    int* vals_1 = pvl4_read_in(argv[1]);
    int* vals_2 = pvl4_read_in(argv[2]); 

    return 0;
}