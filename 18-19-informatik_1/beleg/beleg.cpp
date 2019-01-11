/* Beleg für Informatik 1, Wintersemester 2018/19
Dozierende: Dr. Andreas Müller, Ariane Jacobs
Student: Robert Schulze, Matrikelnummer: 555625 */
// task defined in README

/* next steps:
- write check if temp_y is an int multiple of temp_x in tile_in()
- why do i need to enter parameters several times (the same value) when input is wrong and func starts again
- check max iteration in printing function, doesnt work for floats
- enhance allocator for y-axis
- unify max iterators in allocating and printing functions
- check back for() terminating conditions and unify max iteration length
- how to determine ends of each "line of tiles" (aka 2nd array dimension)
- floats on this system have 4 Bytes (5 decimals) -> how do i array_size the output right?
- remove all debug printouts
*/

#include<iostream>
using namespace std;

struct fliese{
    float x;    /* Breite (x-Richtung) in cm */
    float y;    /* Laenge (y-Richtung) in cm */
};

struct fliese* tile_in(struct fliese *p_tile);
struct fliese* wall_in(struct fliese *p_wall);
struct fliese** array_allocator(struct fliese* p_tile, struct fliese* p_wall, struct fliese** raum);
void array_printer(struct fliese* p_tile, struct fliese* p_wall, struct fliese** raum);

int main(void){
    
    struct fliese *p_tile = new fliese;
    tile_in(p_tile);
    cout << "Debug-Output. Fliesenbreite: " << p_tile->x << " Fliesenlaenge: " << p_tile->y << endl; //delete before handing in
    
    struct fliese *p_wall = new fliese;
    wall_in(p_wall);
    cout << "Debug-Output. Wandbreite: " << p_wall->x << " Wandhoehe: " << p_wall->y << endl;   //delete before handing in
    
    const int rows = (p_wall->x/p_tile->x + 1);
    cout << "Debug-Output. Anzahl Zeilen: " << rows << endl;   //delete before handing in
    const int cols = (p_wall->y/p_tile->y + 1);
    cout << "Debug-Output. Anzahl Spalten: " << cols << endl;   //delete before handing in
    struct fliese** raum = new struct fliese*[rows];
    for(int i = 0; i < rows; i++) {                                                            //allocate array dynamically
        raum[i] = new fliese[cols];
    }

    array_allocator(p_tile, p_wall, raum);
    
    cout << "Der Verlegeplan für die eingegebenen Masze sieht wie folgt aus: " << endl;
    array_printer(p_tile, p_wall, raum);

    free(p_tile);
    free(p_wall);
    for(int i = 0; i < rows; i++) {                                                            //delete array dynamically
        delete [] raum[i];
    } 
    delete [] raum;
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
//        else if((temp_y - (int)temp_y == 0)) { //is this b correct check if y is an int?
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

struct fliese** array_allocator(struct fliese* p_tile, struct fliese* p_wall,  struct fliese** raum) {
    if(p_tile->y == p_tile->x) {                          //fill array if tile length and height are equal
        float dim_y = p_wall->y;
        for(int i = 0, a = 0; a < p_wall->y; a+= p_tile->y, i++) {
            float dim_x = p_wall->x;                      //create local variable that shrinks with each allocated 'tile'
            for(int j = 0, b = 0; b < p_wall->x; b += p_tile->x, j++) {
                if(dim_x >= p_tile->x) {
                    raum[i][j].x = 1;
                    dim_x -= p_tile->x;
                }
                else {
                    raum[i][j].x = dim_x/p_tile->x;         //allocate last tile, if a full one doesn't fit
                    dim_x -= p_tile->x;
                }
                if(dim_y >= p_tile->y) {
                    raum[i][j].y = 1;
                }
                else {
                    raum[i][j].y = dim_y/p_tile->y;
                }
            }
        dim_y -= p_tile->y;                                 //decrement the remaining height of the wall with every allocated row
        }
    }
    return raum;
}

void array_printer(struct fliese* p_tile, struct fliese* p_wall, struct fliese** raum) {
    //prints array iterating through each row
    for(int i = 0; raum[i]; i++) {
            for(int j = 0, a = p_wall->x ; a >= 0; a-= p_tile->x, j++) {
                cout << raum[i][j].x << " " << raum[i][j].y << " | ";
            }
        cout << endl;
        } 
}