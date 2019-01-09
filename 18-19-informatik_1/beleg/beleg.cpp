/* Beleg für Informatik 1, Wintersemester 2018/19
Dozierende: Dr. Andreas Müller, Ariane Jacobs
Student: Robert Schulze, Matrikelnummer: 555625 */
// task defined in README

/* next steps:
- write check, temp_y is an int multiple of temp_x in tile_in()
- write wall_in() (pass two pointers to input to array_allocator())
- write function declarations
- verify parameter types for tile_in(), wall_in() and array_allocator()
- set up main() for working tests
- free() allocated pointers in main() eventually
*/

#include<iostream>
using namespace std;

struct fliese{
    float x;    /* Breite (x-Richtung) in cm */
    float y;    /* Laenge (y-Richtung) in cm */
};

int main(void){

              
    return 0;
}

fliese* tile_in() {
    fliese tile;
    float temp_x = 0, temp_y = 0;
    cout << "Bitte die Breite der Fliesen in cm eingeben: " << endl;
    cin >> temp_x;
        if(temp_x < 10) {
            cout << "Error: Fliesenbreite muss mindestens 10 cm betragen!" << endl;
            tile_in();
        }
        else {
            tile.x = temp_x;
        }
    cout << "Bitte die Laenge der Fliesen in cm eingeben: " << endl;
    cin >> temp_y;
        if(temp_x < 10) {
            cout << "Error: Fliesenlaenge muss mindestens 10 cm betragen!" << endl;
            tile_in();
        }
        else if((temp_y - (long long)temp_y == 0)) { //is this a correct check if y is an int?
            cout << "Error: Fliesenlaenge muss ein ganzzahliges Vielfaches der Breite sein!" << endl;
            tile_in();
        }
        else {
            tile.y = temp_y;
        }
}

int wall_in() {
    float wall_width = 0, wall_height = 0; 
    float* p_width;
    float* p_height = &wall_height;                      
    cout << "Bitte die Breite der Wand in Metern eingeben: " << endl;
    cin >> wall_width;
        if(wall_width > 8) {
            cout << "Error: Die Wandbreite darf maximal 8m betragen!" << endl;
            wall_in();
        }
        else {
           wall_width *= 100;
           p_width = &wall_width; 
        }
    cout << "Bitte die Hoehe der Wand in Metern eingeben: " << endl;
    cin >> wall_height; 
        if(wall_height > 8) {
            cout << "Error: Die Wandhoehe darf maximal 8m betragen!" << endl;
            wall_in();
        }
        else {
            wall_height *= 100;
            p_height = &wall_height; 
        }

}