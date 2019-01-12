/* Beleg für Informatik 1, Wintersemester 2018/19
Dozierende: Dr. Andreas Müller, Ariane Jacobs
Student: Robert Schulze, Matrikelnummer: 555625 */
// task defined in README 

/* next steps:
- enhance allocator for non-squared tiles (half a tile every 2nd row)
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
void price_compare(struct fliese* p_tile, struct fliese* p_wall, struct fliese** raum);
struct fliese* parameter_changer(struct fliese* p_tile, struct fliese* p_tile_new);

int main(void){
    
    struct fliese *p_tile = new fliese;
    tile_in(p_tile);
    
    struct fliese *p_wall = new fliese;
    wall_in(p_wall);
    
    const int cols = (p_wall->x/p_tile->x + 2);
    const int rows = (p_wall->y/p_tile->y + 2);
    struct fliese** raum = new struct fliese*[rows];
    for(int i = 0; i < rows; i++) {                                                            //allocate array dynamically
        raum[i] = new fliese[cols];
    };
    array_allocator(p_tile, p_wall, raum);
    
    cout << "Der Verlegeplan für die eingegebenen Masze sieht wie folgt aus: " << endl;
    array_printer(p_tile, p_wall, raum);
    price_compare(p_tile, p_wall, raum);

    //allocate new tile and new array with changed parameters, call prev funcs again
    struct fliese* p_tile_new = new fliese;
    parameter_changer(p_tile, p_tile_new);
    const int cols_new = (p_wall->x/p_tile_new->x + 2);
    const int rows_new = (p_wall->y/p_tile_new->y + 2);
    struct fliese** raum_new = new struct fliese*[rows_new];
    for(int i = 0; i < rows_new; i++) {                                                         
        raum_new[i] = new fliese[cols_new];
    }
    
    cout << "Folgende Ergebnisse erhaelt man nach Drehung der Fliesen um 90 Grad (also vertauschen von Laenge und Breite)." << endl;
    array_allocator(p_tile_new, p_wall, raum_new);
    array_printer(p_tile_new, p_wall, raum_new);
    price_compare(p_tile_new, p_wall, raum_new);

    delete p_tile;
    delete p_wall;
    for(int i = 0; i < rows; i++) {      //free array iteratively as well                                                      //delete array dynamically
        delete [] raum[i];
    } 
    delete [] raum;
    delete p_tile_new;
    for(int i = 0; i < rows_new; i++) {      //free array iteratively as well                                                      //delete array dynamically
        delete [] raum_new[i];
    } 
    delete [] raum_new;
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
        else {
            p_tile->y = temp_y;
        }
    return p_tile;
}

struct fliese* wall_in(struct fliese *p_wall) {
    float wall_width = 0, wall_height = 0;                     
    cout << "Bitte die Breite der Wand in Metern eingeben: " << endl;
    cin >> wall_width;
        if(wall_width > 8 || wall_width <= 0) {
            cout << "Error: Die Wandbreite darf maximal 8m und muss mehr als 0m betragen!" << endl;
            wall_in(p_wall);
        }
        else {
           wall_width *= 100;
           p_wall->x = wall_width; 
        }
    cout << "Bitte die Hoehe der Wand in Metern eingeben: " << endl;
    cin >> wall_height; 
        if(wall_height > 8 || wall_height < 0) {
            cout << "Error: Die Wandhoehe darf maximal 8m und muss mehr als 0m betragen!" << endl;
            wall_in(p_wall);
        }
        else {
            wall_height *= 100;
            p_wall->y = wall_height; 
        }
    return p_wall;
}

struct fliese** array_allocator(struct fliese* p_tile, struct fliese* p_wall,  struct fliese** raum) {
    if(p_tile->x > p_tile->y) {    
        float dim_y = p_wall->y; 
        for(int i = 0, a = 0; a < p_wall->y; a += p_tile->y, i++) {
            float dim_x = p_wall->x;                      //create local variable that shrinks with each allocated 'tile'
            for(int j = 0, b = 0; b < p_wall->x; b += p_tile->x, j++) {
                if((dim_x >= p_tile->x) && (i % 2 != 1)) {
                    raum[i][j].x = 1;
                    dim_x -= p_tile->x;
                }
                if((dim_x >= p_tile->x) && (i % 2 == 1) && (j == 0)) {
                    raum[i][j].x = 0.5;
                    dim_x -= (p_tile->x * 0.5);
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
        dim_y -= p_tile->y; //decrement the remaining height of the wall with every allocated row
       }
    }                                 
    return raum;
}

void array_printer(struct fliese* p_tile, struct fliese* p_wall, struct fliese** raum) {
    //prints array iterating through each row
    cout.precision(3);
    for(int i = 0, a = 0; a < p_wall->y; a+= p_tile->y, i++) {
            for(int j = 0, b = 0; b < p_wall->x; b += p_tile->x, j++) {
                if(raum[i][j].x > 0 && raum[i][j].y > 0)
                cout << raum[i][j].x << " " << raum[i][j].y << " | ";
            }
        cout << endl;
        } 
}

void price_compare(struct fliese* p_tile, struct fliese* p_wall, struct fliese** raum) {
    /*this function takes measures of tiles and room to calc the area, calcs the total number
    of tiles via iterating over the raum array, and then compares prices to print out the cheapest
    (and why so)*/
    cout.precision(3);
    const float price_cm2 = 0.01;
    float wall_area = p_wall->x * p_wall->y;
    float tile_area = p_tile->x * p_tile->y;
    cout << "debug out. wall area is cm²" << wall_area << endl;
    cout << "debug out. tile area is cm²" << tile_area << endl;

    float sum_tiles = 0;
    for(int i = 0, a = 0; a < p_wall->y; a+= p_tile->y, i++) {  //calculates the tot number of tiles needed via the sum of the respective fractions of whole tiles
            for(int j = 0, b = 0 ; b < p_wall->x; b+= p_tile->x, j++) {
                sum_tiles += raum[i][j].x * raum[i][j].y;
            }
        }
    if(sum_tiles - (int)sum_tiles > 0)                          //if the sum of tiles needed is not an int, add 1 minus whatever is behind the dot
        sum_tiles += 1 - (sum_tiles - (int)sum_tiles);
    cout << "Die Gesamtzahl der benoetigten Fliesen beträgt: " << sum_tiles << endl;

    int num_packages = sum_tiles/10;
    if((int)sum_tiles % 10 > 0)                                 //add one package, if the number of tiles is not divisible by ten
        num_packages++;                                         //since we do integer division there and the decimals get cut off
    cout << "Das entspricht einer Anzahl von " << num_packages << " Paketen." << endl;

    float price_single = sum_tiles * price_cm2 * tile_area;
    float price_lot = num_packages * tile_area * 7.5 * price_cm2;

    cout << "Eine einzelne Fliese kostet: " << price_cm2 * tile_area << " Euro" << endl;
    cout << "Ein Paket á 10 Fliesen kostet: " << price_cm2 * tile_area * 10 * 0.75 << " Euro" << endl;
   
    if(price_single < price_lot) {
        cout << "Die guenstigere Alternative ist es, die Fliesen einzeln zu kaufen." << endl;
        cout << "Der Gesamtpreis der benötigten Fliesen betraegt dann " << price_single << " Euro." << endl; 
    }
    else {
        cout << "Die guenstigere Alternative ist es, die Fliesen in Paketen zu kaufen." << endl;
        cout << "Der Gesamtpreis der benoetigten Fliesen betraegt dann " << price_lot << " Euro." << endl;
    }
}

struct fliese* parameter_changer(struct fliese* p_tile, struct fliese* p_tile_new) {
    /*this function is simple: it creates a temporary pointer that points to swap the values p_tile->x
    and p_tile->y are pointing to, to make the same calculations with tiles turned around 90 degrees*/
    p_tile_new->x = p_tile->y;
    p_tile_new->y = p_tile->x;
    cout << "debug out. new values are x: " << p_tile_new->x << " y: " << p_tile_new->y << endl;
    return p_tile_new;
}