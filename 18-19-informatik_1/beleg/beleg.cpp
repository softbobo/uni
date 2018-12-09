/* Beleg für Informatik 1, Wintersemester 2018/19
Dozent: Dr. Andreas Müller
Student: Robert Schulze, Matrikelnummer: 555625 */
// task defined in README

#include<iostream>
using namespace std;

struct fliese{
    float x;  /* Breite (x-Richtung) in cm */
    float y;  /* Laenge (y-Richtung) in cm */
};

int main(void){

    float size_a, size_b;                       //wallsize in m
    cout << "Bitte die Breite des Raumes in Metern eingeben: " << endl;
    cin >> size_a;
    cout << "Bitte die Laenge des Raumes in Metern eingeben: " << endl;
    cin >> size_b;
    cout << "Bitte die Breite der Fliesen in Centimetern eingeben: " << endl;
    cin >> x;
    cout << "Bitte die Laenge der Fliesen in Centimetern eingeben: " << endl;
    cin >> y;

    cout << "Kontrolle: Raumbreite: " << size_a << " Raumlaenge: " << size_b << endl;
    cout << "Fliesenbreite: " << x << " Fliesenlaenge: " << y << endl; 
    //fliese wand[size_a][size_b]                 //wall-simulation - array holds all the structs representing tiles


    return 0;
}