/* Beleg für Informatik 1, Wintersemester 2018/19
Dozierende: Dr. Andreas Müller, Ariane Jacobs
Student: Robert Schulze, Matrikelnummer: 555625 */
// task defined in README

/* next steps:
- write check if temp_y is an int multiple of temp_x in tile_in()
- write array_allocator(), that takes args - wall and tile - from main() and returns an array
- write array_printer(), that takes array from main() and prints array to console 
*/

#include<iostream>
using namespace std;

struct fliese{
    float x;    /* Breite (x-Richtung) in cm */
    float y;    /* Laenge (y-Richtung) in cm */
};

struct fliese* tile_in(struct fliese *p_tile);
struct fliese* wall_in(struct fliese *p_wall);

int main(void){
    struct fliese *p_tile = new fliese;
    tile_in(p_tile);
    cout << "Debug-Output. Fliesenbreite: " << p_tile->x << " Fliesenlaenge: " << p_tile->y << endl; //delete before handing in
    struct fliese *p_wall = new fliese;
    wall_in(p_wall);
    cout << "Debug-Output. Wandbreite: " << p_wall->x << " Wandhoehe: " << p_wall->y << endl;  //delete before handing in


    free(p_tile);
    free(p_wall);         
    return 0;
}

struct fliese* tile_in(fliese *p_tile) {
    float temp_x = 0, temp_y = 0;
    cout << "Bitte die Breite der Fliesen in cm eingeben: " << endl;
    cin >> temp_x;
        if(temp_x < 10) {
            cout << "Error: Fliesenbreite muss mindestens 10 cm betragen!" << endl;
            tile_in(p_tile);
        }
        else {
            p_tile->x = temp_x;
        }
    cout << "Bitte die Laenge der Fliesen in cm eingeben: " << endl;
    cin >> temp_y;
        if(temp_x < 10) {
            cout << "Error: Fliesenlaenge muss mindestens 10 cm betragen!" << endl;
            tile_in(p_tile);
        }
//        else if((temp_y - (long long)temp_y == 0)) { //is this a correct check if y is an int?
//            cout << "Error: Fliesenlaenge muss ein ganzzahliges Vielfaches der Breite sein!" << endl;
//            tile_in(p_tile);
//        }
        else {
            p_tile->y = temp_y;
        }
    return p_tile;
}

struct fliese* wall_in(struct fliese *p_wall) {
    float wall_width = 0, wall_height = 0;                     
    cout << "Bitte die Breite der Wand in Metern eingeben: " << endl;
    cin >> wall_width;
        if(wall_width > 8) {
            cout << "Error: Die Wandbreite darf maximal 8m betragen!" << endl;
            wall_in(p_wall);
        }
        else {
           wall_width *= 100;
           p_wall->x = wall_width; 
        }
    cout << "Bitte die Hoehe der Wand in Metern eingeben: " << endl;
    cin >> wall_height; 
        if(wall_height > 8) {
            cout << "Error: Die Wandhoehe darf maximal 8m betragen!" << endl;
            wall_in(p_wall);
        }
        else {
            wall_height *= 100;
            p_wall->y = wall_height; 
        }
    return p_wall;
}