/* implemenation of task 9.4 - user puts in count of occult items in
and recursive function calculates number of items to be made, legendary
items first. last feature gets a fictive amount of money and decides,
whether the magician is going to sell his stuff or not */
//softbobo 190218

#include<iostream>

using namespace std;

//stores number of resources, put in by user
struct resources {
    int dskin;
    int feather;
    int essence;
};

//struct to store the ourput of calculation
struct items {
    int normal;
    int rare;
    int legend;
};

items* itemizer(int dskin, int feather, int essence, items* output);
bool sell(items* output, int bid);

//just makes new struct, asks user for input, passes on to calculator 
int main() {
    int dskin, feather, essence;
    items* output = new items;
    
    cout << "Welcome! Please insert count of Dragonskin, feathers, and essences.";
    cout << endl;
    cin >> dskin >> feather >> essence;

    itemizer(dskin, feather, essence, output);
    
    cout << "Normal Items " << output->normal << " ";
    cout << "Rare Items " << output->rare << " ";
    cout << "Legendary Items " << output->legend << " ";

    int bid;
    cout << "Enter sell bid for all items" << endl;
    cin >> bid;

    if(sell(output, bid)) {
        cout << "The magician is gonna sell" << endl;
    }
    else {
        cout << "The magician is not gonna sell" << endl;
    }

    return 0;
}

items* itemizer(int dskin, int feather, int essence, items* output) {
    //checks for available resources, decreases them by allocating new items
    
    //not enough resources for any item, stop recursion
    if(dskin < 2 || feather < 1 || essence < 1) return output;

    //enough resources to make a legendary item
    else if(dskin >= 8 && feather >= 10 && essence >= 10) {
        output->legend += 1;
        return itemizer(dskin-8, feather-10, essence-8, output);
    }

    //make rare item
    else if(dskin >= 5 && feather >= 2 && essence >= 3) {
        output->rare += 1;
        return itemizer(dskin-5, feather-2, essence-3, output);
    }

    //make normal item
    else {
        output->normal += 1;
        return itemizer(dskin-2, feather-1, essence-1, output);
    }
}

bool sell(items* output, int bid) {
    //determines, if price is 128 euro per item or more

    int sum = output->legend + output->rare + output->normal;
    return (bid/sum >= 128) ? true : false;
}

