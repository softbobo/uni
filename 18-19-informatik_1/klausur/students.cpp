//implementation of students task from test exam
//softbobo 190219

#include<iostream>

using namespace std;

struct Student {
    char name[40];
    char vorname[20];
    float noten[50];
    int matrikelnummer;
};

Student studenten[10] = {
    {
        "ralf", 
        "ralf",
        {1.0, 2.5, 4.0},
        123,
    },
};

float get_durchschnitt(int m_nummer) {
    int pos = -1;
    
    //search for right student
    for(int i = 0; i < 10; i++) {
        if(m_nummer == studenten[i].matrikelnummer)
            pos = i;
    }
    
    //error-check: student found?
    if(pos == -1) {
        cout << "Matrikelnummer nicht gefunden!" << endl;
        exit(-1);
    }

    float sum = 0;
    int count = 0;

    //count the number of marks given and add up their values
    for(int i = 0; i < 50; i++) {
        if(studenten[pos].noten[i] > 0) {
            count++;
            sum += studenten[pos].noten[i];
        }
    }
    if(sum == 0) {
        cout << "Student hat noch keine Prüfungen absolviert" << endl;
        exit(0);
    }

    //return the average, no need for an extra variable
    return sum / count;
}

int main() {
    cout << get_durchschnitt(123) << endl;

    return 0;
}