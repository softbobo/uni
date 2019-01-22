/* Beleg für Informatik 1, Wintersemester 2018/19
Dozierende: Dr. Andreas Müller, Ariane Jacobs
Student: Robert Schulze, Matrikelnummer: 555625 */
// task defined in README 

/* known issues:
+ Berechneter Gesamtpreis entspricht nicht der günstigsten Variante.
- preis/cm² auf genau 0.01 festlegen
- run through all tests
- test on remote machine
- clean up code afterwards
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
void array_printer(struct fliese** raum, const int cols, const int rows);
void price_compare(struct fliese* p_tile, struct fliese** raum, const int rows, const int cols);
struct fliese* parameter_changer(struct fliese* p_tile, struct fliese* p_tile_new);

int main(void){
    
    struct fliese *p_tile = new fliese;
    tile_in(p_tile);
    
    struct fliese *p_wall = new fliese;
    wall_in(p_wall);
    
    const int cols = (p_wall->x/p_tile->x + 1);
    const int rows = (p_wall->y/p_tile->y + 1);
    struct fliese** raum = new struct fliese*[rows];
    for(int i = 0; i < rows; i++) {                                                            //allocate array dynamically
        raum[i] = new fliese[cols];
    };
    array_allocator(p_tile, p_wall, raum);
    
    cout << "Der Verlegeplan für die eingegebenen Masze sieht wie folgt aus: " << endl;
    array_printer(raum, cols, rows);
    price_compare(p_tile, raum, rows, cols);

    //allocate new tile and new array with changed parameters, call prev funcs again
    struct fliese* p_tile_new = new fliese;
    parameter_changer(p_tile, p_tile_new);
    const int cols_new = (p_wall->x/p_tile_new->x + 1);
    const int rows_new = (p_wall->y/p_tile_new->y + 1);
    struct fliese** raum_new = new struct fliese*[rows_new];
    for(int i = 0; i < rows_new; i++) {                                                         
        raum_new[i] = new fliese[cols_new];
    }
    
    cout << "Folgende Ergebnisse erhaelt man nach Drehung der Fliesen um 90 Grad (also vertauschen von Laenge und Breite)." << endl;
    array_allocator(p_tile_new, p_wall, raum_new);
    array_printer(raum_new, cols_new, rows_new);
    price_compare(p_tile_new, raum_new, rows_new, cols_new);

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
        if(temp_y < 10) {
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
    //this one's smelly for sure, but didn't know how to implement it better
    if(p_tile->x != p_tile->y) {                                                            //when x-axis is bigger than y-axis, every odd row has to start with a half tile
        float dim_y = p_wall->y; 
        for(int i = 0, a = 0; a < p_wall->y; a += p_tile->y, i++) {
            float dim_x = p_wall->x;                                                        //create local variable that shrinks with each allocated 'tile'
            for(int j = 0; dim_x > 0; j++) {
                if((dim_x >= p_tile->x) && (i % 2 == 0)) {                                  //every even (and zeroeth) row start with a full tile
                    raum[i][j].x = 1;                                                       //and all other tiles except the first one in odd rows
                    dim_x -= p_tile->x;
                }
                else if ((dim_x >= p_tile->x) && (i % 2 == 1) && (j != 0)) {
                    raum[i][j].x = 1;                                                       //and all other tiles except the first one in odd rows
                    dim_x -= p_tile->x;
                }
                else if((dim_x >= p_tile->x) && (i % 2 == 1) && (j == 0)) {                 //first tile in odd rows
                    raum[i][j].x = 0.5;
                    dim_x -= (p_tile->x * 0.5);
                }
                else if(dim_x < p_tile->x) {
                    raum[i][j].x = (dim_x/p_tile->x);                                         //allocate last tile, if a full one doesn't fit
                    dim_x -= (p_tile->x * raum[i][j].x);
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
    if(p_tile->x == p_tile->y) {                           //when x-axis is bigger than y-axis, every odd row has to start with a half tile
        float dim_y = p_wall->y; 
        for(int i = 0, a = 0; a < p_wall->y; a += p_tile->y, i++) {
            float dim_x = p_wall->x;                      //create local variable that shrinks with each allocated 'tile'
            for(int j = 0, b = 0; b < p_wall->x; b += p_tile->x, j++) {
                if(dim_x >= p_tile->x) {   
                    raum[i][j].x = 1;                                                      
                    dim_x -= p_tile->x;
                }
                else {
                    raum[i][j].x = dim_x/p_tile->x;                                         
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

void array_printer(struct fliese** raum, const int cols, const int rows) {
    //prints array iterating through each row
    for(int i = 0; i < rows ; i++) {
            for(int j = 0; j < cols; j++) {
                if(raum[i][j].x > 0.009 && raum[i][j].y > 0.009) {
                    cout.precision(2);
                    cout << fixed << raum[i][j].x << " ";
                    cout << fixed << raum[i][j].y << " | "; 
                    }
            }
        cout << endl;
        } 
}

void price_compare(struct fliese* p_tile, struct fliese** raum, const int rows, const int cols) {
    /*this function takes measures of tiles and room to calc the area, calcs the total number
    of tiles via iterating over the raum array, and then compares prices to print out the cheapest
    (and why so)*/
    cout.precision(2);
    const float price_cm2 = 0.01F;
    float tile_area = p_tile->x * p_tile->y;

    float sum_tiles = 0.0;
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) {
            float temp_size = (raum[i][j].x * raum[i][j].y);
            temp_size += 0.005;
            temp_size = (int)(temp_size * 100);
            temp_size /= 100;
            if(temp_size <= (1 - (sum_tiles - (int)sum_tiles)))
                sum_tiles += temp_size;
            else
                sum_tiles++;
        }
    }
    if(sum_tiles - (int)sum_tiles > 0)                          //if the sum of tiles needed is not an int, add 1 minus whatever is behind the dot
        sum_tiles += 1 - (sum_tiles - (int)sum_tiles);
    cout << "Die Gesamtzahl der benoetigten Fliesen beträgt: " << fixed << sum_tiles << endl;

    float num_packages = sum_tiles/10;
    if(tile_area - (int)tile_area > 0) 
        tile_area += 1 - (tile_area - (int)tile_area);
    float price_tile = tile_area * price_cm2;
    float price_package = price_tile * 7.5;
    float price_single = sum_tiles * price_tile;
    float price_mixed = ((int)num_packages * price_package) + ((num_packages - (int)num_packages) * price_tile * 10);

    float num_packages_rounded = num_packages;
    if(num_packages_rounded - (int)num_packages_rounded > 0)                                 //add one package, if the number of tiles is not divisible by ten
        num_packages_rounded += 1 - (num_packages_rounded - (int)num_packages_rounded);                                         //since we do integer division there and the decimals get cut off
    float price_lot = num_packages_rounded * price_package;

    cout << "Eine einzelne Fliese kostet: " << fixed << price_tile << " Euro" << endl;
    cout << "Ein Paket mit 10 Fliesen kostet: " << fixed << price_package << " Euro" << endl;
   
    if(price_single <= price_mixed && price_single < price_lot) {
        cout << "Die guenstigere Alternative ist es, die Fliesen einzeln zu kaufen." << endl;
        cout << "Der Gesamtpreis der benoetigten Fliesen betraegt dann " << fixed << price_single << " Euro." << endl; 
    }
    else if(price_mixed < price_lot) {
        cout << "Die guenstigere Alternative ist es, die Fliesen in einer Mischung aus Paketen und einzelnen zu kaufen." << endl;
        cout << "Der Einkaufskorb setzt sich dann zusammen aus " << (int)(sum_tiles/10) << " Paketen und " << ((int)sum_tiles % 10) << " einzelnen Fliesen." << endl;
        cout << "Der Gesamtpreis der benoetigten Fliesen betraegt dann " << fixed << price_mixed << " Euro." << endl;
    }
    else if(price_lot < price_mixed) {
        cout << "Die guenstigere Alternative ist es, die Fliesen in Paketen zu kaufen." << endl;
        cout << "Der Gesamtpreis der benoetigten Fliesen betraegt dann " << fixed << price_lot << " Euro." << endl;
    }
}

struct fliese* parameter_changer(struct fliese* p_tile, struct fliese* p_tile_new) {
    /*this function is simple: it creates a temporary pointer that points to swap the values p_tile->x
    and p_tile->y are pointing to, to make the same calculations with tiles turned around 90 degrees*/
    p_tile_new->x = p_tile->y;
    p_tile_new->y = p_tile->x;
    return p_tile_new;
}