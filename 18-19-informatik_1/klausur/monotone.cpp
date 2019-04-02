/* task from test exam, takes input ints an puts out lines
by ascending and descending values*/
//softbobo 190219

/* works with flaws:
- if a change in monotony is given it prints the first value of the new series
to a newline and the rest of the series in the next newline
*/

#include<iostream>

using namespace std;

int main() {
    int arr[500];
    int len;

    cout << "Bitte Feldlaenge eingeben (max. 500)" << endl;
    cin >> len;

    cout << "Bitte Werte eingeben, die in dem Feld gespeichert werden." << endl; 
    for(int i = 0; i < len; i++) cin >> arr[i];

    cout << "Output in monotonen Folgen: " << endl;
    for(int i = 0; i < len-1; i++) {
        //die ersten zwei werte müssen sowieso zusammen ausgegeben werden
        if(i == 0) {
            cout << arr[i] << " " << arr[i+1] << " ";
            i++;
        }
        else {
            //monoton wachsende reihe
            if(arr[i-2] <= arr[i-1]) {
                if(arr[i-1] <= arr[i]) cout << arr[i] << " ";
                else {
                    cout << endl << arr[i] << " ";
                }
            }
            //monoton fallende reihe
            else if(arr[i-2] >= arr[i-1]) {
                if(arr[i-1] >= arr[i]) cout << arr[i] << " ";
                else {
                    cout << endl << arr[i] << " ";
                }
            }
        }
    }
    return 0;
}
