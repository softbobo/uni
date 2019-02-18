/*implementation of task 9.1 - read a text from the filestream and 
output a file according to what has been read*/
//softbobo 190214

#include<fstream>
#include<string.h>
#include<cstring>
#include<iostream>

using namespace std;

struct resp{
    //data strcuture that connects the buzzwords to the respective employee 
    string name;
    string bword_1;
    string bword_2;
    string bword_3;
};

void read_file(string fname);
void file_printer(string name, string bword, string fname);
void file_appender(string fname, string output);

int main() {
    //main() only asks user for filename (required by task)
    string fname;
    cout << "Please enter filename: " << endl;
    cin >> fname;

    read_file(fname);
    return 0;
}

void read_file(string fname) {
    
    resp keys[3] = {
    { "Paul", "Kaffee", "Bohnen", "Koffein" },
    { "Peet", "Wein", "Sekt", "Bier" },
    { "Phil", "Saft", "Wasser", "Schorle" },
    };
    
    string word;
   
    for(int i = 0; i < 3; i++) {
        //to iterate through the resp-array
        ifstream file (fname, ios_base::in);
        //open the file
        if(!file.is_open()) {
            //check, if the file is really opened
            cout << "Cannot open file!" << endl;
            exit(1);
        }
        while(file >> word) {
            if(word == keys[i].bword_1)
                file_printer(keys[i].name, keys[i].bword_1, fname);
            if(word == keys[i].bword_2)
                file_printer(keys[i].name, keys[i].bword_2, fname);
            if(word == keys[i].bword_3)
                file_printer(keys[i].name, keys[i].bword_3, fname);
        }
        file.close();
        //important - after closing fstream gets flushed, can iterate over file again
    }
}

void file_printer(string name, string bword, string fname) {
    //function makes the new file
    ofstream output;
    string outname = "new_mail_to_" + name + ".txt";
    //write the file's name

    output.open(outname, ios::out);
    output << "Hi, " << name << " you have a new mail regarding " << bword << "." << endl;
    //write first line

    file_appender(fname, outname);
} 

void file_appender(string fname, string outname) {
    //func copies from source to dest, char by char
    char c;
    ofstream output(outname, ios_base::app);
    ifstream input(fname);
    while(input.get(c)) {
        output.put(c);
    }

    output.close();
    input.close();
}